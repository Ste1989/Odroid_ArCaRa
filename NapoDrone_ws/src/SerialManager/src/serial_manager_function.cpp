//=================================================================================================
//
//   nodo ROS per leggere e scrivere su seriale
//
//=================================================================================================

#include "serial_manager.h"

/*************************************************************/
//
//modulo che preposto alla ricezione e alla decodifica dei messaggi
//ricevuti da PC  sulla seriale 2 (Xbee)
//
/************************************************************/


/*****************************************************************/
/*                                                               */
/*                 CALLBACK LEGGI POSA                            */
/*****************************************************************/
void Pose_cb(const aruco_mapping::ArucoMarker::ConstPtr& msg)
{
    if(msg->marker_visibile)
    {
        //ho una stima buona della posizione della camera
        global_camera_pose.position.x = msg->global_camera_pose.position.x;
        global_camera_pose.position.y = msg->global_camera_pose.position.y;
        global_camera_pose.position.z = msg->global_camera_pose.position.z;
        //transformo il quaternione in un angoli di eulero
        quaternion_2_euler(msg->global_camera_pose.orientation.x,msg->global_camera_pose.orientation.y,
        msg->global_camera_pose.orientation.z,msg->global_camera_pose.orientation.w, 
        global_camera_pose.orientation.x,global_camera_pose.orientation.y,global_camera_pose.orientation.z);
        new_packet_pose = 1;
    
    }
}


