# GraffitiWar

详细的项目介绍可以阅读[Graffiti War项目介绍.pdf](https://github.com/Lemonwoods/GraffitiWar/blob/master/Graffiti%20War%E9%A1%B9%E7%9B%AE%E4%BB%8B%E7%BB%8D.pdf)

## 项目介绍

我们想制作一款有别于飞机大战，跑酷等传统的控制台游戏。于是我们从一款手机游戏Charles的游戏形式中获得灵感，开始创作Graffiti War。Graffiti War 完全基于控制台开发且不使用任何贴图，但是其精美的UI，多样的特效与动画不同于人们印象中传统的控制台程序，让人耳目一新。其操作简单，但是可玩度高，同时富有趣味。



## 安装

程序的运行依赖于`windows.h`库，可以直接选择项目中的[Graffiti War.exe](https://github.com/Lemonwoods/GraffitiWar/blob/master/Graffiti%20War.exe)运行程序。

运行前请确保电脑的显示缩放比例为100%，其他比例下程序无法正常运行



## 核心技术：

### 双缓冲技术

避免在帧率过高的情况下出现闪屏的情况

### 搭建简单2D游戏框架

* GSprite：实现对于图像的各种操作
* GAnimationSprite：实现了动画的播放
* GDraw：实现图像资源管理和图像绘制
* GMenu：实现了功能完备的菜单

### 核心算法

减小直线运动误差算法根据动点计算角度算法碰撞检测

### 绘图技术

仅使用`windows.h`的 api绘图函数绘制了精美的UI界面及动画特效





