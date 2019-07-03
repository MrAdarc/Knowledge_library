# 机器人开发

&emsp;&emsp;本仓库用于整理机器人开发的相关知识，以便于能够快速地进行的机器人开发相关工作。整个内容按照具体情况进行命名，在每次进行学习与工作后即使进行更新，本仓库的结构主要包含以下几个部分：
```
00_规划
   |_00_项目管理
01_理论
02_硬件
   |_01_RCL
   |_02_晶体管
   |_03_传感器
   |    |_01_激光传感器
   |    |_02_摄像头
   |    |_03_陀螺仪
   |    |_04_卫星定位
   |    |_05_声呐
   |    |_06_微波雷达
   |_04_电机
   |_05_其他器件
03_软件
   |_01_操作系统
   |_02_开发环境
        |_01_ROS
             |_01_ROS基本教程
             |_02_ROS相关工具
                  |_01_RVIZ
04_机械
zz_素材库
   |_01_程序
   |    |_00_markdown
   |    |    |_00_基本语法
   |    |    |_01_markdown_preview_enchanced插件扩展语法
   |    |    |_02
   |    |_01_C
   |    |_02_C++
   |         |_00_基本语法
   |         |_01_ROS编程
   |              |_00_ROS基本模板
   |              |_01_基础编程(创建节点、话题通讯、服务通讯、动作通讯)
   |              |_02_RVIZ编程()
   |_02_模型
```


|主题|主内容|文件|参考链接|更新日期|
|---|---|---|---|---|
|软件|ROS基础部分|01_ROS开发环境搭建|[ROS官网](https://wiki.ros.org/kinetic/Installation/Ubuntu)</br>|2019/06/09|
|软件|ROS工具部分|01_RVIZ环境搭建|[ROS机器人导航仿真](https://www.cnblogs.com/qiangzi0221/p/7941896.html)|2019/06/09|
|硬件|集成设备|01_光学雷达||
|硬件|集成设备|02_惯性导航||
|理论|计算机|01_卷积神经网络|
|理论|计算机|02_增强学习|
|理论|信号与数据处理|01_卷积神经网络对信号的处理||
|应用|无人驾驶|00_无人驾驶|
|应用|无人驾驶|01_感知系统|
|应用|无人驾驶|02_决策系统|
|应用|无人驾驶|03_控制系统|
|程序模型|ROS相关程序|创建通讯|



# 相关官方网站汇总
[Qt插件相关](https://ros-qtc-plugin.readthedocs.io/en/latest/index.html#)</br>
[ROS官网](http://wiki.ros.org/)</br>
[RVIZ官网教程](http://wiki.ros.org/rviz)</br>

说明：由于部分网站资料公司网站无法访问，例如ros、rviz的官方教程，这里将官方教程整理为PDF文件进行上传，存在 “00_相关资料 -> 00_官网”文件夹下

```python {cmd="/usr/local/bin/python3"}
print("这个将会运行 python3 程序")
```

```gnuplot {cmd=true output="html"}
set terminal svg
set title "Simple Plots" font ",20"
set key left box
set samples 50
set style data points
plot [-10:10] sin(x),atan(x),cos(atan(x))
```
Librviz:
IncorporatingRVizintoaCustomGUI

RvizinStereo
