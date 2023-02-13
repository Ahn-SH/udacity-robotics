#include <ros/ros.h>
#include <visualization_msgs/Marker.h>
#include <geometry_msgs/PoseWithCovarianceStamped.h>
#include <std_msgs/UInt8.h>

double pickup[2] = {-2.0, 2.0};
double dropoff[2] = {3.0, 1.0};
//double curdist = 0.0;

/*void GetCurrentPosition(const geometry_msgs::PoseWithCovarianceStamped::ConstPtr& msg)
{
  curpos[0] = msg -> pose.pose.position.x;
  curpos[1] = msg -> pose.pose.position.y;
  //ROS_INFO("received r: %f, y: %f", curpos[0], curpos[1]);
}*/

//bool CARRY = false;

/*double GetDistance(double goalpos[2]){
  double dist_x = goalpos[0] - curpos[0];
  double dist_y = goalpos[1] - curpos[1];
  double dist = sqrt(dist_x * dist_x + dist_y * dist_y);
  ROS_INFO("distance: %f", dist);
  return dist;
}*/

//int robot_state = 0;

/*void GetRobotState(const std_msgs::UInt8::ConstPtr& msg)
{
  robot_state = msg -> data;
}*/



int main( int argc, char** argv )
{
  ros::init(argc, argv, "add_markers");
  ros::NodeHandle n;
  ros::Rate r(1);
  ros::Publisher marker_pub = n.advertise<visualization_msgs::Marker>("visualization_marker", 1);
  //ros::Subscriber pos_sub = n.subscribe("/amcl_pose", 50, GetCurrentPosition); 
  //ros::Subscriber stat_sub = n.subscribe("/robot_state", 50, GetRobotState);

  // Set our initial shape type to be a cube
  uint32_t shape = visualization_msgs::Marker::CUBE;

  while (ros::ok())
  {
    ros::spinOnce();
    
    visualization_msgs::Marker marker;
    // Set the frame ID and timestamp.  See the TF tutorials for information on these.
    marker.header.frame_id = "map";
    marker.header.stamp = ros::Time::now();

    // Set the namespace and id for this marker.  This serves to create a unique ID
    // Any marker sent with the same namespace and id will overwrite the old one
    marker.ns = "basic_shapes";
    marker.id = 0;

    // Set the marker type.  Initially this is CUBE, and cycles between that and SPHERE, ARROW, and CYLINDER
    marker.type = shape;

    // Set the marker action.  Options are ADD, DELETE, and new in ROS Indigo: 3 (DELETEALL)
    marker.action = visualization_msgs::Marker::ADD;

    // Set the pose of the marker.  This is a full 6DOF pose relative to the frame/time specified in the header
    marker.pose.position.x = 0.0;
    marker.pose.position.y = 0.0;
    marker.pose.position.z = 0;
    marker.pose.orientation.x = 0.0;
    marker.pose.orientation.y = 0.0;
    marker.pose.orientation.z = 0.0;
    marker.pose.orientation.w = 1.0;

    // Set the scale of the marker -- 1x1x1 here means 1m on a side
    marker.scale.x = 0.5;
    marker.scale.y = 0.5;
    marker.scale.z = 0.5;

    // Set the color -- be sure to set alpha to something non-zero!
    marker.color.r = 0.0f;
    marker.color.g = 0.0f;
    marker.color.b = 0.5f;
    marker.color.a = 1.0;

    marker.lifetime = ros::Duration();

    // Publish the marker
    while (marker_pub.getNumSubscribers() < 1)
    {
      if (!ros::ok())
      {
        return 0;
      }
      ROS_WARN_ONCE("Please create a subscriber to the marker");
      sleep(1);
    }

    // Cycle between different shapes
    /*switch (shape)
    {
    case visualization_msgs::Marker::CUBE:
      shape = visualization_msgs::Marker::SPHERE;
      break;
    case visualization_msgs::Marker::SPHERE:
      shape = visualization_msgs::Marker::ARROW;
      break;
    case visualization_msgs::Marker::ARROW:
      shape = visualization_msgs::Marker::CYLINDER;
      break;
    case visualization_msgs::Marker::CYLINDER:
      shape = visualization_msgs::Marker::CUBE;
      break;
    }*/
    r.sleep();
    
    ROS_INFO("Mark the pickup location");
    marker.action = visualization_msgs::Marker::ADD;
    marker.pose.position.x = pickup[0];
    marker.pose.position.y = pickup[1];
    marker_pub.publish(marker);
    ros::Duration(5.0).sleep();
    ROS_INFO("Delete the pickup location");
    marker.action = visualization_msgs::Marker::DELETE;
    marker.pose.position.x = pickup[0];
    marker.pose.position.y = pickup[1];
    marker_pub.publish(marker);
    ros::Duration(5.0).sleep();
    ROS_INFO("Mark the dropoff location");
    marker.action = visualization_msgs::Marker::ADD;
    marker.pose.position.x = dropoff[0];
    marker.pose.position.y = dropoff[1];
    marker_pub.publish(marker);   
    ros::Duration(5.0).sleep();
    ROS_INFO("Delete the dropoff location");
    marker.action = visualization_msgs::Marker::DELETE;
    marker.pose.position.x = dropoff[0];
    marker.pose.position.y = dropoff[1];
    marker_pub.publish(marker);

  }
}
