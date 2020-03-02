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

```
roslaunch turtlebro_overheat_detector turtlebro_heat_detector.launch
```

Если нужно отслеживать вывод запущенной программы, то можно добавить опцию --screen  

```
roslaunch turtlebro_overheat_detector turtlebro_heat_detector.launch --screen
```

----------------------------------------------------------------------------------------------------------------

src/arduino/amg88xx_main.ino - скрипт для получения данных с amg8833 на arduino   

Что с ним делать?  

Сначала - откройте в Arduino IDE amg88xx_main.ino  
Нужно будет подключить библиотеку Adafruit_AMG88xx library [можно прямо из репозитория](https://github.com/adafruit/Adafruit_AMG88xx)  
(Или просто найдите ее в arduino library manager).  

Затем скомпилируйте скетч и загрузите в встроенную arduino mega  



-----------------------------------------------------------------------------------------------------------------

voltbro 2020


