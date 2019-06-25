<font size=6><center>ROS介绍资料</center></font>

[TOC]

# 一、ROS介绍
## 1.发展历程
|时间|活动|
|---|---|
|2000年 |斯坦福大学机器人软件系统框架|
|2007年 |柳树车库发起，ROS正式发布|
|2010年 |ROS1.0发布，大多组件和API沿用至今|
|NOW |ROS逐渐流行，相继出现十多个版本|

## 2.ROS特点
  ●将整个机器人的制作过程模块化、通用化，进而实现分层、分工，便于进行开发
  ●非操作系统，为连接操作系统与应用程序，提供着操作系统的部分功能，例如：硬件抽象、底层设备控制、常用函数的实现、进程间消息传递、包管理
|主体|描述|
|---|---|
|框架|分布式、进程（节点）管理、进程间通讯【扩展性好、软件分布率高】|
|工具|仿真、数据可视化、图形界面、数据记录【Gazebo、RVIZ、rqt使仿真和调试变得很容易】|
|功能|控制、规划、视觉、建图【ROS官网、github】|
|社区|软件包管理、文档、教程|



# 二、架构与命令
## 1.常用命令介绍
### （1）catkin_make工作空间的创建与编译
#### ①创建工作空间catkin_make
```
mkdir -p ~/catkin_ws/src
cd ~/catkin_ws/
catkin_make
```
#### ②用于编译catkin_make
```
cd ~/catkin_ws/   //在进行构建之前，首先回到工作空间目录下
catkin_make
source ~/catkin_ws/devel/setup.bash    
```
&#8195;&#8195;在完成构建之后，需要对环境变量进行更新，==但是一次环境变量的更新只对一个终端有效，可将其写入环境变量==，如下命令】
```
echo "source ~/catkin_ws/devel/setup.bash " >> ~/.bashrc    //将环境变量的更新写入.bashrc文件
echo "source /opt/ros/kinetic/setup.bash " >> ~/.bashrc     //更新依赖包
```
### （2）工作空间的管理

## 2.包及其相关命令
### （1）包查找命令rospack  
```
rospack help   //显示rospack的用法
rospack list   //列出本机所有package
rospack depends <package>   //显示package的依赖包
rospack find <package>   //定位某个package
rospack profile   //刷新所有package的位置记录
```

### （2）进入功能包roscd  
```
roscd <package_name>   //跳转到某个pkg路径下
```

### （3）列举包信息rosls
```
rosls <package_name>   //列举某个pkg下的文件信息
```

### （4）编辑包文件rosed  
```
roscd <package_name> <file_name>   //编辑pkg中的文件
```

### （5）创建包catkin_create_pkg
```
catkin_create_pkg <pkg_name> [deps]  //[deps]为包所需要的依赖
```

### （6）安装包的依赖rosdep【clone下的安装】
```
rosdep install <pkg_name>   //安装安装包的依赖项
rosdep check <pacakge>  //检查package的依赖是否满足
rosdep db   //生成和显示依赖数据库
rosdep init   //初始化/etc/ros/rosdep中的源
rosdep keys   //检查package的依赖是否满足
rosdep update   //更新本地的rosdep数据库
```

### （7）显示目录树tree
```
tree
```

## 3.节点及其相关命令
&#8195;&#8195;在对节点进行一系列操作的过程中，有节点管理器对节点进行管理，在运行节点管理器的过程中，会自动运行两个工具，即节点的日志输出（rosout）和参数服务器（parameter server）。
&#8195;&#8195;每一个节点在系统进行运行的过程中都是一个进程。
### （1）运行节点管理器roscore
```
roscore  //执行命令以运行节点管理器
```

