#!/usr/bin/env python
"""
ROS node that publishes the pose (position + quaternion) of the Pozyx

This is an example of how to combine sensor data and positioning into a single
channel output.

Quite overkill using _Pose, as this consists of 7 float64s, while the source
data comes from integers. Suggestions to replace this are quite welcomed.
"""

import pypozyx
import rospy
from geometry_msgs.msg import Point, PoseStamped, Quaternion
from std_msgs.msg import Header, Float32
from sensor_msgs.msg import FluidPressure, Imu,MagneticField 
from pypozyx import (POZYX_RANGE_PROTOCOL_FAST,DeviceRange,POZYX_POS_ALG_UWB_ONLY, POZYX_3D,POZYX_POS_ALG_TRACKING,POZYX_FAILURE, POZYX_2D,Coordinates, POZYX_SUCCESS, POZYX_ANCHOR_SEL_AUTO,
                     DeviceCoordinates, POZYX_RANGE_PROTOCOL_PRECISION,PozyxSerial, get_first_pozyx_serial_port, SingleRegister, DeviceList,SensorData, SingleRegister)
from pypozyx.definitions.bitmasks import POZYX_INT_MASK_IMU

from pythonosc.udp_client import SimpleUDPClient

import time

remote_id = None

anchors_ids = [0xA000,0xA001,0xA002,0xA003];
height_anchor = [1500,2000,2500,3000]; #mm
import time
import math

enable_auto_calibration= True;
enable_auto_calibration_2 = False;
num_campioni_auto_ranging = 100;
y2_positive = True; #Assumiamo y2 positiva o no

imu_log = False;
pos_log =False;
range_log = True;



anchors = [DeviceCoordinates(0xA000, 1, Coordinates(0, 0, height_anchor[0])),
           DeviceCoordinates(0xA001, 1, Coordinates(9993, 0, height_anchor[1])),
           DeviceCoordinates(0xA002, 1, Coordinates(360, 10123, height_anchor[2])),
           DeviceCoordinates(0xA003, 1, Coordinates(9814, 9504, height_anchor[3]))];
