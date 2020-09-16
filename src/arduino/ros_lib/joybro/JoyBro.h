#ifndef _ROS_joybro_JoyBro_h
#define _ROS_joybro_JoyBro_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace joybro
{

  class JoyBro : public ros::Msg
  {
    public:
      typedef int16_t _left_x_type;
      _left_x_type left_x;
      typedef int16_t _left_y_type;
      _left_y_type left_y;
      typedef bool _left_btn_type;
      _left_btn_type left_btn;
      typedef int16_t _right_x_type;
      _right_x_type right_x;
      typedef int16_t _right_y_type;
      _right_y_type right_y;
      typedef bool _right_btn_type;
      _right_btn_type right_btn;
      typedef bool _btn1_type;
      _btn1_type btn1;
      typedef bool _btn2_type;
      _btn2_type btn2;
      typedef bool _btn3_type;
      _btn3_type btn3;
      typedef bool _btn4_type;
      _btn4_type btn4;
      typedef bool _sw1_type;
      _sw1_type sw1;
      typedef bool _sw2_type;
      _sw2_type sw2;
      typedef bool _sw3_type;
      _sw3_type sw3;
      typedef uint16_t _slider1_type;
      _slider1_type slider1;
      typedef uint16_t _slider2_type;
      _slider2_type slider2;

    JoyBro():
      left_x(0),
      left_y(0),
      left_btn(0),
      right_x(0),
      right_y(0),
      right_btn(0),
      btn1(0),
      btn2(0),
      btn3(0),
      btn4(0),
      sw1(0),
      sw2(0),
      sw3(0),
      slider1(0),
      slider2(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int16_t real;
        uint16_t base;
      } u_left_x;
      u_left_x.real = this->left_x;
      *(outbuffer + offset + 0) = (u_left_x.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_left_x.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->left_x);
      union {
        int16_t real;
        uint16_t base;
      } u_left_y;
      u_left_y.real = this->left_y;
      *(outbuffer + offset + 0) = (u_left_y.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_left_y.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->left_y);
      union {
        bool real;
        uint8_t base;
      } u_left_btn;
      u_left_btn.real = this->left_btn;
      *(outbuffer + offset + 0) = (u_left_btn.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->left_btn);
      union {
        int16_t real;
        uint16_t base;
      } u_right_x;
      u_right_x.real = this->right_x;
      *(outbuffer + offset + 0) = (u_right_x.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_right_x.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->right_x);
      union {
        int16_t real;
        uint16_t base;
      } u_right_y;
      u_right_y.real = this->right_y;
      *(outbuffer + offset + 0) = (u_right_y.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_right_y.base >> (8 * 1)) & 0xFF;
      offset += sizeof(this->right_y);
      union {
        bool real;
        uint8_t base;
      } u_right_btn;
      u_right_btn.real = this->right_btn;
      *(outbuffer + offset + 0) = (u_right_btn.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->right_btn);
      union {
        bool real;
        uint8_t base;
      } u_btn1;
      u_btn1.real = this->btn1;
      *(outbuffer + offset + 0) = (u_btn1.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->btn1);
      union {
        bool real;
        uint8_t base;
      } u_btn2;
      u_btn2.real = this->btn2;
      *(outbuffer + offset + 0) = (u_btn2.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->btn2);
      union {
        bool real;
        uint8_t base;
      } u_btn3;
      u_btn3.real = this->btn3;
      *(outbuffer + offset + 0) = (u_btn3.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->btn3);
      union {
        bool real;
        uint8_t base;
      } u_btn4;
      u_btn4.real = this->btn4;
      *(outbuffer + offset + 0) = (u_btn4.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->btn4);
      union {
        bool real;
        uint8_t base;
      } u_sw1;
      u_sw1.real = this->sw1;
      *(outbuffer + offset + 0) = (u_sw1.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->sw1);
      union {
        bool real;
        uint8_t base;
      } u_sw2;
      u_sw2.real = this->sw2;
      *(outbuffer + offset + 0) = (u_sw2.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->sw2);
      union {
        bool real;
        uint8_t base;
      } u_sw3;
      u_sw3.real = this->sw3;
      *(outbuffer + offset + 0) = (u_sw3.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->sw3);
      *(outbuffer + offset + 0) = (this->slider1 >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->slider1 >> (8 * 1)) & 0xFF;
      offset += sizeof(this->slider1);
      *(outbuffer + offset + 0) = (this->slider2 >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->slider2 >> (8 * 1)) & 0xFF;
      offset += sizeof(this->slider2);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int16_t real;
        uint16_t base;
      } u_left_x;
      u_left_x.base = 0;
      u_left_x.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_left_x.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->left_x = u_left_x.real;
      offset += sizeof(this->left_x);
      union {
        int16_t real;
        uint16_t base;
      } u_left_y;
      u_left_y.base = 0;
      u_left_y.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_left_y.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->left_y = u_left_y.real;
      offset += sizeof(this->left_y);
      union {
        bool real;
        uint8_t base;
      } u_left_btn;
      u_left_btn.base = 0;
      u_left_btn.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->left_btn = u_left_btn.real;
      offset += sizeof(this->left_btn);
      union {
        int16_t real;
        uint16_t base;
      } u_right_x;
      u_right_x.base = 0;
      u_right_x.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_right_x.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->right_x = u_right_x.real;
      offset += sizeof(this->right_x);
      union {
        int16_t real;
        uint16_t base;
      } u_right_y;
      u_right_y.base = 0;
      u_right_y.base |= ((uint16_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_right_y.base |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->right_y = u_right_y.real;
      offset += sizeof(this->right_y);
      union {
        bool real;
        uint8_t base;
      } u_right_btn;
      u_right_btn.base = 0;
      u_right_btn.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->right_btn = u_right_btn.real;
      offset += sizeof(this->right_btn);
      union {
        bool real;
        uint8_t base;
      } u_btn1;
      u_btn1.base = 0;
      u_btn1.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->btn1 = u_btn1.real;
      offset += sizeof(this->btn1);
      union {
        bool real;
        uint8_t base;
      } u_btn2;
      u_btn2.base = 0;
      u_btn2.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->btn2 = u_btn2.real;
      offset += sizeof(this->btn2);
      union {
        bool real;
        uint8_t base;
      } u_btn3;
      u_btn3.base = 0;
      u_btn3.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->btn3 = u_btn3.real;
      offset += sizeof(this->btn3);
      union {
        bool real;
        uint8_t base;
      } u_btn4;
      u_btn4.base = 0;
      u_btn4.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->btn4 = u_btn4.real;
      offset += sizeof(this->btn4);
      union {
        bool real;
        uint8_t base;
      } u_sw1;
      u_sw1.base = 0;
      u_sw1.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->sw1 = u_sw1.real;
      offset += sizeof(this->sw1);
      union {
        bool real;
        uint8_t base;
      } u_sw2;
      u_sw2.base = 0;
      u_sw2.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->sw2 = u_sw2.real;
      offset += sizeof(this->sw2);
      union {
        bool real;
        uint8_t base;
      } u_sw3;
      u_sw3.base = 0;
      u_sw3.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->sw3 = u_sw3.real;
      offset += sizeof(this->sw3);
      this->slider1 =  ((uint16_t) (*(inbuffer + offset)));
      this->slider1 |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->slider1);
      this->slider2 =  ((uint16_t) (*(inbuffer + offset)));
      this->slider2 |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->slider2);
     return offset;
    }

    const char * getType(){ return "joybro/JoyBro"; };
    const char * getMD5(){ return "9bec54b48b0b3ef97ad21438236ecaa8"; };

  };

}
#endif
