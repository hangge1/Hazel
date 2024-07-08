## P3 设计游戏引擎

Game Engine

1、Entry Point

2、Application layer

3、Window layer

- Input
- Event

4、Renderer

5、Renderer abstract API

6、Debug support

7、Scriping language

8、memory systems

9、entity component system

10、physical

11、File、IO、VFS

12、Build system



## P4 项目设置

**vs项目设置：**

输出目录：`$(SolutionDir)bin\$(Configuration)-$(Platform)\$(ProjectName)\`

临时目录：`$(SolutionDir)bin-int\$(Configuration)-$(Platform)\$(ProjectName)\`



游戏引擎依赖别的库，采用静态链接！

游戏依赖游戏引擎采用动态链接！





## P5入口点

将依赖游戏引擎的游戏main函数入口，封装到游戏引擎内部。

通过extern一个CreateApplication接口，让引擎依赖游戏端实现的这个接口，从而在main创建并运行！

有一点依赖倒置的感觉！



## P6 日志

使用spdlog日志库！

通过子模块引入：`git submodule add https://gitee.com/roberchen/spdlog.git Hazel/vendor/spdlog`

封装自己的Log，给本身的spdlog进行包装一层。

好处：可控、统一、间接、便利、更换别的日志库容易等！



## P7 premake构建系统

为了处理不同平台的问题，vs只能在windows上！

premake相比CMake很简单，用lua编写，很方便！

关于premake的构建系统的语法：

[premake](https://premake.github.io/docs/What-Is-Premake)



通过premake构建vs2022

最后写个bat批处理，执行premake的构建

脚本非常简单：

```bat
call vendor\bin\premake\premake5.exe vs2022
PAUSE
```



## P8|P9 事件系统

每个窗口上发出的事件，经过封装后，形成自定义的事件类，然后在通知到Application



## P10预编译头

确保预编译头文件是第一个被包含的文件

premake添加如下：

```
pchheader "hzpch.h"
pchsource "Hazel/src/hzpch.cpp"
```

预编译头随着工程的扩大：使得头文件的包含简洁、而且会提高编译速度！



## P11窗口抽象和GLFW

暂且使用GLFW，它跨平台而且简洁！

如何链接github上的glfw库，到自己的项目！



通过创建WIndow接口层，增加跨平台窗口支持的灵活性

提供Platform平台相关代码，实现Windows平台下的具体窗口类！



## P12窗口事件

Window-> SendEvent->Application->Entity



这里面巧妙的实现了低耦合的Window->Application的通信：

Window提供设置回调的public接口，此接口绑定到Application的成员函数。

通过glfw绑定回调，根据不同的窗口事件，创建事件投递、通知Application执行，Application可根据自己要求捕获需要的事件！





## P13 Layers

Layer分层的目的，是为了划分事件传播的优先级。比如：UI层肯定比Game层要先响应鼠标事件等

这里分为：覆盖层和普通层

封装Layer层类

封装LayerStack类，用于管理很多层





## P14 现代OpenGL和Glad

OpenGL系列用的GLEW，这次用GLAD

Glad也是作为vendor的一类，给它写一个premake，作为一个单独的项目！





## P15 Imgui

为了引入Imgui，我们需要继承Layer，实现支持Imgui的ImGuiLayer类

同时为了支持Imgui的交互功能，我们需要移植原本的基于OpenGL实现的Renderer的代码！





## P16 Imgui事件

继承Layer，实现ImGuiLayer子类。通过OnEvent，根据事件类型，通过事件分发器分发到对应处理函数。这些处理函数就是需要移植的imgui事件处理！





>  这里准备fork原本cherno的imgui和glfw库，然后submodule add自己的库



## P19 Input轮询

提供主动查询鼠标坐标、按键是否按下的功能！

通过提供单例Input类，Input类暴露静态公共方法，公共方法调用具体平台实现的真正实现接口！使得使用者无感它的实现的存在！





## P20 按键和鼠标代码

如果要查询某个按键是否按下，必须要用到glfw的一些常量宏定义。但作为用户来说，根本没必要知道这些内容！

所以咱们必须定义一套自己的按键对应表



## P21 数学

引入glm



## P22 ImGui停靠和视口

和视频上不一样，新版本的Docking分支，imgui_impl_glfw和imgui_impl_opengl3不在example文件夹夏，在backend文件夹夏

移植docking



## P23 渲染

渲染的最终目的就是计算屏幕上每个像素的颜色！

虽然OpenGL在几乎所有平台都能用！这既是优点又是缺点！



Windows上最好的就是Direct12

IOS最好的就是Metal

linux上最好的就是Vulkan



多尝试学习不同的图形API，这样抽象才会有根据科研！





## P24 渲染架构

游戏引擎中的渲染系统，有两个方面：

**1、Render API（platform specific）**

- Render Context
- Swap Chain
- FrameBuffer
- Vertex Buffer
- Index Buffer
- Texture
- Shader
- States
- Pipelines
- Render Passes

**2、Renderer（platform agnostic）**

- 2D & 3D Renderer
- Scene Graph
- Sorting
- Culling
- Materials
- LOD
- Animation
- Camera
- VFX（粒子特效等）
- PostFX（后期处理特性）
- Other things（reflection、ambient occlusion）



## P26 静态库和警告去除





## P27 渲染上下文



P29 OpenGL着色器

P30 渲染接口

P31 顶点缓冲区布局

P32 顶点数组



>  以上都是针对OpenGL接口的抽象和封装，后面就不需要直面最原始的图形API



## P33 渲染流和提交

提供抽象的渲染API





## P34 相机原理



## P35 正交相机



### P37 TimeStep增量事件

因为每个人的cpu频率不同，所以针对按键控制的摄像头等的移动速度会不一致，咱们需要根据帧率进行调控！

### P38 模型变换

MVP变换中的M

### P39 材质系统



### P40 着色器抽象

Shader抽象类

### P41 Ref和Scope

Ref包裹shared_ptr

Score包裹unique_ptr

### P42 纹理

Texture纹理的抽象，stb_image引入

### P43 混合

Blend

### P44 着色器资产文件

从文件中读取shader代码！



### P45 着色器库

管理多个着色器的地方



### P47 相机控制器



### P48 调整尺寸



### P49 维护升级

提供script构建脚本文件夹

升级vs版本并不是想象的那么容易

优化代码目录结构























