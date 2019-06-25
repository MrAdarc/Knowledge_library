#include "ros/ros.h"
#include "std_msgs/String.h"

//收到消息订阅消息后，进入消息回调函数
void chatterCallback(const std_msgs::String::ConstPtr& msg)
{
  /*##########处理部分##########*/
  //将收到的消息打印出来
  ROS_INFO("I heard: [%s]", msg->data.c_str());
  /*##########处理结束##########*/
}

int main(int argc, char **argv)
{
  /*#######订阅者的预操作#######*/
  //初始化订阅者节点
  ros::init(argc, argv, "<subscriber_name>");
  //创建节点句柄
  ros::NodeHandle nh;
  //在master中进行订阅者节点注册
  ros::Subscriber sub = nh.subscribe("<message_name>", 1000, chatterCallback);
  /*#########预操作结束#########*/

  ros::spin();

  return 0;
}