### （2）运行节点rosrun
```
rosrun <pkg_name> <node_name>
```
### （3）管理与查看节点rosnode
```
rosnode list  //列出当前运行的node信息
rosnode info <node_name>   //显示某个node的详细信息
rosnode kill <node_name>   //结束某个node
```
### （4）启动master与多个node roslaunch
```
roslaunch <pkg_name> <file_name.launch>
```
&#8195;&#8195;<file_name.launch>记录了工程文件的启动规则，在运行的过程中，先检测master是否正在运行，若不在运行，则启动master后，在运行节点。
&#8195;&#8195;启动后，有日志输出，分别包含以下内容：
&#8195;&#8195;●PARAMETERS 参数服务器打印相关的参数信息
&#8195;&#8195;●NODE 打印相关的节点信息


## 4.消息相关命令
&#8195;&#8195;ROS中的通讯方式存在着四种情况，即话题（Topic）、服务（Service）、参数服务器（Parameter Service）、动作库（Actionlib）
### （1）话题（Topic）及其相关命令rostopic
&#8195;&#8195;Topic是ROS中的异步通信方式[发送时调用publish()方法，发送完成立即返回，不用等待反
馈，subscriber通过回调函数的方式来处理消息]，Node间通过publish-subscribe机制通信；Topic的通讯方式可以实现多对多。
![](assets/markdown-img-paste-20190612214640972.png)
&#8195;&#8195;Topic内容的数据类型称为Message，并定义在<font color = "#ff0000">* .msg</font>文件中。
&#8195;&#8195;topic内容的基本数据类型包括：
```
bool, int8, int16, int32, int64（以及uint）
float32, float64, string
time, duration, header
可变长数组array[]，固定长度数组array[C]
```
&#8195;&#8195;话题相关命令如下：
```
rostopic list    //列出当前所有的topic
rostopic info topic_name    //显示某个topic的属性信息
rostopic echo topic_name    //显示某个topic的内容
rostopic pub topic_name    //向某个topic发布内容
rostopic bw topic_name    //查看某个topic的带宽
rostopic hz topic_name    //查看某个topic的频率
rostopic find topic_type    //查找某个类型的topid
rostopic type topic_name    //查看某个topic的类型（msg）
```
&#8195;&#8195;通过 rostopic help 或 rostopic command -h 查看具体用法。
&#8195;&#8195;关于对*.msg文件进行管理的相关命令如下：
```
rosmsg list   //列出系统上所有的msg
rosmsg show <msg_name>   //显示某个msg的内容
```
&#8195;&#8195;见附录1，常见的message类型

### （2）服务（Service）及其相关命令rosservice
&#8195;&#8195;topic在工作过程中，会造成不必要的资源的浪费，为了使得消息的传输与处理在关键的时候进行，这里使用Service进行消息的传输与处理，在处理的过程中包含对发送方信息的反馈。
&#8195;&#8195;service包括两部分，一部分是请求方（Clinet），另
一部分是应答方/服务提供方（Server）。这时请求方（Client）就会发送一个request，要等待server处理，反馈回一个reply，这样通过类似“请求-应答”的机制完成整个服务通信。
![](assets/markdown-img-paste-20190612214758431.png)
&#8195;&#8195;Node B是server（应答方），提供了一个服务的接口，叫做 /Service ，我们一般都会用string类型来指定service的名称，类似于topic。Node A向Node B发起了请求，经过处理后得到了反馈，因此使得service的通讯过程是同步的。在Node A发布请求后会在原地等待reply，直到Node B处理完了请求并且完成了reply，Node A才会继续执行。Node A等待过程中，是处于==阻塞状态的==。这样的通信模型没有频繁的消息传递，没有冲突与高系统资源的占用，只有接受请求才执行服务，简单而且高效。
&#8195;&#8195;描述服务的内容，是需要在srv文件中进行的，在声明一个服务的过程中，包括两个部分，即请求（request）和响应（reply）两个部分，在*.srv文件中进行定义。
```
rosservice list  //显示服务列表
rosservice info  //打印服务信息
rosservice type  //打印服务类型
rosservice uri  //打印服务ROSRPC uri
rosservice find  //按服务类型查找服务
rosservice call  //使用所提供的args调用服务
rosservice args  //打印服务参数
```
&#8195;&#8195;与*.srv文件管理相关的命令如下：
```
rossrv show   //显示服务描述
rossrv list   //列出所有服务
rossrv md5   //显示服务md5sum
rossrv package   //列出包中的服务
rossrv packages   //列出包含服务的包
```
&#8195;&#8195;见附录2为常见srv类型

