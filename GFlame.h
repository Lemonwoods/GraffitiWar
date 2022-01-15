#pragma once
#include "GAnimationSprite.h"
#include"GObstacleDotArray.h"
#include"GMoveDot.h"
class GFlame :
	public GAnimationSprite
{
public:
	GFlame(int tw, int th, int fps, int fram, HDC hdcD, HDC hdcS, HDC hbeforeflame,BITMAP temp, BITMAP bbeforeflame,int spe, int z);
	void Initial();
	void ClearObstacleDot(GObstacleDotArray &obstaclearry);
	void Storge(double deltaTime, POINT mouse, GMoveDot& moveDot);
	void CalculatePosition(POINT, GMoveDot&);//获得位置
	void Launch(POINT mouse, GMoveDot& moveDot);
	bool GetWorking();
	void IsLaunch();
	void FlameRender(double deltaTime, POINT mouse, GMoveDot& moveDot,GObstacleDotArray& obstaclearry);
private:
	HDC hFlame;//存储蓄力图句柄
	BITMAP bFlame;//存储蓄力图信息
	HDC hbeforeFlame;//存储蓄力图句柄
	BITMAP bbeforeFlame;//存储蓄力图信息
	HDC hexhibition;//展示
	BITMAP bexhibition;//展示
	double storageTime=0.7;
	double sinceLastTime=0;
	bool working;
	POINT orientationpos;
};

