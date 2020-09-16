#ifndef _ROS_SERVICE_LedDevice_h
#define _ROS_SERVICE_LedDevice_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace ros_farmer_pc
{

static const char LEDDEVICE[] = "ros_farmer_pc/LedDevice";

  class LedDeviceRequest : public ros::Msg
  {
    public:
      typedef const char* _command_type;
      _command_type command;
      typedef uint16_t _red_type;
      _red_type red;
      typedef uint16_t _white_type;
      _white_type white;

    LedDeviceRequest():
      command(""),
      red(0),
      white(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_command = strlen(this->command);
      varToArr(outbuffer + offset, length_command);
      offset += 4;
      memcpy(outbuffer + offset, this->command, length_command);
      offset += length_command;
      *(outbuffer + offset + 0) = (this->red >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->red >> (8 * 1)) & 0xFF;
      offset += sizeof(this->red);
      *(outbuffer + offset + 0) = (this->white >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->white >> (8 * 1)) & 0xFF;
      offset += sizeof(this->white);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_command;
      arrToVar(length_command, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_command; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_command-1]=0;
      this->command = (char *)(inbuffer + offset-1);
      offset += length_command;
      this->red =  ((uint16_t) (*(inbuffer + offset)));
      this->red |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->red);
      this->white =  ((uint16_t) (*(inbuffer + offset)));
      this->white |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->white);
     return offset;
    }

    const char * getType(){ return LEDDEVICE; };
    const char * getMD5(){ return "07a403535088f5d681d0eac71fbba3a0"; };

  };

  class LedDeviceResponse : public ros::Msg
  {
    public:
      typedef const char* _response_type;
      _response_type response;

    LedDeviceResponse():
      response("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_response = strlen(this->response);
      varToArr(outbuffer + offset, length_response);
      offset += 4;
      memcpy(outbuffer + offset, this->response, length_response);
      offset += length_response;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_response;
      arrToVar(length_response, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_response; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_response-1]=0;
      this->response = (char *)(inbuffer + offset-1);
      offset += length_response;
     return offset;
    }

    const char * getType(){ return LEDDEVICE; };
    const char * getMD5(){ return "6de314e2dc76fbff2b6244a6ad70b68d"; };

  };

  class LedDevice {
    public:
    typedef LedDeviceRequest Request;
    typedef LedDeviceResponse Response;
  };

}
#endif