/*****************************************************************/
/*                                                               */
/*                 PARSING DEL PACKET                            */
/*****************************************************************/
//funzione che riceve e decodifica i pacchetti in arrivo da PC
void parser_mess(unsigned char buffer){


    //implementazione della macchina a stati
    switch(state_msg){
        case HEADER_1:

            if(buffer == HEADER_A)
            {
                state_msg=HEADER_2;
            }else
            {
                state_msg=HEADER_1;
            }
            break;

        case HEADER_2:
            if(buffer == HEADER_B)
            {
                state_msg=PAYLOAD_1_1;
                //è stato riconosciuto un header-->è in arrivo un nuovo pacchetto
                //ma non è ancora stato ricevuto e decodificato tutto
            }
            else
            {
                state_msg=HEADER_1;
            }
            break;

        case PAYLOAD_1_1:
            coda_recv_seriale.push(buffer);
            if(buffer == PAYLOAD_CMD)
                state_msg=PAYLOAD_1_2;
            else if(buffer == PAYLOAD_PARAM)
                state_msg=PAYLOAD_2_2;
            else if(buffer == PAYLOAD_MODE)
                state_msg = PAYLOAD_3_2;
            else if(buffer == PAYLOAD_WAYPOINT)
                state_msg = PAYLOAD_4_2;
            break;


            /*********************************************************/
            //PCCHETTO CONTENTENTE UN COMANDO
        case PAYLOAD_1_2:
            coda_recv_seriale.push(buffer);
            //notifico che c'è un nuovo pacchetto da decodificare
            new_packet = 1;
            state_msg=HEADER_1;
            break;

            /*********************************************************/
            //PCCHETTO CONTENTENTE UN PARAMETRO (INT 32)
        case PAYLOAD_2_2:
            coda_recv_seriale.push(buffer);
            state_msg=PAYLOAD_2_3;
            break;

        case PAYLOAD_2_3:
            coda_recv_seriale.push(buffer);
            state_msg=PAYLOAD_2_4;
            break;

        case PAYLOAD_2_4:
            coda_recv_seriale.push(buffer);
            state_msg=PAYLOAD_2_5;
            break;

        case PAYLOAD_2_5:
            coda_recv_seriale.push(buffer);
            state_msg=PAYLOAD_2_6;
            break;

        case PAYLOAD_2_6:
            coda_recv_seriale.push(buffer);
            state_msg = HEADER_1;
            new_packet = 1;
            break;
            /*********************************************************/
            //PCCHETTO CONTENTENTE UN MODO
        case PAYLOAD_3_2:
            coda_recv_seriale.push(buffer);
            //notifico che c'è un nuovo pacchetto da decodificare
            new_packet = 1;
            state_msg=HEADER_1;
            break;
            /*********************************************************/
            //PCCHETTO CONTENTENTE UN  X Y Z RZ
            //X
        case PAYLOAD_4_2:
            coda_recv_seriale.push(buffer);
            state_msg = PAYLOAD_4_3;
            break;
        case PAYLOAD_4_3:
            coda_recv_seriale.push(buffer);
            state_msg = PAYLOAD_4_4;
            break;
        case PAYLOAD_4_4:
            coda_recv_seriale.push(buffer);
            state_msg = PAYLOAD_4_5;
            break;
        case PAYLOAD_4_5:
            coda_recv_seriale.push(buffer);
            state_msg = PAYLOAD_4_6;
            break;
            //Y
        case PAYLOAD_4_6:
            coda_recv_seriale.push(buffer);
            state_msg = PAYLOAD_4_7;
            break;
        case PAYLOAD_4_7:
            coda_recv_seriale.push(buffer);
            state_msg = PAYLOAD_4_8;
            break;
        case PAYLOAD_4_8:
            coda_recv_seriale.push(buffer);
            state_msg = PAYLOAD_4_9;
            break;
        case PAYLOAD_4_9:
            coda_recv_seriale.push(buffer);
            state_msg = PAYLOAD_4_10;
            break;
            //Z
        case PAYLOAD_4_10:
            coda_recv_seriale.push(buffer);
            state_msg = PAYLOAD_4_11;
            break;
        case PAYLOAD_4_11:
            coda_recv_seriale.push(buffer);
            state_msg = PAYLOAD_4_12;
            break;
        case PAYLOAD_4_12:
            coda_recv_seriale.push(buffer);
            state_msg = PAYLOAD_4_13;
            break;
        case PAYLOAD_4_13:
            coda_recv_seriale.push(buffer);
            state_msg = PAYLOAD_4_14;
            break;
            //Z
        case PAYLOAD_4_14:
            coda_recv_seriale.push(buffer);
            state_msg = PAYLOAD_4_15;
            break;
        case PAYLOAD_4_15:
            coda_recv_seriale.push(buffer);
            state_msg = PAYLOAD_4_16;
            break;
        case PAYLOAD_4_16:
            coda_recv_seriale.push(buffer);
            state_msg = PAYLOAD_4_17;
            break;
        case PAYLOAD_4_17:
            coda_recv_seriale.push(buffer);
            state_msg = HEADER_1;
            new_packet = 1;
            break;

    }

    return;
}

/*****************************************************************/
/*                                                               */
/*                 DECODE PAYLOAD                                */
/*****************************************************************/
double decode_payload()
{
    //in coda_recv_seriale ho 4 bytes da decodificare
    int decode;
    decode = (long int)coda_recv_seriale.front();
    coda_recv_seriale.pop();
    decode = decode | (0x0000FF00 &(((long int)coda_recv_seriale.front())<<8));
    coda_recv_seriale.pop();
    decode = decode | (0x00FF0000 &(((long int)coda_recv_seriale.front())<<16));
    coda_recv_seriale.pop();
    decode = decode | (0xFF000000 &(((long int)coda_recv_seriale.front())<<24));
    coda_recv_seriale.pop();

    double param_ = (double)decode / 1000;
    cout << "ricevuto payload : " << param_ << endl;
    return param_;
}

