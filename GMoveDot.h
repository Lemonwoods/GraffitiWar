#pragma once
#include"GSprite.h"
#include"GAnimationSprite.h"
#include<Windows.h>
#include"GProp.h"
#include"GObstacleDotArray.h"

#define PLANE_SPEED 20

class GMoveDot :public GAnimationSprite
{
public:
	GMoveDot(int tw, int th, int fps, int fram, HDC hdcD, HDC hdcS, BITMAP temp, int spe, int z);
	~GMoveDot();
	void SethPen(COLORREF, int);
	void Render(int, int);
	void SetPropKind(short);
	short GetPropKind()const;
	short IsGameOver(GObstacleDotArray& obstacle);//判断游戏是否结束(new) 并且通过返回值判断 0没碰到 1结束 2有保护工具
	void SetShield(bool);//(new)
	bool GetShield();//(new)
	void DrawLine(int,int);
	void SetLineState(bool);
	void Initial();
private:
	bool IsCrashed = false;//是否发生了碰撞
	int redius=7;//半径

	HPEN hPen;
	HPEN hPenOld;
	bool HasShield=false;//是否有保护盾(new)
	short propKind=-1;//道具的种类

	bool lineState = true;
};