#! /bin/sh
xterm -e " gazebo " &
sleep 5
xterm -e " source /devel/setup.bash; roscore" &
sleep 5
xterm -e " rosrun rviz rviz"
