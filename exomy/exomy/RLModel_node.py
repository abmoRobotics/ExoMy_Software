#!/usr/bin/env python
from exomy_msgs.msg import CameraData, Actions
import rclpy
from rclpy.node import Node
import sys
import torch
from skrl.agents.torch.ppo import PPO, PPO_DEFAULT_CONFIG
from typing import Union
from gym.spaces import Box
import gym
import math
import time
import numpy as np
sys.path.append('/home/xavier/ExoMy_Software/exomy/scripts/utils')
import model as m
class RLModelNode(Node):
    def __init__(self):
        self.drive = True
        self.node_name = 'RLModel_node'
        super().__init__(self.node_name)
        
        self.Dcamera_sub = self.create_subscription(
            CameraData,
            'CameraData',
            self.camera_callback,
            10)

        self.robot_pub = self.create_publisher(
            Actions,
            'Actions',
            1)
        self.observation_space = Box(-math.inf,math.inf,(154,))
        self.action_space = Box(-1.0,1.0,(2,))  
        self.goal = np.array([0.0,-0.3])
        self.model = self.load_model('/home/xavier/ExoMy_Software/exomy/config/obstacle_run/450000_policy.pt')
        self.value = self.load_value('/home/xavier/ExoMy_Software/exomy/config/obstacle_run/450000_policy.pt')
        self.oldSteering = 0
        self.oldVelocity = 0
        cfg_ppo = PPO_DEFAULT_CONFIG.copy()
        self.policy = {"policy": m.StochasticActorHeightmap(self.observation_space, self.action_space, network_features=[256,160,128], encoder_features=[60,20], activation_function="relu"),
                        "value": None}

        self.policy["policy"].load("/home/xavier/ExoMy_Software/exomy/config/obstacle_run/450000_policy.pt")
        #cfg_ppo = PPO_DEFAULT_CONFIG.copy()
        self.agent = PPO(models=self.policy,
            memory=None, 
            cfg=cfg_ppo, 
            observation_space=self.observation_space, 
            action_space=self.action_space,
            device='cuda:0')
        
       
        self.get_logger().info('\t{} STARTED.'.format(self.node_name.upper()))

    def camera_callback(self, msg):
        try:
            start = time.perf_counter()
            direction_vector = np.zeros((2,))
            direction_vector[0] = math.cos(msg.robot_rot[2] - (math.pi/2)) # x value
            direction_vector[1] = math.sin(msg.robot_rot[2] - (math.pi/2)) # y value
            goal_vec = self.goal - np.array([msg.robot_pos[0], msg.robot_pos[1]])

            heading_diff = math.atan2(goal_vec[0] * direction_vector[1] - goal_vec[1] * direction_vector[0], goal_vec[0] * direction_vector[0] + goal_vec[1] * direction_vector[1])
            target_dist = math.sqrt(self.square(self.goal - [msg.robot_pos[0], msg.robot_pos[1]]).sum(-1))
            depth_data = np.array(msg.depth_data)


            #self.get_logger().info('\tOwn Z Rot: {}'.format(msg.robot_rot[2]))
            #self.get_logger().info('\tHeading Difference: {}'.format(heading_diff))
            self.get_logger().info('\tDistance to Target: {}'.format(target_dist))
            if target_dist > 0.05 and self.drive:
                DepthInfo = torch.zeros((1,154))
                DepthInfo[0,0] = target_dist/4
                DepthInfo[0,1] = heading_diff/3
                #a[0,2] = msg.robot_rot[2]
                DepthInfo[0,2] = self.oldVelocity
                DepthInfo[0,3] = self.oldSteering
                DepthInfo[0,4:154] = torch.from_numpy(depth_data)
                
                motorsCom = self.agent.policy.act(DepthInfo,inference=True)
                # self.get_logger().info('\tLin Vel: {}'.format(motorsCom[0][0][0]))
                # self.get_logger().info('\tAng Vel: {}'.format(motorsCom[0][0][1]))
                # self.get_logger().info('\tTarget Distance: {}'.format(a[0,0]))
                # self.get_logger().info('\tHeading Difference: {}'.format(a[0,1]))
                # self.get_logger().info('\tPrevious Lin Vel: {}'.format(a[0,2]))
                # self.get_logger().info('\tPrevious Ang Vel: {}'.format(a[0,3]))

                velocity = torch.clip(motorsCom[0][0][0], min = -1, max = 1)
                steering = torch.clip(motorsCom[0][0][1], min = -1, max = 1)
                
                velocity = velocity.item()
                steering = steering.item()
                
                
                self.oldVelocity = velocity
                self.oldSteering = steering
                
                
                message = Actions()
                message.lin_vel = float(velocity) * 3
                message.ang_vel = float(steering) * 3
                # if ((-0.6 < message.lin_vel < 0.6) and (1.2 < message.ang_vel < -1.2)):
                #     message.lin_vel = 0.0
                
                # print(message.lin_vel)
                # print(message.ang_vel)
                self.robot_pub.publish(message)
                finish = time.perf_counter() - start
                #self.get_logger().info('\t TIME: {}'.format(finish))
            else:
                message = Actions()
                message.lin_vel = float(0)
                message.ang_vel = float(0)
                self.drive = False
                # if ((-0.6 < message.lin_vel < 0.6) and (1.2 < message.ang_vel < -1.2)):
                #     message.lin_vel = 0.0
                
                # print(message.lin_vel)
                # print(message.ang_vel)
                self.robot_pub.publish(message)
        except Exception as e:
            self.get_logger().info('\t Error in the Model Node: {}'.format(e))


    def load_checkpoint(checkpoint, model):
        print("=> Loading checkpoint")
        model.load_state_dict(checkpoint["state_dict"])



    def load_model(self, model_name, features=[256,160,128]):
        observation_space = self.observation_space
        action_space = self.action_space
        model = m.StochasticActorHeightmap(observation_space=observation_space, action_space=action_space, network_features=features, activation_function="relu")
        checkpoint = torch.load(model_name)
        # model.load_state_dict(checkpoint['state_dict'])
        model.eval()
        model.cuda()
        return model

    def load_value(self, model_name, features=[128,64]):
        observation_space = self.observation_space
        action_space = self.action_space
        model = m.DeterministicActor(observation_space=observation_space, action_space=action_space, features=features, activation_function="relu")
        checkpoint = torch.load(model_name)
        # model.load_state_dict(checkpoint['state_dict'])
        # model.eval()
        #model.cuda()
        return model
    def square(self, var):
        return var*var

def main(args=None):
    rclpy.init(args=args)

    try:
        RLModel_Node = RLModelNode()
        try:
            rclpy.spin(RLModel_Node)
        finally:
            RLModel_Node.destroy_node()
    except KeyboardInterrupt:
        pass
    finally:
        rclpy.shutdown()


if __name__ == '__main__':
    main()
