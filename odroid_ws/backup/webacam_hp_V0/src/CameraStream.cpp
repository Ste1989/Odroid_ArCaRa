#include <ros/ros.h>
#include <image_transport/image_transport.h>
#include <cv_bridge/cv_bridge.h>
#include <stdio.h>
#include <iostream>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <sensor_msgs/CameraInfo.h>

int main(int argc, char** argv)
{
  ros::init(argc, argv, "image_publisher");
  ros::NodeHandle nh;
  image_transport::ImageTransport it(nh);
  image_transport::Publisher pub = it.advertise("/camera/image_raw", 1);
  ros::Publisher info_pub = nh.advertise<sensor_msgs::CameraInfo>("/camera/camera_info",1);
  /*Open the webcam*/
  cv::VideoCapture cap;

  //cap.open("http://131.114.220.254:8080/video?x.mjpeg");
  //cap.open("http://131.114.237.193");
  cap.open(0);		//Open system default camera
  cap.set(CV_CAP_PROP_FRAME_WIDTH, 1280); // valueX = your wanted width 
  cap.set(CV_CAP_PROP_FRAME_HEIGHT, 800);
  cap.set(CV_CAP_PROP_FPS, 30);
  // Check if video device can be opened with the given index
  if(!cap.isOpened()) {
	ROS_ERROR("No camera Found");
	return 1;
  }
  
  cv::Mat frame;
  sensor_msgs::ImagePtr msg;

  while (nh.ok()) 
  {
    cap >> frame;
    std::cout << frame.size() << std::endl;
    // Check if grabbed frame is actually full with some content
    if(!frame.empty()) 
    {

      //cv::Mat src_gray;
      //cvtColor( frame, src_gray, CV_BGR2GRAY );

      sensor_msgs::CameraInfo info;
      info.height = 800;
      info.width = 1280;
      msg = cv_bridge::CvImage(std_msgs::Header(), "bgr8", frame).toImageMsg();
      pub.publish(msg);
      info_pub.publish(info);
    }

    else
    {
      ROS_ERROR("No camera Found");
    }

    ros::spinOnce();
  }
}






/*

}
*/

