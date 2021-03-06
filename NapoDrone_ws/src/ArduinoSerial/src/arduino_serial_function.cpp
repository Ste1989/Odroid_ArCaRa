//=================================================================================================
//
//   nodo ROS per leggere e scrivere su seriale
//
//=================================================================================================
//A,RANGE.
//B,RANGE.
#include "arduino_serial.h"

/*****************************************************************/
/*                                                               */
/*                 PARSING DEL PACKET                            */
/*****************************************************************/
//funzione che riceve e decodifica i pacchetti in arrivo da PC
void parser_mess(unsigned char buffer)
{    
    sensor_msgs::Imu msg;
    geometry_msgs::Pose msg_anchor;
     //implementazione della macchina a stati
    switch(state_msg){
        case HEADER_1:

            if(buffer == HEADER_A)
            {
                state_msg=PAYLOAD_1_1;
                index_range = 0;
                
            }
            if(buffer == HEADER_B)
            {
                state_msg=PAYLOAD_1_2;
                index_range = 0;
                
            }
            if(buffer == HEADER_C)
            {
                state_msg=PAYLOAD_1_3;
                index_range = 0;
                
            }
            if(buffer == HEADER_D)
            {
                state_msg=PAYLOAD_1_4;
                index_range = 0;
                
            }
            if(buffer == HEADER_E)
            {
                state_msg=PAYLOAD_1_5;
                index_range = 0;
                
            }
            if(buffer == HEADER_F)
            {
                state_msg=PAYLOAD_1_6;
                index_range = 0;
                
            }
            if(buffer == HEADER_G)
            {
                state_msg=PAYLOAD_1_7;
                index_range = 0;
                
            }
            if(buffer == HEADER_H)
            {
                state_msg=PAYLOAD_1_8;
                index_range = 0;
                
            }
            //calibrazione
            if(buffer == HEADER_CALIB)
            {
                state_msg=PAYLOAD_1_C;
                index_range = 0;
            }
            break;
//////////////////////////////////////////////////////////////////////////////////////////////////
        case PAYLOAD_1_1:
            switch(buffer)
            {
                case END_PACKET:
                    
                    range_recv[index_range] = decode_payload();
                    //cout << range_recv[index_range] << endl;
                    msg.angular_velocity.x = range_recv[0];
                    msg.angular_velocity.y = range_recv[1];
                    msg.angular_velocity.z = range_recv[2];
                    msg.linear_acceleration.x = range_recv[3];
                    range1_pub.publish(msg);

                    new_packet ++;
                    state_msg=HEADER_1;
                    index_range = 0;
                    break;

                case HEADER_A:
                
                    for(int i = 0; i< coda_recv_seriale.size(); i++)
                        coda_recv_seriale.pop();
                    index_range = 0;

                    break;

                case SEPARATORE:
                    
                    //ho ricevuto un range, lo devo codificare
                    range_recv[index_range] = decode_payload();
                    //cout << range_recv[index_range] << endl;
                    index_range ++;
                    break;

                default:
                
                    coda_recv_seriale.push(buffer);
                    break;
            }
            break;
//////////////////////////////////////////////////////////////////////////////////////////////////
        case PAYLOAD_1_2:
            switch(buffer)
            {
                case END_PACKET:
                    
                    range_recv[index_range] = decode_payload();
                    //cout << range_recv[index_range] << endl;
                    msg.angular_velocity.x = range_recv[0];
                    msg.angular_velocity.y = range_recv[1];
                    msg.angular_velocity.z = range_recv[2];
                    msg.linear_acceleration.x = range_recv[3];
                    range2_pub.publish(msg);

                    new_packet ++;
                    state_msg=HEADER_1;
                    index_range = 0;
                    break;

                case HEADER_B:
                
                    for(int i = 0; i< coda_recv_seriale.size(); i++)
                        coda_recv_seriale.pop();
                    index_range = 0;

                    break;

                case SEPARATORE:
                    
                    //ho ricevuto un range, lo devo codificare
                    range_recv[index_range] = decode_payload();
                    //cout << range_recv[index_range] << endl;
                    index_range ++;
                    break;

                default:
                
                    coda_recv_seriale.push(buffer);
                    break;
            }
            break;
//////////////////////////////////////////////////////////////////////////////////////////////////
        case PAYLOAD_1_3:
            switch(buffer)
            {
                case END_PACKET:
                    
                    range_recv[index_range] = decode_payload();
                    //cout << range_recv[index_range] << endl;
                    msg.angular_velocity.x = range_recv[0];
                    msg.angular_velocity.y = range_recv[1];
                    msg.angular_velocity.z = range_recv[2];
                    msg.linear_acceleration.x = range_recv[3];
                    range3_pub.publish(msg);

                    new_packet ++;
                    state_msg=HEADER_1;
                    index_range = 0;
                    break;

                case HEADER_C:
                
                    for(int i = 0; i< coda_recv_seriale.size(); i++)
                        coda_recv_seriale.pop();
                    index_range = 0;

                    break;

                case SEPARATORE:
                    
                    //ho ricevuto un range, lo devo codificare
                    range_recv[index_range] = decode_payload();
                    //cout << range_recv[index_range] << endl;
                    index_range ++;
                    break;

                default:
                
                    coda_recv_seriale.push(buffer);
                    break;
            }
            break;
//////////////////////////////////////////////////////////////////////////////////////////////////
        case PAYLOAD_1_4:
            switch(buffer)
            {
                case END_PACKET:
                    
                    range_recv[index_range] = decode_payload();
                    //cout << range_recv[index_range] << endl;
                    msg.angular_velocity.x = range_recv[0];
                    msg.angular_velocity.y = range_recv[1];
                    msg.angular_velocity.z = range_recv[2];
                    msg.linear_acceleration.x = range_recv[3];
                    range4_pub.publish(msg);

                    new_packet ++;
                    state_msg=HEADER_1;
                    index_range = 0;
                    break;

                case HEADER_D:
                
                    for(int i = 0; i< coda_recv_seriale.size(); i++)
                        coda_recv_seriale.pop();
                    index_range = 0;

                    break;

                case SEPARATORE:
                    
                    //ho ricevuto un range, lo devo codificare
                    range_recv[index_range] = decode_payload();
                    //cout << range_recv[index_range] << endl;
                    index_range ++;
                    break;

                default:
                
                    coda_recv_seriale.push(buffer);
                    break;
            }
            break;
//////////////////////////////////////////////////////////////////////////////////////////////////
        case PAYLOAD_1_5:
            switch(buffer)
            {
                case END_PACKET:
                    
                    range_recv[index_range] = decode_payload();
                    //cout << range_recv[index_range] << endl;
                    msg.angular_velocity.x = range_recv[0];
                    msg.angular_velocity.y = range_recv[1];
                    msg.angular_velocity.z = range_recv[2];
                    msg.linear_acceleration.x = range_recv[3];
                    range5_pub.publish(msg);

                    new_packet ++;
                    state_msg=HEADER_1;
                    index_range = 0;
                    break;

                case HEADER_E:
                
                    for(int i = 0; i< coda_recv_seriale.size(); i++)
                        coda_recv_seriale.pop();
                    index_range = 0;

                    break;

                case SEPARATORE:
                    
                    //ho ricevuto un range, lo devo codificare
                    range_recv[index_range] = decode_payload();
                    //cout << range_recv[index_range] << endl;
                    index_range ++;
                    break;

                default:
                
                    coda_recv_seriale.push(buffer);
                    break;
            }
            break;
//////////////////////////////////////////////////////////////////////////////////////////////////
        case PAYLOAD_1_6:
            switch(buffer)
            {
                case END_PACKET:
                    
                    range_recv[index_range] = decode_payload();
                    //cout << range_recv[index_range] << endl;
                    msg.angular_velocity.x = range_recv[0];
                    msg.angular_velocity.y = range_recv[1];
                    msg.angular_velocity.z = range_recv[2];
                    msg.linear_acceleration.x = range_recv[3];
                    range6_pub.publish(msg);

                    new_packet ++;
                    state_msg=HEADER_1;
                    index_range = 0;
                    break;

                case HEADER_F:
                
                    for(int i = 0; i< coda_recv_seriale.size(); i++)
                        coda_recv_seriale.pop();
                    index_range = 0;

                    break;

                case SEPARATORE:
                    
                    //ho ricevuto un range, lo devo codificare
                    range_recv[index_range] = decode_payload();
                    //cout << range_recv[index_range] << endl;
                    index_range ++;
                    break;

                default:
                
                    coda_recv_seriale.push(buffer);
                    break;
            }
            break;
//////////////////////////////////////////////////////////////////////////////////////////////////
        case PAYLOAD_1_7:
            switch(buffer)
            {
                case END_PACKET:
                    
                    range_recv[index_range] = decode_payload();
                    //cout << range_recv[index_range] << endl;
                    msg.angular_velocity.x = range_recv[0];
                    msg.angular_velocity.y = range_recv[1];
                    msg.angular_velocity.z = range_recv[2];
                    msg.linear_acceleration.x = range_recv[3];
                    range7_pub.publish(msg);

                    new_packet ++;
                    state_msg=HEADER_1;
                    index_range = 0;
                    break;

                case HEADER_G:
                
                    for(int i = 0; i< coda_recv_seriale.size(); i++)
                        coda_recv_seriale.pop();
                    index_range = 0;

                    break;

                case SEPARATORE:
                    
                    //ho ricevuto un range, lo devo codificare
                    range_recv[index_range] = decode_payload();
                    //cout << range_recv[index_range] << endl;
                    index_range ++;
                    break;

                default:
                
                    coda_recv_seriale.push(buffer);
                    break;
            }
            break;
//////////////////////////////////////////////////////////////////////////////////////////////////
        case PAYLOAD_1_8:
            switch(buffer)
            {
                case END_PACKET:
                    
                    range_recv[index_range] = decode_payload();
                    //cout << range_recv[index_range] << endl;
                    msg.angular_velocity.x = range_recv[0];
                    msg.angular_velocity.y = range_recv[1];
                    msg.angular_velocity.z = range_recv[2];
                    msg.linear_acceleration.x = range_recv[3];
                    range8_pub.publish(msg);

                    new_packet ++;
                    state_msg=HEADER_1;
                    index_range = 0;
                    break;

                case HEADER_H:
                
                    for(int i = 0; i< coda_recv_seriale.size(); i++)
                        coda_recv_seriale.pop();
                    index_range = 0;

                    break;

                case SEPARATORE:
                    
                    //ho ricevuto un range, lo devo codificare
                    range_recv[index_range] = decode_payload();
                    //cout << range_recv[index_range] << endl;
                    index_range ++;
                    break;

                default:
                
                    coda_recv_seriale.push(buffer);
                    break;
            }
            break;
            
//////////////////////////////////////////CALIBRATION//////////////////////
        case PAYLOAD_1_C:
            switch(buffer)
            {
                case END_PACKET:
                    
                    anchor_range[index_range] = decode_payload();
                    //cout << anchor_range[index_range] << endl;
                    cout << "Autocalibration response" << endl;
                    msg_anchor.position.x = anchor_range[0];
                    msg_anchor.position.y = anchor_range[1];
                    msg_anchor.position.z = anchor_range[2];
                    msg_anchor.orientation.x = anchor_range[3];
                    msg_anchor.orientation.y = anchor_range[4];
                    msg_anchor.orientation.z = anchor_range[5];
                    anchor_range_pub.publish(msg_anchor);

                    //new_packet ++;
                    state_msg=HEADER_1;
                    index_range = 0;
                    break;

                case SEPARATORE:
                    
                    //ho ricevuto un range, lo devo codificare
                    anchor_range[index_range] = decode_payload();
                    //cout << anchor_range[index_range] << endl;
                    index_range ++;
                    break;

                default:
                
                    coda_recv_seriale.push(buffer);
                    break;
            }
            break;

    }
      
}
/*****************************************************************/
/*                                                               */
/*                 service start                                 */
/*****************************************************************/
bool service_start(std_srvs::Trigger::Request& request, std_srvs::Trigger::Response& response)
{
  cout << "Start request" << endl;
  servizio_richiesto = 2;
  return true;
}
/*****************************************************************/
/*                                                               */
/*                 service calib                             */
/*****************************************************************/
bool service_calib(std_srvs::Trigger::Request& request, std_srvs::Trigger::Response& response)
{
  cout << "Autocalibration request" << endl;
  servizio_richiesto = 1;
  return true;
}

