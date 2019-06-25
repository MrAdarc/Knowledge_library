#include "ros/ros.h"
#include "ros_tutorials_topic/MsgTutorial.h"
#include "ros_tutorials_topic/MsgTutorial2.h"


class SubscribeAndPublish
{
public:
      SubscribeAndPublish()
    {
      /*##########节点预操作#########*/
      //向Master注册节点发布者信息
      pub = n.advertise<ros_tutorials_topic::MsgTutorial2>("<message_name1>", 100);
      //向Master注册节点订阅者注册
      sub = n.subscribe("<message_name2>", 100, &SubscribeAndPublish::msgCallback, this);
      /*#########预操作结束#########*/
    }

  //收到消息订阅消息后，进入消息回调函数
  void msgCallback(const ros_tutorials_topic::MsgTutorial::ConstPtr& msg)
  {
    /*##########处理部分##########*/
    //将收到的消息打印出来
    ROS_INFO("recieve msg = %d", <message_name2_member>);
    /*##########处理结束##########*/
  }

private:
  //创建节点句柄
  ros::NodeHandle n;
  //创建节点发布者句柄
  ros::Publisher pub;
  //创建节点订阅者句柄
  ros::Subscriber sub;
};

int main(int argc, char **argv)
{
  /*##########节点预操作#########*/
  //初始化发布者节点
  ros::init(argc, argv, "<subscriber_publisher_name>");

  SubscribeAndPublish SAPObject;
  /*#########预操作结束#########*/

  ros::spin();
  return 0;
}