### （3）参数服务器（Parameter server）及其相关命令rosparam
&#8195;&#8195;参数服务器是节点存储参数的地方，用于配置参数，全局共享参数。参数服务器使用互联网传输，在节点管理器中运行，以实现整个通信过程。
&#8195;&#8195;与话题（topic）和服务（service）进行比较，参数服务器的工作方式更加的静态。参数服务器维护着一个数据字典，字典里存储着各种参数和配置。
&#8195;&#8195;字典类似于一个个的键值对，每一个key不重复，且每一个key对应着一个value。也可以说字典就是一种映射关系，通常将一些不常用到的参数和配置放入参数服务器里的字典里，这样对这些数据进行读写都将方便高效。
&#8195;&#8195;字典文件通常用local和dump文件的形式进行存储，在进行编辑时要遵循YAML格式，如下：
```
<key_name>:<value_name>
```
&#8195;&#8195;例如：
```
name:'Zhangsan'
age:20
gender:'M'
score:{Chinese:80,Math:90}
score_history:[85,82,88,90]
```
&#8195;&#8195;要对参数服务器进行维护，存在三种方式：
    +命令行维护
    +launch文件内读写
    +node源码
&#8195;&#8195;命令行维护
&#8195;&#8195;&#8195;&#8195;使用命令行对参数服务器进行整理（相关命令行见下）
&#8195;&#8195;launch文件内读写
&#8195;&#8195;&#8195;&#8195;（后续整理决定）
&#8195;&#8195;node源码
&#8195;&#8195;&#8195;&#8195;利用API来对参数服务器进行操作。

```
rosparam set param_key param_value   //设置参数
rosparam get param_key   //显示参数
rosparam load file_name   //从文件加载参数
rosparam dump file_name   //保存参数到文件
rosparam delete   //删除参数
rosparam list   //列出参数名称
```

&#8195;&#8195;命令行维护相关命令
```
rosparam set param_key param_value   //设置参数
rosparam get param_key   //显示参数
rosparam load file_name   //从文件加载参数
rosparam dump file_name   //保存参数到文件
rosparam delete   //删除参数
rosparam list   //列出参数名称
```

### （4）动作库（action）及其相关命令
&#8195;&#8195;Actionlib是ROS中一个很重要的库，类似service通信机制，actionlib也是一种请求响应机制的通信方式，actionlib主要弥补了service通信的一个不足，即publisher会很长时间接受不到反馈的reply，致使通信受阻。当service通信不能很好的完成任务时候，actionlib则可以比较适合实现长时间的通信过程，actionlib通信过程可以随时被查看过程进度，也可以终止请求。

![](assets/markdown-img-paste-20190613223216741.png)
![](assets/markdown-img-paste-20190613223227542.png)

&#8195;&#8195;利用动作库进行请求响应，动作的内容格式应包含三个部分，目标、反馈、结果。
目标：机器人执行一个动作，应该有明确的移动目标信息，包括一些参数的设定，方向、角度、速度等等。从而使机器人完成动作任务。
反馈：在动作进行的过程中，应该有实时的状态信息反馈给服务器的实施者，告诉实施者动作完成
的状态，可以使实施者作出准确的判断去修正命令。
结果：当运动完成时，动作服务器把本次运动的结果数据发送给客户端，使客户端得到本次动作的全部信息，例如可能包含机器人的运动时长，最终姿势等等。

**action规范文件格式**
&#8195;&#8195;Action规范文件的后缀名是.action，它的内容格式如下：
```
# Define the goal
uint32 dishwasher_id # Specify which dishwasher we want to use
---
# Define the result
uint32 total_dishes_cleaned
---
# Define a feedback message
float32 percent_complete
```

