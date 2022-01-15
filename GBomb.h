#pragma once
#include "GAnimationSprite.h"
#include"GObstacleDotArray.h"
class GBomb :
	public GAnimationSprite
{
public:
	GBomb(int tw, int th, int fps, int fram, HDC hdcD, HDC hdcS, BITMAP temp, int spe, int z);
	void Initial();
	void Working();
	void ClearPos(GObstacleDotArray&);
	bool GetWorking()const;
	void SetexplosionPoint(POINT);
	void BombUpdate(double);
	void BombRender(double, GObstacleDotArray&);
	void BombSpecialRender();
	
private:
	double duration=2;//爆炸持续时间（new）
	double sinceStart = 0;//从开始到结束时间
	int explosionredius=50;//爆炸最大半径（new）
	POINT explosionPoint;//爆炸起始点
	bool working = false;
};

