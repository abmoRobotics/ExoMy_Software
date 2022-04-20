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
        self.observation_space = Box(-math.inf,math.inf,(155,))
        self.action_space = Box(-1.0,1.0,(2,))  
        self.goal = np.array([0.0,-2.0])
        self.model = self.load_model('/home/xavier/ExoMy_Software/exomy/config/237000_policy.pt')
        self.value = self.load_value('/home/xavier/ExoMy_Software/exomy/config/237000_policy.pt')
        self.oldSteering = 0
        self.oldVelocity = 0
        cfg_ppo = PPO_DEFAULT_CONFIG.copy()
        self.policy = {"policy" : self.model,
                        "value" : self.value}
        
        
        self.agent = PPO(models=self.policy,
            memory=None, 
            cfg=cfg_ppo, 
            observation_space=self.observation_space, 
            action_space=self.action_space,
            device='cuda:0')
        
       
        self.get_logger().info('\t{} STARTED.'.format(self.node_name.upper()))

    def camera_callback(self, msg):
        start = time.perf_counter()
        direction_vector = np.zeros((2,))
        direction_vector[0] = math.cos(msg.robot_rot[2] - (math.pi/2)) # x value
        direction_vector[1] = math.sin(msg.robot_rot[2] - (math.pi/2)) # y value
        goal_vec = self.goal - np.array([msg.robot_pos[0], msg.robot_pos[1]])

        heading_diff = math.atan2(goal_vec[0] * direction_vector[1] - goal_vec[1] * direction_vector[0], goal_vec[0] * direction_vector[0] + goal_vec[1] * direction_vector[1])
        target_dist = math.sqrt(self.square(self.goal - [msg.robot_pos[0], msg.robot_pos[1]]).sum(-1))

        #self.get_logger().info('\tOwn Z Rot: {}'.format(msg.robot_rot[2]))
        #self.get_logger().info('\tHeading Difference: {}'.format(heading_diff))
        #self.get_logger().info('\tDistance to Target: {}'.format(target_dist))
        
        a = torch.zeros((1,155))
        a[0,0] = target_dist/4
        a[0,1] = heading_diff/3
        a[0,2] = msg.robot_rot[2]
        a[0,3] = self.oldSteering
        a[0,4] = self.oldVelocity

        motorsCom = self.agent.policy.act(a,inference=True)
        steering = torch.clip(motorsCom[0][0][0], min = -1, max = 1)
        velocity = torch.clip(motorsCom[0][0][1], min = -1, max = 1)
        steering = steering.item()
        velocity = velocity.item()
        
        
        self.oldSteering = steering
        self.oldVelocity = velocity

        message = Actions()
        message.lin_vel = float(velocity) * 3
        message.ang_vel = float(steering) * 3
        self.robot_pub.publish(message)
        finish = time.perf_counter() - start
        #self.get_logger().info('\t TIME: {}'.format(finish))


    def load_checkpoint(checkpoint, model):
        print("=> Loading checkpoint")
        model.load_state_dict(checkpoint["state_dict"])



    def load_model(self, model_name, features=[512,256,128]):
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
