#include "ros/ros.h"
#include "ball_chaser/DriveToTarget.h"
#include <sensor_msgs/Image.h>

ros::ServiceClient client;

void drive_robot(float lin_x, float ang_z)
{
	ROS_INFO_STREAM("Driving Robot");

	ball_chaser::DriveToTarget srv;
	srv.request.linear_x = lin_x;
	srv.request.angular_z = ang_z;

	if (!client.call(srv))
		ROS_ERROR("Failed to call service");
}

void process_image_callback(const sensor_msgs::Image img)
{
	float white_pixel = 255;	

	int left_limit = img.step / 3;
	int forward_limit = (img.step / 3) * 2;
	int img_size = img.height * img.step;
	
	for (int i = 0; i < img_size - 3 ; i+=3){
		if((img.data[i] == white_pixel) && (img.data[i+1] == white_pixel) && (img.data[i+2] == white_pixel)) {
			int pixel_index = (i+1) % img.step;
			ROS_INFO_STREAM("This pixel is white!");
			if(pixel_index < left_limit) { 
				ROS_INFO_STREAM("Left");
				drive_robot(0.0, 0.1);
				break; 
			}
			else if(pixel_index < forward_limit) {
				ROS_INFO_STREAM("Front");
				drive_robot(0.3, 0.0); 
				break;
			}
			else {
			ROS_INFO_STREAM("Right");
			drive_robot(0.3, -0.1);
			break;
			} 
		}
	}
	ROS_INFO_STREAM("Stop");
	drive_robot(0.0, 0.0);
}

int main(int argc, char** argv) 
{
	ros::init(argc, argv, "process_image");
	ros::NodeHandle n;
	
	client = n.serviceClient<ball_chaser::DriveToTarget>("/ball_chaser/command_robot");

	ros::Subscriber sub1 = n.subscribe("/camera/rgb/image_raw", 10, process_image_callback);

	ros::spin();
		
	return 0;
}
			
