<font size=6><center>C++基础部分</center></font>

[TOC]

# 说明
&#8195;&#8195;针对C++的内容，大致分为三个部分进行整理，分别如下：
1. 基础部分
  &#8195;&#8195;指出C++编程的相关知识有哪些，包括语法的讲解、相关概念的介绍;
2. 进阶部分
  &#8195;&#8195;从内存分配的角度，来说明不同概念在计算机中存在的形式以及程序的运行的过程，以规范变量定义的使用;
3. 高阶部分
  &#8195;&#8195;从系统工程的角度，来指出如何对相关概念进行使用，使得系统的运行效率最高，消耗资源最小;

&#8195;&#8195;本文档作为C++知识的基础部分，同另外两个部分一同整理总结C++编程中的一系列知识与问题，以保证开发的效率与代码的质量;
&#8195;&#8195;在对软件进行的开发的过程中，主要从代码的可读性、执行效率、消耗资源、健壮性等几个方面进行考虑，整体体现软件的性能，这对三个部分的内容都有着特定的要求;在对不同的性能分析上，应建立相应的评判标准，使能够对代码进行针对性的优化。

**注意**
&#8195;&#8195;在对相关知识进行整理的过程中，需要表明内容的出处，一方面是为了保证知识内容有证可查，即知识、消息的可靠性、另一方面在于尊重相关作者的著作权，即对学问保持严谨、尊重的态度。
&#8195;&#8195;在文中引用，使用“>”标记位置，并在文件结尾使用“$^{[<序号>]}$”，同参考链接中为同一序号的为信息源处。
&#8195;&#8195;填写源文件信息，按照文件引用的一般格式如下：
```
[<序号>] <作者>.<标题>[<源信息类型>].<发布平台>.<日期>.<引用日期>
```
&#8195;&#8195;本文暂时作为最基础的模板，对于C++的相关文件操作来说，相关知识还不充分，有需要查询资料的地方，则使用“**补充**”的方式进行提示，以便提醒在后续补充相关知识。

# 1 C++引论
&#8195;&#8195;C++是一种中级语言$^{[1]}$，对C语言的内容进行进一步的完善和扩充，是一种面向对象的编程语言，它可以运行在多个平台上，如windows、mac以及各种unix版本。
## 1.1 C++简介
&#8195;&#8195;C++ 是一种静态类型的、编译式的、通用的、大小写敏感的、不规则的编程语言，支持过程化编程、面向对象编程和泛型编程。

&#8195;&#8195;C++ 被认为是一种中级语言，它综合了高级语言和低级语言的特点。

&#8195;&#8195;C++ 是由 Bjarne Stroustrup 于 1979 年在新泽西州美利山贝尔实验室开始设计开发的。C++ 进一步扩充和完善了 C 语言，最初命名为带类的C，后来在 1983 年更名为 C++。

&#8195;&#8195;C++ 是 C 的一个超集，事实上，任何合法的 C 程序都是合法的 C++ 程序。

注意：使用静态类型的编程语言是在编译时执行类型检查，而不是在运行时执行类型检查。

### 1.1.1 面向对象特性
&#8195;&#8195;C++ 完全支持面向对象的程序设计，包括面向对象开发的四大特性：

封装
抽象
继承
多态
标准库

### 1.1.2 C++程序的组成
&#8195;&#8195;标准的 C++ 由三个重要部分组成：
- 核心语言，提供了所有构件块，包括变量、数据类型和常量，等等。
- C++ 标准库，提供了大量的函数，用于操作文件、字符串等。
- 标准模板库（STL），提供了大量的方法，用于操作数据结构等。

### 1.1.3 ANSI 标准
&#8195;&#8195;ANSI 标准是为了确保 C++ 的便携性 —— 您所编写的代码在 Mac、UNIX、Windows、Alpha 计算机上都能通过编译。

&#8195;&#8195;由于 ANSI 标准已稳定使用了很长的时间，所有主要的 C++ 编译器的制造商都支持 ANSI 标准。

### 1.1.4 标准化
|发布时间	|文档	|通称	|备注|
|:-:|:-:|:-:|:-:|
|2015	|ISO/IEC TS 19570:2015	|-	|用于并行计算的扩展|
|2015	|ISO/IEC TS 18822:2015	|-	|文件系统|
|2014	|ISO/IEC 14882:2014	|C++14	|第四个C++标准|
|2011	|ISO/IEC TR 24733:2011	|-	|十进制浮点数扩展|
|2011	|ISO/IEC 14882:2011	|C++11	|第三个C++标准|
|2010	|ISO/IEC TR 29124:2010	|-	|数学函数扩展|
|2007	|ISO/IEC TR 19768:2007	|C++TR1	|C++技术报告：库扩展|
|2006	|ISO/IEC TR 18015:2006	|-	C++性能技术报告|
|2003	|ISO/IEC 14882:2003	|C++03	|第二个C++标准|
1998	ISO/IEC 14882:1998	|C++98	|第一个C++标准|
<font size=2>本节内容来源于参考链接[2]</font>
## 1.2 C++的编译与执行
&#8195;&#8195;C++程序一般是以“<文件名>.cpp”的名称形式进行命名的，在不同的操作系统下有着不同的编译执行方式。
### 1.1.1 Linux环境下的编译
&#8195;&#8195;在Linux系统下，为了方便进行操作，推荐使用终端下运行。例如：对于C++文件，helloworld.cpp，其内容如下：
```
#include <iostream>
using namespace std;
int main()
{
  cout << "Hello World!" << endl;
  return 0;
}
```
<font size=2>程序来源于参考链接[1]</font>
&#8195;&#8195;编译过程是在GCC编译器下进行的，一般情况下，Linux自带GCC编译器，可通过如下命令查看GCC版本
```
$ g++ -v
```
&#8195;&#8195;文件的编译与运行过程如下：

(1)编译，crtl+alt+T，启动终端，并进入文件所在的目录，执行下列命令进行编译
```
$ g++ helloworld.cpp -o helloworld
```
(2)运行，编译后，得到文件名为”helloworld”的二进制文件，使用下述命令进行执行
```
$./helloworld
```
**补充**
&#8195;&#8195;对于C++程序的编译，在linux系统下主要使用GCC编译器进行实现的，可查阅相关资料，以了解其他的操作参数。
# 2 C++基础语法
## 2.1 C++中的基本概念
## 2.2 C++程序结构

# 3 控制语句
# 4 结构与操作
# 5 面向对象
# 6 文件流
# 7 异常处理
# 8 动态内存
# 9 命名空间
# 10 模板
# 11 预处理器
# 12 信号处理
# 13 多线程
# 14 Web编程
# 15 资源库

# 参考链接
[1] 菜鸟教程.C++教程:https://www.runoob.com/cplusplus/cpp-tutorial.html [EB]菜鸟教程.2013.2019.07.09
[2] 菜鸟教程.C++简介:https://www.runoob.com/cplusplus/cpp-intro.html[EB]菜鸟教程.2013.2019.07.10
