Установка пакета  

На RaspberryPi установить пакет "стандартным" способом  

```
cd ros_catkin_ws/src
git clone https://github.com/voltbro/turtlebro_patrol
cd ..
sudo ./src/catkin/bin/catkin_make_isolated --install -DCMAKE_BUILD_TYPE=Release --install-space /opt/ros/melodic --pkg=turtlebro_overheat_detector

```

Как запустить через rosrun :  
```
rosrun turtlebro_heat_detector heat_detector.py _threshold:=30
```

Как запустить через roslaunch:  

----------------------------------------------------------------------------------------------------------------

src/arduino/amg88xx_main.ino - скрипт для запуска amg8833 на arduino   

Как это сделать?  

Сначала - откройте в Arduino IDE amg88xx_main.ino  
Нужно будет использовать библиотеку Adafruit_AMG88xx library [отсюда](https://github.com/adafruit/Adafruit_AMG88xx):  

Или просто найдите ее в arduino library manager.  
Затем скомпилируйте скетч и загрузите в встроенную arduino mega  

-----------------------------------------------------------------------------------------------------------------

voltbro 2020


