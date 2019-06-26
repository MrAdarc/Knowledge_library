<font size=6><center>ROS操作资料</center></font>

[TOC]

# 一、ROS安装
## 1.ROS安装
&emsp;&emsp;对于不同的版本，ROS版本对操作系统的版本需求也不一样，常用的两个ROS版本分别为Indigo和Kinetic，该两个版本分别只能在Ubuntu14.04.5 TLS与Ubuntu16.04.5 TLS上进行安装，这里整理出在Ubuntu16.04.5 TLS上进行安装的流程，要参考在Ubuntu14.04.5 TLS上进行安装，则只需将网址中的kinetic替换成indigo即可：
##### 对于Ubuntu16版本
**步骤1 系统安装配置**
&emsp;&emsp;配置Ubuntu允许"restricted" "universe" and "multiverse"，在“设置”->“更新和软件”中进行设置，一般为默认状态。

**步骤2 安装源列表**
```
sudo sh -c 'echo "deb http://packages.ros.org/ros/ubuntu $(lsb_release -sc) main" > /etc/apt/sources.list.d/ros-latest.list'
```

**步骤3 安装密钥**
```
sudo apt-key adv --keyserver 'hkp://keyserver.ubuntu.com:80' --recv-key C1CF6E31E6BADE8868B172B4F42ED6FBAB17C654
```

**步骤4 ROS安装**
```
sudo apt-get update     //刷新网址
sudo apt-get install ros-kinetic-desktop-full     //将所有组件进行安装
apt-cache search ros-kinetic      //自动寻找依赖包进行安装
```

**步骤5 初始化rosdep**
```
sudo rosdep init
rosdep update
```

**步骤6 环境变量设置**
```
echo "source /opt/ros/kinetic/setup.bash" >> ~/.bashrc
source ~/.bashrc
```

```
source /opt/ros/kinetic/setup.bash
```

```
echo "source /opt/ros/kinetic/setup.zsh" >> ~/.zshrc
source ~/.zshrc
```

**步骤7 安装与构建依赖包**
```
sudo apt install python-rosinstall python-rosinstall-generator python-wstool build-essential
```

## 2.IDE安装
### （1）QtCreator安装
&emsp;&emsp;要能够在QtCreator中创建工程，在安装QtCreator的基础上，需要安装相应的ROS开发的插件：
**步骤1 下载Ubuntu16相关程序**
```
sudo add-apt-repository ppa:levi-armstrong/qt-libraries-xenial
sudo add-apt-repository ppa:levi-armstrong/ppa
sudo apt-get update
sudo apt install qt59creator
sudo apt-get install qt57creator-plugin-ros libqtermwidget59-0-dev
```

**步骤2 配置系统工作路径**
```
sudo gedit /usr/lib/x86_64-linux-gnu/qt-default/qtchooser/default.conf
```
&emsp;&emsp;修改内容为如下：
```
/opt/qt59/bin
/opt/qt59/lib
```

