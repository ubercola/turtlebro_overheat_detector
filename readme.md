
### Description

This package allows you to start a node for receiving data from the built-in AMG88xx GridEYE 8x8 IR camera thermal sensor and control the patrolling process from the https://github.com/voltbro/turtlebro_patrol package. When a heat source with a temperature higher than 45C is detected, the detection node stops patrolling, turns on the signal lamp and enters the standby state for 10 seconds. After that, the robot starts patrolling again, but for the first 10 seconds it ignores all sources of heat.


### Dependecies

- turtlebro_patrol

### Package installation

Install the package on RaspberryPi in the "standard" way:

```
cd ~/ros_catkin_ws/src
git clone https://github.com/ubercola/turtlebro_overheat_detector
cd ~/ros_catkin_ws
sudo ./src/catkin/bin/catkin_make_isolated --install -DCMAKE_BUILD_TYPE=Release --install-space /opt/ros/melodic --pkg=turtlebro_overheat_detector
```

### Launch


Launch only detector node, without patrol:
```
roslaunch turtlebro_overheat_detector turtlebro_heat_detector.launch
```

Launch patrol and heat detector:
```
roslaunch turtlebro_overheat_detector heat_patrol.launch
```