/*****************************************************************/
/*                                                               */
/*                 DECODE PACKET                                 */
/*****************************************************************/
void decode_packet()
{

    
 label:
    while(!coda_recv_seriale.empty())
    {

        if(coda_recv_seriale.front() == PAYLOAD_CMD && coda_recv_seriale.size() >= NBYTES_PAYLOAD_CMD)
        {   
            coda_recv_seriale.pop();
            //è un pacchetto di comando, vedo che tipo di comando
            switch(coda_recv_seriale.front()){
                case CMD_NO_REQ:
                    cmd_msg = NO_REQ;
                    coda_recv_seriale.pop();
                    break;
                case CMD_ARM:
                    cmd_msg = ARM;
                    coda_recv_seriale.pop();
                    break;
                case CMD_DISARM:
                    cmd_msg = DISARM;
                    coda_recv_seriale.pop();
                    break;
                case CMD_TAKEOFF:
                    cmd_msg = TAKEOFF;
                    coda_recv_seriale.pop();
                    break;
                case CMD_LAND:
                    cmd_msg = LAND;
                    coda_recv_seriale.pop();
                    break;
                case CMD_RTL:
                    cmd_msg = RTL;
                    coda_recv_seriale.pop();
                    break;
                case CMD_EMERGENCYSTOP:
                    cmd_msg = EMERGENCY_STOP;
                    coda_recv_seriale.pop();
                    break;
                case CMD_CLEAR_RADIO_OVERRIDE:
                    cmd_msg = CLEARRADIOOVERRIDE;
                    coda_recv_seriale.pop();
                    break;

            }
            goto label;
        }

        if(coda_recv_seriale.front() == PAYLOAD_PARAM && coda_recv_seriale.size() >= NBYTES_PAYLOAD_PARAM)
        {
            coda_recv_seriale.pop();
            //in coda_recv_seriale ho 4 bytes che devono essere convertiti in un intero
            //il primo bytes mi dice che parametro si tratta
            switch(coda_recv_seriale.front())
            {
                case PARAM_ALT_TAKEOFF:
                    coda_recv_seriale.pop();
                    param = decode_payload();
                    param_msg = ALT_TAKEOFF;
                    break;
                    /*parametri dei pid: YAW*/
                case PARAM_KP_YAW:
                    coda_recv_seriale.pop();
                    param = decode_payload();
                    param_msg = KP_YAW;
                    break;
                case PARAM_KI_YAW:
                    coda_recv_seriale.pop();
                    param = decode_payload();
                    param_msg = KI_YAW;
                    break;
                case PARAM_KD_YAW:
                    coda_recv_seriale.pop();
                    param = decode_payload();
                    param_msg = KD_YAW;
                    break;
                case PARAM_TS_YAW:
                    coda_recv_seriale.pop();
                    param = decode_payload();
                    param_msg = TS_YAW;
                    break;
                case PARAM_ND_YAW:
                    coda_recv_seriale.pop();
                    param = decode_payload();
                    param_msg = ND_YAW;
                    break;
                case PARAM_LUP_YAW:
                    coda_recv_seriale.pop();
                    param = decode_payload();
                    param_msg = LUP_YAW;
                    break;
                case PARAM_LDOWN_YAW:
                    coda_recv_seriale.pop();
                    param = decode_payload();
                    param_msg = LDOWN_YAW;
                    break;

            }
            goto label;
        }


        if(coda_recv_seriale.front() == PAYLOAD_WAYPOINT && coda_recv_seriale.size() >= NBYTES_PAYLOAD_WAYPOINT)
        {


           
            coda_recv_seriale.pop();
            //devo decodificare il pacchetto
            double x_waypoint = decode_payload();
            double y_waypoint = decode_payload();
            double z_waypoint = decode_payload();
            double rz_waypoint = decode_payload();

            /*salvo nella variabile gloable*/
            waypoint_recv.position.x = x_waypoint;
            waypoint_recv.position.y = y_waypoint;
            waypoint_recv.position.z = z_waypoint;

            waypoint_recv.orientation.x = 0;
            waypoint_recv.orientation.y = 0;
            waypoint_recv.orientation.z = rz_waypoint / 180 * PI;
            waypoint_recv.orientation.w = 0;

            new_waypoint = 1;
            cout << "NEW WAYPOINT X:" << x_waypoint << " Y:" << y_waypoint << " Z:" << z_waypoint << " RZ:" << rz_waypoint << endl;
            goto label;
        }

        if(coda_recv_seriale.front() == PAYLOAD_MODE && coda_recv_seriale.size() >= NBYTES_PAYLOAD_MODE)
        {
            
            
            coda_recv_seriale.pop();
            
            switch(coda_recv_seriale.front())
            {
                case MODE_ACRO:
                    mode_msg = ACRO;
                    coda_recv_seriale.pop();
                    cout << "MODE ACRO" << endl;
                    break;
                case MODE_ALT_HOLD:
                    mode_msg = ALT_HOLD;
                    coda_recv_seriale.pop();
                    cout << "MODE ALT HOLD" << endl;
                    break;
                case MODE_AUTO:
                    mode_msg = AUTO;
                    coda_recv_seriale.pop();
                    cout << "MODE AUTO" << endl;
                    break;
                case MODE_BRAKE:
                    mode_msg = BRAKE;
                    coda_recv_seriale.pop();
                    cout << "MODE BRAKE" << endl;
                    break;
                case MODE_CIRCLE:
                    mode_msg = CIRCLE;
                    coda_recv_seriale.pop();
                    cout << "MODE CIRCLE" << endl;
                    break;
                case MODE_DRIFT:
                    mode_msg = DRIFT;
                    coda_recv_seriale.pop();
                    cout << "MODE DRIFT" << endl;
                    break;
                case MODE_FOLLOW_ME:
                    mode_msg = FOLLOW_ME;
                    coda_recv_seriale.pop();
                    cout << "MODE FOLLOW ME" << endl;
                    break;
                case MODE_GUIDED:
                    mode_msg = GUIDED;
                    coda_recv_seriale.pop();
                    cout << "MODE GUIDED" << endl;
                    break;
                case MODE_LOITER:
                    mode_msg = LOITER;
                    coda_recv_seriale.pop();
                    cout << "MODE LOITER" << endl;
                    break;
                case MODE_POS_HOLD:
                    mode_msg = POS_HOLD;
                    coda_recv_seriale.pop();
                    cout << "MODE POS HOLD" << endl;
                    break;
                case MODE_SIMPLE_SUPER:
                    mode_msg = SIMPLE_SUPER;
                    coda_recv_seriale.pop();
                    cout << "MODE SIMPLE SUP" << endl;
                    break;
                case MODE_SPORT:
                    mode_msg = SPORT;
                    coda_recv_seriale.pop();
                    cout << "MODE SPORT" << endl;
                    break;
                case MODE_STABILIZE:
                    mode_msg = STABILIZE;
                    coda_recv_seriale.pop();
                    cout << "MODE STABILIZE" << endl;
                    break;

            }
            goto label;

        }
        if(coda_recv_seriale.size() > 0)
        {
            cout << "PACCHETTO NON RICONOSCIUTO" << endl;
            coda_recv_seriale.pop();
        }






    }


    //pacchetto è stato analizzato: resetto new_packet
    new_packet = 0;
}
/*****************************************************************/
/*                                                               */
/*                  ENCODE PAYALOD                               */
/*****************************************************************/
void encode_payload(double payload)
{

    //vedere dalla tesi delle macchinine come fare
    long int payload_1000 = (long int)(payload *1000);
    coda_send_seriale.push((unsigned char)(0x000000FF & payload_1000));
    
    coda_send_seriale.push((unsigned char)(0x000000FF & (payload_1000 >> 8)));
    
    coda_send_seriale.push((unsigned char)(0x000000FF & (payload_1000 >> 16)));
    
    coda_send_seriale.push((unsigned char)(0x000000FF & (payload_1000 >> 24)));
    

}

