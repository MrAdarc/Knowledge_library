# RVIZ环境搭建
&emsp;&emsp;RVIZ相关程序在ROS进行安装的过程中已经进行过安装，但是部分相关的依赖插件并没能进行安装，这里根据网络上的例程进行整理，以便于进行参考：

###### 步骤1 安装turtlebot包
```
sudo apt-get install ros-kinetic-turtlebot-*
```

###### 步骤2 安装模拟器
```
sudo apt-get install ros-kinetic-arbotix-*
```

###### 步骤3 安装相关依赖包以及例程相关代码包
**依赖包**
```
sudo apt-get install ros-kinetic-turtlebot-bringup
sudo apt-get install ros-kinetic-turtlebot-create
sudo apt-get install ros-kinetic-openni-*
sudo apt-get install ros-kinetic-openni2-*
sudo apt-get install ros-kinetic-freenect-*
sudo apt-get install ros-kinetic-usb-cam
sudo apt-get install ros-kinetic-laser-*
sudo apt-get install ros-kinetic-hokuyo-node
sudo apt-get install ros-kinetic-audio-common
sudo apt-get install gstreamer0.10-pocketsphinx
sudo apt-get install ros-kinetic-pocketsphinx
sudo apt-get install ros-kinetic-slam-gmapping
sudo apt-get install ros-kinetic-joystick-drivers
sudo apt-get install python-rosinstall
sudo apt-get install ros-kinetic-orocos-kdl
sudo apt-get install ros-kinetic-python-orocos-kdl
sudo apt-get install python-setuptools
sudo apt-get install ros-kinetic-dynamixel-motor
sudo apt-get install libopencv-dev
sudo apt-get install python-opencv
sudo apt-get install ros-kinetic-vision-opencv
sudo apt-get install ros-kinetic-depthimage-to-laserscan
sudo apt-get install ros-kinetic-arbotix-*
sudo apt-get install ros-kinetic-turtlebot-teleop
sudo apt-get install ros-kinetic-move-base
sudo apt-get install ros-kinetic-map-server
sudo apt-get install ros-kinetic-fake-localization
sudo apt-get install ros-kinetic-amcl
```

**代码包**
```
cd ~/catkin_ws/src
git clone https://github.com/pirobot/rbx1.git
cd ..
catkin_make
```

###### 步骤4 导航仿真
&emsp;&emsp;在运行程序的时候，注意使用命令对整个环境变量进行更新，更新命令如下[下述命令在工作区间下执行]：
```
catkin_make
source devel/setup.bash
```
运行命令
```
roscore
roslaunch rbx1_bringup fake_turtlebot.launch
roslaunch rbx1_nav fake_amcl.launch map:=test_map.yaml
rosrun rviz rviz -d `rospack find rbx1_nav`/nav.rviz
```