/*****************************************************************/
/*                                                               */
/*                 DECODE PAYLOAD                                */
/*****************************************************************/
int decode_payload()
{
    int a = 0;
    int n = coda_recv_seriale.size()-1 ;
    
    for(int i=0; i<n+1; i++)
    {   
        
        a = (int)(coda_recv_seriale.front()-'0') * pow(10,n-i) + a;
        coda_recv_seriale.pop();
    } 
    
    return a;
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
    //prova con for...
    /*if(coda_recv_seriale.size() > 0)
    {   cout << "dimensione coda: " << coda_recv_seriale.size() << endl;
        decode_packet();
    }*/
    //while(new_packet)
//    {
        //cout << "pacchetti da elaborare: " << new_packet << endl;
        //decode_payload();
  //  }



}

/*****************************************************************/
/*                                                               */
/*                 INIT GLOBL VAR                                */
/*****************************************************************/
void init_global_var()
{
    state_msg=HEADER_1;
    new_packet = 0;
    index_range = 0;
    servizio_richiesto = 0;
}
/*****************************************************************/
/*                                                               */
/*                 WRITE SERIALE                                 */
/*****************************************************************/
void write_to_serial(int* serial, int richiesta)
{   
    if(richiesta == 1)
    {   
        char data[] = {'C','.'};
        int n_written = write( *serial, data, 2 );
    }
    if(richiesta == 2)
    {
        char data[] = {'S','.'};
        int n_written = write( *serial, data, 2 );

    }
    //legenda
    //richiesta = 5 T1ON
    //richiesta = 6 T1OFF
    //richiesta = 7 T2ON
    //richiesta = 8 T2OFF
    //richiesta = 9 T3ON
    //richiesta = 10 T3OFF
    //richiesta = 11 T4ON
    //richiesta = 12 T4OFF
    //richiesta = 13 T5ON
    //richiesta = 14 T5OFF
    //richiesta = 15 T6ON
    //richiesta = 16 T6OFF
    //richiesta = 17 T7ON
    //richiesta = 18 T7OFF
    //richiesta = 19 T8ON
    //richiesta = 20 T8OFF
    if(richiesta == 5)
    {
        char data[] = "T1ON.";
        int n_written = write( *serial, data, 5 );

    }
    if(richiesta == 6)
    {
        char data[] = "T1OFF";
        int n_written = write( *serial, data, 6 );

    }
    if(richiesta == 7)
    {
        char data[] = "T2ON";
        int n_written = write( *serial, data, 5 );

    }
    if(richiesta == 8)
    {
        char data[] = "T2OFF";
        int n_written = write( *serial, data, 6 );

    }
    if(richiesta == 9)
    {
        char data[] = "T3ON";
        int n_written = write( *serial, data, 5 );

    }
    if(richiesta == 10)
    {
        char data[] = "T3OFF";
        int n_written = write( *serial, data, 6 );

    }
    if(richiesta == 11)
    {
        char data[] = "T4ON";
        int n_written = write( *serial, data, 5 );

    }
    if(richiesta == 12)
    {
        char data[] = "T4OFF";
        int n_written = write( *serial, data, 6 );

    }
    if(richiesta == 13)
    {
        char data[] = "T5ON";
        int n_written = write( *serial, data, 5 );

    }
    if(richiesta == 14)
    {
        char data[] = "T5OFF";
        int n_written = write( *serial, data, 6 );

    }
    if(richiesta == 15)
    {
        char data[] = "T6ON";
        int n_written = write( *serial, data, 5 );

    }
    if(richiesta == 16)
    {
        char data[] = "T6OFF";
        int n_written = write( *serial, data, 6 );

    }
    if(richiesta == 17)
    {
        char data[] = "T7ON";
        int n_written = write( *serial, data, 5 );

    }
    if(richiesta == 18)
    {
        char data[] = "T7OFF";
        int n_written = write( *serial, data, 6 );

    }
    if(richiesta == 19)
    {
        char data[] = "T8ON";
        int n_written = write( *serial, data, 5 );

    }
    if(richiesta == 20)
    {
        char data[] = "T8OFF";
        int n_written = write( *serial, data, 6 );

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
    set_interface_attribs (*fd, B115200, 0);  // set speed to 115,200 bps, 8n1 (no parity)
    set_blocking (*fd, 0);




    return 1;
}