# 二、ROS创建
## 1.结构创建
### （1）创建空间
&emsp;&emsp;创建ROS工程根据IDE的不同，创建的过程也有所不同，这里分别进行叙述：
|IDE|方式|参考链接|
|---|---|---|
| 无 | 终端下创建 |(公司培训资料)|
| Qtcreator | QtCreator创建ROS工程 |[wiki](https://ros-qtc-plugin.readthedocs.io/en/latest/_source/Improve-ROS-Qt-Creator-Plugin-Developers-ONLY.html)</br>[CSDN](https://blog.csdn.net/gxuphf123/article/details/81146621)|

#### ①终端下创建
```
#创建工作空间
mkdir-p ~/catkin_ _ws/src
cd ~/catkin_ ws/src
catkin_init_workspace

#编译工作空间
cd ~/catkin_ _ws/
catkin_ make

#设置环境变量
source devel/setup.bash

#检查环境变量
echo $ROS_PACKAGE_PATH
```

#### ②Qtcreator创建
**步骤1 创建工程**
&emsp;&emsp;New Project -> Other Project -> ROS Workspace => Choose...
&emsp;&emsp;命名+路径 => finish

**步骤2 创建包**
&emsp;&emsp;项目右击 -> Add New... -> ROS -> Packages

### （2）包创建
#### ①终端下创建包
```
#创建功能包
cd ~/catkin_ws/src
catkin_create_pkg learning_communication std_msgs rospy roscpp

#编译功能包
cd ~/catkin_ws
catkin_make
source ~/catkin_ws/devel/setup.bash
```

### （3）节点创建
#### ①终端下创建
##### #1创建发布者与订阅者
###### ●发布者
&#8195;&#8195;由于在终端下，无法直接生成样板方便开发，这里发布者模板见附录1；
&#8195;&#8195;在调用发布者的模板后并不能直接

**调试问题汇总**
###### ●订阅者
&#8195;&#8195;订阅者模板见附录2
###### ●相关文件修改
&#8195;&#8195;在构建发布者与订阅者后，需要在CMakeList.txt文件中修改相关内容，修改内容见附录3

##### #2创建服务器与客户端
###### ●服务器
&#8195;&#8195;服务器模板见附录4
###### ●客户端
&#8195;&#8195;客户端模板见附录5
###### ●相关文件修改
&#8195;&#8195;相关文件修改内容见附录6

##### #3创建动作服务器与动作客户端
###### ●动作服务器
&#8195;&#8195;动作服务器模板见附录7
###### ●动作客户端
&#8195;&#8195;动作客户端模板见附录8
###### ●相关文件修改
&#8195;&#8195;相关文件修改内容见附录9

## 2.创建通讯（创建消息）
### （1）创建话题（msg）
&#8195;&#8195;msg文件是ROS中的简单的文本文件，用以记录消息的类型
```
<msg_name>.msg   //msg文件标记
```
#### 1)msg文件类型
```
int8, int16, int32, int64 (plus uint*)
float32, float64
string
time, duration
other msg files
variable-length array[] and fixed-length array[C]
```
&#8195;&#8195;其中other msg file文件的使用方式为：
```
<msg_name>/<msg_member_name> <member_name>
```
#### 2)文件编辑规则
&#8195;&#8195;msg文件的编写较为简单，由消息类型与消息成员的形式以列表的方式进行编写
```
//示范
<msg_type1> <msg_member1>
<msg_type2> <msg_member2>   

//示例
string child_frame_id
geometry_msgs/PoseWithCovariance pose
geometry_msgs/TwistWithCovariance twist
```
#### 3)其他文件修改
**package.xml中添加功能依赖包**
```
<build_depend> message_generation </build_depend>
<exec_depend> message_runtime </exec_depend>
```
**CMakeList.txt添加编译选项**
```
find_package ( …… message_generation)

catkin_package(CATKIN_DEPENDS geometry_msgs roscpp
rospy std_msgs message_runtime)

add_message_files(FILES Person.msg)
generate_messages(DEPENDENCIES std_msgs）
```
|检索|作用|一般|
|:-:|:-:|:-:|
|搜寻find_package(catkin|添加包的依赖库（包括信息依赖与其他依赖|roscpp</br>rospy</br>std_msgs</br>generate_messages|
|catkin_package|添加信息依赖|message_runtime|
|add_message_files|添加信息文件|\|
|generate_messages|生成工程中的|std_msgs|
### 4)msg文件的相关操作
&#8195;&#8195;msg文件存放在包下的src/msg目录下。
```
echo "<msg_type> <member_name>" >
```

### （2）创建服务（srv）
&#8195;&#8195;srv的消息类型同msg文件的消息类型相同，不同的地方在于src文件的内容格式划分为两个部分，这两个部分使用“---”进行隔开
#### 1)文件编辑规则
```
<srv_type1> <request_member1>
<srv_type2> <request_member2>
---
<srv_type3> <response_member1>
<srv_type4> <response_membersrv
```
#### 2)其他文件修改
&#8195;&#8195;srv文件存放在包下的src/srv目录下。
**package.xml中添加功能依赖包**
```
<build_depend> message_generation</build_depend>
<exec_depend> message_runtime</exec_depend>
```
**CMakeList.txt添加编译选项**
```
find_package( …… message_generation)

catkin_package(CATKIN_DEPENDS geometry_msgs roscpp
rospy std_msgs message_runtime)

add_service_files(FILES AddTwoInts.srv)
```
#### 3)srv文件的相关操作

### （3）创建动作（action）
#### 1)文件编辑规则
#### 2)其他文件修改
**package.xml中添加功能依赖包**
```
<build_depend>actionlib</build_depend>
<build_depend>actionlib_msgs</build_depend>
<exec_depend>actionlib</exec_depend>
<exec_depend>actionlib_msgs</exec_depend>
```
**CMakeList.txt添加编译选项**
```
find_package (catkin REQUIRED actionlib_msgs actionlib)
add_action_files(DIRECTORY action FILES DoDishes.action)
generate_messages(DEPENDENCIES actionlib_msgs)
```

### （4）创建参数配置文件（param）

## 3.其他文件编写规则
### （1）launch文件
**运行launch**
```
roslaunch [package] [filename.launch]  //运行包中的launch文件
```
**编写规则**

### （2）CMakeLists.txt文件
```
###############################################
##        ROS的消息声明（话题、服务、动作）       ##
###############################################
## cmake版本信息及功能包名称
cmake_minimum_required(VERSION 2.8.3)
project(<package_name>)
## 添加编译器
# add_compile_options(-std=c++11)
## 添加功能包的依赖包
# find_package(catkin REQUIRED COMPONENTS
  <dependence_package_name1>
  <dependence_package_name2>
# )

## 未知
# find_package(Boost REQUIRED COMPONENTS system)

##
# catkin_python_setup()
######################################################################
## 处理对象：                                                         ##
##     <package_name>：功能包名                                       ##
##     <dependence_package_name1>：功能包的依赖包1名                   ##
##     <dependence_package_name1>：功能包的依赖包1名                   ##
######################################################################

###############################################
##        ROS的消息声明（话题、服务、动作）       ##
###############################################
## 在src/msg目录下生成消息文件
# add_message_files(
#   FILES
#   <msg_name>.msg
# )

## 在src/msg目录下生成消息文件
# add_service_files(
#   FILES
#   <srv_name>.srv
# )

## 在src/msg目录下生成消息文件
# add_action_files(
#   FILES
#   <act_name>.action
# )

## 添加消息/服务的依赖
# generate_messages(
#   DEPENDENCIES
#   <msg_dep_package>
# )

######################################################################
## 处理对象：                                                         ##
##     <msg_name>.msg：msg文件名                                      ##
##     <srv_name>.srv：srv文件名                                      ##
##     <act_name>.action：action文件名                                ##
##     <msg_dep_package>：消息相关依赖包                               ##
######################################################################

################################################
##             ROS的动态参数声明               ##
################################################
## Generate dynamic reconfigure parameters in the 'cfg' folder
# generate_dynamic_reconfigure_options(
#   cfg/DynReconf1.cfg
#   cfg/DynReconf2.cfg
# )

###################################
## catkin specific configuration ##
###################################
# catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES using_markers
#  CATKIN_DEPENDS roscpp visualization_msgs
#  DEPENDS system_lib
# )


################################################
##                   构建                     ##
################################################
## 添加本地头文件
##>>>>>>对功能包
# include_directories(include ${catkin_INCLUDE_DIRS})
## 声明C++库
# add_library(${PROJECT_NAME} src/${PROJECT_NAME}/using_markers.cpp)
## 对库添加依赖
# add_dependencies(${PROJECT_NAME} ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
##>>>>>>对节点
## 声明C++可执行程序
# add_executable(${PROJECT_NAME}_node src/using_markers_node.cpp)
## 对节点进行重命名，去掉后缀（.cpp）
# set_target_properties(${PROJECT_NAME}_node PROPERTIES OUTPUT_NAME node PREFIX "")
## 添加node的依赖
# add_dependencies(${PROJECT_NAME}_node ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
## 连接到库或者可执行目标上
# target_link_libraries(${PROJECT_NAME}_node ${catkin_LIBRARIES})

######################################################################
## 处理对象：                                                        ##
##     ${PROJECT_NAME}：功能包名                                     ##
##     ${PROJECT_NAME}_node：节点名                                  ##
######################################################################


###############################################
##                    安装                    ##
###############################################
##
# install(PROGRAMS
#   scripts/my_python_script
#   DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
# )

## Mark executables and/or libraries for installation
# install(TARGETS ${PROJECT_NAME} ${PROJECT_NAME}_node
#   ARCHIVE DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
#   LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
#   RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
# )

## Mark cpp header files for installation
# install(DIRECTORY include/${PROJECT_NAME}/
#   DESTINATION ${CATKIN_PACKAGE_INCLUDE_DESTINATION}
#   FILES_MATCHING PATTERN "*.h"
#   PATTERN ".svn" EXCLUDE
# )

## Mark other files for installation (e.g. launch and bag files, etc.)
# install(FILES
#   # myfile1
#   # myfile2
#   DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}
# )

###############################################
##                   测试                    ##
###############################################

## Add gtest based cpp test target and link libraries
# catkin_add_gtest(${PROJECT_NAME}-test test/test_using_markers.cpp)
# if(TARGET ${PROJECT_NAME}-test)
#   target_link_libraries(${PROJECT_NAME}-test ${PROJECT_NAME})
# endif()

## Add folders to be run by python nosetests
# catkin_add_nosetests(test)
```
&#8195;&#8195;因为CMakeLists.txt文件记录着从工程到节点，以及从源文件到生成文件的一系列信息，因此，在对工程的内容进行创建的过程中，为便于进行开发，这里将关键词列表，根据相关的操作操作来检索需要进行配置的位置，通过查找替换的方式进行操作:
```
功能包的相关配置
消息的相关配置
   检索:
     msg:Message1.msg
     srv:Service1.srv
     act:Action1.action
   替换:
     msg:<msg_name>.msg
     srv:<srv_name>.srv
     act:<act_name>.action
   去注释化：
     msg:add_message_files
     srv:add_service_files
     act:add_action_files
   添加:
     find_package(catkin
     catkin_package
     generate_messages
动态参数的配置
节点配置
   检索：${PROJECT_NAME}_node
   替换：<node_name>
   去注释化：
      add_executable
      add_dependencies
      target_link_libraries
安装配置
```


## 4.文件编辑流程

# 三、编译及问题排查

# 四、ROS工程执行方式

# 附录0 节点模板
```
#include <ros/ros.h>

int main(int argc, char **argv)
{
  //初始化ROS节点
  ros::init(argc, argv, "<node_name>");
  //创建节点句柄
  ros::NodeHandle nh;

  //节点打印信息
  ROS_INFO("Hello world!");
}
```
# 附录1 发布者模板
```
#include "ros/ros.h"
#include "std_msgs/String.h"

int main(int argc, char **argv)
{
  //初始化发布者节点
  ros::init(argc, argv, "<Publisher_name>");
  //初始化发布者节点句柄
  ros::NodeHandle nh;
  //向Master注册节点信息
  ros::Publisher chatter_pub = nh.advertise<std_msgs::String>("chatter", 1000);
  //设置循环频率
  ros::Rate loop_rate(10);
  while (ros::ok())
  {
    std_msgs::String msg;
    msg.data = "hello world";

    chatter_pub.publish(msg);
    //等待循环调回函数
    ros::spinOnce();
    //按照循环频率延时
    loop_rate.sleep();
  }

  return 0;
}

```
# 附录2 订阅者模板
```
#include "ros/ros.h"
#include "std_msgs/String.h"
//收到消息订阅消息后，进入消息回调函数
void chatterCallback(const std_msgs::String::ConstPtr& msg)
{
  //将收到的消息打印出来
  ROS_INFO("I heard: [%s]", msg->data.c_str());
}

int main(int argc, char **argv)
{
  //初始化订阅者节点
  ros::init(argc, argv, "2");
  //创建订阅者节点句柄
  ros::NodeHandle nh;

  ros::Subscriber sub = nh.subscribe("chatter", 1000, chatterCallback);

  ros::spin();

  return 0;
}

```
# 附录3 话题节点相关文件修改
```
add_executable(<Publisher_name> src/<Publisher_name>.cpp)
target_link_libraries(<Publisher_name> ${catkin_LIBRARIES})
add_dependencies (<Publisher_name> ${PROJECT_NAME}_generate_messages_cpp)
add_executable(<Subscriber_name> src/Subscriber_name>.cpp)
target_link_libraries(Subscriber_name> ${catkin_LIBRARIES})
add_dependencies (Subscriber_name> ${PROJECT_NAME}_generate_messages_cpp)
```
# 附录4 服务器模板
```
#include "ros/ros.h"
#include "beginner_tutorials/AddTwoInts.h"

bool add(beginner_tutorials::AddTwoInts::Request  &req,
         beginner_tutorials::AddTwoInts::Response &res)
{
  res.sum = req.a + req.b;
  ROS_INFO("request: x=%ld, y=%ld", (long int)req.a, (long int)req.b);
  ROS_INFO("sending back response: [%ld]", (long int)res.sum);
  return true;
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "3");
  ros::NodeHandle nh;

  ros::ServiceServer service = nh.advertiseService("add_two_ints", add);
  ROS_INFO("Ready to add two ints.");
  ros::spin();

  return 0;
}

```
# 附录5 客户端模板
```
#include "ros/ros.h"
#include "beginner_tutorials/AddTwoInts.h"
#include <cstdlib>

int main(int argc, char **argv)
{
  ros::init(argc, argv, "4");
  if (argc != 3)
  {
    ROS_INFO("usage: add_two_ints_client X Y");
    return 1;
  }

  ros::NodeHandle nh;
  ros::ServiceClient client = nh.serviceClient<beginner_tutorials::AddTwoInts>("add_two_ints");
  beginner_tutorials::AddTwoInts srv;
  srv.request.a = atoll(argv[1]);
  srv.request.b = atoll(argv[2]);
  if (client.call(srv))
  {
    ROS_INFO("Sum: %ld", (long int)srv.response.sum);
  }
  else
  {
    ROS_ERROR("Failed to call service add_two_ints");
    return 1;
  }

  return 0;
}

```
# 附录6 服务节点相关文件修改
```
add_executable(server src/server.cpp)
target_link_libraries(server ${catkin_LIBRARIES})
add_dependencies(server ${PROJECT_NAME}_gencpp)
add_executable(client src/client.cpp)
target_link_libraries(client ${catkin_LIBRARIES})
add_dependencies(client ${PROJECT_NAME}_gencpp)
```
# 附录7 动作服务器模板
```

```
# 附录8 动作客户端模板
```

```
# 附录9 动作节点相关文件修改
```
add_executable(DoDishes_client src/DoDishes_client.cpp)
target_link_libraries( DoDishes_client ${catkin_LIBRARIES})
add_dependencies(DoDishes_client ${${PROJECT_NAME}_EXPORTED_TARGETS})
add_executable(DoDishes_server src/DoDishes_server.cpp)
target_link_libraries( DoDishes_server catkin_LIBRARIES})
add_dependencies(DoDishes_server ${${PROJECT_NAME}_EXPORTED_TARGETS})
```
# 附录10 消息模板
```
string first_name
string last_name
uint8 age
uint32 score
```

# 附录11 服务模板
```
int64 a
int64 b
---
int64 sum
```

# 附录12 动作模板
```

```

# 附录13 launch模板
```
<launch>

</launch>
```

# 附录14 机器人模型模板
```
<?xml version="1.0" ?>
<robot name="test_robot" xmlns:xacro="http://ros.org/wiki/xacro">
  <link name="base"/>
  <link name="tool0"/>

  <joint name="base_to_tool0" type="fixed">
    <parent link="base"/>
    <child link="tool0"/>
    <origin xyz="0 0 0" rpy="0 0 0"/>
  </joint>
</robot>
```
# 附录15 Commend line
## 1.rosnode
```
rosnode list 查看当前运行节点
rosnode info <node_name>查看节点信息
rosnode ping <node_name>测试节点
rosrun [package_name] [node_name] 运行节点
```
## 2.rostopic
```
rostopic -h 查看rostopic的帮助
    rostopic bw     display bandwidth used by topic
    rostopic echo   print messages to screen
    rostopic hz     display publishing rate of topic
        rostopic hz [topic]    
    rostopic list   print information about active topics
    rostopic pub    publish data to topic
        rostopic pub [topic] [msg_type] [args]
        rostopic pub -1 /turtle1/cmd_vel geometry_msgs/Twist -- '[2.0, 0.0, 0.0]' '[0.0, 0.0, 1.8]'
    rostopic type   print topic type
        rostopic type <topic_name>  输出话题<topic_name>的消息类型
```

## 3.rosservice
```
rosservice -h
    rosservice list         print information about active services
    rosservice call         call the service with the provided args
        rosservice call [service] [args]
        rosservice call /spawn 2 2 0.2 ""
    rosservice type         print service type
        rosservice type [service]
    rosservice find         find services by service type
    rosservice uri          print service ROSRPC uri
```

## 4.rosparam
```
rosparam set            set parameter
rosparam get            get parameter
    rosparam set [param_name] value
    rosparam get [param_name]
rosparam load           load parameters from file
rosparam dump           dump(卸装) parameters to file
    rosparam dump [file_name] [namespace]
    rosparam load [file_name] [namespace]
rosparam delete         delete parameter
rosparam list           list parameter names
```
## 5.常用ROS工具使用
```
rosrun rqt_graph rqt_graph  //查看节点关系图
rosrun rqt_plot rqt_plot  //查看话题中传输的消息数据
rosrun rqt_console rqt_console
rosrun rqt_logger_level rqt_logger_level
```