### （6）几种通讯方式的比较
|名称|Topic |Service|
|---|---|---|
|通信方式|异步通信|同步通信|
|实现原理|TCP/IP |TCP/IP|
|通信模型|Publish-Subscribe |Request-Reply|
|映射关系|Publish-Subscribe(多对多) |Request-Reply（多对一）|
|特点|接受者收到数据会回调（Callback）|远程过程调用（RPC）服务器端的服务|
|应用场景|连续、高频的数据发布|偶尔使用的功能/具体的任务|
|举例|激光雷达、里程计发布数据|开关传感器、拍照、逆解计算|

# 三、工具介绍
## 1.RVIZ工具介绍
## 2.Gazebo工具介绍
## 3.rqt工具介绍

# 四、结构介绍
![](assets/markdown-img-paste-20190612205707323.png)
![](assets/markdown-img-paste-20190612205859638.png)

|catkin workspace| < | < |
|---|---|---|
| src |build（catkin_make构建生成） |devel（catkin_make构建生成）|
|package源代码 |cmake&catkin缓存和中间文件 |目标文件(头文件、动态链接库、静态链接库、可执行文件)|

# 附录1 常见msg类型
**Vector3.msg**
```
//文件位置:geometry_msgs/Vector3.msg
float64 x
float64 y
float64 z
```

**Accel.msg**
```
//定义加速度项，包括线性加速度和角加速度
//文件位置:geometry_msgs/Accel.msg
Vector3 linear
Vector3 angular
```

**Header.msg**
```
//定义数据的参考时间和参考坐标
//文件位置:std_msgs/Header.msg
uint32 seq #数据ID
time stamp #数据时间戳
string frame_id #数据的参考坐标系
```

**Echos.msg**
```
//定义超声传感器
//文件位置:自定义msg文件
Header header
uint16 front_left
uint16 front_center
uint16 front_right
uint16 rear_left
uint16 rear_center
uint16 rear_right
```

**Quaternion.msg**
```
//消息代表空间中旋转的四元数
//文件位置:geometry_msgs/Quaternion.msg
float64 x
float64 y
float64 z
float64 w
```

**Imu.msg**
```
//消息包含了从惯性原件中得到的数据，加速度为m/^2，角速度为rad/s
//如果所有的测量协方差已知，则需要全部填充进来如果只知道方差，则
//只填充协方差矩阵的对角数据即可
//位置：sensor_msgs/Imu.msg
Header header
Quaternion orientation
float64[9] orientation_covariance
Vector3 angular_velocity
float64[9] angular_velocity_covariance
Vector3 linear_acceleration
float64[] linear_acceleration_covariance
```

**LaserScan.msg**
```
//平面内的激光测距扫描数据，注意此消息类型仅仅适配激光测距设备
//如果有其他类型的测距设备(如声呐)，需要另外创建不同类型的消息
//位置：sensor_msgs/LaserScan.msg
Header header #时间戳为接收到第一束激光的时间
float32 angle_min #扫描开始时的角度(单位为rad)
float32 angle_max #扫描结束时的角度(单位为rad)
float32 angle_increment #两次测量之间的角度增量(单位为rad)
float32 time_increment #两次测量之间的时间增量(单位为s)
float32 scan_time #两次扫描之间的时间间隔(单位为s)
float32 range_min #距离最小值(m)
float32 range_max #距离最大值(m)
float32[] ranges #测距数据(m,如果数据不在最小数据和最大数据之间，则抛弃)
float32[] intensities #强度，具体单位由测量设备确定，如果仪器没有强度测量，则数组为空即可
```

**Point.msg**
```
//空间中的点的位置
//文件位置:geometry_msgs/Point.msg
float64 x
float64 y
float64 z
Pose.msg
//消息定义自由空间中的位姿信息，包括位置和指向信息
//文件位置:geometry_msgs/Pose.msg
Point position
Quaternion orientation
```

**PoseStamped.msg**
```
//定义有时空基准的位姿
//文件位置：geometry_msgs/PoseStamped.msg
Header header
Pose pose
```

