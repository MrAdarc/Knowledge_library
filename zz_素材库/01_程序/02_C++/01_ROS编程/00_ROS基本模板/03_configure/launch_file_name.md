# launch文件的编写规则
## 1、launch文件中需要<launch>在第一行作为开头，并需要</launch>在最后一行作为结尾，即：
```
<launch>
    <launch_content>
</launch>
```
## 2、launch内部包含group和node两个部分：
###（1）group部分
1）一个组相当于一个运行空间，
2）当launch文件只运行一个运行空间，则不需要该部分
3）同名节点在不同运行空间，则不会发生冲突
4）在一个组中，添加相关的节点信息，则可以在该运行空间中运行该节点。
5）格式
```
<group ns="<group_name>">  //添加组名称，<group_name>指代组名
    <relation_node>        //组当中运行的节点，<relation_node>指代组中包含的节点内容
</group>                   //组结束标志

```
###（2）node部分

1）node可分为两部分进行运行，在组当中的为私有部分，在组外为公有部分，并且相互之间可以进行通讯
2）格式：
```
私有部分：
    <node pkg="<node_package>" name="<node_name>" type="<node_type>"/>
    //<node_package>为节点所在的包名，<node_name>为在本次运行过程中的名称，<node_type>为节点的可执行文件名称
公有部分：
    <node pkg="<node_package>" name="<node_name>" type="<node_type>">
    //<node_package>为节点所在的包名，<node_name>为在本次运行过程中的名称，<node_type>为节点的可执行文件名称
        <remap from="<message_pipe>" to="<message_name>"/>
	//<message_pipe>为消息通道，同相应节点有关系，<message_name>为传递消息的名称
    </node>
```

示例：
```
<launch>

  <group ns="turtlesim1">
    <node pkg="turtlesim" name="sim" type="turtlesim_node"/>
  </group>

  <group ns="turtlesim2">
    <node pkg="turtlesim" name="sim" type="turtlesim_node"/>
  </group>

  <node pkg="turtlesim" name="mimic" type="mimic">
    <remap from="input" to="turtlesim1/turtle1"/>
    <remap from="output" to="turtlesim2/turtle1"/>
  </node>

</launch>
```
