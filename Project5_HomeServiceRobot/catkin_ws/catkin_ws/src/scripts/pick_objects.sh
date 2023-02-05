#!/bin/sh
xterm -e "cd $(pwd)/../..; source dvel/setup.bash" &
sleep 5
xterm -e "roslaunch turtlebot_gazebo turtlebot_world.launch " &
sleep 5
xterm -e "roslaunch turtlebot_gazebo amcl_demo.launch " &
sleep 5
xterm -e "roslaunch turtlebot_rviz_launchers view_navigation.launch " &
sleep 5
xterm -e "rosrun pick_objects pick_objects_node " 
