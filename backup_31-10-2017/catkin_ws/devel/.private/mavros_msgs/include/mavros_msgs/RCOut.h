// Generated by gencpp from file mavros_msgs/RCOut.msg
// DO NOT EDIT!


#ifndef MAVROS_MSGS_MESSAGE_RCOUT_H
#define MAVROS_MSGS_MESSAGE_RCOUT_H


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
struct RCOut_
{
  typedef RCOut_<ContainerAllocator> Type;

  RCOut_()
    : header()
    , channels()  {
    }
  RCOut_(const ContainerAllocator& _alloc)
    : header(_alloc)
    , channels(_alloc)  {
  (void)_alloc;
    }



   typedef  ::std_msgs::Header_<ContainerAllocator>  _header_type;
  _header_type header;

   typedef std::vector<uint16_t, typename ContainerAllocator::template rebind<uint16_t>::other >  _channels_type;
  _channels_type channels;




  typedef boost::shared_ptr< ::mavros_msgs::RCOut_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::mavros_msgs::RCOut_<ContainerAllocator> const> ConstPtr;

}; // struct RCOut_

typedef ::mavros_msgs::RCOut_<std::allocator<void> > RCOut;

typedef boost::shared_ptr< ::mavros_msgs::RCOut > RCOutPtr;
typedef boost::shared_ptr< ::mavros_msgs::RCOut const> RCOutConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::mavros_msgs::RCOut_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::mavros_msgs::RCOut_<ContainerAllocator> >::stream(s, "", v);
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
struct IsFixedSize< ::mavros_msgs::RCOut_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::mavros_msgs::RCOut_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::mavros_msgs::RCOut_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::mavros_msgs::RCOut_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::mavros_msgs::RCOut_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::mavros_msgs::RCOut_<ContainerAllocator> const>
  : TrueType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::mavros_msgs::RCOut_<ContainerAllocator> >
{
  static const char* value()
  {
    return "52cacf104bab5ae3b103cfe176590713";
  }

  static const char* value(const ::mavros_msgs::RCOut_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x52cacf104bab5ae3ULL;
  static const uint64_t static_value2 = 0xb103cfe176590713ULL;
};

template<class ContainerAllocator>
struct DataType< ::mavros_msgs::RCOut_<ContainerAllocator> >
{
  static const char* value()
  {
    return "mavros_msgs/RCOut";
  }

  static const char* value(const ::mavros_msgs::RCOut_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::mavros_msgs::RCOut_<ContainerAllocator> >
{
  static const char* value()
  {
    return "# RAW Servo out state\n\
\n\
std_msgs/Header header\n\
uint16[] channels\n\
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

  static const char* value(const ::mavros_msgs::RCOut_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::mavros_msgs::RCOut_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.header);
      stream.next(m.channels);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct RCOut_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::mavros_msgs::RCOut_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::mavros_msgs::RCOut_<ContainerAllocator>& v)
  {
    s << indent << "header: ";
    s << std::endl;
    Printer< ::std_msgs::Header_<ContainerAllocator> >::stream(s, indent + "  ", v.header);
    s << indent << "channels[]" << std::endl;
    for (size_t i = 0; i < v.channels.size(); ++i)
    {
      s << indent << "  channels[" << i << "]: ";
      Printer<uint16_t>::stream(s, indent + "  ", v.channels[i]);
    }
  }
};

} // namespace message_operations
} // namespace ros

#endif // MAVROS_MSGS_MESSAGE_RCOUT_H
