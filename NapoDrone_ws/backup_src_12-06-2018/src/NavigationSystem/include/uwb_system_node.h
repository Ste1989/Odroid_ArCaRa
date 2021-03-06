//#ifndef UWB_SYSTEM_H
//#define UWB_SYSTEM_H

#include <ros/ros.h>
#include <stdio.h>
#include <sys/time.h>

#include "sensor_msgs/Imu.h"
#include <Eigen/Dense>
#include <fstream>
#include <malloc.h>
#include <geometry_msgs/PoseStamped.h>
#include <geometry_msgs/Pose.h>
#include <std_msgs/Int16.h>
#include <std_srvs/Trigger.h>

using namespace std;
using Eigen::MatrixXd;
using Eigen::Vector3d;
using Eigen::VectorXd;
using Eigen::ArrayXd;

//subscriber ros
ros::Subscriber rangeUWB_sub;
ros::Subscriber rangePOZ_sub;
ros::Subscriber anchor_range_sub;
//publisher
ros::Publisher pos_estimated_ekf;
ros::Publisher service_pub;
//client
ros::ServiceClient get_time_sec0;
ros::ServiceClient service_calib;
ros::ServiceClient service_start;

//uwb_manager::RangeUwb range_uwb;
int new_range_packet;

char start_range_recv;
//timeval
//timeval  current_time, filter_time, range_time;
double elapsed_time_filter, elapsed_time_range;
ros::Time current_time, filter_time, range_time, begin_time;

//per lettura file log
int Num_measure;
double* time_log, *range1_log, *range2_log, *range3_log, *range4_log;
double* time_log_rs, *range1_log_rs, *range2_log_rs, *range3_log_rs, *range4_log_rs;

//ancore
Vector3d anchor0;
Vector3d anchor1;
Vector3d anchor2;
Vector3d anchor3;
//
bool anchor_calib = false;
//vettore range resample
VectorXd range_rs(4);

//somma nell'intervallo dei range

struct anchor_range{
 	float anchor0;
	float anchor1;
	float anchor2;
	float anchor3;
}sum_range_dt;


//per debug
int index_range ;
double time_next;
//EKF///////////////////////////////////////
bool first_cycle_EKF;
MatrixXd A(6,6);
VectorXd x_k(6);
ArrayXd  d_hat(4);
MatrixXd H(4,6);
MatrixXd R(4,4);
MatrixXd P(6,6);
MatrixXd Q(6,6);
MatrixXd K(6,4);
MatrixXd anchor_pos(4,3);
int freq_filter;
double time_ms;
double dt_filter ;

int num_samples_rs; 
/////////////////////////////////////////////

bool log_file;
bool debug;
double secs_0;
int freq_ros_node;

FILE* fd;
std::string log_uwb_path;
//dichiarazione delle callback
//void rangeUWB_cb(const uwb_manager::RangeUwb::ConstPtr& msg);
void init_global_var();
void EKF_solo_range_init(VectorXd range);
void EKF_solo_range(VectorXd range,  double dt, VectorXd& position_estimated);
void triangolazione_range(VectorXd range,  Vector3d& pos_triangolata);
void leggi_file_debug();
void resample_data_range();
void rangePOZ_cb(const sensor_msgs::Imu::ConstPtr& imu);
void anchorRange_cb(const geometry_msgs::Pose::ConstPtr& msg);
void leggi_file_calibrazione();
void scrivi_file_calib();
//#endif
