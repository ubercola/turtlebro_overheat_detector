/***************************************************************************
  This is a library for the AMG88xx GridEYE 8x8 IR camera

  This sketch tries to read the pixels from the sensor

  Designed specifically to work with the Adafruit AMG88 breakout
  ----> http://www.adafruit.com/products/3538

  These sensors use I2C to communicate. The device's I2C address is 0x69

  Adafruit invests time and resources providing this open source code,
  please support Adafruit andopen-source hardware by purchasing products
  from Adafruit!

  Written by Dean Miller for Adafruit Industries.
  BSD license, all text above must be included in any redistribution
 ***************************************************************************/

#include <Wire.h>
#include <Adafruit_AMG88xx.h>
#include <ros.h>
#include <std_msgs/String.h>
#include <std_msgs/Float32MultiArray.h>

Adafruit_AMG88xx amg;

float pixels[AMG88xx_PIXEL_ARRAY_SIZE];


class NewHardware : public ArduinoHardware
{
  public:
  NewHardware():ArduinoHardware(&Serial1, 115200){};
};
ros::NodeHandle_<NewHardware>  nh;

std_msgs::Float32MultiArray f_array_msg;
ros::Publisher amg88xx_pixels_pub("amg88xx_pixels", &f_array_msg);

void setup()
{

    bool status;
    
    // default settings
    status = amg.begin();
    if (!status) {
        while (1);
    }
    delay(100); 

    f_array_msg.data = (float*)malloc(sizeof(float) * AMG88xx_PIXEL_ARRAY_SIZE);
    f_array_msg.data_length = AMG88xx_PIXEL_ARRAY_SIZE;

    nh.initNode();
    nh.advertise(amg88xx_pixels_pub);
}

void loop()
{
    amg.readPixels(pixels);

    for (int i = 0; i < AMG88xx_PIXEL_ARRAY_SIZE; ++i)
    {
        f_array_msg.data[i] = pixels[i];
    }

    amg88xx_pixels_pub.publish(&f_array_msg);

    nh.spinOnce();
    delay(1000);
}
