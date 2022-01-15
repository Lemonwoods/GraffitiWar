#pragma once
#include"GObstacleDot.h"
#include<vector>
#include<iostream>
using namespace std;
#define OBSTACLE_NUMBER 500
class GObstacleDotArray
{
public:
	GObstacleDotArray(HDC hdc);
	void SetVisibleObstacle(POINT positionPos);
	bool Update(double deltaTime);
	bool IsGrameOverAll(POINT positionPos, int redius);//判断所有点是否发生碰撞
	void IsAnyCrashed(POINT positionPos, int redius);//new
	void IsAnyCrashed(RECT&);//new(传入x轴坐标值)
	void Render(POINT positionPos, double deltaTime);//(new)
	void SetSpeed(int);
	void SetBlue();//new
	void SetRed();
	void SetRandColor();//new
	void IsCrashWithLine(double,double,int,POINT,POINT);//new
	void IsCrashWithVerticalLine(int, int,POINT,POINT);//new
	void UpdateRect(int,int);//new
	void SetMouseRect(POINT);//new
	int GetMouseRect()const;
	int GetPosRect(POINT);//new
	void Initial();
	~GObstacleDotArray();
private:
	vector<GObstacleDot*> obstacle;
	double sinceLastTime = 0;
	double interval = 2;
	RECT rect[4];
	int mouseRect = 1;
	int minuseNumber = 7;
	int plusNumber = 1;

};

