#include"GMenu.h"
#include<Windows.h>

#pragma comment(lib,"msimg32.lib")

void GMenu::Initial(GTimer&timer,GMoveDot& moveDot, GObstacleDotArray&obstacleDotArray, GSpecialArray&specialArray, GPropArray& propArray, GBomb&bomb, GFrozen&frozen, GFlame&flame, GTank&tank, GBrush&brush, GShell&shell,GBomb&shield)
{
	moveDot.Initial();
	obstacleDotArray.Initial();
	specialArray.Initial();
	propArray.Initial();
	timer.Initial();
	
	/////特效类初始化
	bomb.Initial();
	frozen.Initial(obstacleDotArray);
	flame.Initial();
	tank.Initial();
	brush.Initial();
	shell.Initial();
	shield.Initial();
}
void GMenu::Start(GMyConsole&console,HDC hdc,BITMAP bitmap)
{	
	FlushConsoleInputBuffer(console.hIN);
	SetStretchBltMode(console.hdc, COLORONCOLOR);
	StretchBlt(console.hdc, 0, 0, console.xScreen, 9*console.xScreen/16, hdc, 0, 0, 1920, 1080, SRCCOPY);
	while (1)
	{		
		ReadConsoleInput(console.hIN, &mouseRecord, 1,&res);
		if (mouseRecord.EventType==MOUSE_EVENT)
		{
			//单击鼠标左键
			if (mouseRecord.Event.MouseEvent.dwButtonState==FROM_LEFT_1ST_BUTTON_PRESSED)
			{
				break; 
			}
		}
	}
}
void GMenu::Pause(GTimer&timer,GMyConsole& console, GMoveDot& moveDot, GObstacleDotArray& obstacleDotArray, GSpecialArray& specialArray, GPropArray& propArray, GBomb& bomb, GFrozen& frozen, GFlame& flame, GTank& tank, GBrush& brush, GShell& shell, GBomb& shield,HDC hdc,BITMAP bitmap)
{
	FlushConsoleInputBuffer(console.hIN);
	TransparentBlt(console.hdcFro, 0.5 * console.xScreen - 443, 0.5 * console.yScreen - 453, 886, 906, hdc, 0, 0, 886, 906, RGB(0,0,0));
	BitBlt(console.hdc, 0, 0, console.xScreen, console.yScreen, console.hdcFro, 0, 0, SRCCOPY);
	while (1)
	{
		ReadConsoleInput(console.hIN, &mouseRecord, 1, &res);
		if (mouseRecord.EventType == MOUSE_EVENT)
		{
		////对按键判断
			if (mouseRecord.Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
			{
				break;
			}
			if (mouseRecord.Event.MouseEvent.dwButtonState == RIGHTMOST_BUTTON_PRESSED)
			{
				Initial(timer,moveDot, obstacleDotArray, specialArray, propArray,bomb,frozen,flame,tank,brush,shell,shield);
				break;
			}			
		}
	}
}
void GMenu::End(GTimer&timer,GMyConsole&console, GMoveDot& moveDot, GObstacleDotArray& obstacleDotArray, GSpecialArray& specialArray, GPropArray& propArray, GBomb& bomb, GFrozen& frozen, GFlame& flame, GTank& tank, GBrush& brush, GShell& shell, GBomb& shield,HDC hdc,BITMAP bitmap)
{
	obstacleDotArray.SetRed();
	obstacleDotArray.SetSpeed(0);
	obstacleDotArray.Render(moveDot.GetHotPoint(), 0.01);
	BitBlt(console.hdc, 0, 0, console.xScreen, console.yScreen, console.hdcFro, 0, 0, SRCCOPY);
	Sleep(700);
	FlushConsoleInputBuffer(console.hIN);
	SetStretchBltMode(console.hdc, COLORONCOLOR);
	StretchBlt(console.hdc, 0, 0, console.xScreen, 9 * console.xScreen / 16, hdc, 0, 0, 1920, 1080, SRCCOPY);
	while (1)
	{
		ReadConsoleInput(console.hIN, &mouseRecord, 1, &res);
		if (mouseRecord.EventType == MOUSE_EVENT)
		{
			if (mouseRecord.Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
			{
				Initial(timer,moveDot, obstacleDotArray, specialArray, propArray, bomb, frozen, flame, tank, brush, shell,shield);
				break;
			}
			if (mouseRecord.Event.MouseEvent.dwButtonState == RIGHTMOST_BUTTON_PRESSED)
			{
				gameOver = true;
				break;
			}
		}
	}
}