#########################################################################################################
#
#                               calibrazione Automatica STEFANO
#
########################################################################################################
def Anchor_calibration(self):
    if enable_auto_calibration == True :
        range_0_1 = [];
        range_0_2 = [];
        range_1_2 = [];
        range_0_3 = [];
        range_1_3 = [];
        range_2_3 = [];

        d01 = 0.0;
        d02 = 0.0;
        d12 = 0.0;
        d03 = 0.0;
        d13 = 0.0;
        d23 = 0.0;

        device_range = DeviceRange();
        #########################################################################################################################################
        #doranging tra Anchor 0 e Anchor 1
        print("Range between Anchor 0 and Anchor 1")
        i = 0;
        #self.remote_id  = 0xA001
        remote_id = anchors_ids[0];
        destination_id = anchors_ids[1];
        sum = 0;
        print(destination_id-40960)    
        print(remote_id-40960)
        tempo_init = time.time()
        while i < num_campioni_auto_ranging:
            #self.pozyx.setRangingProtocol(POZYX_RANGE_PROTOCOL_PRECISION,self.remote_id )
            #status = self.pozyx.doRanging(self.id, device_range , 0xA001);
            self.pozyx.setRangingProtocol(POZYX_RANGE_PROTOCOL_PRECISION,destination_id )
            status = self.pozyx.doRanging(destination_id, device_range, remote_id)
            #tempo_finale = time.time() - tempo_init
            #print(1/tempo_finale)
            #tempo_init = time.time()
            #print(device_range.distance)
            if status == POZYX_SUCCESS and abs(device_range.RSS) >= 79 and abs(device_range.RSS) <= 103 and device_range.distance < 20000:
                #range_0_1[i] = device_range.distance;
                sum = sum + device_range.distance
                i = i +1;
                
        d01 = sum/i;
        print(sum/i);
        #########################################################################################################################################
        #doranging tra Anchor 0 e Anchor 1
        print("Range between Anchor 0 and Anchor 2")
        i = 0;
        #self.remote_id  = 0xA001
        remote_id = anchors_ids[0];
        destination_id = anchors_ids[2];
        sum = 0;
        print(destination_id-40960)    
        print(remote_id-40960)
        while i < num_campioni_auto_ranging:
            self.pozyx.setRangingProtocol(POZYX_RANGE_PROTOCOL_PRECISION,remote_id )
            #status = self.pozyx.doRanging(self.id, device_range , 0xA001);
            status = self.pozyx.doRanging(destination_id, device_range, remote_id)
                
            #print(device_range.distance)
            if status == POZYX_SUCCESS and abs(device_range.RSS) >= 79 and abs(device_range.RSS) <= 103 and device_range.distance < 20000:
                #range_0_2[i] = device_range.distance;
                sum = sum + device_range.distance
                i = i +1;

        d02 = sum/i;
        print(sum/i);
        #########################################################################################################################################
        #doranging tra Anchor 0 e Anchor 1
        print("Range between Anchor 1 and Anchor 2")
        i = 0;
        #self.remote_id  = 0xA001
        remote_id = anchors_ids[1];
        destination_id = anchors_ids[2];
        sum = 0;
        while i < num_campioni_auto_ranging:
            #self.pozyx.setRangingProtocol(POZYX_RANGE_PROTOCOL_PRECISION,self.remote_id )
            #status = self.pozyx.doRanging(self.id, device_range , 0xA001);
            status = self.pozyx.doRanging(0xA001, device_range, 0xA002)
                
            #print(device_range.distance)
            if status == POZYX_SUCCESS and abs(device_range.RSS) >= 79 and abs(device_range.RSS) <= 103 and device_range.distance < 20000:
                #range_1_2[i] = device_range.distance;
                sum = sum + device_range.distance
                i = i +1;

        d12 = sum/i;
        print(sum/i);
        #########################################################################################################################################
        #doranging tra Anchor 0 e Anchor 1
        print("Range between Anchor 0 and Anchor 3")
        i = 0;
        #self.remote_id  = 0xA001
        remote_id = anchors_ids[0];
        destination_id = anchors_ids[3];
        sum = 0;
        while i < num_campioni_auto_ranging:
            #self.pozyx.setRangingProtocol(POZYX_RANGE_PROTOCOL_PRECISION,self.remote_id )
            #status = self.pozyx.doRanging(self.id, device_range , 0xA001);
            status = self.pozyx.doRanging(0xA000, device_range, 0xA003)
                
            #print(status)
            if status == POZYX_SUCCESS and abs(device_range.RSS) >= 79 and abs(device_range.RSS) <= 103 and device_range.distance < 20000:
                #range_0_3[i] = device_range.distance;
                sum = sum + device_range.distance
                i = i +1;

        d03 = sum/i;
        print(sum/i);
        #########################################################################################################################################
        #doranging tra Anchor 0 e Anchor 1
        print("Range between Anchor 1 and Anchor 3")
        i = 0;
        #self.remote_id  = 0xA001
        remote_id = anchors_ids[1];
        destination_id = anchors_ids[3];
        sum = 0;
        while i < num_campioni_auto_ranging:
            #self.pozyx.setRangingProtocol(POZYX_RANGE_PROTOCOL_PRECISION,self.remote_id )
            #status = self.pozyx.doRanging(self.id, device_range , 0xA001);
            status = self.pozyx.doRanging(destination_id, device_range, remote_id)
                
            #print(status)
            if status == POZYX_SUCCESS and abs(device_range.RSS) >= 79 and abs(device_range.RSS) <= 103 and device_range.distance < 20000:
                #range_1_3[i] = device_range.distance;
                sum = sum + device_range.distance
                i = i +1;

        d13 = sum/i;
        print(sum/i);
        ########################################################################################################################################
        #doranging tra Anchor 0 e Anchor 1
        print("Range between Anchor 2 and Anchor 3")
        i = 0;
        #self.remote_id  = 0xA001
        remote_id = anchors_ids[2];
        destination_id = anchors_ids[3];
        sum = 0;
        while i < num_campioni_auto_ranging:
            #self.pozyx.setRangingProtocol(POZYX_RANGE_PROTOCOL_PRECISION,self.remote_id )
            #status = self.pozyx.doRanging(self.id, device_range , 0xA001);
            status = self.pozyx.doRanging(destination_id, device_range, remote_id)
                
            #print(status)
            if status == POZYX_SUCCESS and abs(device_range.RSS) >= 79 and abs(device_range.RSS) <= 103 and device_range.distance < 20000:
                #range_2_3[i] = device_range.distance;
                sum = sum + device_range.distance
                i = i +1;

        d23 = sum/i;
        print(sum/i);


        print("dist A0 A1: ", d01);
        print("dist A0 A2: ", d02);
        print("dist A1 A2: ", d12);
        print("dist A0 A3: ", d03);
        print("dist A1 A3: ", d13);
        print("dist A2 A3: ", d23);


        #calcolo distanza sul piano X-Y
        r01 = math.sqrt(d01*d01 - ((height_anchor[1]-height_anchor[0])*(height_anchor[1]-height_anchor[0])));
        r02 = math. sqrt(d02*d02 - ((height_anchor[2]-height_anchor[0])*(height_anchor[2]-height_anchor[0])));
        r12 = math.sqrt(d12*d12 - ((height_anchor[2]-height_anchor[1])*(height_anchor[2]-height_anchor[1])));
        r03 = math.sqrt(d03*d03 - ((height_anchor[3]-height_anchor[0])*(height_anchor[3]-height_anchor[0])));
        r13 = math.sqrt(d13*d13 - ((height_anchor[3]-height_anchor[1])*(height_anchor[3]-height_anchor[1])));
        r23 = math.sqrt(d23*d23 - ((height_anchor[3]-height_anchor[2])*(height_anchor[3]-height_anchor[2])));

        print("dist A0 A1: ", r01);
        print("dist A0 A2: ", r02);
        print("dist A1 A2: ", r12);
        print("dist A0 A3: ", r03);
        print("dist A1 A3: ", r13);
        print("dist A2 A3: ", r23);

        CARNOT = (r01*r01 + r02*r02 - r12*r12)/(2*r01*r02);
        if CARNOT > 1 :
            print("CALIBRATION ERROR");
            return

        alpha = math.acos(((r01*r01 + r02*r02 - r12*r12)/(2*r01*r02)))
        print("angolo " , alpha *180 /3.14);

        x0_anchor = 0;
        y0_anchor = 0;
        z0_anchor = height_anchor[0];
        
        x1_anchor = 0;
        y1_anchor = r01;
        z1_anchor = height_anchor[1];

        x2_anchor = r02 * math.sin(alpha);
        y2_anchor = r02 * math.cos(alpha);
        z2_anchor = height_anchor[2];

        a11 = y1_anchor;
        a20 = x2_anchor;
        a21 = y2_anchor;

        y3 = (a11*a11 + r03*r03 - r13*r13)/(2*a11);
        x3 = (a20*a20 - r23*r23 + (y3 - a21)*(y3 - a21) + r03*r03 - y3*y3)/(2*a20);
        #z3 = sqrt((r03*r03 - x3*x3 - y3*y3));

        print("x1 ", x1_anchor);
        print("y1 ", y1_anchor);
        print("z1 ", z1_anchor);


        print("x2 ", x2_anchor);
        print("y2 ", y2_anchor);
        print("z2 ", z2_anchor);


        print("x3 ", x3);
        print("y3 ", y3);
        print("z3 ", height_anchor[3]);

        
        self.anchors[0] = DeviceCoordinates(0xA000, 1, Coordinates(int(0), int(0), height_anchor[0]))
        self.anchors[1] = DeviceCoordinates(0xA001, 1, Coordinates(int(y1_anchor), int(x1_anchor), height_anchor[1]))
        self.anchors[2] = DeviceCoordinates(0xA002, 1, Coordinates(int(y2_anchor), int(x2_anchor), height_anchor[2]))
        self.anchors[3] = DeviceCoordinates(0xA003, 1, Coordinates(int(y3), int(x3), height_anchor[3]))
    



    #adesso in self.anchors dovrei avere le coordinate delle antenne calcolate in automatico tranne l altezza imposta
    #richiamo quindi la funzione seTAnchorManual
    self.setAnchorsManual()
    #####################################################################################################
    #calolo della componente x  dell'antenna 1
    #####################################################################################################
    #x1_stimated = [];
    #sum = 0.0 ;
    #for i = 0 in len(range_0_1):
    #    x1_stimated[i] = sqrt(range_0_1[i]*range_0_1[i] - (height_anchor[1]-height_anchor[0])*(height_anchor[1]-height_anchor[0]));
    #    sum = x1_stimated[i] + sum;
    #calolo della media
    #x1 = sum / num_campioni_auto_ranging;
    #####################################################################################################
    #calolo della componente x e y dell'antenna 2
    #####################################################################################################
    #x2_stimated = [];
    #y2_stimated = [];
    #z20_2 = (height_anchor[2]-height_anchor[0])*(height_anchor[2]-height_anchor[0]);
    #z21_2 = (height_anchor[2]-height_anchor[1])*(height_anchor[2]-height_anchor[1]);
    #x1_2 = x1*x1;
    #sum1 = 0;
    #sum2 = 0;
    #for i = 0 in len(range_0_2):
    #    d02_2 = range_0_2[i]*range_0_2[i];
    #    d12_2 = range_1_2[i]*range_1_2[i];
    #    x2_stimated[i] = (z02_2 - z12_2 + x1_2 - z02_2 + z12_2)/(2*x1);
    #    if y2_positive:
    #        y2_stimated[i] = sqrt(d02_2 - (x2_stimated[i]*x2_stimated[i]) - z02_2);    
    #   else:
    #       y2_stimated[i] = -sqrt(d02_2 - (x2_stimated[i]*x2_stimated[i]) - z02_2);
    #   sum1 = sum1 + x2_stimated[i];
    #    sum2 = sum2 + x2_stimated[i];

    #calcolo con la media 
    #x2 = sum1 / num_campioni_auto_ranging;
    #y2 = sum2 / num_campioni_auto_ranging;
    #####################################################################################################
    #calolo della componente x e y e z  dell'antenna 3
    #####################################################################################################


