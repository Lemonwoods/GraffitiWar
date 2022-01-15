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
	void CalculatePosition(POINT, GMoveDot&);//���λ��
	void Launch(POINT mouse, GMoveDot& moveDot);
	bool GetWorking();
	void IsLaunch();
	void FlameRender(double deltaTime, POINT mouse, GMoveDot& moveDot,GObstacleDotArray& obstaclearry);
private:
	HDC hFlame;//�洢����ͼ���
	BITMAP bFlame;//�洢����ͼ��Ϣ
	HDC hbeforeFlame;//�洢����ͼ���
	BITMAP bbeforeFlame;//�洢����ͼ��Ϣ
	HDC hexhibition;//չʾ
	BITMAP bexhibition;//չʾ
	double storageTime=0.7;
	double sinceLastTime=0;
	bool working;
	POINT orientationpos;
};

