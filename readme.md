
### Description

This package allows you to start a node for receiving data from the AMG88xx GridEYE 8x8 IR camera thermal sensor and control the patrolling process from the https://github.com/voltbro/turtlebro_patrol package.  When a heat source with a temperature higher than threshold is detected, the detection node stops patrolling, turns on the signal lamp and enters the standby state for 10 seconds. After that, the robot starts patrolling again, but for the first 10 seconds it ignores all sources of heat.


### Dependecies

- turtlebro_patrol  

### Package installation on RPI

Install the package on RaspberryPi in the "standard" way:

```
cd ~/ros_catkin_ws/src
git clone https://github.com/ubercola/turtlebro_overheat_detector
cd ~/ros_catkin_ws
sudo ./src/catkin/bin/catkin_make_isolated --install -DCMAKE_BUILD_TYPE=Release --install-space /opt/ros/melodic --pkg=turtlebro_overheat_detector
```

### Connecting thermal sensor

AMG88xx thermal sensor   must be connected to built-in arduino compatible controller via I2C protocol. Wires from AMG88XX pins must be connected to one of the white connectors A8-A11 or A13-A15 on the Turtlebro Board.

sensor documentation:  
https://cdn.sparkfun.com/assets/4/1/c/0/1/Grid-EYE_Datasheet.pdf  
https://cdn-learn.adafruit.com/downloads/pdf/adafruit-amg8833-8x8-thermal-camera-sensor.pdf  

Wiring:  

AMG88XX pins -> Turtlebro pin  
VIN -> 5V  
GND -> GND  
SDA -> SDA  
SCL -> SCL  

Example about connecting AMG88xx to Arduino:  
https://learn.adafruit.com/adafruit-amg8833-8x8-thermal-camera-sensor/arduino-wiring-test  


### Connecting led lamp

Led lamp '+' pin must be connected STRICTLY to pin marked 'GPIO' in  white connector marked as 'A12'.   
Led lamp '-' pin must be connected to 'GND' pin on the same connector marked as 'A12'.  

NOTE:  
If you are using an unbranded LED lamp module, connect a current limiting resistor to the LED.  

### How to install on Arduino

Install Arduino Ide https://www.arduino.cc/en/main/software  
Open the Arduino Library Manager, find AMGXX library in search string, and install it. You also can download it directly from https://github.com/adafruit/Adafruit_AMG88xx  

Open file src/arduino/amg88xx_main.ino from cloned repo in Arduino IDE. Connect built-in turtlebro`s Arduino Mega via USB, and upload script to it.

Reboot RPi, you must see  topic "amg88xx_pixels" in list of ros topics. Node sends array of 64 floats those it got from sensor.


### Launch

Launch only detector node, without patrol:
```
roslaunch turtlebro_overheat_detector heat_detector.launch
```

Launch patrol and heat detector:
```
roslaunch turtlebro_overheat_detector heat_patrol.launch
```

Heat detector node ('heat_detector') will read topic "amg88xx_pixels" (it publish array of 64 floats, those it got from sensor) and check maximum value of temperature from that array. If maximum value is bigger than threshold (threshold can be set from .launch file), node sends command 'pause' to topic '/patrol_control' and send message to topic '/alarm_led'(it turns on the signal lamp). For 10 seconds patrol node enters the standby state. After that, the robot starts patrolling again, but for the first 10 seconds it ignores all sources of heat.



