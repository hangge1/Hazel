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

