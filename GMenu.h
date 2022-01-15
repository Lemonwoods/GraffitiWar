#pragma once
#include"GMoveDot.h"
#include"GObstacleDotArray.h"
#include"GSpecialArray.h"
#include"GPropArray.h"
#include"GMyConsole.h"
#include"GTimer.h"

#include<Windows.h>

class GMenu
{
public:
	void Initial(GTimer&,GMoveDot&, GObstacleDotArray&, GSpecialArray&, GPropArray&,GBomb&,GFrozen&,GFlame&,GTank&,GBrush&,GShell&,GBomb&);
	void Start(GMyConsole&,HDC,BITMAP);
	void Pause(GTimer&,GMyConsole&, GMoveDot&, GObstacleDotArray&, GSpecialArray&, GPropArray&, GBomb&, GFrozen&, GFlame&, GTank&, GBrush&, GShell&, GBomb&, HDC,BITMAP);
	void End(GTimer&,GMyConsole&, GMoveDot&, GObstacleDotArray&, GSpecialArray&, GPropArray&, GBomb&, GFrozen&, GFlame&, GTank&, GBrush&, GShell&, GBomb&, HDC, BITMAP);
public:
	///////声明鼠标事件变量
	INPUT_RECORD mouseRecord;
	DWORD res;
	char pause = ' ';
	char key;
	bool gameOver = false;
};