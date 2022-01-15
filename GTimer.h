#pragma once
#include<Windows.h>
#include"strsafe.h"
class GTimer
{
public:
	GTimer(HDC);
	void Initial();
	void Update(double deltaTime);
	void Render(int x, int y);
private:
	HDC hdcDest;
	HFONT hFont;
	double time;
	int score;
	int digit;
};

