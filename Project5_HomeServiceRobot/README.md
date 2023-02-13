# Home Service Robot
This is the final project of Robotics Software Engineering course in Udacity.


## The list of package
```
    ├──                                # Official ROS packages
    |
    ├── slam_gmapping                  # gmapping_demo.launch file                   
    │   ├── gmapping
    │   ├── ...
    ├── turtlebot                      # keyboard_teleop.launch file
    │   ├── turtlebot_teleop
    │   ├── ...
    ├── turtlebot_interactions         # view_navigation.launch file      
    │   ├── turtlebot_rviz_launchers
    │   ├── ...
    ├── turtlebot_simulator            # turtlebot_world.launch file 
    │   ├── turtlebot_gazebo
    │   ├── ...
    ├──                                # Your packages and direcotries
    |
    ├── map                          # map files
    │   ├── ...
    ├── scripts                   # shell scripts files to avoid repetitive tasks
    │   ├── ...
    ├──rvizConfig                      # rviz configuration files to avoid repetitive tasks
    │   ├── ...
    ├──pick_objects                    # C++ node moving towards the goal points
    │   ├── src/pick_objects.cpp
    │   ├── ...
    ├──add_markers                     
    │   ├── src/add_markers_node.cpp   # C++ node marking the goal points (mark the goal points and disappear when the it reached to the goal)
    │   ├── src/add_markers_node_time.cpp   # C++ node marking the goal points (just marking the pick up and drop off point alternately every 5 seconds)
    │   ├── ...
    └──
```

The package I used in this project is
- gmapping (gmapping_demo.launch / amcl_demo.launch) <br />
 With the sensor data given by RGBD camera, the robot performs AMCL(Adaptive Monte Carlo Localization) and builds map of the environment it is located. <br />
 AMCL uses particle filter, so the the robot sample and re-sample the particles based on the data from the RGBD camera, laser sensor and so on. <br />
 You can see the green particles in the image below. <br />
 The range of the particles distribution becomes narrower and narrower as the robot gets to know where it is. <br />
 ![alt text](https://github.com/Ahn-SH/udacity-robotics/blob/master/Project5_HomeServiceRobot/image_2.png)
- turtlebot_rviz_launchers (view_navigation.launch) <br />
 This package is for saving time setting some configurations of rviz workspace.
- turtlebot_gazebo (turtlebot_world.launch) <br />
 This is the basic gazebo environment where the robot performs pick-up and drop-off actions.
 ![alt text](https://github.com/Ahn-SH/udacity-robotics/blob/master/Project5_HomeServiceRobot/image_1.png)
- pick_objects (pick_ojbects_node.cpp) <br />
 With this file, the robot moves to the pick-up or drop-off point finding the best way to get there in real time.
- add_markers (add_markers_node.cpp / add_markers_node_time.cpp) <br />
 add_markers notes the pick-up point and drop-off point with dark blue box shape. <br />
add_markers_node.cpp delete the pick-up / drop-off marker when the robot gets there. <br />
add_markers_node_time.cpp just shows the pick-up point and drop-off point alternately every 5 seconds. <br />
