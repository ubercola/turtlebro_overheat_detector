src/arduino/amg88xx_main.ino - arduino amg8833 sensor script that sends 64 pixels each second  

at first - download amg88xx_main.cpp  
open in Arduino IDE  
you have to use Adafruit_AMG88xx library from here:  

https://github.com/adafruit/Adafruit_AMG88xx  

or find it in arduino library manager.  

then compile and download to onboard arduino mega  


-----------------------------------------------------------------------------------------------------------------

turtlebro_heat_detector - package for handling data from arduino heat node  

load this package to   

```
~/ros_catkin_ws/src
```

compile as package in RPi:  

```
sudo ./src/catkin/bin/catkin_make_isolated --install -DCMAKE_BUILD_TYPE=Release --install-space /opt/ros/melodic --pkg=turtlebro_heat_detector
```

how to run:  
```
rosrun turtlebro_heat_detector heat_detector.py _threshold:=30
```

---------------------------------------------------------------------------------------------------------------

voltbro 2020


