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
	///////��ʼ����
	srand(time(0));

	////////��ʼ������̨��	
	GMyConsole console;
	if (!console.IsChangeDisplayScale())
	{
		return 0;
	}
	//////��ʼ�Ʒ���
	GTimer timer(console.hdcFro);

	//////��ʼ���˵�
	GMenu menu;

	////////��ʼ���滭��
	GDraw draw(console);

	////////��ʼ���ɻ���
	GMoveDot moveDot(50,50,6,2,console.hdcFro, draw.GetHDC(0), draw.GetBitmap(0), PLANE_SPEED, 100);
	
	////////��ʼ����Ч�������Ч��
	GSpecialArray specialArray;
	GFrozen frozen(500, 500, 1, 1, console.hdcFro, draw.GetHDC(FROZEN_POS), draw.GetBitmap(FROZEN_POS), 0, 0);
	GBomb bomb(300, 300, 3, 3, console.hdcFro, draw.GetHDC(BOMB_POS), draw.GetBitmap(BOMB_POS), 0, 100);
	GBomb shield(300, 300, 3, 3, console.hdcFro, draw.GetHDC(SHELL_BOMB_POS), draw.GetBitmap(SHELL_BOMB_POS), 0, 100);
	GTank tank(300, 300, 4, 4, console.hdcFro, draw.GetHDC(TANK_POS), draw.GetBitmap(TANK_POS), 0, 0);
	GFlame flame(80, 40, 2, 2, console.hdcFro, draw.GetHDC(FLAME_POS), draw.GetHDC(BEFORE_FLAME), draw.GetBitmap(FLAME_POS), draw.GetBitmap(BEFORE_FLAME), 15, 100);
	GBrush brush(600, GetSystemMetrics(SM_CYMIN), 1, 1, console.hdcFro, draw.GetHDC(BRUSH_POS), draw.GetBitmap(BRUSH_POS), 20, 100);
	GShell shell(70, 70, 1, 1, console.hdcFro, draw.GetHDC(SHELL_POS), draw.GetBitmap(SHELL_POS), 0, 100);

	////////��ʼ��������ˢ
	HBRUSH hBrush = CreateSolidBrush(RGB(253, 251, 239));
	SelectObject(console.hdcFro, hBrush);

	////////��ʼ����������
	moveDot.Play();

	////////��ʼ���ϰ��������
	GObstacleDotArray obstacleDotArray(console.hdcFro);

	///////��ʼ�����ߵ�����
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

	/////////��Ϸ��ʼ����
	menu.Start(console,draw.GetHDC(START_BACKGROUND),draw.GetBitmap(START_BACKGROUND));

	while (1)
	{
		Rectangle(console.hdcFro, 0, 0, console.xScreen, console.yScreen);//�����Ϸ����

		/////////��Ⱦ��Ч
		specialArray.Render(bomb, frozen,flame,tank,brush,shell,shield, moveDot.GetPropKind(), 0.01, obstacleDotArray,moveDot,console, propArray.GetCollisionPosition());
		moveDot.SetPropKind(-1);
		
		////////�Զ����������ʱ��
		moveDot.Update(0.01);
		bomb.Update(0.01);
		
		///////��Ⱦ�ϰ����
		obstacleDotArray.Render(moveDot.GetHotPoint(),0.01);

		////////��Ⱦ���ߵ�
		propArray.Render(0.01, moveDot.GetHotPoint());		
		
		/////////��Ⱦ�ɻ������������
		moveDot.DrawLine(console.GetRealMousePos().x, console.GetRealMousePos().y);
		moveDot.Render(console.GetRealMousePos().x,console.GetRealMousePos().y);		
		
		///////��Ⱦ���ְ�
		timer.Render(console.xScreen / 2 - 50, 0);
		timer.Update(0.01);

		////////�ж��Ƿ�����߷�������ײ
		if (propArray.IsAnyCrashed(moveDot.GetHotPoint(), 25))
		{
			moveDot.SetPropKind(propArray.GetMode());
		}

		///////�ж��Ƿ���Ҫ��ͣ
		if (_kbhit())
		{
			menu.key = _getch();
			if (menu.key == menu.pause)
			{
				menu.Pause(timer,console, moveDot, obstacleDotArray, specialArray, propArray, bomb, frozen, flame, tank, brush, shell,shield,draw.GetHDC(PAUSE),draw.GetBitmap(PAUSE));
			}
		}

		///////�ж���Ϸ�Ƿ���ֹ
		if (moveDot.IsGameOver(obstacleDotArray) == 1)
		{
			menu.End(timer,console, moveDot, obstacleDotArray, specialArray, propArray, bomb, frozen, flame, tank, brush, shell,shield, draw.GetHDC(END), draw.GetBitmap(END));
		}
		
		
		BitBlt(console.hdc, 0, 0,console.xScreen,console.yScreen, console.hdcFro, 0, 0, SRCCOPY);//˫���棬ͶӰ����Ļ

		Sleep(10);//////ÿһ֡�ļ��

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