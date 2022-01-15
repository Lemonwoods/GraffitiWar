#pragma once
#include"GProp.h"
#include<Windows.h>
#include<vector>

#define PROP_NUMBER	6

using namespace std;

class GPropArray
{
public:
	GPropArray(POINT point, short mo, HDC hdcD, HDC hdcS, BITMAP tem, int spe, int z);
	~GPropArray();
	void SetVisibleProp(POINT positionPos);
	bool Update(double);
	bool IsAnyCrashed(POINT, int);
	void Render(double,POINT);
	void SetMode(int, int);
	void SetCollisionPosition( int);
	short GetMode();
	POINT& GetCollisionPosition();
	void SetHdcSprite(int, HDC);
	void Initial();
	void SetLast(int);
	int GetLast()const;
private:
	vector<GProp*> prop;
	double sinceLastTime=0;
	double interval = 3;
	POINT collisionPosition;
	short mode=-1;
	int last = -1;
};