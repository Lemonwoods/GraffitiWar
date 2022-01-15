#include<Windows.h>
#include"GMoveDot.h"
#include<math.h>
using namespace std;

GMoveDot::GMoveDot(int tw, int th, int fps, int fram, HDC hdcD, HDC hdcS, BITMAP temp, int spe, int z)
	:GAnimationSprite(tw,th,fps,fram,hdcD, hdcS, temp, spe, z)
{
	SethPen(RGB(255, 0, 0), 1);
}
GMoveDot::~GMoveDot()
{
	DeleteObject(hPen);
	DeleteObject(hPenOld);
}

void GMoveDot::SethPen(COLORREF color,int width)
{
	hPen = CreatePen(PS_SOLID, width, color);
}
void GMoveDot::SetPropKind(short p)
{
	propKind = p;
}
short GMoveDot::GetPropKind()const
{
	return propKind;
}
short GMoveDot::IsGameOver(GObstacleDotArray& obstacle)//(new)
{
	if (obstacle.IsGrameOverAll(hotPoint, redius))
	{
		if (HasShield)
		{

			return 2;
		}
		else
		{
			return 1;
		}
	}
	return 0;
}
void GMoveDot::Render(int mousex,int mousey)
{
	RotateAroundHotPoint(mousex, mousey);
	GAnimationSprite::Render(currentPos.x - hotPoint.x, currentPos.y - hotPoint.y);
	ReSetTransformWorld();
	if (Distance(mousex, mousey) <= 25)
		return;
	CalculateNextPos(POINT{ mousex,mousey });
	UpdateHotPoint();
}
void GMoveDot::SetShield(bool Judge)
{
	HasShield = Judge;
}

bool GMoveDot::GetShield()
{
	return HasShield;
}
void GMoveDot::DrawLine(int mousex, int mousey)
{
	if (!lineState)
		return;
	hPenOld = (HPEN)SelectObject(hdcDest, hPen);
	MoveToEx(hdcDest, hotPoint.x, hotPoint.y, NULL);
	LineTo(hdcDest, mousex, mousey);
	SelectObject(hdcDest, hPenOld);
}
void GMoveDot::SetLineState(bool l)
{
	lineState = l;
}
void GMoveDot::Initial()
{
	SetPos(POINT{ GetSystemMetrics(SM_CXSCREEN) / 2,GetSystemMetrics(SM_CYSCREEN) / 2 });
	SetHotPoint(POINT{ currentPos.x + texWidth / 2,currentPos.y + texHeight / 2 });
	SetSpeed(PLANE_SPEED);
	lineState = true;
	propKind = -1;
	HasShield = false;
	IsCrashed = false;
}
