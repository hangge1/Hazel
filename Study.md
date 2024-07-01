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

将依赖游戏引擎的main函数入口，封装到游戏引擎内部。

通过extern 一个CreateApplication接口，让游戏端实现这个接口，从而能够创建应用，运行！

有一点依赖倒置的感觉！







