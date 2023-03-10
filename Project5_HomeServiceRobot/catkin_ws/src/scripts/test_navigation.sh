#!/bin/sh

xterm -e "cd $(pwd)/../..; source devel/setup.bash"
sleep 5

xterm -e "roslaunch turtlebot_gazebo turtlebot_world.launch " &
sleep 15
xterm -e "roslaunch turtlebot_gazebo amcl_demo.launch" &
sleep 15
xterm -e "roslaunch turtlebot_rviz_launchers view_navigation.launch"