**PoseWithCovariance.msg**
```
//表示空间中含有不确定性的位姿信息
//文件位置：geometry_msgs/PoseWithCovariance.msg
Pose pose
float64[36] covariance
```

**Power.msg**
```
//表示电源状态，是否开启
//文件位置：自定义msg文件
Header header
bool power
######################
bool ON = 1
bool OFF = 0
```
**Twist.msg**
```
//定义空间中物体运动的线速度和角速度
//文件位置：geometry_msgs/Twist.msg
Vector3 linear
Vector3 angular
```

**TwistWithCovariance.msg**
```
//消息定义了包含不确定性的速度量，协方差矩阵按行分别表示：
//沿x方向速度的不确定性，沿y方向速度的不确定性，沿z方向速度的不确定性
//绕x转动角速度的不确定性，绕y轴转动的角速度的不确定性，绕z轴转动的
//角速度的不确定性
//文件位置：geometry_msgs/TwistWithCovariance.msg
Twist twist
float64[36] covariance #分别表示[x; y; z; Rx; Ry; Rz]
```
**Odometry.msg**
```
//消息描述了自由空间中位置和速度的估计值
//文件位置：nav_msgs/Odometry.msg
Header header
string child_frame_id
PoseWithCovariance pose
TwistWithCovariance twist
```

# 附录2 常见srv类型

**AddTwoInts.srv**
```
//对两个整数求和，虚线前是输入量，后是返回量
//文件位置：自定义srv文件
int32 a
int32 b
---
int32 sum
```
**Empty.srv**
```
//文件位置：std_srvs/Empty.srv
//代表一个空的srv类型
---
```
**GetMap.srv**
```
//文件位置:nav_msgs/GetMap.srv
//获取地图，注意请求部分为空
---
nav_msgs/OccupancyGrid map
```
**GetPlan.srv**
```
//文件位置:nav_msgs/GetPlan.srv
//得到一条从当前位置到目标点的路径
geometry_msgs/PoseStamped start #起始点
geometry_msgs/PoseStamped goal #目标点
float32 tolerance #到达目标点的x，y方向的容错距离
---
nav_msgs/Path plan
```
**SetBool.srv**
```
//文件位置：std_srvs/SetBools.srv
bool data # 启动或者关闭硬件
---
bool success # 标示硬件是否成功运行
string message # 运行信息
```
**SetCameraInfo.srv**
```
//文件位置:sensor_msgs/SetCameraInfo.srv
//通过给定的CameraInfo相机信息，来对相机进行标定
sensor_msgs/CameraInfo camera_info #相机信息
---
bool success #如果调用成功，则返回true
string status_message #给出调用成功的细节
```
**SetMap.srv**
```
//文件位置：nav_msgs/SetMap.srv
//以初始位置为基准，设定新的地图
nav_msgs/OccupancyGrid map
geometry_msgs/PoseWithCovarianceStamped initial_pose
---
bool success
```
**TalkerListener.srv**
```
//文件位置: 自定义srv文件
---
bool success # 标示srv是否成功运行
string message # 信息，如错误信息等
```
**Trigger.srv**
```
//文件位置:std_srvs/Trigger.srv
---
bool success # 标示srv是否成功运行
string message # 信息，如错误信息等
```

# 附录3 常见action类型
**AddTwoInts.action**
```
//文件位置:自定义action文件
//表示将两个整数求和
int64 a
int64 b
---
int64 sum
---
```
**AutoDocking.action**
```
//文件位置:自定义action文件
//goal
---
//result
string text
---
//feedback
string state
string text
```
**GetMap.action**
```
//文件位置:nav_msgs/GetMap.action
//获取地图信息，响应部分为空
---
nav_msgs/OccupancyGrid map
---
//无返回部分
```
**MoveBase.action**
```
//文件位置:geometry_msgs/MoveBase.action
geometry_msgs/PoseStamped target_pose
---
---
geometry_msgs/PoseStamped base_position
```
