// Generated by gencpp from file mavros_msgs/FileTruncateRequest.msg
// DO NOT EDIT!


#ifndef MAVROS_MSGS_MESSAGE_FILETRUNCATEREQUEST_H
#define MAVROS_MSGS_MESSAGE_FILETRUNCATEREQUEST_H


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
struct FileTruncateRequest_
{
  typedef FileTruncateRequest_<ContainerAllocator> Type;

  FileTruncateRequest_()
    : file_path()
    , length(0)  {
    }
  FileTruncateRequest_(const ContainerAllocator& _alloc)
    : file_path(_alloc)
    , length(0)  {
  (void)_alloc;
    }



   typedef std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  _file_path_type;
  _file_path_type file_path;

   typedef uint64_t _length_type;
  _length_type length;




  typedef boost::shared_ptr< ::mavros_msgs::FileTruncateRequest_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::mavros_msgs::FileTruncateRequest_<ContainerAllocator> const> ConstPtr;

}; // struct FileTruncateRequest_

typedef ::mavros_msgs::FileTruncateRequest_<std::allocator<void> > FileTruncateRequest;

typedef boost::shared_ptr< ::mavros_msgs::FileTruncateRequest > FileTruncateRequestPtr;
typedef boost::shared_ptr< ::mavros_msgs::FileTruncateRequest const> FileTruncateRequestConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::mavros_msgs::FileTruncateRequest_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::mavros_msgs::FileTruncateRequest_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace mavros_msgs

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': False, 'IsMessage': True, 'HasHeader': False}
// {'std_msgs': ['/opt/ros/indigo/share/std_msgs/cmake/../msg'], 'geometry_msgs': ['/opt/ros/indigo/share/geometry_msgs/cmake/../msg'], 'mavros_msgs': ['/home/robot/catkin_ws/src/mavros/mavros_msgs/msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::mavros_msgs::FileTruncateRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::mavros_msgs::FileTruncateRequest_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::mavros_msgs::FileTruncateRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::mavros_msgs::FileTruncateRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::mavros_msgs::FileTruncateRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::mavros_msgs::FileTruncateRequest_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::mavros_msgs::FileTruncateRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "8153dbfb1601dd12c2e69aba3171d186";
  }

  static const char* value(const ::mavros_msgs::FileTruncateRequest_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x8153dbfb1601dd12ULL;
  static const uint64_t static_value2 = 0xc2e69aba3171d186ULL;
};

template<class ContainerAllocator>
struct DataType< ::mavros_msgs::FileTruncateRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "mavros_msgs/FileTruncateRequest";
  }

  static const char* value(const ::mavros_msgs::FileTruncateRequest_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::mavros_msgs::FileTruncateRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "\n\
\n\
\n\
\n\
\n\
string file_path\n\
uint64 length\n\
";
  }

  static const char* value(const ::mavros_msgs::FileTruncateRequest_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::mavros_msgs::FileTruncateRequest_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.file_path);
      stream.next(m.length);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct FileTruncateRequest_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::mavros_msgs::FileTruncateRequest_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::mavros_msgs::FileTruncateRequest_<ContainerAllocator>& v)
  {
    s << indent << "file_path: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::stream(s, indent + "  ", v.file_path);
    s << indent << "length: ";
    Printer<uint64_t>::stream(s, indent + "  ", v.length);
  }
};

} // namespace message_operations
} // namespace ros

#endif // MAVROS_MSGS_MESSAGE_FILETRUNCATEREQUEST_H
