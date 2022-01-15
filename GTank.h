#pragma once
#include"GAnimationSprite.h"
#include"GMoveDot.h"
#include<Windows.h>

class GTank :public GAnimationSprite
{
public:
	GTank(int tw, int th, int fps, int fram, HDC hdcD, HDC hdcS, BITMAP bitmap, int spe, int z);
	~GTank();
	void Render(int,int,double,GMoveDot&);
	void UpdatePen(double);
	void Update(double,GMoveDot&);
	void Working();
	bool GetWorking()const;
	void SetBeenTank(bool);
	bool GetBeenTank()const;
	void SetKAndB(GMoveDot&);
	double GetK()const;
	double GetB()const;
	int GetHalfPenWidth()const;
	void Test();
	bool GetDxIsZero()const;
	void Initial();
private:
	HPEN hPen[3];
	HPEN hPenOld;

	int penWidth = 40;
	double tankTime = 3;
	double penTime = 0.3;
	double sinceStart = 0;
	double sinceLastPen = 0;
	bool working = false;
	int penNumber = 0;
	bool beenTank = false;

	int dx;
	int dy;
	double k;
	double b;
	int scale;
	POINT linePos;

};