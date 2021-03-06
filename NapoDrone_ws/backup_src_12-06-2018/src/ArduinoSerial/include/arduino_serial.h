//=================================================================================================
//
//   nodo ROS per leggere e scrivere su seriale
//
//=================================================================================================
#include "ros/ros.h"
#include <errno.h>
#include <termios.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <termios.h>
#include <strings.h>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <iostream>
#include <geometry_msgs/PoseStamped.h>
#include <sys/time.h>
#include <queue>
#include <string>       // std::string
#include <sstream>      // std::stringstream
#include <sensor_msgs/Imu.h>
#include <std_msgs/Int16.h>
#include <std_srvs/Trigger.h>
#include <geometry_msgs/Pose.h>

using namespace std;

#define HEADER_A  (char) 'A'
#define HEADER_CALIB  (char) 'Z'
#define END_PACKET  (char)'.'
#define SEPARATORE (char)','
/**************************************************************************************************/
/*********************************************MACCHINA A STATI*************************************/
/**************************************************************************************************/
typedef enum{
    HEADER_1,
    PAYLOAD_1_1,
    PAYLOAD_1_C,
    
} waiting_msg;

//variabile per la memorizzazione dello stato della macchina a stati
waiting_msg state_msg;
int new_packet = 0;

/************BUFFER DI RICEZIONE E TRASMISSIONE***************************************************/
//buffer di ricezione
std::queue<unsigned char> coda_recv_seriale;
int range_recv[4];
int anchor_range[6];
int index_range;
//client
ros::ServiceServer service_calib_srv;
ros::ServiceServer service_start_srv;
ros::Publisher range_pub;
ros::Publisher anchor_range_pub;
ros::Subscriber service_pub;
int freq_ros_node;
bool start_calibration = false;
int servizio_richiesto = 0 ;

/***************************FUNZIONI************************************************************************/
void init_global_var();
int decode_payload();
void parser_mess(unsigned char buffer);
void write_to_serial(int* serial, int richiesta);
void read_from_serial(int* serial);
int set_interface_attribs (int fd, int speed, int parity);
void set_blocking (int fd, int should_block);
int serial_init(int* fd,const char* seriale_dev);
void service_cb(const std_msgs::Int16::ConstPtr& msg);
void calibrazione();
bool service_calib(std_srvs::Trigger::Request& request, std_srvs::Trigger::Response& response);
bool service_start(std_srvs::Trigger::Request& request, std_srvs::Trigger::Response& response);


