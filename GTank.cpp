#include"GTank.h"
#include<Windows.h>

GTank::GTank(int tw, int th, int fps, int fram, HDC hdcD, HDC hdcS, BITMAP bitmap, int spe, int z)
	:GAnimationSprite(tw, th, fps, fram, hdcD, hdcS, bitmap, spe, z)
{
	hPen[0] = CreatePen(PS_SOLID, penWidth, RGB(185,227,217));
	hPen[1] = CreatePen(PS_SOLID, penWidth, RGB(255,66,93));
	hPen[2] = CreatePen(PS_SOLID, penWidth, RGB(147,224,255));
}
GTank::~GTank()
{
	DeleteObject(hPen[0]);
	DeleteObject(hPen[1]);
	DeleteObject(hPen[2]);
	DeleteObject(hPenOld);
}
void GTank::Working()
{
	working = true;
}
bool GTank::GetWorking()const
{
	return working;
}
void GTank::Render(int x, int y,double deltaTime,GMoveDot&moveDot)
{
	dx = x - moveDot.GetHotPoint().x;
	dy = y - moveDot.GetHotPoint().y;
	if (dx != 0)
		scale = GetSystemMetrics(SM_CXSCREEN) / dx;
	else
		scale = 1000;
	if (scale < 0)
		scale = -scale;
	linePos.x =x + dx * scale;
	linePos.y =y + dy * scale;

	UpdatePen(deltaTime);
	hPenOld = (HPEN)SelectObject(hdcDest, hPen[penNumber]);
	MoveToEx(hdcDest, moveDot.GetHotPoint().x, moveDot.GetHotPoint().y,NULL);
	LineTo(hdcDest, linePos.x, linePos.y);
	SelectObject(hdcDest, hPenOld);

	RotateAroundHotPoint(x, y);
	GAnimationSprite::Render(currentPos.x - hotPoint.x, currentPos.y - hotPoint.y);
	ReSetTransformWorld();
	///////äÖÈ¾Î»Í¼
}
void GTank::UpdatePen(double deltaTime)
{
	if (sinceLastPen >= penTime)
	{
		sinceLastPen = 0;
		penNumber++;
		if (penNumber >= 3)
			penNumber = 0;
	}
	else
	{
		sinceLastPen += deltaTime;
	}
}
void GTank::Update(double deltaTime,GMoveDot&moveDot)
{
	if (sinceStart >= tankTime)
	{
		sinceStart = 0;
		working = false;
		beenTank = false;
		moveDot.SetSpeed(PLANE_SPEED);
		moveDot.SetLineState(true);
	}
	else
	{
		sinceStart += deltaTime;
	}
}
void GTank::SetBeenTank(bool b)
{
	beenTank = b;
}
bool GTank::GetBeenTank()const
{
	return beenTank;
}
void GTank::SetKAndB(GMoveDot& moveDot)
{
	if (dx == 0)
	{
		return;
	}
	k = (double)dy / dx;
	b = moveDot.GetHotPoint().y - k * moveDot.GetHotPoint().x;
}
double GTank::GetK()const
{
	return k;
}
double GTank::GetB()const
{
	return b;
}
int GTank::GetHalfPenWidth()const
{
	return penWidth / 2;
}
void GTank::Test()
{
	HPEN hPenTest = CreatePen(PS_SOLID, 2, RGB(255, 0, 255));
	hPenOld =(HPEN) SelectObject(hdcDest, hPenTest);
	MoveToEx(hdcDest, 0, b,NULL);
	LineTo(hdcDest, 2000, 2000 * k + b);
	SelectObject(hdcDest, hPenOld);
	DeleteObject(hPenTest);
}
bool GTank::GetDxIsZero()const
{
	if (dx == 0)
		return true;
	else
		return false;
}
void GTank::Initial()
{
	sinceStart = 0;
	penNumber = 0;
	sinceLastPen = 0;
	sinceLastFrame = 0;
	working = false;
	beenTank = false;
}
