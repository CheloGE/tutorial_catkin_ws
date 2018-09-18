#include "ros/ros.h"
#include "custom_msg_pub_sub/custom_msg.h"

#include <iostream>
#include <string>


void number_callback(const custom_msg_pub_sub::custom_msg::ConstPtr& msg){// a pointer is passed to the callback
    ROS_INFO("Received message: %s",msg->greeting.c_str());//c_str() is a function that lets C++ work\
                                                            with constant strings developed in C. 
    ROS_INFO("Received number: %i",msg->number);
}
int main(int argc, char **argv)
{
    // initialize ros node
    ros::init(argc,argv, "custom_msg_subscriber");
    // create an object of type nodehandle
    ros::NodeHandle node_object;
    // create a subscriber object targeting a topic
    ros::Subscriber msg_subscriber = node_object.subscribe<custom_msg_pub_sub::custom_msg>("/custom_msg_topic",10,number_callback);
    // calling callback function (spinning) continuously
    ros::spin(); 
    return 0;
}