/*****************************************************************/
/*                                                               */
/*                 WRITE SERIALE                                 */
/*****************************************************************/
void write_to_serial(int* serial)
{

    while( !coda_send_seriale.empty() )
    {
        write(*serial,&coda_send_seriale.front(), 1);
        coda_send_seriale.pop();
    }




}

/*****************************************************************/
/*                                                               */
/*                 READ SERIALE                                  */
/*****************************************************************/
void read_from_serial(int* serial)
{

    static int recv1 = 0;
    static int recv2 = 0;
    int bytes = 0;
    int sum_bytes = 0;
    unsigned char buf[1024];

    // Read data from the COM-port
    bytes= read(*serial, buf, sizeof buf);

    for(int a = 0 ; a < bytes ; a++)
    {
        parser_mess(buf[a]);
    }

    if(new_packet == 1)
    {
        decode_packet();
        //aggiorno il tempo
        gettimeofday(&new_pkt_time, NULL);
    }


}
/*****************************************************************/
/*                                                               */
/*                 CHECK_SEND_REQUEST                            */
/*****************************************************************/
void check_send_request()
{
    /*COMANDI*********************************************/
    if(cmd_msg != NO_REQ && cmd_msg != cmd_msg_last)
    {
        cout << "COMANDO RICEVUTO" << endl;
        //preparo la struttura dati
        std_msgs::Int32 msg;
        //riempio la struttura dati
        msg.data = cmd_msg;
        //pubblico sul topc
        req_topic.publish(msg);

        //invio ack
        coda_send_seriale.push(HEADER_A);
        coda_send_seriale.push(HEADER_B);
        coda_send_seriale.push(PAYLOAD_CMD);
        coda_send_seriale.push(PAYLOAD_ACK);
  

        cmd_msg_last = cmd_msg;
        //resetto cmd_msg
        cmd_msg = NO_REQ;

    }

    /********PARAMETRI**********************************************/
    if(param_msg != NO_PARAM)
    {
        cout << "PARAM RICEVUTO" << endl;
        //preparo la struttura dati
        serial_manager::Param msg;
        //riempio la struttura dati
    
        msg.header = param_msg;
        msg.param = param;

        //invio ack 
        coda_send_seriale.push(HEADER_A);
        coda_send_seriale.push(HEADER_B);
        coda_send_seriale.push(PAYLOAD_PARAM);
        coda_send_seriale.push(PAYLOAD_ACK);
        
        //pubblico sul topc
        param_topic.publish(msg);

        param_msg = NO_PARAM;

    }
     /********MODO GUIDA**********************************************/
    if(mode_msg != NO_MODE)
    {
        cout << "FLIGHT MODE RICEVUTO" << endl;
        //preparo la struttura dati
        std_msgs::Int32 msg;
        //riempio la struttura dati
        msg.data = mode_msg;
        //invio ack 
        coda_send_seriale.push(HEADER_A);
        coda_send_seriale.push(HEADER_B);
        coda_send_seriale.push(PAYLOAD_MODE);
        coda_send_seriale.push(PAYLOAD_ACK);
        //pubblico sul topc
        mode_topic.publish(msg);

        mode_msg = NO_MODE;

    }
    /**************NEW WAYPOINT****************************************/
    if(new_waypoint)
    {
        cout << "WAYPOINT RICEVUTO" << endl;
        //invio ack 
        coda_send_seriale.push(HEADER_A);
        coda_send_seriale.push(HEADER_B);
        coda_send_seriale.push(PAYLOAD_WAYPOINT);
        coda_send_seriale.push(PAYLOAD_ACK);

        //pubblico il waypoint sul topic
        geometry_msgs::Pose msg = waypoint_recv;
        waypoint_topic.publish(msg);

        new_waypoint = 0;
    }
}
/*****************************************************************/
/*                                                               */
/*                 CALLBACK PX4 STATUS                           */
/*****************************************************************/
void  Status_Pixhawk_Callback(const std_msgs::Int32::ConstPtr& msg)
{
    //routine che legge lo stato del drone
    cout << "MSG FROM PIXHAWK" << endl;
    switch(msg->data){
        case 0:
            current_status_px4 = CONNECTING;
            //preparo il pacchetto di ack da mandare su seriale
            coda_send_seriale.push(HEADER_A);
            coda_send_seriale.push(HEADER_B);
            coda_send_seriale.push(PAYLOAD_PX4);
            coda_send_seriale.push(CONNECTING);
            break;
        case 1:
            current_status_px4 = CONNECTED;
            //preparo il pacchetto di ack da mandare su seriale
            coda_send_seriale.push(HEADER_A);
            coda_send_seriale.push(HEADER_B);
            coda_send_seriale.push(PAYLOAD_PX4);
            coda_send_seriale.push(CONNECTED);
            break;
        case 2:
            current_status_px4 = ARMABLE;
            coda_send_seriale.push(HEADER_A);
            coda_send_seriale.push(HEADER_B);
            coda_send_seriale.push(PAYLOAD_PX4);
            coda_send_seriale.push(ARMABLE);
            break;
        case 3:
            current_status_px4 = NOT_ARMABLE;
            coda_send_seriale.push(HEADER_A);
            coda_send_seriale.push(HEADER_B);
            coda_send_seriale.push(PAYLOAD_PX4);
            coda_send_seriale.push(NOT_ARMABLE);
            break;
        case 4:
            current_status_px4 = ARMED;
            coda_send_seriale.push(HEADER_A);
            coda_send_seriale.push(HEADER_B);
            coda_send_seriale.push(PAYLOAD_PX4);
            coda_send_seriale.push(ARMED);
            break;
        case 5:
            current_status_px4 = TAKE_OFF;
            coda_send_seriale.push(HEADER_A);
            coda_send_seriale.push(HEADER_B);
            coda_send_seriale.push(PAYLOAD_PX4);
            coda_send_seriale.push(TAKE_OFF);
            break;
        case 6:
            current_status_px4 = LANDED;
            coda_send_seriale.push(HEADER_A);
            coda_send_seriale.push(HEADER_B);
            coda_send_seriale.push(PAYLOAD_PX4);
            coda_send_seriale.push(LANDED);
            break;
        case 7:
            current_status_px4 = DISCONNECTED;
            coda_send_seriale.push(HEADER_A);
            coda_send_seriale.push(HEADER_B);
            coda_send_seriale.push(PAYLOAD_PX4);
            coda_send_seriale.push(DISCONNECTED);
            break;
        case 8:
            current_status_px4 = HOVER;
            coda_send_seriale.push(HEADER_A);
            coda_send_seriale.push(HEADER_B);
            coda_send_seriale.push(PAYLOAD_PX4);
            coda_send_seriale.push(HOVER);
            break;
        case 9:
            current_status_px4 = LANDING;
            coda_send_seriale.push(HEADER_A);
            coda_send_seriale.push(HEADER_B);
            coda_send_seriale.push(PAYLOAD_PX4);
            coda_send_seriale.push(LANDING);
            break;
        case 10:
            current_status_px4 = RTL_STATUS;
            coda_send_seriale.push(HEADER_A);
            coda_send_seriale.push(HEADER_B);
            coda_send_seriale.push(PAYLOAD_PX4);
            coda_send_seriale.push(RTL);
            break;
        case 11:
            current_status_px4 = EMERGENCY_STOP_STATUS;
            coda_send_seriale.push(HEADER_A);
            coda_send_seriale.push(HEADER_B);
            coda_send_seriale.push(PAYLOAD_PX4);
            coda_send_seriale.push(EMERGENCY_STOP_STATUS);
            break;

    }

}
/*****************************************************************/
/*                                                               */
/*                 INIT SERIALE                                  */
/*****************************************************************/
int set_interface_attribs (int fd, int speed, int parity)
{
        struct termios tty;
        memset (&tty, 0, sizeof tty);
        if (tcgetattr (fd, &tty) != 0)
        {
        printf("error %d from tcgetattr", errno) ;
        //error_message("error %d from tcgetattr", errno);
                return -1;
        }

        cfsetospeed (&tty, speed);
        cfsetispeed (&tty, speed);

        tty.c_cflag = (tty.c_cflag & ~CSIZE) | CS8;     // 8-bit chars
        // disable IGNBRK for mismatched speed tests; otherwise receive break
        // as \000 chars
        tty.c_iflag &= ~IGNBRK;         // disable break processing
        tty.c_lflag = 0;                // no signaling chars, no echo,
                                        // no canonical processing
        tty.c_oflag = 0;                // no remapping, no delays
        tty.c_cc[VMIN]  = 0;            // read doesn't block
        tty.c_cc[VTIME] = 5;            // 0.5 seconds read timeout

        tty.c_iflag &= ~(IXON | IXOFF | IXANY); // shut off xon/xoff ctrl

        tty.c_cflag |= (CLOCAL | CREAD);// ignore modem controls,
                                        // enable reading
        tty.c_cflag &= ~(PARENB | PARODD);      // shut off parity
        tty.c_cflag |= parity;
        tty.c_cflag &= ~CSTOPB;
        tty.c_cflag &= ~CRTSCTS;

        if (tcsetattr (fd, TCSANOW, &tty) != 0)
        {
                printf("error %d from tcsetattr", errno);
                return -1;
        }
        return 0;
}

