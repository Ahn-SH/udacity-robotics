# Home Service Robot
This is the final project of Robotics Software Engineering course in Udacity.

The package I used in this project is
- gmapping (gmapping_demo.launch)
 With the sensor data given by RGBD camera, the robot performs SLAM and builds map of the environment it is located.
 ![alt text](https://github.com/Ahn-SH/udacity-robotics/blob/master/Project5_HomeServiceRobot/image_2.png)
- turtlebot_rviz_launchers (view_navigation.launch)
 This package is for saving time setting some configurations of rviz workspace.
- turtlebot_gazebo (turtlebot_world.launch)
 This is the basic gazebo environment where the robot performs pick-up and drop-off actions.
 ![alt text](https://github.com/Ahn-SH/udacity-robotics/blob/master/Project5_HomeServiceRobot/image_1.png)
- pick_objects (pick_ojbects_node.cpp)
 With this file, the robot moves to the pick-up or drop-off point finding the best way to get there in real time.
- add_markers (add_markers_node.cpp / add_markers_node_time.cpp)
 add_markers notes the pick-up point and drop-off point with dark blue box shape.
add_markers_node.cpp delete the pick-up / drop-off marker when the robot gets there.
add_markers_node_time.cpp just shows the goal points every 5 seconds.
