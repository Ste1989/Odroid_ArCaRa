# This Python file uses the following encoding: utf-8
"""autogenerated by genpy from mavros_msgs/StreamRateRequest.msg. Do not edit."""
import sys
python3 = True if sys.hexversion > 0x03000000 else False
import genpy
import struct


class StreamRateRequest(genpy.Message):
  _md5sum = "d12f7661724c8ba25f67ba597bb7d039"
  _type = "mavros_msgs/StreamRateRequest"
  _has_header = False #flag to mark the presence of a Header object
  _full_text = """


uint8 STREAM_ALL = 0
uint8 STREAM_RAW_SENSORS = 1
uint8 STREAM_EXTENDED_STATUS = 2
uint8 STREAM_RC_CHANNELS = 3
uint8 STREAM_RAW_CONTROLLER = 4
uint8 STREAM_POSITION = 6
uint8 STREAM_EXTRA1 = 10
uint8 STREAM_EXTRA2 = 11
uint8 STREAM_EXTRA3 = 12

uint8 stream_id
uint16 message_rate
bool on_off
"""
  # Pseudo-constants
  STREAM_ALL = 0
  STREAM_RAW_SENSORS = 1
  STREAM_EXTENDED_STATUS = 2
  STREAM_RC_CHANNELS = 3
  STREAM_RAW_CONTROLLER = 4
  STREAM_POSITION = 6
  STREAM_EXTRA1 = 10
  STREAM_EXTRA2 = 11
  STREAM_EXTRA3 = 12

  __slots__ = ['stream_id','message_rate','on_off']
  _slot_types = ['uint8','uint16','bool']

  def __init__(self, *args, **kwds):
    """
    Constructor. Any message fields that are implicitly/explicitly
    set to None will be assigned a default value. The recommend
    use is keyword arguments as this is more robust to future message
    changes.  You cannot mix in-order arguments and keyword arguments.

    The available fields are:
       stream_id,message_rate,on_off

    :param args: complete set of field values, in .msg order
    :param kwds: use keyword arguments corresponding to message field names
    to set specific fields.
    """
    if args or kwds:
      super(StreamRateRequest, self).__init__(*args, **kwds)
      #message fields cannot be None, assign default values for those that are
      if self.stream_id is None:
        self.stream_id = 0
      if self.message_rate is None:
        self.message_rate = 0
      if self.on_off is None:
        self.on_off = False
    else:
      self.stream_id = 0
      self.message_rate = 0
      self.on_off = False

  def _get_types(self):
    """
    internal API method
    """
    return self._slot_types

  def serialize(self, buff):
    """
    serialize message into buffer
    :param buff: buffer, ``StringIO``
    """
    try:
      _x = self
      buff.write(_struct_BHB.pack(_x.stream_id, _x.message_rate, _x.on_off))
    except struct.error as se: self._check_types(struct.error("%s: '%s' when writing '%s'" % (type(se), str(se), str(locals().get('_x', self)))))
    except TypeError as te: self._check_types(ValueError("%s: '%s' when writing '%s'" % (type(te), str(te), str(locals().get('_x', self)))))

  def deserialize(self, str):
    """
    unpack serialized message in str into this message instance
    :param str: byte array of serialized message, ``str``
    """
    try:
      end = 0
      _x = self
      start = end
      end += 4
      (_x.stream_id, _x.message_rate, _x.on_off,) = _struct_BHB.unpack(str[start:end])
      self.on_off = bool(self.on_off)
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e) #most likely buffer underfill


  def serialize_numpy(self, buff, numpy):
    """
    serialize message with numpy array types into buffer
    :param buff: buffer, ``StringIO``
    :param numpy: numpy python module
    """
    try:
      _x = self
      buff.write(_struct_BHB.pack(_x.stream_id, _x.message_rate, _x.on_off))
    except struct.error as se: self._check_types(struct.error("%s: '%s' when writing '%s'" % (type(se), str(se), str(locals().get('_x', self)))))
    except TypeError as te: self._check_types(ValueError("%s: '%s' when writing '%s'" % (type(te), str(te), str(locals().get('_x', self)))))

  def deserialize_numpy(self, str, numpy):
    """
    unpack serialized message in str into this message instance using numpy for array types
    :param str: byte array of serialized message, ``str``
    :param numpy: numpy python module
    """
    try:
      end = 0
      _x = self
      start = end
      end += 4
      (_x.stream_id, _x.message_rate, _x.on_off,) = _struct_BHB.unpack(str[start:end])
      self.on_off = bool(self.on_off)
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e) #most likely buffer underfill

_struct_I = genpy.struct_I
_struct_BHB = struct.Struct("<BHB")
# This Python file uses the following encoding: utf-8
"""autogenerated by genpy from mavros_msgs/StreamRateResponse.msg. Do not edit."""
import sys
python3 = True if sys.hexversion > 0x03000000 else False
import genpy
import struct


class StreamRateResponse(genpy.Message):
  _md5sum = "d41d8cd98f00b204e9800998ecf8427e"
  _type = "mavros_msgs/StreamRateResponse"
  _has_header = False #flag to mark the presence of a Header object
  _full_text = """
"""
  __slots__ = []
  _slot_types = []

  def __init__(self, *args, **kwds):
    """
    Constructor. Any message fields that are implicitly/explicitly
    set to None will be assigned a default value. The recommend
    use is keyword arguments as this is more robust to future message
    changes.  You cannot mix in-order arguments and keyword arguments.

    The available fields are:
       

    :param args: complete set of field values, in .msg order
    :param kwds: use keyword arguments corresponding to message field names
    to set specific fields.
    """
    if args or kwds:
      super(StreamRateResponse, self).__init__(*args, **kwds)

  def _get_types(self):
    """
    internal API method
    """
    return self._slot_types

  def serialize(self, buff):
    """
    serialize message into buffer
    :param buff: buffer, ``StringIO``
    """
    try:
      pass
    except struct.error as se: self._check_types(struct.error("%s: '%s' when writing '%s'" % (type(se), str(se), str(locals().get('_x', self)))))
    except TypeError as te: self._check_types(ValueError("%s: '%s' when writing '%s'" % (type(te), str(te), str(locals().get('_x', self)))))

  def deserialize(self, str):
    """
    unpack serialized message in str into this message instance
    :param str: byte array of serialized message, ``str``
    """
    try:
      end = 0
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e) #most likely buffer underfill


  def serialize_numpy(self, buff, numpy):
    """
    serialize message with numpy array types into buffer
    :param buff: buffer, ``StringIO``
    :param numpy: numpy python module
    """
    try:
      pass
    except struct.error as se: self._check_types(struct.error("%s: '%s' when writing '%s'" % (type(se), str(se), str(locals().get('_x', self)))))
    except TypeError as te: self._check_types(ValueError("%s: '%s' when writing '%s'" % (type(te), str(te), str(locals().get('_x', self)))))

  def deserialize_numpy(self, str, numpy):
    """
    unpack serialized message in str into this message instance using numpy for array types
    :param str: byte array of serialized message, ``str``
    :param numpy: numpy python module
    """
    try:
      end = 0
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e) #most likely buffer underfill

_struct_I = genpy.struct_I
class StreamRate(object):
  _type          = 'mavros_msgs/StreamRate'
  _md5sum = 'd12f7661724c8ba25f67ba597bb7d039'
  _request_class  = StreamRateRequest
  _response_class = StreamRateResponse