void set_blocking (int fd, int should_block)
{
        struct termios tty;
        memset (&tty, 0, sizeof tty);
        if (tcgetattr (fd, &tty) != 0)
        {
                printf("error %d from tggetattr", errno);
                return;
        }

        tty.c_cc[VMIN]  = should_block ? 1 : 0;
        tty.c_cc[VTIME] = 5;            // 0.5 seconds read timeout

        if (tcsetattr (fd, TCSANOW, &tty) != 0)
                printf("error %d setting term attributes", errno);
}


int serial_init(int* fd,const char* seriale_dev)
{


    /* apro la porta seriale*/
    const char * portname = seriale_dev;

     *fd = open(portname, O_RDWR | O_NOCTTY | O_SYNC);
    if (*fd < 0)
    {
        printf("error %d opening %s: %s", errno, portname, strerror (errno));
        return -1;
    }
    /*imposto baud rate*/
    set_interface_attribs (*fd, B57600, 0);  // set speed to 115,200 bps, 8n1 (no parity)
    set_blocking (*fd, 0);


    /*inizializzazione macchina a stati*/
    //inizializzazone della macchina a stati con il primo stato
    state_msg = HEADER_1;
    //nessun nuovo pacchetto
    new_packet = 0;
    //nessua richiesta di comando
    cmd_msg = NO_REQ;
    cmd_msg_last = NO_REQ;
    //nessun parametro da inviare
    param_msg = NO_PARAM;

    return 1;
}
/*****************************************************************/
/*                                                               */
/*                  QUATERNIONe TO EULERO                             */
/*****************************************************************/
void quaternion_2_euler(double xquat, double yquat, double zquat, double wquat, double& roll, double& pitch, double& yaw)
{
    //Trasformo le corrdinate SVO in coordinate frame camera.
    double r11 = wquat*wquat + xquat*xquat - yquat*yquat - zquat*zquat;
    double r12 = 2*(xquat*yquat - wquat*zquat);
    double r13 = 2*(zquat*xquat + wquat*yquat);
    double r21 =  2*(xquat*yquat + wquat*zquat);
    double r22 = wquat*wquat - xquat*xquat + yquat*yquat - zquat*zquat;
    double r23 = 2*(yquat*zquat - wquat*xquat);
    double r31 = 2*(zquat*xquat - wquat*yquat);
    double r32 = 2*(yquat*zquat + wquat*xquat);
    double r33 = wquat*wquat - xquat*xquat - yquat*yquat + zquat*zquat;
    //Scrivo la trasposta:
    double rt11,rt12,rt13,rt21,rt22,rt23,rt31,rt32,rt33;
    rt11 = r11;
    rt12 = r21;
    rt13 = r31;
    rt21 = r12;
    rt22 = r22;
    rt23 = r32;
    rt31 = r13;
    rt32 = r23;
    rt33 = r33;
    //calcolo angoli di eulero
    roll = atan2(rt23,rt33);
    pitch = -asin(rt13);
    yaw = atan2(rt12,rt11);
 }