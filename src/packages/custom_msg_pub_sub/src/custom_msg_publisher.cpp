#include "ros/ros.h"
#include "custom_msg_pub_sub/custom_msg.h"

#include <iostream>
#include <string>
int main(int argc, char **argv)
{
    // initialize ros node
    ros::init(argc,argv, "custom_msg_publisher");
    // create an object of type nodehandle
    ros::NodeHandle node_object;
    // create a publisher object targeting a topic
    ros::Publisher msg_publisher = node_object.advertise<custom_msg_pub_sub::custom_msg>("/custom_msg_topic",10);
    // create a rate object to set frequency in hz
    ros::Rate frequency_loop(1);
    // create a number integer to count
    int counter = 0;
    while(ros::ok()){
        // create an obj of the message
        custom_msg_pub_sub::custom_msg msg;
        // filling messages' variables
        msg.greeting = "hello chelo";
        msg.number = counter;

        //Printing message data
		ROS_INFO("%d",msg.number);
        ROS_INFO("%s",msg.greeting.c_str()); 
        // incrementing counter
        counter++;
        // frequency loop sleeping the necessary time for meeting the frequency stated before 
        // e.g. 10 hz requires to sleep 1/10 secs 
        frequency_loop.sleep();

        msg_publisher.publish(msg);
    }
    
    return 0;
}

