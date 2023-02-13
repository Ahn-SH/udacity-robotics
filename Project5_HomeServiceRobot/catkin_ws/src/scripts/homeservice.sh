#!/bin/sh
xterm -e " cd $(pwd)/../../; source devel/setup.bash;" &

xterm -e " roslaunch turtlebot_gazebo turtlebot_world.launch" &

sleep 15

xterm -e " roslaunch turtlebot_gazebo amcl_demo.launch " &

sleep 5

xterm -e " rosrun rviz rviz -d `rospack find turtlebot_rviz_launchers`/rviz/with_marker.rviz" &

sleep 5

xterm -e " rosrun add_markers add_markers_node" &

sleep 5

xterm -e " rosrun pick_objects pick_objects_node"
