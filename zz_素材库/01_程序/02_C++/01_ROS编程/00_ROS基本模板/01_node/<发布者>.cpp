#include "ros/ros.h"
#include "std_msgs/String.h"

int main(int argc, char **argv)
{
  /*#######发布者的预操作#######*/
  //初始化发布者节点
  ros::init(argc, argv, "<Publisher_name>");
  //初始化节点句柄
  ros::NodeHandle nh;
  //向Master注册发布者节点信息
  ros::Publisher chatter_pub = nh.advertise<std_msgs::String>("chatter", 1000);
  /*#########预操作结束#########*/

  /*#######发布者发布消息#######*/
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
  /*#######发布者发布消息#######*/
  return 0;
}