class ReadyToLocalize(object):

    """Continuously calls the Pozyx positioning function and prints its position."""
#########################################################################################################
#
#                               Init
#
########################################################################################################
    def __init__(self, pozyx, osc_udp_client, anchors, algorithm=POZYX_POS_ALG_UWB_ONLY, dimension=POZYX_3D, height=1000, remote_id=None):
        self.pozyx = pozyx
        self.osc_udp_client = osc_udp_client

        self.anchors = anchors
        self.algorithm = algorithm
        self.dimension = dimension
        self.height = height
        self.remote_id = remote_id


        

#########################################################################################################
#
#                               SETUP
#
########################################################################################################
    def setup(self):
        """Sets up the Pozyx for positioning by calibrating its anchor list."""
        print("NOTES: ")
        print("- No parameters required.")
        print()
        print("- System will auto start configuration")
        print()
        print("- System will auto start positioning")
        print()
        self.pozyx.printDeviceInfo(self.remote_id)
        print()
        print()
        #cancella i devices in memoria

        self.pozyx.clearDevices(self.remote_id)
        
        Anchor_calibration(self)

        #status = self.setAnchorAuto()
     
        self.printPublishConfigurationResult()




#########################################################################################################
#
#                               calibrazione Automatica
#
########################################################################################################
    def setAnchorAuto(self):
        if enable_auto_calibration_2 == True :
            status = self.pozyx.doAnchorCalibration(POZYX_2D,100,anchors_ids,height)
            #adesso rileggo le posizione delle ancore
            list_size = SingleRegister()
            self.pozyx.getDeviceListSize(list_size, self.remote_id)
            #print("List size: {0}".format(list_size[0]))
            if list_size[0] != len(self.anchors):
                self.printPublishErrorCode("configuration")
                return

            device_list = DeviceList(list_size=list_size[0])
            self.pozyx.getDeviceIds(device_list, self.remote_id)
            #print("Calibration result:")
            #print("Anchors found: {0}".format(list_size[0]))
            #print("Anchor IDs: ", device_list)

            for i in range(list_size[0]):
                anchor_coordinates = Coordinates()
                self.pozyx.getDeviceCoordinates(device_list[i], anchor_coordinates, self.remote_id)
                if i == 0:
                    self.anchors[i] = DeviceCoordinates(0xA000, 1, Coordinates(int(anchor_coordinates.x), int(anchor_coordinates.y), height_anchor[i]))
                if i == 1:
                    self.anchors[i] = DeviceCoordinates(0xA001, 1, Coordinates(int(anchor_coordinates.x), int(anchor_coordinates.y), height_anchor[i]))
                if i == 2:
                    self.anchors[i] = DeviceCoordinates(0xA002, 1, Coordinates(int(anchor_coordinates.x), int(anchor_coordinates.y), height_anchor[i]))
                if i == 3:
                    self.anchors[i] = DeviceCoordinates(0xA003, 1, Coordinates(int(anchor_coordinates.x), int(anchor_coordinates.y), height_anchor[i]))            
             


        #adesso in self.anchors dovrei avere le coordinate delle antenne calcolate in automatico tranne l altezza imposta
        #richiamo quindi la funzione seTAnchorManual
        self.setAnchorsManual()
