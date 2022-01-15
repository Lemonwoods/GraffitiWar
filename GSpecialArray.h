#pragma once

#include"GFrozen.h"
#include"GObstacleDotArray.h"
#include"GMoveDot.h"
#include"GBomb.h"
#include"GTank.h"
#include"GFrozen.h"
#include"GBrush.h"
#include"GFlame.h"
#include"GMyConsole.h"
#include"GShell.h"
#include<Windows.h>

#define SPECIAL_NUMBER 7
#define BOMB 0
#define FROZEN 1
#define FLAME 2
#define TANK 3
#define BRUSH 4
#define SHELL 5

class GSpecialArray
{
public:
	GSpecialArray();
	void Render(GBomb&,GFrozen&,GFlame&,GTank&,GBrush&,GShell&,GBomb&,short,double,GObstacleDotArray&,GMoveDot&,GMyConsole&,POINT&);
	void Initial();
private:
	bool crashed[SPECIAL_NUMBER];
};
