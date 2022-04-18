#!/usr/bin/env python
from exomy_msgs.msg import CameraData, Actions
import rclpy
from rclpy.node import Node
import sys
sys.path.append('/root/exomy_ws/src/exomy/scripts/utils')
import model as m
import torch
from skrl.agents.torch.ppo import PPO, PPO_DEFAULT_CONFIG
from typing import Union
from gym.spaces import Box
import gym
import math
import time
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
        self.observation_space = Box(-math.inf,math.inf,(3,))
        self.action_space = Box(-1.0,1.0,(2,))  

        self.model = self.load_model('/root/exomy_ws/src/exomy/resource/policies/822000_policy.pt')
        self.value = self.load_value('/root/exomy_ws/src/exomy/resource/policies/822000_policy.pt')
        
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
        #img = DepthData()
        start = time.perf_counter()
        a = torch.tensor([ [1.2,1.38,0.7]])
        motorsCom = self.agent.policy.act(a,inference=True)
        steering = motorsCom[0][0][0].item()
        velocity = motorsCom[0][0][1].item()
        message = Actions()
        message.lin_vel = float(velocity)
        message.ang_vel = float(steering)
        self.robot_pub.publish(message)
        finish = time.perf_counter() - start
        self.get_logger().info('\t TIME: {}'.format(finish))


    def load_checkpoint(checkpoint, model):
        print("=> Loading checkpoint")
        model.load_state_dict(checkpoint["state_dict"])



    def load_model(self, model_name, features=[512,256,128]):
        observation_space = self.observation_space
        action_space = self.action_space
        model = m.Policy(observation_space=observation_space, action_space=action_space, features=features)
        checkpoint = torch.load(model_name)
        # model.load_state_dict(checkpoint['state_dict'])
        model.eval()
        model.cuda()
        return model

    def load_value(self, model_name, features=[512,256,128]):
        observation_space = self.observation_space
        action_space = self.action_space
        model = m.Value(observation_space=observation_space, action_space=action_space, features=features)
        checkpoint = torch.load(model_name)
        # model.load_state_dict(checkpoint['state_dict'])
        # model.eval()
        #model.cuda()
        return model


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