#########################################################################################################
#
#                               Main LOOP
#
########################################################################################################
    def loop(self):
        #dichiaro le variabili
        position = Coordinates()
        quat = pypozyx.Quaternion()
        sensor_data = SensorData()
        calibration_status = SingleRegister()
        #lego dati IMU ####################################################################################################
        if imu_log == True:
            if self.remote_id is not None or self.pozyx.checkForFlag(POZYX_INT_MASK_IMU, 0.01) == POZYX_SUCCESS:

                status = self.pozyx.getAllSensorData(sensor_data, self.remote_id)
                status &= self.pozyx.getCalibrationStatus(calibration_status, self.remote_id)
                if status == POZYX_SUCCESS:
                    time_dt = Header()
                    time_dt = rospy.Time.now()
                    #self.publishSensorData(sensor_data, calibration_status)
                    
                    
                    #Pubblico Pressione
                    pressure_msg = FluidPressure()
                    pressure_msg.header.stamp = rospy.Time.now()
                    pressure_msg.fluid_pressure = float(sensor_data.pressure.value)
                    pub_pressure.publish(pressure_msg)

                    #imu msg
                  
                    imu_msg = Imu()
                    imu_msg.header.stamp = time_dt
                    imu_msg.angular_velocity.x = sensor_data.angular_vel.x
                    imu_msg.angular_velocity.y = sensor_data.angular_vel.y
                    imu_msg.angular_velocity.z = sensor_data.angular_vel.z
                    imu_msg.linear_acceleration.x = sensor_data.linear_acceleration.x
                    imu_msg.linear_acceleration.y = sensor_data.linear_acceleration.y
                    imu_msg.linear_acceleration.z = sensor_data.linear_acceleration.z
                    imu_msg.orientation.x = sensor_data.quaternion.x
                    imu_msg.orientation.y = sensor_data.quaternion.y
                    imu_msg.orientation.z = sensor_data.quaternion.z
                    imu_msg.orientation.w = sensor_data.quaternion.w
                    pub_imu.publish(imu_msg)

                    #bussola
                    magnetic_msg = MagneticField()
                    magnetic_msg.header.stamp = time_dt
                    magnetic_msg.magnetic_field.x = sensor_data.magnetic.x
                    magnetic_msg.magnetic_field.y = sensor_data.magnetic.y
                    magnetic_msg.magnetic_field.z = sensor_data.magnetic.z
                    pub_magnetic.publish(magnetic_msg)


        #faccio la stima di poszione #######################################################################################         
        if pos_log == True:
            status = self.pozyx.doPositioning(position, self.dimension, self.height, self.algorithm, remote_id=self.remote_id)
            self.pozyx.getQuaternion(quat, remote_id=remote_id)
            if status == POZYX_SUCCESS:
                pos_stamped = PoseStamped()
                pos_stamped.header.frame_id = "/pozyx_frame"
                pos_stamped.header.stamp = rospy.Time.now()
                pos_stamped.pose.position.x = position.x
                pos_stamped.pose.position.y = position.y
                pos_stamped.pose.position.z = position.z
                pos_stamped.pose.orientation.x = quat.x
                pos_stamped.pose.orientation.y = quat.y
                pos_stamped.pose.orientation.z = quat.z
                pos_stamped.pose.orientation.w = quat.w
                #self.printPublishPosition(position)
                #pub on topic
                pub.publish(pos_stamped)
            else:
                self.printPublishErrorCode("positioning")

        #faccio la stima di poszione #######################################################################################         
        if range_log == True:
           
            device_range_1 = DeviceRange()
            device_range_2 = DeviceRange()
            device_range_3 = DeviceRange()
            device_range_4 = DeviceRange()
            time_range_0 =time.time()
            destination_id = 0xA000 
            tag_id = 0xB000;
            status = self.pozyx.doRanging(destination_id, device_range_1, tag_id)
            destination_id = 0xA001 
            status = self.pozyx.doRanging(destination_id, device_range_2, tag_id)
            destination_id = 0xA002
            status = self.pozyx.doRanging(destination_id, device_range_3, tag_id)
            destination_id = 0xA003 
            status = self.pozyx.doRanging(destination_id, device_range_4, tag_id)
            time_range =time.time()
            #print("tempo tra range 1 e 4")
            #print(time_range - time_range_0)

            range_msg = Imu()
            range_msg.header.stamp = rospy.Time.now()
            range_msg.angular_velocity.x = device_range_1.distance
            range_msg.angular_velocity.y = device_range_2.distance
            range_msg.angular_velocity.z = device_range_3.distance
            range_msg.linear_acceleration.x = device_range_4.distance
            range_msg.linear_acceleration.y = device_range_1.RSS
            range_msg.linear_acceleration.z = device_range_2.RSS
            range_msg.orientation.x = device_range_3.RSS
            range_msg.orientation.y = device_range_4.RSS
            range_msg.orientation.z = 0
            range_msg.orientation.w = 0
            pub_range.publish(range_msg)



        


