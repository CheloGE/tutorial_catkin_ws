cmake_minimum_required(VERSION 2.8.3)
project(custom_msg_pub_sub)

## Compile as C++11, supported in ROS Kinetic and newer
# add_compile_options(-std=c++11)

## Find catkin macros and libraries
## if COMPONENTS list like find_package(catkin REQUIRED COMPONENTS xyz)
## is used, also find other catkin packages
find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  std_msgs
  message_generation #this line finds packages for message generation of custom msgs
)


################################################
## Declare ROS messages, services and actions ##
################################################

## Generate messages in the 'msg' folder
add_message_files(
   FILES
   custom_msg.msg 
)

## Generate services in the 'srv' folder
# add_service_files(
#   FILES
#   Service1.srv
#   Service2.srv
# )

## Generate actions in the 'action' folder
# add_action_files(
#   FILES
#   Action1.action
#   Action2.action
# )

## Generate added messages and services with any dependencies listed here
 generate_messages(
   DEPENDENCIES
   std_msgs
)

###################################
## catkin specific configuration ##
###################################
## The catkin_package macro generates cmake config files for your package
## Declare things to be passed to dependent projects
## INCLUDE_DIRS: uncomment this if your package contains header files
## LIBRARIES: libraries you create in this project that dependent projects also need
## CATKIN_DEPENDS: catkin_packages dependent projects also need
## DEPENDS: system dependencies of this project that dependent projects also need
catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES custom_msg_pub_sub
#  CATKIN_DEPENDS roscpp rospy std_msgs
#  DEPENDS system_lib
)

###########
## Build ##
###########

## Specify additional locations of header files
## Your package locations should be listed before other locations
include_directories(
# include
  ${catkin_INCLUDE_DIRS}
)
## This will create executables of the nodes
add_executable(${PROJECT_NAME}_publisher_node src/custom_msg_publisher.cpp)
add_executable(${PROJECT_NAME}_subscriber_node src/custom_msg_subscriber.cpp)
## This will link executables to their corresponding libraries
target_link_libraries(${PROJECT_NAME}_publisher_node ${catkin_LIBRARIES})
target_link_libraries(${PROJECT_NAME}_subscriber_node ${catkin_LIBRARIES})

## catkin creates several files which are used as flags to determine if something has been built or not. 
## The flags for messages generatedd are always following the same naming convention: "<package_name>_generate_messages_cpp"
## Therefore This will generate message header file before building the target (outout -o)
add_dependencies(${PROJECT_NAME}_publisher_node ${PROJECT_NAME}_generate_messages_cpp)
add_dependencies(${PROJECT_NAME}_subscriber_node ${PROJECT_NAME}_generate_messages_cpp)


#############
## Install ##
#############


#############
## Testing ##
#############

