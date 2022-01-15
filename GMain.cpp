#include<iostream>
#include<Windows.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>

#include"GAnimationSprite.h"
#include"GMyConsole.h"
#include"GMoveDot.h"
#include"GObstacleDot.h"
#include"GMenu.h"
#include"GSprite.h"
#include"GtagResDesc.h"
#include"GMoveDot.h"
#include"GDraw.h"
#include"GObstacleDotArray.h"
#include"GPropArray.h"
#include"GProp.h"
#include"GSpecialArray.h"
#include"GBomb.h"
#include"GFrozen.h"
#include"GFlame.h"
#include"GTank.h"
#include"GBomb.h"
#include"GShell.h"
#include"GTimer.h"

using namespace std;

extern "C" WINBASEAPI HWND WINAPI GetConsoleWindow();

int main()
{	
	///////初始种子
	srand(time(0));

	////////初始化控制台类	
	GMyConsole console;
	if (!console.IsChangeDisplayScale())
	{
		return 0;
	}
	//////初始计分器
	GTimer timer(console.hdcFro);

	//////初始化菜单
	GMenu menu;

	////////初始化绘画类
	GDraw draw(console);

	////////初始化飞机类
	GMoveDot moveDot(50,50,6,2,console.hdcFro, draw.GetHDC(0), draw.GetBitmap(0), PLANE_SPEED, 100);
	
	////////初始化特效组类和特效类
	GSpecialArray specialArray;
	GFrozen frozen(500, 500, 1, 1, console.hdcFro, draw.GetHDC(FROZEN_POS), draw.GetBitmap(FROZEN_POS), 0, 0);
	GBomb bomb(300, 300, 3, 3, console.hdcFro, draw.GetHDC(BOMB_POS), draw.GetBitmap(BOMB_POS), 0, 100);
	GBomb shield(300, 300, 3, 3, console.hdcFro, draw.GetHDC(SHELL_BOMB_POS), draw.GetBitmap(SHELL_BOMB_POS), 0, 100);
	GTank tank(300, 300, 4, 4, console.hdcFro, draw.GetHDC(TANK_POS), draw.GetBitmap(TANK_POS), 0, 0);
	GFlame flame(80, 40, 2, 2, console.hdcFro, draw.GetHDC(FLAME_POS), draw.GetHDC(BEFORE_FLAME), draw.GetBitmap(FLAME_POS), draw.GetBitmap(BEFORE_FLAME), 15, 100);
	GBrush brush(600, GetSystemMetrics(SM_CYMIN), 1, 1, console.hdcFro, draw.GetHDC(BRUSH_POS), draw.GetBitmap(BRUSH_POS), 20, 100);
	GShell shell(70, 70, 1, 1, console.hdcFro, draw.GetHDC(SHELL_POS), draw.GetBitmap(SHELL_POS), 0, 100);

	////////初始化背景笔刷
	HBRUSH hBrush = CreateSolidBrush(RGB(253, 251, 239));
	SelectObject(console.hdcFro, hBrush);

	////////初始化动画精灵
	moveDot.Play();

	////////初始化障碍物点组类
	GObstacleDotArray obstacleDotArray(console.hdcFro);

	///////初始化道具点组类
	GPropArray propArray(moveDot.GetHotPoint(),0, console.hdcFro, draw.GetHDC(BOMB_PROP_POS), draw.GetBitmap(BOMB_PROP_POS), 0, 50);

	propArray.SetHdcSprite(1, draw.GetHDC(FROZEN_PROP_POS));
	propArray.SetMode(1,FROZEN);
	propArray.SetHdcSprite(2, draw.GetHDC(FLAME_PROP_POS));
	propArray.SetMode(2, FLAME);
	propArray.SetHdcSprite(3, draw.GetHDC(TANK_PROP_POS));
	propArray.SetMode(3, TANK);
	propArray.SetHdcSprite(4, draw.GetHDC(BRUSH_PROP_POS));
	propArray.SetMode(4, BRUSH);
	propArray.SetHdcSprite(5, draw.GetHDC(SHELL_PROP_POS));
	propArray.SetMode(5, SHELL);

	/////////游戏开始界面
	menu.Start(console,draw.GetHDC(START_BACKGROUND),draw.GetBitmap(START_BACKGROUND));

	while (1)
	{
		Rectangle(console.hdcFro, 0, 0, console.xScreen, console.yScreen);//填充游戏背景

		/////////渲染特效
		specialArray.Render(bomb, frozen,flame,tank,brush,shell,shield, moveDot.GetPropKind(), 0.01, obstacleDotArray,moveDot,console, propArray.GetCollisionPosition());
		moveDot.SetPropKind(-1);
		
		////////对动画精灵更新时间
		moveDot.Update(0.01);
		bomb.Update(0.01);
		
		///////渲染障碍物点
		obstacleDotArray.Render(moveDot.GetHotPoint(),0.01);

		////////渲染道具点
		propArray.Render(0.01, moveDot.GetHotPoint());		
		
		/////////渲染飞机和与鼠标连线
		moveDot.DrawLine(console.GetRealMousePos().x, console.GetRealMousePos().y);
		moveDot.Render(console.GetRealMousePos().x,console.GetRealMousePos().y);		
		
		///////渲染积分板
		timer.Render(console.xScreen / 2 - 50, 0);
		timer.Update(0.01);

		////////判断是否与道具发生了碰撞
		if (propArray.IsAnyCrashed(moveDot.GetHotPoint(), 25))
		{
			moveDot.SetPropKind(propArray.GetMode());
		}

		///////判断是否需要暂停
		if (_kbhit())
		{
			menu.key = _getch();
			if (menu.key == menu.pause)
			{
				menu.Pause(timer,console, moveDot, obstacleDotArray, specialArray, propArray, bomb, frozen, flame, tank, brush, shell,shield,draw.GetHDC(PAUSE),draw.GetBitmap(PAUSE));
			}
		}

		///////判断游戏是否中止
		if (moveDot.IsGameOver(obstacleDotArray) == 1)
		{
			menu.End(timer,console, moveDot, obstacleDotArray, specialArray, propArray, bomb, frozen, flame, tank, brush, shell,shield, draw.GetHDC(END), draw.GetBitmap(END));
		}
		
		
		BitBlt(console.hdc, 0, 0,console.xScreen,console.yScreen, console.hdcFro, 0, 0, SRCCOPY);//双缓存，投影到屏幕

		Sleep(10);//////每一帧的间隔

		if (menu.gameOver)
		{
			break;
		}
	}
	SetStretchBltMode(console.hdc, COLORONCOLOR);
	StretchBlt(console.hdc, 0, 0, console.xScreen, 9 * console.xScreen / 16,draw.GetHDC(END), 0, 0, 1920, 1080, SRCCOPY);
	DeleteObject(hBrush);
	return 0;
}