#########################################################################################################
#
#                               Pubblica posizione
#
########################################################################################################

    def printPublishPosition(self, position):
        """Prints the Pozyx's position and possibly sends it as a OSC packet"""
        network_id = self.remote_id
        if network_id is None:
            network_id = 0
        print("POS ID {}, x(mm): {pos.x} y(mm): {pos.y} z(mm): {pos.z}".format(
            "0x%0.4x" % network_id, pos=position))
        if self.osc_udp_client is not None:
            self.osc_udp_client.send_message(
                "/position", [network_id, int(position.x), int(position.y), int(position.z)])
#########################################################################################################
#
#                               stampa messaggi di errore
#
########################################################################################################
    def printPublishErrorCode(self, operation):
        """Prints the Pozyx's error and possibly sends it as a OSC packet"""
        error_code = SingleRegister()
        network_id = self.remote_id
        if network_id is None:
            self.pozyx.getErrorCode(error_code)
            print("LOCAL ERROR %s, %s" % (operation, self.pozyx.getErrorMessage(error_code)))
            if self.osc_udp_client is not None:
                self.osc_udp_client.send_message("/error", [operation, 0, error_code[0]])
            return
        status = self.pozyx.getErrorCode(error_code, self.remote_id)
        if status == POZYX_SUCCESS:
            print("ERROR %s on ID %s, %s" %
                  (operation, "0x%0.4x" % network_id, self.pozyx.getErrorMessage(error_code)))
            if self.osc_udp_client is not None:
                self.osc_udp_client.send_message(
                    "/error", [operation, network_id, error_code[0]])
        else:
            self.pozyx.getErrorCode(error_code)
            print("ERROR %s, couldn't retrieve remote error code, LOCAL ERROR %s" %
                  (operation, self.pozyx.getErrorMessage(error_code)))
            if self.osc_udp_client is not None:
                self.osc_udp_client.send_message("/error", [operation, 0, -1])
            # should only happen when not being able to communicate with a remote Pozyx.
