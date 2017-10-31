// Generated by gencpp from file mavros_msgs/CommandTriggerControlRequest.msg
// DO NOT EDIT!


#ifndef MAVROS_MSGS_MESSAGE_COMMANDTRIGGERCONTROLREQUEST_H
#define MAVROS_MSGS_MESSAGE_COMMANDTRIGGERCONTROLREQUEST_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace mavros_msgs
{
template <class ContainerAllocator>
struct CommandTriggerControlRequest_
{
  typedef CommandTriggerControlRequest_<ContainerAllocator> Type;

  CommandTriggerControlRequest_()
    : trigger_enable(false)
    , integration_time(0.0)  {
    }
  CommandTriggerControlRequest_(const ContainerAllocator& _alloc)
    : trigger_enable(false)
    , integration_time(0.0)  {
  (void)_alloc;
    }



   typedef uint8_t _trigger_enable_type;
  _trigger_enable_type trigger_enable;

   typedef float _integration_time_type;
  _integration_time_type integration_time;




  typedef boost::shared_ptr< ::mavros_msgs::CommandTriggerControlRequest_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::mavros_msgs::CommandTriggerControlRequest_<ContainerAllocator> const> ConstPtr;

}; // struct CommandTriggerControlRequest_

typedef ::mavros_msgs::CommandTriggerControlRequest_<std::allocator<void> > CommandTriggerControlRequest;

typedef boost::shared_ptr< ::mavros_msgs::CommandTriggerControlRequest > CommandTriggerControlRequestPtr;
typedef boost::shared_ptr< ::mavros_msgs::CommandTriggerControlRequest const> CommandTriggerControlRequestConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::mavros_msgs::CommandTriggerControlRequest_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::mavros_msgs::CommandTriggerControlRequest_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace mavros_msgs

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': True, 'IsMessage': True, 'HasHeader': False}
// {'std_msgs': ['/opt/ros/indigo/share/std_msgs/cmake/../msg'], 'geometry_msgs': ['/opt/ros/indigo/share/geometry_msgs/cmake/../msg'], 'mavros_msgs': ['/home/robot/catkin_ws/src/mavros/mavros_msgs/msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::mavros_msgs::CommandTriggerControlRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::mavros_msgs::CommandTriggerControlRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::mavros_msgs::CommandTriggerControlRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::mavros_msgs::CommandTriggerControlRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::mavros_msgs::CommandTriggerControlRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::mavros_msgs::CommandTriggerControlRequest_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::mavros_msgs::CommandTriggerControlRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "8b8f5196da8cf0a44cb3975e4f2ea948";
  }

  static const char* value(const ::mavros_msgs::CommandTriggerControlRequest_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x8b8f5196da8cf0a4ULL;
  static const uint64_t static_value2 = 0x4cb3975e4f2ea948ULL;
};

template<class ContainerAllocator>
struct DataType< ::mavros_msgs::CommandTriggerControlRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "mavros_msgs/CommandTriggerControlRequest";
  }

  static const char* value(const ::mavros_msgs::CommandTriggerControlRequest_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::mavros_msgs::CommandTriggerControlRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "\n\
\n\
bool    trigger_enable\n\
float32 integration_time\n\
";
  }

  static const char* value(const ::mavros_msgs::CommandTriggerControlRequest_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::mavros_msgs::CommandTriggerControlRequest_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.trigger_enable);
      stream.next(m.integration_time);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct CommandTriggerControlRequest_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::mavros_msgs::CommandTriggerControlRequest_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::mavros_msgs::CommandTriggerControlRequest_<ContainerAllocator>& v)
  {
    s << indent << "trigger_enable: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.trigger_enable);
    s << indent << "integration_time: ";
    Printer<float>::stream(s, indent + "  ", v.integration_time);
  }
};

} // namespace message_operations
} // namespace ros

#endif // MAVROS_MSGS_MESSAGE_COMMANDTRIGGERCONTROLREQUEST_H
