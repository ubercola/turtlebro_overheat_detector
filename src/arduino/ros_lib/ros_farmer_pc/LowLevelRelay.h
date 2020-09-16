#ifndef _ROS_SERVICE_LowLevelRelay_h
#define _ROS_SERVICE_LowLevelRelay_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace ros_farmer_pc
{

static const char LOWLEVELRELAY[] = "ros_farmer_pc/LowLevelRelay";

  class LowLevelRelayRequest : public ros::Msg
  {
    public:
      typedef bool _ch1_type;
      _ch1_type ch1;
      typedef bool _ch2_type;
      _ch2_type ch2;
      typedef bool _ch3_type;
      _ch3_type ch3;
      typedef bool _ch4_type;
      _ch4_type ch4;
      typedef bool _ch5_type;
      _ch5_type ch5;
      typedef bool _ch6_type;
      _ch6_type ch6;
      typedef bool _ch7_type;
      _ch7_type ch7;
      typedef bool _ch8_type;
      _ch8_type ch8;

    LowLevelRelayRequest():
      ch1(0),
      ch2(0),
      ch3(0),
      ch4(0),
      ch5(0),
      ch6(0),
      ch7(0),
      ch8(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_ch1;
      u_ch1.real = this->ch1;
      *(outbuffer + offset + 0) = (u_ch1.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->ch1);
      union {
        bool real;
        uint8_t base;
      } u_ch2;
      u_ch2.real = this->ch2;
      *(outbuffer + offset + 0) = (u_ch2.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->ch2);
      union {
        bool real;
        uint8_t base;
      } u_ch3;
      u_ch3.real = this->ch3;
      *(outbuffer + offset + 0) = (u_ch3.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->ch3);
      union {
        bool real;
        uint8_t base;
      } u_ch4;
      u_ch4.real = this->ch4;
      *(outbuffer + offset + 0) = (u_ch4.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->ch4);
      union {
        bool real;
        uint8_t base;
      } u_ch5;
      u_ch5.real = this->ch5;
      *(outbuffer + offset + 0) = (u_ch5.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->ch5);
      union {
        bool real;
        uint8_t base;
      } u_ch6;
      u_ch6.real = this->ch6;
      *(outbuffer + offset + 0) = (u_ch6.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->ch6);
      union {
        bool real;
        uint8_t base;
      } u_ch7;
      u_ch7.real = this->ch7;
      *(outbuffer + offset + 0) = (u_ch7.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->ch7);
      union {
        bool real;
        uint8_t base;
      } u_ch8;
      u_ch8.real = this->ch8;
      *(outbuffer + offset + 0) = (u_ch8.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->ch8);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_ch1;
      u_ch1.base = 0;
      u_ch1.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->ch1 = u_ch1.real;
      offset += sizeof(this->ch1);
      union {
        bool real;
        uint8_t base;
      } u_ch2;
      u_ch2.base = 0;
      u_ch2.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->ch2 = u_ch2.real;
      offset += sizeof(this->ch2);
      union {
        bool real;
        uint8_t base;
      } u_ch3;
      u_ch3.base = 0;
      u_ch3.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->ch3 = u_ch3.real;
      offset += sizeof(this->ch3);
      union {
        bool real;
        uint8_t base;
      } u_ch4;
      u_ch4.base = 0;
      u_ch4.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->ch4 = u_ch4.real;
      offset += sizeof(this->ch4);
      union {
        bool real;
        uint8_t base;
      } u_ch5;
      u_ch5.base = 0;
      u_ch5.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->ch5 = u_ch5.real;
      offset += sizeof(this->ch5);
      union {
        bool real;
        uint8_t base;
      } u_ch6;
      u_ch6.base = 0;
      u_ch6.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->ch6 = u_ch6.real;
      offset += sizeof(this->ch6);
      union {
        bool real;
        uint8_t base;
      } u_ch7;
      u_ch7.base = 0;
      u_ch7.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->ch7 = u_ch7.real;
      offset += sizeof(this->ch7);
      union {
        bool real;
        uint8_t base;
      } u_ch8;
      u_ch8.base = 0;
      u_ch8.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->ch8 = u_ch8.real;
      offset += sizeof(this->ch8);
     return offset;
    }

    const char * getType(){ return LOWLEVELRELAY; };
    const char * getMD5(){ return "685605ab6b741f094202a13bd6d36aff"; };

  };

  class LowLevelRelayResponse : public ros::Msg
  {
    public:
      typedef uint16_t _response_type;
      _response_type response;

    LowLevelRelayResponse():
      response(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->response >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->response >> (8 * 1)) & 0xFF;
      offset += sizeof(this->response);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->response =  ((uint16_t) (*(inbuffer + offset)));
      this->response |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->response);
     return offset;
    }

    const char * getType(){ return LOWLEVELRELAY; };
    const char * getMD5(){ return "10f562e597313f2e990194ad2a84d493"; };

  };

  class LowLevelRelay {
    public:
    typedef LowLevelRelayRequest Request;
    typedef LowLevelRelayResponse Response;
  };

}
#endif