#########################################################################################################
#
#                               setta le ancore manulamente
#
########################################################################################################
    def setAnchorsManual(self):
        """Adds the manually measured anchors to the Pozyx's device list one for one."""
        status = self.pozyx.clearDevices(self.remote_id)
        for anchor in self.anchors:
            status &= self.pozyx.addDevice(anchor, self.remote_id)
        if len(self.anchors) > 4:
            status &= self.pozyx.setSelectionOfAnchors(POZYX_ANCHOR_SEL_AUTO, len(self.anchors))
        return status
#########################################################################################################
#
#                               Stampa configurazione ancore
#
########################################################################################################
    def printPublishConfigurationResult(self):
        """Prints and potentially publishes the anchor configuration result in a human-readable way."""
        list_size = SingleRegister()

        self.pozyx.getDeviceListSize(list_size, self.remote_id)
        #print("List size: {0}".format(list_size[0]))
        if list_size[0] != len(self.anchors):
            self.printPublishErrorCode("configuration")
            return
        device_list = DeviceList(list_size=list_size[0])
        self.pozyx.getDeviceIds(device_list, self.remote_id)
        print("Calibration result:")
        #print("Anchors found: {0}".format(list_size[0]))
        #print("Anchor IDs: ", device_list)

        for i in range(list_size[0]):
            anchor_coordinates = Coordinates()
            self.pozyx.getDeviceCoordinates(device_list[i], anchor_coordinates, self.remote_id)
            print("ANCHOR, 0x%0.4x, %s" % (device_list[i], str(anchor_coordinates)))
            if self.osc_udp_client is not None:
                self.osc_udp_client.send_message(
                    "/anchor", [device_list[i], int(anchor_coordinates.x), int(anchor_coordinates.y), int(anchor_coordinates.z)])
                sleep(0.025)
