#include "ros/ros.h"
#include "python_keyboard_teleop/motors_signal.h"

void motors_callback(const python_keyboard_teleop::motors_signal::ConstPtr& motors_signal){
    ROS_INFO("motor left :%i  motor right: %i",motors_signal->motor_left,motors_signal->motor_right);
}

main(int argc, char **argv)
{
    // initialize ros node
    ros::init(argc,argv, "motors_subscriber");
    // create an object of type nodehandle
    ros::NodeHandle node_object;
    // create a publisher object targeting a topic
    ros::Subscriber msg_publisher = \
    node_object.subscribe<python_keyboard_teleop::motors_signal>("/motors_topic",10,motors_callback);
    // spinning for callback
    ros::spin();
    
    return 0;
}
