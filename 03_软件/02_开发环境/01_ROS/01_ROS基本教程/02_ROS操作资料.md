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
#### ①文件编辑规则
#### ②其他文件修改
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

### （2）创建服务（srv）
#### ①文件编辑规则
#### ②其他文件修改
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
### （3）创建动作（action）
#### ①文件编辑规则
#### ②其他文件修改
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