#########################################################################################################
#
#                               Stampa configurazione ancore
#
########################################################################################################
    def printPublishAnchorConfiguration(self):
        """Prints and potentially publishes the anchor configuration"""

        for anchor in self.anchors:
            print("ANCHOR,0x%0.4x,%s" % (anchor.network_id, str(anchor.coordinates)))
            if self.osc_udp_client is not None:
                self.osc_udp_client.send_message(
                    "/anchor", [anchor.network_id, int(anchor.coordinates.x), int(anchor.coordinates.y), int(anchor.coordinates.z)])
                sleep(0.025)

#########################################################################################################
#
#                               MAIN
#
########################################################################################################

if __name__ == '__main__':
    # shortcut to not have to find out the port yourself
    
    serial_port = get_first_pozyx_serial_port()
    if serial_port is None:
        print("No Pozyx connected. Check your USB cable or your driver!")
        quit()
    
    remote_id = 0x6069                 # remote device network ID
    remote = False                   # whether to use a remote device
    if not remote:
        remote_id = None

    use_processing = False             # enable to send position data through OSC
    ip = "127.0.0.1"                   # IP for the OSC UDP
    network_port = 8888                # network port for the OSC UDP
    osc_udp_client = None
    if use_processing:
        osc_udp_client = SimpleUDPClient(ip, network_port)
    # necessary data for calibration, change the IDs and coordinates yourself
    #anchors = [DeviceCoordinates(0xA000, 1, Coordinates(0, 0, height_anchor[0])),
    #           DeviceCoordinates(0xA001, 1, Coordinates(8571, 0, height_anchor[1])),
    #           DeviceCoordinates(0xA002, 1, Coordinates(1363, 7847, height_anchor[2])),
    #           DeviceCoordinates(0xA003, 1, Coordinates(9280, 4100, height_anchor[3]))]

    algorithm = POZYX_POS_ALG_TRACKING  # positioning algorithm to use
    dimension = POZYX_3D               # positioning dimension
    height = 1000                      # height of device, required in 2.5D positioning

    pozyx = PozyxSerial(serial_port)
    r = ReadyToLocalize(pozyx, osc_udp_client, anchors, algorithm, dimension, height, remote_id)
    r.setup()
    rospy.init_node('pozyx_pose_node')
    pub = rospy.Publisher('pozyx_pose', PoseStamped, queue_size=40)
    pub_pressure = rospy.Publisher('pozyx_pressure', FluidPressure, queue_size=100)
    pub_imu = rospy.Publisher('pozyx_imu', Imu, queue_size=100)
    pub_magnetic = rospy.Publisher('pozyx_magnetic', MagneticField, queue_size=100)
    pub_range = rospy.Publisher('pozyx_range', Imu, queue_size=1)
    while not rospy.is_shutdown():
        try:
            r.loop()
        except rospy.ROSInterruptException:
            pass