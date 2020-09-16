#ifndef _ROS_SERVICE_ControlSystem_h
#define _ROS_SERVICE_ControlSystem_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace ros_farmer_pc
{

static const char CONTROLSYSTEM[] = "ros_farmer_pc/ControlSystem";

  class ControlSystemRequest : public ros::Msg
  {
    public:
      typedef const char* _command_type;
      _command_type command;
      typedef const char* _argument_type;
      _argument_type argument;

    ControlSystemRequest():
      command(""),
      argument("")
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
      uint32_t length_argument = strlen(this->argument);
      varToArr(outbuffer + offset, length_argument);
      offset += 4;
      memcpy(outbuffer + offset, this->argument, length_argument);
      offset += length_argument;
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
      uint32_t length_argument;
      arrToVar(length_argument, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_argument; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_argument-1]=0;
      this->argument = (char *)(inbuffer + offset-1);
      offset += length_argument;
     return offset;
    }

    const char * getType(){ return CONTROLSYSTEM; };
    const char * getMD5(){ return "89ea12cd1f3864199e2c936705472021"; };

  };

  class ControlSystemResponse : public ros::Msg
  {
    public:
      typedef const char* _response_type;
      _response_type response;

    ControlSystemResponse():
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

    const char * getType(){ return CONTROLSYSTEM; };
    const char * getMD5(){ return "6de314e2dc76fbff2b6244a6ad70b68d"; };

  };

  class ControlSystem {
    public:
    typedef ControlSystemRequest Request;
    typedef ControlSystemResponse Response;
  };

}
#endif
