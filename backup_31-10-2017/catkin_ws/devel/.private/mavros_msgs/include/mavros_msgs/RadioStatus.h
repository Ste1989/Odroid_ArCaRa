// Generated by gencpp from file mavros_msgs/RadioStatus.msg
// DO NOT EDIT!


#ifndef MAVROS_MSGS_MESSAGE_RADIOSTATUS_H
#define MAVROS_MSGS_MESSAGE_RADIOSTATUS_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <std_msgs/Header.h>

namespace mavros_msgs
{
template <class ContainerAllocator>
struct RadioStatus_
{
  typedef RadioStatus_<ContainerAllocator> Type;

  RadioStatus_()
    : header()
    , rssi(0)
    , remrssi(0)
    , txbuf(0)
    , noise(0)
    , remnoise(0)
    , rxerrors(0)
    , fixed(0)
    , rssi_dbm(0.0)
    , remrssi_dbm(0.0)  {
    }
  RadioStatus_(const ContainerAllocator& _alloc)
    : header(_alloc)
    , rssi(0)
    , remrssi(0)
    , txbuf(0)
    , noise(0)
    , remnoise(0)
    , rxerrors(0)
    , fixed(0)
    , rssi_dbm(0.0)
    , remrssi_dbm(0.0)  {
  (void)_alloc;
    }



   typedef  ::std_msgs::Header_<ContainerAllocator>  _header_type;
  _header_type header;

   typedef uint8_t _rssi_type;
  _rssi_type rssi;

   typedef uint8_t _remrssi_type;
  _remrssi_type remrssi;

   typedef uint8_t _txbuf_type;
  _txbuf_type txbuf;

   typedef uint8_t _noise_type;
  _noise_type noise;

   typedef uint8_t _remnoise_type;
  _remnoise_type remnoise;

   typedef uint16_t _rxerrors_type;
  _rxerrors_type rxerrors;

   typedef uint16_t _fixed_type;
  _fixed_type fixed;

   typedef float _rssi_dbm_type;
  _rssi_dbm_type rssi_dbm;

   typedef float _remrssi_dbm_type;
  _remrssi_dbm_type remrssi_dbm;




  typedef boost::shared_ptr< ::mavros_msgs::RadioStatus_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::mavros_msgs::RadioStatus_<ContainerAllocator> const> ConstPtr;

}; // struct RadioStatus_

typedef ::mavros_msgs::RadioStatus_<std::allocator<void> > RadioStatus;

typedef boost::shared_ptr< ::mavros_msgs::RadioStatus > RadioStatusPtr;
typedef boost::shared_ptr< ::mavros_msgs::RadioStatus const> RadioStatusConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::mavros_msgs::RadioStatus_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::mavros_msgs::RadioStatus_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace mavros_msgs

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': False, 'IsMessage': True, 'HasHeader': True}
// {'std_msgs': ['/opt/ros/indigo/share/std_msgs/cmake/../msg'], 'geometry_msgs': ['/opt/ros/indigo/share/geometry_msgs/cmake/../msg'], 'mavros_msgs': ['/home/robot/catkin_ws/src/mavros/mavros_msgs/msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::mavros_msgs::RadioStatus_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::mavros_msgs::RadioStatus_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::mavros_msgs::RadioStatus_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::mavros_msgs::RadioStatus_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::mavros_msgs::RadioStatus_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::mavros_msgs::RadioStatus_<ContainerAllocator> const>
  : TrueType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::mavros_msgs::RadioStatus_<ContainerAllocator> >
{
  static const char* value()
  {
    return "04e4a879bb2687140da50a1a821e2190";
  }

  static const char* value(const ::mavros_msgs::RadioStatus_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x04e4a879bb268714ULL;
  static const uint64_t static_value2 = 0x0da50a1a821e2190ULL;
};

template<class ContainerAllocator>
struct DataType< ::mavros_msgs::RadioStatus_<ContainerAllocator> >
{
  static const char* value()
  {
    return "mavros_msgs/RadioStatus";
  }

  static const char* value(const ::mavros_msgs::RadioStatus_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::mavros_msgs::RadioStatus_<ContainerAllocator> >
{
  static const char* value()
  {
    return "# RADIO_STATUS message\n\
\n\
std_msgs/Header header\n\
\n\
# message data\n\
uint8 rssi\n\
uint8 remrssi\n\
uint8 txbuf\n\
uint8 noise\n\
uint8 remnoise\n\
uint16 rxerrors\n\
uint16 fixed\n\
\n\
# calculated\n\
float32 rssi_dbm\n\
float32 remrssi_dbm\n\
\n\
================================================================================\n\
MSG: std_msgs/Header\n\
# Standard metadata for higher-level stamped data types.\n\
# This is generally used to communicate timestamped data \n\
# in a particular coordinate frame.\n\
# \n\
# sequence ID: consecutively increasing ID \n\
uint32 seq\n\
#Two-integer timestamp that is expressed as:\n\
# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')\n\
# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')\n\
# time-handling sugar is provided by the client library\n\
time stamp\n\
#Frame this data is associated with\n\
# 0: no frame\n\
# 1: global frame\n\
string frame_id\n\
";
  }

  static const char* value(const ::mavros_msgs::RadioStatus_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::mavros_msgs::RadioStatus_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.header);
      stream.next(m.rssi);
      stream.next(m.remrssi);
      stream.next(m.txbuf);
      stream.next(m.noise);
      stream.next(m.remnoise);
      stream.next(m.rxerrors);
      stream.next(m.fixed);
      stream.next(m.rssi_dbm);
      stream.next(m.remrssi_dbm);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct RadioStatus_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::mavros_msgs::RadioStatus_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::mavros_msgs::RadioStatus_<ContainerAllocator>& v)
  {
    s << indent << "header: ";
    s << std::endl;
    Printer< ::std_msgs::Header_<ContainerAllocator> >::stream(s, indent + "  ", v.header);
    s << indent << "rssi: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.rssi);
    s << indent << "remrssi: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.remrssi);
    s << indent << "txbuf: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.txbuf);
    s << indent << "noise: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.noise);
    s << indent << "remnoise: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.remnoise);
    s << indent << "rxerrors: ";
    Printer<uint16_t>::stream(s, indent + "  ", v.rxerrors);
    s << indent << "fixed: ";
    Printer<uint16_t>::stream(s, indent + "  ", v.fixed);
    s << indent << "rssi_dbm: ";
    Printer<float>::stream(s, indent + "  ", v.rssi_dbm);
    s << indent << "remrssi_dbm: ";
    Printer<float>::stream(s, indent + "  ", v.remrssi_dbm);
  }
};

} // namespace message_operations
} // namespace ros

#endif // MAVROS_MSGS_MESSAGE_RADIOSTATUS_H
