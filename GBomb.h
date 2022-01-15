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
	double duration=2;//��ը����ʱ�䣨new��
	double sinceStart = 0;//�ӿ�ʼ������ʱ��
	int explosionredius=50;//��ը���뾶��new��
	POINT explosionPoint;//��ը��ʼ��
	bool working = false;
};

