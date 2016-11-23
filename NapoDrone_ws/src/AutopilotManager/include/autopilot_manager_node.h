
#include <ros/ros.h>
#include <mavros_msgs/CommandBool.h>
#include <mavros_msgs/SetMode.h>
#include <mavros_msgs/OverrideRCIn.h>
#include <mavros_msgs/State.h>
#include "std_msgs/Int32.h"
#include <mavros_msgs/StreamRate.h>
#include <sensor_msgs/FluidPressure.h>
#include <stdio.h>
#include <aruco_mapping/ArucoMarker.h>
#include <geometry_msgs/Pose.h>
#include <serial_manager/Param.h>
#include <sys/time.h>


using namespace std;

//Il gradiente barico verticale è legato alla variazione di pressione con l'aumentare o il diminuire della quota.
// La sua variazione è fissata in 27 piedi (8,23 m) per ogni hPa (o millibar) 
//di differenza di pressione in aria standard
//quindi la proporzione da impostare sarà:
//8.23 : 100 = x : variazione_registrata

//stato del drone
mavros_msgs::State current_state;
//pressione 
double init_pressure;
double current_pressure;
double alt_from_barometer; 

//cvarianili per la gestione del tempo
timeval  current_time, control_time;
double elapsed_time_control;
char waypoint_recv;
std::string PID_file;
bool init_takeoff;
std::string init_flight_mode;
int loop_rate;
int stream_rate;
bool marker_visibile;
//altezza di takeoff da raggiungere
double alt_takeoff_target;
//struttura per la memorizzazione della posa della camera nel frame world
struct global_pose
{
    geometry_msgs::Point position;
    geometry_msgs::Point orientation;

};
global_pose global_camera_pose;

//memorizzo waypoint
geometry_msgs::Pose current_waypoint;

//ros topic subscriber
ros::Subscriber state_sub;
ros::Subscriber cmd_sub;
ros::Subscriber mode_sub;
ros::Subscriber param_sub;
ros::Subscriber pressure_sub;
ros::Subscriber aruco_poses_sub;
ros::Subscriber waypoint_sub;
//ros topic publisher
ros::Publisher rc_pub;
ros::Publisher state_pub;
//ros topic service
ros::ServiceClient arming_client;
ros::ServiceClient set_mode_client;
ros::ServiceClient set_stream_rate_client;


//RC_MAP è la mappa dei segnali radio
//[0] : ROOL
//[1] : PITCH
//[2] : THRLOTTE
//[3] : ALT
//[4]
#define RC_YAW 3
#define RC_ROLL 0
#define RC_PITCH 1
#define RC_THROTTLE 2
#define PWM_LOW_LIMIT 1000
#define PWM_HIGH_LIMIT 2000
#define PWM_MEDIUM 1500
#define NO_OVERRIDE 0



//ENUMERATORI
/*possibili stati autopilota *************************************/
typedef enum{
    CONNECTING,
    CONNECTED,
    ARMABLE,
    NOT_ARMABLE,
    ARMED,
    TAKE_OFF,
    LANDED,
    DISCONNECTED,
    HOVER,
    LANDING,
    RTL_STATUS,
    EMERGENCY_STOP_STATUS,
}status_px4;


/*possibili richieste di flight mode *************************************/
typedef enum{
    NO_MODE,
    STABILIZE,
    ALT_HOLD,
    LOITER,
    AUTO,
    ACRO,
    SPORT,
    DRIFT,
    GUIDED,
    CIRCLE,
    POS_HOLD,
    BRAKE,
    FOLLOW_ME,
    SIMPLE_SUPER,
} mode_request;

mode_request current_mode_req;
/*possibili richiesta di comandi**********************************/
typedef enum{
    NO_REQ,
    ARM,
    DISARM,
    TAKEOFF,
    LAND,
    RTL,
    EMERGENCY_STOP,
    CLEAR_RADIO_OVERRIDE,
} cmd_request;

cmd_request current_cmd_req;
/*possibili richieste di cambio parametri*****************************/
typedef enum{
    NO_PARAM,
    ALT_TAKEOFF, 

    K_ROLL,
    B_ROLL,
    TI_ROLL, 
    TS_ROLL, 
    TD_ROLL, 
    ND_ROLL, 
    LUP_ROLL,  
    LDOWN_ROLL, 

    K_PITCH,
    B_PITCH,
    TI_PITCH, 
    TS_PITCH, 
    TD_PITCH, 
    ND_PITCH, 
    LUP_PITCH,  
    LDOWN_PITCH, 

    K_YAW,
    B_YAW,
    TI_YAW, 
    TS_YAW, 
    TD_YAW, 
    ND_YAW, 
    LUP_YAW,  
    LDOWN_YAW, 

    K_ALT,
    B_ALT,
    TI_ALT, 
    TS_ALT, 
    TD_ALT, 
    ND_ALT, 
    LUP_ALT,  
    LDOWN_ALT,
} param_request;


/***********************************************************************************************/
/*                                                                                             */
/*                PID                                                                          */
/*                                                                                             */
/***********************************************************************************************/
class PIDController {
  private:
    //parametri del controllore
    double K;
    double b;
    double Ti;
    double Td;
    double Ts;
    double Nd;
    double saturazione_max;
    double saturazione_min;
    //parametri che memorizzano lo stato del controllore
    double I_k;
    double D_k;
    
  public:
    PIDController();
    void init_PID();
    double update_PID(double errore);
    void set_K(double param);
    void set_b(double param);
    void set_Ti(double param);
    void set_Td(double param);
    void set_Ts(double param);
    void set_Nd(double param);
    void set_saturazione_max(double param);
    void set_saturazione_min(double param);

    
};

struct Controllers 
{
  PIDController roll;
  PIDController pitch;
  PIDController yaw;
  //PIDController velocity_x;
  //PIDController velocity_y;
  PIDController altitude;
} pid_controllers;

//double K_roll,B_roll,Ti_roll,Ts_roll, Td_roll,Nd_roll,limit_max_roll,limit_min_roll;
//double K_pitch,B_pitch,Ti_pitch,Ts_pitch, Td_pitch,Nd_pitch,limit_max_pitch,limit_min_pitch;
//double K_yaw,B_yaw,Ti_yaw,Ts_yaw, Td_yaw,Nd_yaw,limit_max_yaw,limit_min_yaw;
//double K_alt,B_alt,Ti_alt,Ts_alt, Td_alt,Nd_alt,limit_max_alt,limit_min_alt;
//FUNZIONI////////////////////////////////////////////////////////////////////////////////////
void init_global_variables();
void state_cb(const mavros_msgs::State::ConstPtr& msg);
void pressure_cb(const sensor_msgs::FluidPressure::ConstPtr& msg);
void cmd_cb(const std_msgs::Int32::ConstPtr& msg);
void mode_cb(const std_msgs::Int32::ConstPtr& msg);
void param_cb(const serial_manager::Param::ConstPtr& msg);
void waypoint_cb(const geometry_msgs::Pose::ConstPtr& msg);
void poses_cb(const aruco_mapping::ArucoMarker::ConstPtr& msg);
bool arm_vehicle();
bool disarm_vehicle();
bool takeoff_vehicle();
void clear_radio_override();
void quaternion_2_euler(double xquat, double yquat, double zquat, double wquat, double& roll, double& pitch, double& yaw);
void update_control();
double map_control_2_radio(double u, int channel);
bool leggi_PID_file(std::string PID_file);
bool scrivi_PID_file(std::string PID_file);

