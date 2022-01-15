#include<Windows.h>
#include"GDraw.h"

using namespace std;

GDraw::GDraw(GMyConsole&c)
{
	console = c;
	InitialHDCB();

	DrawPlane();
	DrawBombProp();
	DrawBomb();
	DrawFrozenProp();
	DrawFrozen();
	DrawFlameProp();
	DrawTankProp();
	DrawTank();
	DrawShellProp();
	DrawShell();
	DrawBrush();
	DrawBrushProp();
	DrawFlame();
	DrawFlameProp();
	DrawBeforeFlame();
	DrawShellBomb();

	DrawStartBackground();
	DrawPause();
	DrawEnd();
}
GDraw::~GDraw()
{
	for (int i = 0; i < RES_NUMBER; i++)
	{
		DeleteDC(res[i].hdc);
		DeleteObject(res[i].hBitmap);
	}
	DeleteObject(hPen);
	DeleteObject(hBrush);
	DeleteObject(hFont);
}
void GDraw::InitialHDCB()
{
	for (int i = 0; i < RES_NUMBER; i++)
	{
		res[i].hdc = CreateCompatibleDC(console.hdc);
	}
}
HDC GDraw::GetHDC(int num)
{
	return res[num].hdc;
}
BITMAP GDraw::GetBitmap(int num)
{
	return res[num].bitmap;
}

void GDraw::DrawPlane()
{
	POINT rectOne[4];

	res[PLANE_POS].hBitmap = CreateCompatibleBitmap(console.hdc, 100, 50);
	GetObject(res[PLANE_POS].hBitmap, sizeof(BITMAP), &res[PLANE_POS].bitmap);
	SelectObject(res[PLANE_POS].hdc, res[PLANE_POS].hBitmap);
	/////////////初始化位图
	hPen = CreatePen(PS_SOLID, 2, RGB(0,0,0));
	hBrush = CreateSolidBrush(RGB(0,0,0));
	SelectObject(res[PLANE_POS].hdc, hPen);
	SelectObject(res[PLANE_POS].hdc, hBrush);
	Rectangle(res[PLANE_POS].hdc, 0, 0, 100, 50);

	/////////////画底部小三角形
	rectOne[0] = { 20,35 };
	rectOne[1] = { 30,35 };
	rectOne[2] = { 25,41 };
	hPen = CreatePen(PS_SOLID, 2, RGB(236, 54, 29));
	hBrush = CreateSolidBrush(RGB(236, 54, 29));
	SelectObject(res[PLANE_POS].hdc, hPen);
	SelectObject(res[PLANE_POS].hdc, hBrush);
	Polygon(res[PLANE_POS].hdc, rectOne, 3);


	/////////////画飞机的大三角形
	
	rectOne[0] = { 25,0 };
	rectOne[1] = { 12,42 };
	rectOne[2] = { 25,35 };
	hPen = CreatePen(PS_SOLID, 2, RGB(88, 115, 132));
	hBrush = CreateSolidBrush(RGB(88, 115, 132));
	SelectObject(res[PLANE_POS].hdc, hPen);
	SelectObject(res[PLANE_POS].hdc, hBrush);
	Polygon(res[PLANE_POS].hdc, rectOne, 3);

	rectOne[0] = { 25,0 };
	rectOne[1] = { 38,42 };
	rectOne[2] = { 25,35 };
	hPen = CreatePen(PS_SOLID, 2, RGB(48,70,98));
	hBrush = CreateSolidBrush(RGB(48, 70, 98));
	SelectObject(res[PLANE_POS].hdc, hPen);
	SelectObject(res[PLANE_POS].hdc, hBrush);
	Polygon(res[PLANE_POS].hdc, rectOne, 3);

	/////////画顶部红色小三角形
	rectOne[0] = { 25,0 };
	rectOne[1] = { 20,16 };
	rectOne[2] = { 25,13 };
	rectOne[3] = { 30,16 };
	hPen = CreatePen(PS_SOLID, 2, RGB(236, 54, 29));
	hBrush = CreateSolidBrush(RGB(236, 54, 29));
	SelectObject(res[PLANE_POS].hdc, hPen);
	SelectObject(res[PLANE_POS].hdc, hBrush);
	Polygon(res[PLANE_POS].hdc, rectOne, 4);

	//////////画第二帧

	/////////////画底部小三角形
	rectOne[0] = { 50+20,35 };
	rectOne[1] = { 50 + 30,35 };
	rectOne[2] = { 50 + 25,41 };
	hPen = CreatePen(PS_SOLID, 2, RGB(236, 54, 29));
	hBrush = CreateSolidBrush(RGB(236, 54, 29));
	SelectObject(res[PLANE_POS].hdc, hPen);
	SelectObject(res[PLANE_POS].hdc, hBrush);
	Polygon(res[PLANE_POS].hdc, rectOne, 3);


	/////////////画飞机的大三角形

	rectOne[0] = { 50 + 25,0 };
	rectOne[1] = { 50 + 12,42 };
	rectOne[2] = { 50 + 25,35 };
	hPen = CreatePen(PS_SOLID, 2, RGB(48, 70, 98));
	hBrush = CreateSolidBrush(RGB(48, 70, 98));
	SelectObject(res[PLANE_POS].hdc, hPen);
	SelectObject(res[PLANE_POS].hdc, hBrush);
	Polygon(res[PLANE_POS].hdc, rectOne, 3);

	rectOne[0] = { 50 + 25,0 };
	rectOne[1] = { 50 + 38,42 };
	rectOne[2] = { 50 + 25,35 };
	hPen = CreatePen(PS_SOLID, 2, RGB(88, 115, 132));
	hBrush = CreateSolidBrush(RGB(88, 115, 132));
	SelectObject(res[PLANE_POS].hdc, hPen);
	SelectObject(res[PLANE_POS].hdc, hBrush);
	Polygon(res[PLANE_POS].hdc, rectOne, 3);

	/////////画顶部红色小三角形
	rectOne[0] = { 50 + 25,0 };
	rectOne[1] = { 50 + 20,16 };
	rectOne[2] = { 50 + 25,13 };
	rectOne[3] = { 50 + 30,16 };
	hPen = CreatePen(PS_SOLID, 2, RGB(236, 54, 29));
	hBrush = CreateSolidBrush(RGB(236, 54, 29));
	SelectObject(res[PLANE_POS].hdc, hPen);
	SelectObject(res[PLANE_POS].hdc, hBrush);
	Polygon(res[PLANE_POS].hdc, rectOne, 4);

}
void GDraw::DrawBombProp()
{
	res[BOMB_PROP_POS].hBitmap = CreateCompatibleBitmap(console.hdc, 50, 50);
	GetObject(res[BOMB_PROP_POS].hBitmap, sizeof(BITMAP), &res[BOMB_PROP_POS].bitmap);
	SelectObject(res[BOMB_PROP_POS].hdc, res[BOMB_PROP_POS].hBitmap);
	///////初始化位图	

	hBrush = CreateSolidBrush(RGB(0, 0, 0));
	hPen = CreatePen(PS_SOLID, 1, RGB(0, 0, 0));
	SelectObject(res[BOMB_PROP_POS].hdc, hBrush);
	SelectObject(res[BOMB_PROP_POS].hdc, hPen);
	Rectangle(res[BOMB_PROP_POS].hdc, 0, 0, 50, 50);
	////////填充黑色背景

	POINT rect[6];

	rect[0] = { 25,0 };
	rect[1] = { 4,13 };
	rect[2] = { 4,38 };
	rect[3] = { 25,50 };
	rect[4] = { 46,38 };
	rect[5] = { 46,13 };
	hBrush = CreateSolidBrush(RGB(118, 108, 101));
	hPen = CreatePen(PS_SOLID, 1, RGB(118, 108, 101));
	SelectObject(res[BOMB_PROP_POS].hdc, hBrush);
	SelectObject(res[BOMB_PROP_POS].hdc, hPen);
	Polygon(res[BOMB_PROP_POS].hdc, rect, 6);
	////////画六边形边框

	rect[0] = { 25,5 };
	rect[1] = { 9,15 };
	rect[2] = { 9,35 };
	rect[3] = { 25,45 };
	rect[4] = { 41,35 };
	rect[5] = { 41,15 };
	hBrush = CreateSolidBrush(RGB(253, 251, 239));
	hPen = CreatePen(PS_SOLID, 1, RGB(253, 251, 239));
	SelectObject(res[BOMB_PROP_POS].hdc, hBrush);
	SelectObject(res[BOMB_PROP_POS].hdc, hPen);
	Polygon(res[BOMB_PROP_POS].hdc, rect, 6);
	///////画米白色六边形区域

	hBrush = CreateSolidBrush(RGB(59,48,44));
	hPen = CreatePen(PS_SOLID, 1, RGB(18,14,8));
	SelectObject(res[BOMB_PROP_POS].hdc, hBrush);
	SelectObject(res[BOMB_PROP_POS].hdc, hPen);
	Ellipse(res[BOMB_PROP_POS].hdc, 13, 16, 37, 38);

	rect[0] = { 21,13 };
	rect[1] = { 21,18 };
	rect[2] = { 29,18 };
	rect[3] = { 29,13 };
	hBrush = CreateSolidBrush(RGB(59, 48, 44));
	hPen = CreatePen(PS_SOLID, 1, RGB(18, 14, 8));
	SelectObject(res[BOMB_PROP_POS].hdc, hBrush);
	SelectObject(res[BOMB_PROP_POS].hdc, hPen);
	Polygon(res[BOMB_PROP_POS].hdc, rect, 4);

	rect[0] = { 25,13 };
	rect[1] = { 30,10 };
	rect[2] = { 30,10 };
	rect[3] = { 35,15 };
	hBrush = CreateSolidBrush(RGB(236, 54, 29));
	hPen = CreatePen(PS_SOLID, 2, RGB(236, 54, 29));
	SelectObject(res[BOMB_PROP_POS].hdc, hBrush);
	SelectObject(res[BOMB_PROP_POS].hdc, hPen);
	PolyBezier(res[BOMB_PROP_POS].hdc, rect, 4);
	///画炸弹


}
void GDraw::DrawFrozenProp()
{
	res[FROZEN_PROP_POS].hBitmap = CreateCompatibleBitmap(console.hdc, 50, 50);
	GetObject(res[FROZEN_PROP_POS].hBitmap, sizeof(BITMAP), &res[FROZEN_PROP_POS].bitmap);
	SelectObject(res[FROZEN_PROP_POS].hdc, res[FROZEN_PROP_POS].hBitmap);
	///////初始化位图	
	
	hBrush = CreateSolidBrush(RGB(0, 0, 0));
	hPen = CreatePen(PS_SOLID, 1, RGB(0, 0, 0));
	SelectObject(res[FROZEN_PROP_POS].hdc, hBrush);
	SelectObject(res[FROZEN_PROP_POS].hdc, hPen);
	Rectangle(res[FROZEN_PROP_POS].hdc, 0, 0, 50, 50);
	////////填充黑色背景

	POINT rect[6];

	rect[0] = { 25,0 };
	rect[1] = { 4,13 };
	rect[2] = { 4,38 };
	rect[3] = { 25,50 };
	rect[4] = { 46,38 };
	rect[5] = { 46,13 };
	hBrush = CreateSolidBrush(RGB(135, 122, 235));
	hPen = CreatePen(PS_SOLID, 1, RGB(135,122,235));
	SelectObject(res[FROZEN_PROP_POS].hdc, hBrush);
	SelectObject(res[FROZEN_PROP_POS].hdc, hPen);
	Polygon(res[FROZEN_PROP_POS].hdc, rect, 6);
	////////画六边形边框

	rect[0] = { 25,5 };
	rect[1] = { 9,15 };
	rect[2] = { 9,35 };
	rect[3] = { 25,45 };
	rect[4] = { 41,35 };
	rect[5] = { 41,15 };
	hBrush = CreateSolidBrush(RGB(253, 251, 239));
	hPen = CreatePen(PS_SOLID, 1, RGB(253, 251, 239));
	SelectObject(res[FROZEN_PROP_POS].hdc, hBrush);
	SelectObject(res[FROZEN_PROP_POS].hdc, hPen);
	Polygon(res[FROZEN_PROP_POS].hdc, rect, 6);
	///////画米白色六边形区域

	hBrush = CreateSolidBrush(RGB(151,202,243));
	hPen = CreatePen(PS_SOLID, 2, RGB(151, 202, 243));
	SelectObject(res[FROZEN_PROP_POS].hdc, hBrush);
	SelectObject(res[FROZEN_PROP_POS].hdc, hPen);
	MoveToEx(res[FROZEN_PROP_POS].hdc, 25, 11, NULL);
	LineTo(res[FROZEN_PROP_POS].hdc, 25,40);
	MoveToEx(res[FROZEN_PROP_POS].hdc, 12, 15, NULL);
	LineTo(res[FROZEN_PROP_POS].hdc, 38, 35);
	MoveToEx(res[FROZEN_PROP_POS].hdc, 38, 15, NULL);
	LineTo(res[FROZEN_PROP_POS].hdc, 12, 35);

	MoveToEx(res[FROZEN_PROP_POS].hdc, 20, 11, NULL);
	LineTo(res[FROZEN_PROP_POS].hdc, 25, 16);
	LineTo(res[FROZEN_PROP_POS].hdc, 30, 11);

	MoveToEx(res[FROZEN_PROP_POS].hdc, 20, 39, NULL);
	LineTo(res[FROZEN_PROP_POS].hdc, 25, 34);
	LineTo(res[FROZEN_PROP_POS].hdc, 30, 39);

	MoveToEx(res[FROZEN_PROP_POS].hdc, 16, 38, NULL);
	LineTo(res[FROZEN_PROP_POS].hdc, 17, 31);
	LineTo(res[FROZEN_PROP_POS].hdc, 11, 29);


	MoveToEx(res[FROZEN_PROP_POS].hdc, 12, 21, NULL);
	LineTo(res[FROZEN_PROP_POS].hdc, 18, 21);
	LineTo(res[FROZEN_PROP_POS].hdc, 17, 13);

	MoveToEx(res[FROZEN_PROP_POS].hdc, 34, 38, NULL);
	LineTo(res[FROZEN_PROP_POS].hdc, 33, 31);
	LineTo(res[FROZEN_PROP_POS].hdc, 39, 29);

	MoveToEx(res[FROZEN_PROP_POS].hdc, 38, 21, NULL);
	LineTo(res[FROZEN_PROP_POS].hdc, 32, 21);
	LineTo(res[FROZEN_PROP_POS].hdc, 33, 13);
}
void GDraw::DrawFlameProp()
{
	res[FLAME_PROP_POS].hBitmap = CreateCompatibleBitmap(console.hdc, 50, 50);
	GetObject(res[FLAME_PROP_POS].hBitmap, sizeof(BITMAP), &res[FLAME_PROP_POS].bitmap);
	SelectObject(res[FLAME_PROP_POS].hdc, res[FLAME_PROP_POS].hBitmap);
	///////初始化位图	

	hBrush = CreateSolidBrush(RGB(0, 0, 0));
	hPen = CreatePen(PS_SOLID, 1, RGB(0, 0, 0));
	SelectObject(res[FLAME_PROP_POS].hdc, hBrush);
	SelectObject(res[FLAME_PROP_POS].hdc, hPen);
	Rectangle(res[FLAME_PROP_POS].hdc, 0, 0, 50, 50);
	////////填充黑色背景

	POINT rect[7];

	rect[0] = { 25,0 };
	rect[1] = { 4,13 };
	rect[2] = { 4,38 };
	rect[3] = { 25,50 };
	rect[4] = { 46,38 };
	rect[5] = { 46,13 };
	hBrush = CreateSolidBrush(RGB(234, 63, 28));
	hPen = CreatePen(PS_SOLID, 1, RGB(234, 63, 28));
	SelectObject(res[FLAME_PROP_POS].hdc, hBrush);
	SelectObject(res[FLAME_PROP_POS].hdc, hPen);
	Polygon(res[FLAME_PROP_POS].hdc, rect, 6);
	////////画六边形边框

	rect[0] = { 25,5 };
	rect[1] = { 9,15 };
	rect[2] = { 9,35 };
	rect[3] = { 25,45 };
	rect[4] = { 41,35 };
	rect[5] = { 41,15 };
	hBrush = CreateSolidBrush(RGB(253, 251, 239));
	hPen = CreatePen(PS_SOLID, 1, RGB(253, 251, 239));
	SelectObject(res[FLAME_PROP_POS].hdc, hBrush);
	SelectObject(res[FLAME_PROP_POS].hdc, hPen);
	Polygon(res[FLAME_PROP_POS].hdc, rect, 6);
	///////画米白色六边形区域

	rect[0] = { 25,8 };
	rect[1] = { 32,23 };
	rect[2] = { 35,18 };
	rect[3] = { 41,33 };
	rect[4] = { 9,33 };
	rect[5] = { 15,18 };
	rect[6] = { 18,23 };
	hBrush = CreateSolidBrush(RGB(229,68,34));
	hPen = CreatePen(PS_SOLID, 1, RGB(229, 68, 34));
	SelectObject(res[FLAME_PROP_POS].hdc, hBrush);
	SelectObject(res[FLAME_PROP_POS].hdc, hPen);
	Polygon(res[FLAME_PROP_POS].hdc, rect, 7);

	rect[0] = { 25,17 };
	rect[1] = { 28,27 };
	rect[2] = { 30,24 };
	rect[3] = { 33,33 };
	rect[4] = { 17,33 };
	rect[5] = { 20,24 };
	rect[6] = { 22,27 };
	hBrush = CreateSolidBrush(RGB(246,220,134));
	hPen = CreatePen(PS_SOLID, 1, RGB(246, 220, 134));
	SelectObject(res[FLAME_PROP_POS].hdc, hBrush);
	SelectObject(res[FLAME_PROP_POS].hdc, hPen);
	Polygon(res[FLAME_PROP_POS].hdc, rect, 7);
}
void GDraw::DrawTankProp()
{
	res[TANK_PROP_POS].hBitmap = CreateCompatibleBitmap(console.hdc, 50, 50);
	GetObject(res[TANK_PROP_POS].hBitmap, sizeof(BITMAP), &res[TANK_PROP_POS].bitmap);
	SelectObject(res[TANK_PROP_POS].hdc, res[TANK_PROP_POS].hBitmap);
	///////初始化位图	

	hBrush = CreateSolidBrush(RGB(0, 0, 0));
	hPen = CreatePen(PS_SOLID, 1, RGB(0, 0, 0));
	SelectObject(res[TANK_PROP_POS].hdc, hBrush);
	SelectObject(res[TANK_PROP_POS].hdc, hPen);
	Rectangle(res[TANK_PROP_POS].hdc, 0, 0, 50, 50);
	////////填充黑色背景

	POINT rect[7];

	rect[0] = { 25,0 };
	rect[1] = { 4,13 };
	rect[2] = { 4,38 };
	rect[3] = { 25,50 };
	rect[4] = { 46,38 };
	rect[5] = { 46,13 };
	hBrush = CreateSolidBrush(RGB(80,157,73));
	hPen = CreatePen(PS_SOLID, 1, RGB(80, 157, 73));
	SelectObject(res[TANK_PROP_POS].hdc, hBrush);
	SelectObject(res[TANK_PROP_POS].hdc, hPen);
	Polygon(res[TANK_PROP_POS].hdc, rect, 6);
	////////画六边形边框

	rect[0] = { 25,5 };
	rect[1] = { 9,15 };
	rect[2] = { 9,35 };
	rect[3] = { 25,45 };
	rect[4] = { 41,35 };
	rect[5] = { 41,15 };
	hBrush = CreateSolidBrush(RGB(253, 251, 239));
	hPen = CreatePen(PS_SOLID, 1, RGB(253, 251, 239));
	SelectObject(res[TANK_PROP_POS].hdc, hBrush);
	SelectObject(res[TANK_PROP_POS].hdc, hPen);
	Polygon(res[TANK_PROP_POS].hdc, rect, 6);
	///////画米白色六边形区域

	hBrush = CreateSolidBrush(RGB(181,216,176));
	hPen = CreatePen(PS_SOLID, 1, RGB(181, 216, 176));
	SelectObject(res[TANK_PROP_POS].hdc, hBrush);
	SelectObject(res[TANK_PROP_POS].hdc, hPen);
	Ellipse(res[TANK_PROP_POS].hdc, 15, 15, 27, 27);
	////////画坦克小圆

	hBrush = CreateSolidBrush(RGB(103,129,99));
	hPen = CreatePen(PS_SOLID, 1, RGB(103, 129, 99));
	SelectObject(res[TANK_PROP_POS].hdc, hBrush);
	SelectObject(res[TANK_PROP_POS].hdc, hPen);
	RoundRect(res[TANK_PROP_POS].hdc, 13, 21, 37, 36,6,6);
	///////坦克主体

	hPen = CreatePen(PS_SOLID, 2, RGB(103, 129, 99));
	SelectObject(res[TANK_PROP_POS].hdc, hPen);
	MoveToEx(res[TANK_PROP_POS].hdc, 38, 16, NULL);
	LineTo(res[TANK_PROP_POS].hdc, 27, 20);
	//////画弹道

	hBrush = CreateSolidBrush(RGB(103, 133, 102));
	hPen = CreatePen(PS_SOLID, 1, RGB(103, 129, 99));
	SelectObject(res[TANK_PROP_POS].hdc, hBrush);
	SelectObject(res[TANK_PROP_POS].hdc, hPen);
	RoundRect(res[TANK_PROP_POS].hdc, 11, 26, 39, 34, 6, 6);
	///////轮胎背景

	hBrush = CreateSolidBrush(RGB(201,229,197));
	hPen = CreatePen(PS_SOLID, 1, RGB(201, 229, 197));
	SelectObject(res[TANK_PROP_POS].hdc, hBrush);
	SelectObject(res[TANK_PROP_POS].hdc, hPen);
	Ellipse(res[TANK_PROP_POS].hdc, 11, 27, 17, 33);
	Ellipse(res[TANK_PROP_POS].hdc, 18, 27, 24, 33);
	Ellipse(res[TANK_PROP_POS].hdc, 26, 27, 32, 33);
	Ellipse(res[TANK_PROP_POS].hdc, 33, 27, 39, 33);
}
void GDraw::DrawBrushProp()
{
	res[BRUSH_PROP_POS].hBitmap = CreateCompatibleBitmap(console.hdc, 50, 50);
	GetObject(res[BRUSH_PROP_POS].hBitmap, sizeof(BITMAP), &res[BRUSH_PROP_POS].bitmap);
	SelectObject(res[BRUSH_PROP_POS].hdc, res[BRUSH_PROP_POS].hBitmap);
	//初始化位图


	hBrush = CreateSolidBrush(RGB(0, 0, 0));
	hPen = CreatePen(PS_SOLID, 1, RGB(0, 0, 0));
	SelectObject(res[BRUSH_PROP_POS].hdc, hBrush);
	SelectObject(res[BRUSH_PROP_POS].hdc, hPen);
	Rectangle(res[BRUSH_PROP_POS].hdc, 0, 0, 50, 50);
	//填充黑色背景

	POINT rect[6];

	rect[0] = { 25,0 };
	rect[1] = { 4,13 };
	rect[2] = { 4,38 };
	rect[3] = { 25,50 };
	rect[4] = { 46,38 };
	rect[5] = { 46,13 };
	hBrush = CreateSolidBrush(RGB(242, 156, 177));
	hPen = CreatePen(PS_SOLID, 1, RGB(242, 156, 177));
	SelectObject(res[BRUSH_PROP_POS].hdc, hBrush);
	SelectObject(res[BRUSH_PROP_POS].hdc, hPen);
	Polygon(res[BRUSH_PROP_POS].hdc, rect, 6);
	//画六边形边框

	rect[0] = { 25,5 };
	rect[1] = { 9,15 };
	rect[2] = { 9,35 };
	rect[3] = { 25,45 };
	rect[4] = { 41,35 };
	rect[5] = { 41,15 };
	hBrush = CreateSolidBrush(RGB(253, 251, 239));
	hPen = CreatePen(PS_SOLID, 1, RGB(253, 251, 239));
	SelectObject(res[BRUSH_PROP_POS].hdc, hBrush);
	SelectObject(res[BRUSH_PROP_POS].hdc, hPen);
	Polygon(res[BRUSH_PROP_POS].hdc, rect, 6);
	//画米白色六边形区域

	POINT trangle[4];
	rect[0] = { 11,22 };
	rect[1] = { 20,27 };


	trangle[0] = { 20,22 };
	trangle[1] = { 20,27 };
	trangle[2] = { 29,36 };
	trangle[3] = { 29,31 };

	rect[2] = { 29,31 };
	rect[3] = { 32,37 };

	hBrush = CreateSolidBrush(RGB(242, 156, 177));
	hPen = CreatePen(PS_SOLID, 1, RGB(242, 156, 177));
	SelectObject(res[BRUSH_PROP_POS].hdc, hBrush);
	SelectObject(res[BRUSH_PROP_POS].hdc, hPen);
	Rectangle(res[BRUSH_PROP_POS].hdc, rect[0].x, rect[0].y, rect[1].x, rect[1].y);
	Polygon(res[BRUSH_PROP_POS].hdc, trangle, 4);
	Rectangle(res[BRUSH_PROP_POS].hdc, rect[2].x, rect[2].y, rect[3].x, rect[3].y);
	//画出画刷手柄

	rect[0] = { 32,15 };
	rect[1] = { 37,37 };

	trangle[0] = { 32,13 };
	trangle[1] = { 37,17 };
	trangle[2] = { 37,15 };
	trangle[3] = { 32,15 };

	rect[2] = { 32,35 };
	rect[3] = { 37,39 };
	rect[4] = { 32,35 };
	rect[5] = { 37,39 };

	hBrush = CreateSolidBrush(RGB(255, 215, 0));
	hPen = CreatePen(PS_SOLID, 1, RGB(255, 215, 0));
	SelectObject(res[BRUSH_PROP_POS].hdc, hBrush);
	SelectObject(res[BRUSH_PROP_POS].hdc, hPen);
	Rectangle(res[BRUSH_PROP_POS].hdc, rect[0].x, rect[0].y, rect[1].x, rect[1].y);
	Chord(res[BRUSH_PROP_POS].hdc, trangle[0].x, trangle[0].y, trangle[1].x, trangle[1].y, trangle[2].x, trangle[2].y, trangle[3].x, trangle[3].y);
	Chord(res[BRUSH_PROP_POS].hdc, rect[2].x, rect[2].y, rect[3].x, rect[3].y, rect[4].x, rect[4].y, rect[5].x, rect[5].y);
}
void GDraw::DrawShellProp()
{
	res[SHELL_PROP_POS].hBitmap = CreateCompatibleBitmap(console.hdc, 50, 50);
	GetObject(res[SHELL_PROP_POS].hBitmap, sizeof(BITMAP), &res[SHELL_PROP_POS].bitmap);
	SelectObject(res[SHELL_PROP_POS].hdc, res[SHELL_PROP_POS].hBitmap);
	///////初始化位图	

	hBrush = CreateSolidBrush(RGB(0, 0, 0));
	hPen = CreatePen(PS_SOLID, 1, RGB(0, 0, 0));
	SelectObject(res[SHELL_PROP_POS].hdc, hBrush);
	SelectObject(res[SHELL_PROP_POS].hdc, hPen);
	Rectangle(res[SHELL_PROP_POS].hdc, 0, 0, 50, 50);
	////////填充黑色背景

	POINT rect[7];

	rect[0] = { 25,0 };
	rect[1] = { 4,13 };
	rect[2] = { 4,38 };
	rect[3] = { 25,50 };
	rect[4] = { 46,38 };
	rect[5] = { 46,13 };
	hBrush = CreateSolidBrush(RGB(89,164,247));
	hPen = CreatePen(PS_SOLID, 1, RGB(89, 164, 247));
	SelectObject(res[SHELL_PROP_POS].hdc, hBrush);
	SelectObject(res[SHELL_PROP_POS].hdc, hPen);
	Polygon(res[SHELL_PROP_POS].hdc, rect, 6);
	////////画六边形边框

	rect[0] = { 25,5 };
	rect[1] = { 9,15 };
	rect[2] = { 9,35 };
	rect[3] = { 25,45 };
	rect[4] = { 41,35 };
	rect[5] = { 41,15 };
	hBrush = CreateSolidBrush(RGB(253, 251, 239));
	hPen = CreatePen(PS_SOLID, 1, RGB(253, 251, 239));
	SelectObject(res[SHELL_PROP_POS].hdc, hBrush);
	SelectObject(res[SHELL_PROP_POS].hdc, hPen);
	Polygon(res[SHELL_PROP_POS].hdc, rect, 6);
	///////画米白色六边形区域

	hBrush = CreateSolidBrush(RGB(70,134,212));
	hPen = CreatePen(PS_SOLID, 1, RGB(70, 134, 212));
	SelectObject(res[SHELL_PROP_POS].hdc, hBrush);
	SelectObject(res[SHELL_PROP_POS].hdc, hPen);
	Ellipse(res[SHELL_PROP_POS].hdc, 15, 21, 35, 41);
	Rectangle(res[SHELL_PROP_POS].hdc, 15, 15, 35, 31);

	hPen = CreatePen(PS_SOLID, 3, RGB(57,199,252));
	SelectObject(res[SHELL_PROP_POS].hdc, hPen);
	MoveToEx(res[SHELL_PROP_POS].hdc, 25, 19,NULL);
	LineTo(res[SHELL_PROP_POS].hdc, 25, 33);
	MoveToEx(res[SHELL_PROP_POS].hdc, 19, 25, NULL);
	LineTo(res[SHELL_PROP_POS].hdc,31, 25);

}
void GDraw::DrawBomb()
{

	res[BOMB_POS].hBitmap = CreateCompatibleBitmap(console.hdc, 1200, 300);
	GetObject(res[BOMB_POS].hBitmap, sizeof(BITMAP), &res[BOMB_POS].bitmap);
	SelectObject(res[BOMB_POS].hdc, res[BOMB_POS].hBitmap);

	hBrush = CreateSolidBrush(RGB(255, 0, 0));
	hPen = CreatePen(PS_SOLID, 1, RGB(255, 0, 0));
	SelectObject(res[BOMB_POS].hdc, hBrush);
	SelectObject(res[BOMB_POS].hdc, hPen);
	Rectangle(res[BOMB_POS].hdc, 900, 0, 1200, 300);

	POINT circle[8][2];//这边是圆爆炸动态的点
	POINT rectangle[2][2];
	POINT trangle[3][3];
	POINT line[2][2];

	circle[0][0] = { 100, 100 };
	circle[0][1] = { 200, 200 };

	circle[1][0] = { 350,50 };
	circle[1][1] = { 550,250 };

	circle[2][0] = { 600,0 };
	circle[2][1] = { 900,300 };

	circle[3][0] = { 900, 0 };
	circle[3][1] = { 1200,300 };

	circle[4][0] = { 965, 20 };
	circle[4][1] = { 1135,190 };
	//黄色外球

	circle[5][0] = { 990, 45 };
	circle[5][1] = { 1110,165 };
	//红色里球

	rectangle[0][0] = { 1000,150 };
	rectangle[0][1] = { 1100,230 };

	rectangle[1][0] = { 1020,110 };
	rectangle[1][1] = { 1080,210 };
	//下巴

	trangle[0][0] = { 1050,145 };
	trangle[0][1] = { 1035,160 };
	trangle[0][2] = { 1065,160 };
	//嘴巴

	line[0][0] = { 1015,85 };
	line[0][1] = { 1030,105 };

	line[1][0] = { 1030,85 };
	line[1][1] = { 1015,105 };
	//左眼

	circle[6][0] = { 1060, 80 };
	circle[6][1] = { 1090,110 };
	//右眼

	trangle[1][0] = { 1050, 255 };
	trangle[1][1] = { 1000,235 };
	trangle[1][2] = { 1000,275 };

	trangle[2][0] = { 1050, 255 };
	trangle[2][1] = { 1100,235 };
	trangle[2][2] = { 1100,275 };
	//领结


	hPen = CreatePen(PS_SOLID, 0, RGB(255, 0, 0));
	hBrush = CreateSolidBrush(RGB(255, 0, 0));
	SelectObject(res[BOMB_POS].hdc, hPen);
	SelectObject(res[BOMB_POS].hdc, hBrush);
	Chord(res[BOMB_POS].hdc, circle[0][0].x, circle[0][0].y, circle[0][1].x, circle[0][1].y, 0, 0, 0, 0);
	Chord(res[BOMB_POS].hdc, circle[1][0].x, circle[1][0].y, circle[1][1].x, circle[1][1].y, 0, 0, 0, 0);
	Chord(res[BOMB_POS].hdc, circle[2][0].x, circle[2][0].y, circle[2][1].x, circle[2][1].y, 0, 0, 0, 0);
	//Chord(res[BOMB_POS].hdc, circle[3][0].x, circle[3][0].y, circle[3][1].x, circle[3][1].y, 0, 0, 0, 0);

	hPen = CreatePen(PS_SOLID, 0, RGB(255, 255, 0));
	hBrush = CreateSolidBrush(RGB(255, 255, 0));
	SelectObject(res[BOMB_POS].hdc, hPen);
	SelectObject(res[BOMB_POS].hdc, hBrush);
	Chord(res[BOMB_POS].hdc, circle[4][0].x, circle[4][0].y, circle[4][1].x, circle[4][1].y, 0, 0, 0, 0);
	Rectangle(res[BOMB_POS].hdc, rectangle[0][0].x, rectangle[0][0].y, rectangle[0][1].x, rectangle[0][1].y);

	hPen = CreatePen(PS_SOLID, 0, RGB(255, 0, 0));
	hBrush = CreateSolidBrush(RGB(255, 0, 0));
	SelectObject(res[BOMB_POS].hdc, hPen);
	SelectObject(res[BOMB_POS].hdc, hBrush);
	Chord(res[BOMB_POS].hdc, circle[5][0].x, circle[5][0].y, circle[5][1].x, circle[5][1].y, 0, 0, 0, 0);
	Rectangle(res[BOMB_POS].hdc, rectangle[1][0].x, rectangle[1][0].y, rectangle[1][1].x, rectangle[1][1].y);

	hPen = CreatePen(PS_SOLID, 0, RGB(255, 255, 0));
	hBrush = CreateSolidBrush(RGB(255, 255, 0));
	SelectObject(res[BOMB_POS].hdc, hPen);
	SelectObject(res[BOMB_POS].hdc, hBrush);
	Polygon(res[BOMB_POS].hdc, trangle[0], 3);

	hPen = CreatePen(PS_SOLID, 10, RGB(255, 255, 0));
	SelectObject(res[BOMB_POS].hdc, hPen);
	MoveToEx(res[BOMB_POS].hdc, line[0][0].x, line[0][0].y, NULL);
	LineTo(res[BOMB_POS].hdc, line[0][1].x, line[0][1].y);
	MoveToEx(res[BOMB_POS].hdc, line[1][0].x, line[1][0].y, NULL);
	LineTo(res[BOMB_POS].hdc, line[1][1].x, line[1][1].y);

	hPen = CreatePen(PS_SOLID, 0, RGB(255, 255, 0));
	hBrush = CreateSolidBrush(RGB(255, 255, 0));
	SelectObject(res[BOMB_POS].hdc, hPen);
	SelectObject(res[BOMB_POS].hdc, hBrush);
	Chord(res[BOMB_POS].hdc, circle[6][0].x, circle[6][0].y, circle[6][1].x, circle[6][1].y, 0, 0, 0, 0);
	Polygon(res[BOMB_POS].hdc, trangle[1], 3);
	Polygon(res[BOMB_POS].hdc, trangle[2], 3);
}
void GDraw::DrawFrozen()
{
	res[FROZEN_POS].hBitmap = CreateCompatibleBitmap(console.hdc, 500, 500);
	GetObject(res[FROZEN_POS].hBitmap, sizeof(BITMAP), &res[FROZEN_POS].bitmap);
	SelectObject(res[FROZEN_POS].hdc, res[FROZEN_POS].hBitmap);
	//////初始化位图

	hBrush = CreateSolidBrush(RGB(0, 0, 0));
	hPen = CreatePen(PS_SOLID, 1, RGB(0, 0, 0));
	SelectObject(res[FROZEN_POS].hdc, hBrush);
	SelectObject(res[FROZEN_POS].hdc, hPen);
	Rectangle(res[FROZEN_POS].hdc, 0, 0, 500, 500);
	//////填充黑色

	hBrush = CreateSolidBrush(RGB(165,200,229));
	hPen = CreatePen(PS_SOLID, 10, RGB(165, 200, 229));
	SelectObject(res[FROZEN_POS].hdc, hBrush);
	SelectObject(res[FROZEN_POS].hdc, hPen);
	
	POINT rect[17];

	rect[0] = { 250,134 };//1
	rect[1] = { 319,94 };
	rect[2] = { 333,162 };//2
	rect[3] = { 401,180 };
	rect[4] = { 370,250 };//3
	rect[5] = { 400,311 };
	rect[6] = { 333,327 };//4
	rect[7] = { 316,401 };
	rect[8] = { 250,367 };//1
	rect[9] = { 184,401 };
	rect[10] = { 167,327 };//2
	rect[11] = { 100,311 };
	rect[12] = { 130,250 };//3
	rect[13] = { 99,180 };
	rect[14] = { 167,162 };//4
	rect[15] = { 181,94 };
	rect[16] = { 250,134 };//5
	Polyline(res[FROZEN_POS].hdc, rect, 17);

	hPen = CreatePen(PS_SOLID, 6, RGB(165, 200, 229));
	SelectObject(res[FROZEN_POS].hdc, hPen);
	rect[0] = { 250,187 };
	rect[1] = { 287,166 };
	rect[2] = { 294,202 };
	rect[3] = { 335,213 };
	rect[4] = { 313,250 };
	rect[5] = { 332,282 };
	rect[6] = { 294,291 };
	rect[7] = { 285,328 };
	rect[8] = { 250,309 };
	rect[9] = { 215,328 };
	rect[10] = { 206,291 };
	rect[11] = { 168,282 };
	rect[12] = { 187,250 };
	rect[13] = { 165,213 };
	rect[14] = { 206,202 };
	rect[15] = { 213,166 };
	rect[16] = { 250,187 };
	Polyline(res[FROZEN_POS].hdc, rect, 17);
	////////大小两个多边形

	MoveToEx(res[FROZEN_POS].hdc, 250, 134, NULL);
	LineTo(res[FROZEN_POS].hdc, 250, 367);
	MoveToEx(res[FROZEN_POS].hdc, 333, 162, NULL);
	LineTo(res[FROZEN_POS].hdc, 167, 327);
	MoveToEx(res[FROZEN_POS].hdc, 370, 250, NULL);
	LineTo(res[FROZEN_POS].hdc, 130, 250);
	MoveToEx(res[FROZEN_POS].hdc, 333, 327, NULL);
	LineTo(res[FROZEN_POS].hdc, 167, 162);
	Ellipse(res[FROZEN_POS].hdc, 240, 240, 260, 260);
	//////画对角线

	rect[0] = { 250,0 };
	rect[1] = { 273,75 };
	rect[2] = { 250,134 };
	rect[3] = { 227,75 };
	rect[4] = { 250,0 };
	Polyline(res[FROZEN_POS].hdc, rect, 5);

	rect[0] = { 409,85 };
	rect[1] = { 389,141 };
	rect[2] = { 333,162 };
	rect[3] = { 353,108 };
	rect[4] = { 409,85};
	Polyline(res[FROZEN_POS].hdc, rect, 5);

	rect[0] = { 91,85 };
	rect[1] = { 111,141 };
	rect[2] = { 167,162 };
	rect[3] = { 147,108 };
	rect[4] = { 91,85 };
	Polyline(res[FROZEN_POS].hdc, rect, 5);

	rect[0] = { 500,250 };
	rect[1] = { 419,269 };
	rect[2] = { 370,250 };
	rect[3] = { 419,231 };
	rect[4] = { 500,250 };
	Polyline(res[FROZEN_POS].hdc, rect, 5);

	rect[0] = { 0,250 };
	rect[1] = { 81,269 };
	rect[2] = { 130,250 };
	rect[3] = { 81,231 };
	rect[4] = { 0,250 };
	Polyline(res[FROZEN_POS].hdc, rect, 5);

	rect[0] = { 93,415 };
	rect[1] = { 152,391 };
	rect[2] = { 167,331 };
	rect[3] = { 113,349 };
	rect[4] = { 93,415 };
	Polyline(res[FROZEN_POS].hdc, rect, 5);

	rect[0] = { 407,415 };
	rect[1] = { 348,391 };
	rect[2] = { 333,331 };
	rect[3] = { 387,349 };
	rect[4] = { 407,415 };
	Polyline(res[FROZEN_POS].hdc, rect, 5);

	rect[0] = { 250,500 };
	rect[1] = { 273,425 };
	rect[2] = { 250,366 };
	rect[3] = { 227,425};
	rect[4] = { 250,500};
	Polyline(res[FROZEN_POS].hdc, rect, 5);
}
void GDraw::DrawFlame()
{
	res[FLAME_POS].hBitmap = CreateCompatibleBitmap(console.hdc, 200, 200);
	GetObject(res[FLAME_POS].hBitmap, sizeof(BITMAP), &res[FLAME_POS].bitmap);
	SelectObject(res[FLAME_POS].hdc, res[FLAME_POS].hBitmap);

	POINT trangle[3][3];
	trangle[0][0] = { 30,100 };
	trangle[0][1] = { 100,200 };
	trangle[0][2] = { 170,100 };

	trangle[1][0] = { 50,150 };
	trangle[1][1] = { 76,100 };
	trangle[1][2] = { 24,100 };

	trangle[2][0] = { 150,150 };
	trangle[2][1] = { 124,100 };
	trangle[2][2] = { 176,100 };


	POINT trangle2[3][3];
	trangle2[0][0] = { 65,100 };
	trangle2[0][1] = { 100,150 };
	trangle2[0][2] = { 135,100 };

	trangle2[1][0] = { 66,100 };
	trangle2[1][1] = { 83,135 };
	trangle2[1][2] = { 100,100 };

	trangle2[2][0] = { 134,100 };
	trangle2[2][1] = { 117,135 };
	trangle2[2][2] = { 100,100 };

	POINT halfCircle[4];

	halfCircle[0] = { 23,0 };
	halfCircle[1] = { 175,200 };
	halfCircle[2] = { 175,100 };
	halfCircle[3] = { 23,100 };




	hPen = CreatePen(PS_SOLID, 0, RGB(251, 69, 39));
	hBrush = CreateSolidBrush(RGB(251, 69, 39));
	SelectObject(res[FLAME_POS].hdc, hPen);
	SelectObject(res[FLAME_POS].hdc, hBrush);
	Polygon(res[FLAME_POS].hdc, trangle[0], 3);
	Polygon(res[FLAME_POS].hdc, trangle[1], 3);
	Polygon(res[FLAME_POS].hdc, trangle[2], 3);
	Chord(res[FLAME_POS].hdc, halfCircle[0].x, halfCircle[0].y, halfCircle[1].x, halfCircle[1].y, halfCircle[2].x, halfCircle[2].y, halfCircle[3].x, halfCircle[3].y);


	halfCircle[0] = { 66,50 };
	halfCircle[1] = { 134,150 };
	halfCircle[2] = { 134,100 };
	halfCircle[3] = { 66,100 };
	hPen = CreatePen(PS_SOLID, 0, RGB(255, 215, 0));
	hBrush = CreateSolidBrush(RGB(255, 215, 0));
	SelectObject(res[FLAME_POS].hdc, res[FLAME_POS].hBitmap);
	SelectObject(res[FLAME_POS].hdc, hPen);
	SelectObject(res[FLAME_POS].hdc, hBrush);
	Polygon(res[FLAME_POS].hdc, trangle2[0], 3);
	Polygon(res[FLAME_POS].hdc, trangle2[1], 3);
	Polygon(res[FLAME_POS].hdc, trangle2[2], 3);
	Chord(res[FLAME_POS].hdc, halfCircle[0].x, halfCircle[0].y, halfCircle[1].x, halfCircle[1].y, halfCircle[2].x, halfCircle[2].y, halfCircle[3].x, halfCircle[3].y);
}
void GDraw::DrawTank()
{
	res[TANK_POS].hBitmap = CreateCompatibleBitmap(console.hdc, 300, 400);
	GetObject(res[TANK_POS].hBitmap, sizeof(BITMAP), &res[TANK_POS].bitmap);
	SelectObject(res[TANK_POS].hdc, res[TANK_POS].hBitmap);
	//////初始化位图

	hBrush = CreateSolidBrush(RGB(0, 0, 0));
	hPen = CreatePen(PS_SOLID, 1, RGB(0, 0, 0));
	SelectObject(res[TANK_POS].hdc, hBrush);
	SelectObject(res[TANK_POS].hdc, hPen);
	Rectangle(res[TANK_POS].hdc, 0, 0, 300,400);
	//////填充黑色	

	hBrush = CreateSolidBrush(RGB(72,96,70));
	hPen = CreatePen(PS_SOLID, 1, RGB(72, 96, 70));
	SelectObject(res[TANK_POS].hdc, hBrush);
	SelectObject(res[TANK_POS].hdc, hPen);
	RoundRect(res[TANK_POS].hdc, 74, 76, 115, 240,20,20);
	RoundRect(res[TANK_POS].hdc, 226, 76, 185, 240, 20, 20);
	///轮胎

	hBrush = CreateSolidBrush(RGB(105,135,104));
	hPen = CreatePen(PS_SOLID, 1, RGB(105, 135, 104));
	SelectObject(res[TANK_POS].hdc, hBrush);
	SelectObject(res[TANK_POS].hdc, hPen);
	RoundRect(res[TANK_POS].hdc, 100, 80, 200, 232, 50, 50);
	/////主体


	hBrush = CreateSolidBrush(RGB(72, 96, 70));
	hPen = CreatePen(PS_SOLID, 1, RGB(72, 96, 70));
	SelectObject(res[TANK_POS].hdc, hBrush);
	SelectObject(res[TANK_POS].hdc, hPen);
	RoundRect(res[TANK_POS].hdc, 123, 53, 177, 150, 20, 20);
	/////弹道

	hBrush = CreateSolidBrush(RGB(183,215,177));
	hPen = CreatePen(PS_SOLID, 1, RGB(183,215,177));
	SelectObject(res[TANK_POS].hdc, hBrush);
	SelectObject(res[TANK_POS].hdc, hPen);
	Ellipse(res[TANK_POS].hdc, 112,112,188,188);
	////驾驶舱
}
void GDraw::DrawBrush()
{
	res[BRUSH_POS].hBitmap = CreateCompatibleBitmap(console.hdc, 700, GetSystemMetrics(SM_CYSCREEN));
	GetObject(res[BRUSH_POS].hBitmap, sizeof(BITMAP), &res[BRUSH_POS].bitmap);
	SelectObject(res[BRUSH_POS].hdc, res[BRUSH_POS].hBitmap);


	POINT point[4];
	point[0] = { 0,GetSystemMetrics(SM_CYSCREEN) / 2  };
	point[1] = { 400,GetSystemMetrics(SM_CYSCREEN) / 2 };
	point[2] = { 600,GetSystemMetrics(SM_CYSCREEN) / 2 + 450 };
	point[3] = { 630,GetSystemMetrics(SM_CYSCREEN) / 2 + 450 };

	hPen = CreatePen(PS_SOLID, 40, RGB(242, 156, 177));
	hBrush = CreateSolidBrush(RGB(242, 156, 177));

	SelectObject(res[BRUSH_POS].hdc, hPen);
	SelectObject(res[BRUSH_POS].hdc, hBrush);
	MoveToEx(res[BRUSH_POS].hdc, point[0].x, point[0].y, NULL);
	LineTo(res[BRUSH_POS].hdc, point[1].x, point[1].y);
	MoveToEx(res[BRUSH_POS].hdc, point[1].x, point[1].y, NULL);
	LineTo(res[BRUSH_POS].hdc, point[2].x, point[2].y);
	MoveToEx(res[BRUSH_POS].hdc, point[2].x, point[2].y, NULL);
	LineTo(res[BRUSH_POS].hdc, point[3].x, point[3].y);

	hPen = CreatePen(PS_SOLID, 50, RGB(242, 156, 177));
	SelectObject(res[BRUSH_POS].hdc, hPen);
	MoveToEx(res[BRUSH_POS].hdc, point[0].x, point[0].y, NULL);
	LineTo(res[BRUSH_POS].hdc, point[0].x + 30, point[0].y);

	point[0] = { 630,0 };
	point[1] = { 700,GetSystemMetrics(SM_CYSCREEN) };
	hPen = CreatePen(PS_SOLID, 0, RGB(255, 215, 0));
	hBrush = CreateSolidBrush(RGB(255, 215, 0));
	SelectObject(res[BRUSH_POS].hdc, hPen);
	SelectObject(res[BRUSH_POS].hdc, hBrush);
	RoundRect(res[BRUSH_POS].hdc, point[0].x, point[0].y, point[1].x, point[1].y, 60, 60);

	hPen = CreatePen(PS_SOLID, 0, RGB(253, 251, 239));
	hBrush = CreateSolidBrush(RGB(253, 251, 239));
	SelectObject(res[BRUSH_POS].hdc, hPen);
	SelectObject(res[BRUSH_POS].hdc, hBrush);
	Chord(res[BRUSH_POS].hdc, 640, GetSystemMetrics(SM_CYSCREEN) / 2 + 430, 690, GetSystemMetrics(SM_CYSCREEN) / 2 + 470, 0, 0, 0, 0);
}
void GDraw::DrawShell()
{
	res[SHELL_POS].hBitmap = CreateCompatibleBitmap(console.hdc, 70, 70);
	GetObject(res[SHELL_POS].hBitmap, sizeof(BITMAP), &res[SHELL_POS].bitmap);
	SelectObject(res[SHELL_POS].hdc, res[SHELL_POS].hBitmap);
	//////初始化位图

	hBrush = CreateSolidBrush(RGB(0, 0, 0));
	hPen = CreatePen(PS_SOLID, 1, RGB(0, 0, 0));
	SelectObject(res[SHELL_POS].hdc, hBrush);
	SelectObject(res[SHELL_POS].hdc, hPen);
	Rectangle(res[SHELL_POS].hdc, 0, 0, 70, 70);
	//////填充黑色	

	hBrush = CreateSolidBrush(RGB(92, 153, 235));
	hPen = CreatePen(PS_SOLID, 1, RGB(92, 153, 235));
	SelectObject(res[SHELL_POS].hdc, hBrush);
	SelectObject(res[SHELL_POS].hdc, hPen);
	Chord(res[SHELL_POS].hdc, 0, 0, 70, 70, 0, 0, 0, 0);

	hBrush = CreateSolidBrush(RGB(218, 234, 252));
	hPen = CreatePen(PS_SOLID, 1, RGB(218, 234, 252));
	SelectObject(res[SHELL_POS].hdc, hBrush);
	SelectObject(res[SHELL_POS].hdc, hPen);
	Chord(res[SHELL_POS].hdc, 10, 10, 60, 60, 0, 0, 0, 0);
}
void GDraw::UpdateConsole(GMyConsole&c)
{
	console = c;
}
void GDraw::DrawBeforeFlame()
{
	res[BEFORE_FLAME].hBitmap = CreateCompatibleBitmap(console.hdc, 80, 40);
	GetObject(res[BEFORE_FLAME].hBitmap, sizeof(BITMAP), &res[BEFORE_FLAME].bitmap);
	SelectObject(res[BEFORE_FLAME].hdc, res[BEFORE_FLAME].hBitmap);
	//////初始化位图

	hBrush = CreateSolidBrush(RGB(0, 0, 0));
	hPen = CreatePen(PS_SOLID, 1, RGB(0, 0, 0));
	SelectObject(res[BEFORE_FLAME].hdc, hBrush);
	SelectObject(res[BEFORE_FLAME].hdc, hPen);
	Rectangle(res[BEFORE_FLAME].hdc, 0, 0, 100, 50);


	hBrush = CreateSolidBrush(RGB(251, 69, 39));
	hPen = CreatePen(PS_SOLID, 1, RGB(251, 69, 39));
	SelectObject(res[BEFORE_FLAME].hdc, hBrush);
	SelectObject(res[BEFORE_FLAME].hdc, hPen);
	Chord(res[BEFORE_FLAME].hdc, 10, 20, 30, 40, 0, 0, 0, 0);
	Chord(res[BEFORE_FLAME].hdc, 40, 0, 80, 40, 0, 0, 0, 0);
	//外部圆


	hBrush = CreateSolidBrush(RGB(255, 215, 0));
	hPen = CreatePen(PS_SOLID, 1, RGB(255, 215, 0));
	SelectObject(res[BEFORE_FLAME].hdc, hBrush);
	SelectObject(res[BEFORE_FLAME].hdc, hPen);
	Chord(res[BEFORE_FLAME].hdc, 15, 25, 25, 35, 0, 0, 0, 0);
	Chord(res[BEFORE_FLAME].hdc, 45, 5, 75, 35, 0, 0, 0, 0);
	//内部圆
}
void GDraw::DrawShellBomb()
{
	res[SHELL_BOMB_POS].hBitmap = CreateCompatibleBitmap(console.hdc, 900, 300);
	GetObject(res[SHELL_BOMB_POS].hBitmap, sizeof(BITMAP), &res[SHELL_BOMB_POS].bitmap);
	SelectObject(res[SHELL_BOMB_POS].hdc, res[SHELL_BOMB_POS].hBitmap);
	//////初始化位图

	hBrush = CreateSolidBrush(RGB(0, 0, 0));
	hPen = CreatePen(PS_SOLID, 1, RGB(0, 0, 0));
	SelectObject(res[SHELL_BOMB_POS].hdc, hBrush);
	SelectObject(res[SHELL_BOMB_POS].hdc, hPen);
	Rectangle(res[SHELL_BOMB_POS].hdc, 0, 0, 100, 50);
	POINT circle[6][2];

	circle[0][0] = { 100, 100 };
	circle[0][1] = { 200, 200 };

	circle[1][0] = { 350,50 };
	circle[1][1] = { 550,250 };

	circle[2][0] = { 600,0 };
	circle[2][1] = { 900,300 };
	//画外部圆

	hBrush = CreateSolidBrush(RGB(92, 153, 235));
	hPen = CreatePen(PS_SOLID, 1, RGB(92, 153, 235));
	SelectObject(res[SHELL_BOMB_POS].hdc, hBrush);
	SelectObject(res[SHELL_BOMB_POS].hdc, hPen);

	Chord(res[SHELL_BOMB_POS].hdc, circle[0][0].x, circle[0][0].y, circle[0][1].x, circle[0][1].y, 0, 0, 0, 0);
	Chord(res[SHELL_BOMB_POS].hdc, circle[1][0].x, circle[1][0].y, circle[1][1].x, circle[1][1].y, 0, 0, 0, 0);
	Chord(res[SHELL_BOMB_POS].hdc, circle[2][0].x, circle[2][0].y, circle[2][1].x, circle[2][1].y, 0, 0, 0, 0);

	circle[3][0] = { 120, 120 };
	circle[3][1] = { 180, 180 };

	circle[4][0] = { 370,70 };
	circle[4][1] = { 530,230 };

	circle[5][0] = { 620,20 };
	circle[5][1] = { 880,280 };
	//画内部圆


	hBrush = CreateSolidBrush(RGB(218, 234, 252));
	hPen = CreatePen(PS_SOLID, 1, RGB(218, 234, 252));
	SelectObject(res[SHELL_BOMB_POS].hdc, hBrush);
	SelectObject(res[SHELL_BOMB_POS].hdc, hPen);

	Chord(res[SHELL_BOMB_POS].hdc, circle[3][0].x, circle[3][0].y, circle[3][1].x, circle[3][1].y, 0, 0, 0, 0);
	Chord(res[SHELL_BOMB_POS].hdc, circle[4][0].x, circle[4][0].y, circle[4][1].x, circle[4][1].y, 0, 0, 0, 0);
	Chord(res[SHELL_BOMB_POS].hdc, circle[5][0].x, circle[5][0].y, circle[5][1].x, circle[5][1].y, 0, 0, 0, 0);

}

void GDraw::DrawStartBackground()
{
	res[START_BACKGROUND].hBitmap = CreateCompatibleBitmap(console.hdc, 1920,1080);
	GetObject(res[START_BACKGROUND].hBitmap, sizeof(BITMAP), &res[START_BACKGROUND].bitmap);
	SelectObject(res[START_BACKGROUND].hdc, res[START_BACKGROUND].hBitmap);
	//////初始化位图

	hBrush = CreateSolidBrush(RGB(0, 0, 0));
	hPen = CreatePen(PS_SOLID, 1, RGB(0, 0, 0));
	SelectObject(res[START_BACKGROUND].hdc, hBrush);
	SelectObject(res[START_BACKGROUND].hdc, hPen);
	Rectangle(res[START_BACKGROUND].hdc, 0, 0, 1920,1080);
	//////填充黑色	

	hBrush = CreateSolidBrush(RGB(253, 251, 239));
	hPen = CreatePen(PS_SOLID, 1, RGB(253, 251, 239));
	SelectObject(res[START_BACKGROUND].hdc, hBrush);
	SelectObject(res[START_BACKGROUND].hdc, hPen);
	Rectangle(res[START_BACKGROUND].hdc, 0,0,1920, 1080);

	hBrush = CreateSolidBrush(RGB(255,255,255));
	hPen = CreatePen(PS_SOLID, 3, RGB(255, 255, 255));
	SelectObject(res[START_BACKGROUND].hdc, hBrush);
	SelectObject(res[START_BACKGROUND].hdc, hPen);
	RoundRect(res[START_BACKGROUND].hdc, 312, 79, 1639, 1000,150,150);
	///////初始化框架

	hFont = CreateFont(106, 0, 0, 0, 700, false, false,0, ANSI_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH, NULL);
	SelectObject(res[START_BACKGROUND].hdc, hFont);
	SetTextColor(res[START_BACKGROUND].hdc, RGB(100,100,100));
	SetBkColor(res[START_BACKGROUND].hdc, RGB(255,255,255));
	SetBkMode(res[START_BACKGROUND].hdc, TRANSPARENT);
	TextOut(res[START_BACKGROUND].hdc, 688, 166, TEXT("Graffiti"), 8);

	SetTextColor(res[START_BACKGROUND].hdc, RGB(74,159,255));
	TextOut(res[START_BACKGROUND].hdc, 1042, 166, TEXT("W"), 1);

	GetTextMetrics(res[START_BACKGROUND].hdc, &textMetric);

	SetTextColor(res[START_BACKGROUND].hdc, RGB(250,89,144));
	TextOut(res[START_BACKGROUND].hdc, 1042+1.8*textMetric.tmAveCharWidth, 166, TEXT("a"), 1);

	SetTextColor(res[START_BACKGROUND].hdc, RGB(253,174,8));
	TextOut(res[START_BACKGROUND].hdc, 1042 + 2.9*textMetric.tmAveCharWidth, 166, TEXT("r"), 1);
	//////文字输出

	POINT rect[4];

	//////画飞机
	/////蓝色底

	rect[0] = { 960,438 };
	rect[1] = { 865,714 };
	rect[2] = { 960,669 };

	hBrush = CreateSolidBrush(RGB(88,115,130));
	hPen = CreatePen(PS_SOLID, 1, RGB(88,115,130));
	SelectObject(res[START_BACKGROUND].hdc, hBrush);
	SelectObject(res[START_BACKGROUND].hdc, hPen);
	Polygon(res[START_BACKGROUND].hdc, rect, 3);

	rect[0] = { 960,438 };
	rect[1] = { 1055,714 };
	rect[2] = { 960,669 };

	hBrush = CreateSolidBrush(RGB(45,71,100));
	hPen = CreatePen(PS_SOLID, 1, RGB(45, 71, 100));
	SelectObject(res[START_BACKGROUND].hdc, hBrush);
	SelectObject(res[START_BACKGROUND].hdc, hPen);
	Polygon(res[START_BACKGROUND].hdc, rect, 3);

	//////顶部红色

	rect[0] = { 960,438 };
	rect[1] = { 926,536 };
	rect[2] = { 960,521 };

	hBrush = CreateSolidBrush(RGB(234,51,37));
	hPen = CreatePen(PS_SOLID, 1, RGB(234, 51, 37));
	SelectObject(res[START_BACKGROUND].hdc, hBrush);
	SelectObject(res[START_BACKGROUND].hdc, hPen);
	Polygon(res[START_BACKGROUND].hdc, rect, 3);

	rect[0] = { 960,438 };
	rect[1] = { 994,536 };
	rect[2] = { 960,521 };

	hBrush = CreateSolidBrush(RGB(203,42,30));
	hPen = CreatePen(PS_SOLID, 1, RGB(234, 51, 37));
	SelectObject(res[START_BACKGROUND].hdc, hBrush);
	SelectObject(res[START_BACKGROUND].hdc, hPen);
	Polygon(res[START_BACKGROUND].hdc, rect, 3);

	//////底部红色

	rect[0] = { 960,668 };
	rect[1] = { 939,677 };
	rect[2] = { 960,699 };
	rect[3] = { 981,677 };

	hBrush = CreateSolidBrush(RGB(234,51,37));
	hPen = CreatePen(PS_SOLID, 1, RGB(234, 51, 37));
	SelectObject(res[START_BACKGROUND].hdc, hBrush);
	SelectObject(res[START_BACKGROUND].hdc, hPen);
	Polygon(res[START_BACKGROUND].hdc, rect, 4);

	//////////顶部小圆
	hBrush = CreateSolidBrush(RGB(241,78,135));
	hPen = CreatePen(PS_SOLID, 1, RGB(241, 78, 135));
	SelectObject(res[START_BACKGROUND].hdc, hBrush);
	SelectObject(res[START_BACKGROUND].hdc, hPen);
	Ellipse(res[START_BACKGROUND].hdc, 533, 324, 582, 373);

	hBrush = CreateSolidBrush(RGB(255,220,106));
	hPen = CreatePen(PS_SOLID, 1, RGB(255, 220, 106));
	SelectObject(res[START_BACKGROUND].hdc, hBrush);
	SelectObject(res[START_BACKGROUND].hdc, hPen);
	Ellipse(res[START_BACKGROUND].hdc, 623, 324, 672, 373);

	hBrush = CreateSolidBrush(RGB(85,159,247));
	hPen = CreatePen(PS_SOLID, 1, RGB(85, 159, 247));
	SelectObject(res[START_BACKGROUND].hdc, hBrush);
	SelectObject(res[START_BACKGROUND].hdc, hPen);
	Ellipse(res[START_BACKGROUND].hdc, 712, 324, 761, 373);

	hBrush = CreateSolidBrush(RGB(253,47,7));
	hPen = CreatePen(PS_SOLID, 1, RGB(253, 47, 7));
	SelectObject(res[START_BACKGROUND].hdc, hBrush);
	SelectObject(res[START_BACKGROUND].hdc, hPen);
	Ellipse(res[START_BACKGROUND].hdc, 801, 324,850, 373);

	hBrush = CreateSolidBrush(RGB(75,125,162));
	hPen = CreatePen(PS_SOLID, 1, RGB(75, 125, 162));
	SelectObject(res[START_BACKGROUND].hdc, hBrush);
	SelectObject(res[START_BACKGROUND].hdc, hPen);
	Ellipse(res[START_BACKGROUND].hdc, 891, 324, 940, 373);

	hBrush = CreateSolidBrush(RGB(248,177,48));
	hPen = CreatePen(PS_SOLID, 1, RGB(248, 177, 48));
	SelectObject(res[START_BACKGROUND].hdc, hBrush);
	SelectObject(res[START_BACKGROUND].hdc, hPen);
	Ellipse(res[START_BACKGROUND].hdc, 981, 324,1030, 373);

	hBrush = CreateSolidBrush(RGB(126,111,94));
	hPen = CreatePen(PS_SOLID, 1, RGB(126, 111, 94));
	SelectObject(res[START_BACKGROUND].hdc, hBrush);
	SelectObject(res[START_BACKGROUND].hdc, hPen);
	Ellipse(res[START_BACKGROUND].hdc,1070, 324, 1118, 373);

	hBrush = CreateSolidBrush(RGB(95, 133,100));
	hPen = CreatePen(PS_SOLID, 1, RGB(95, 133, 100));
	SelectObject(res[START_BACKGROUND].hdc, hBrush);
	SelectObject(res[START_BACKGROUND].hdc, hPen);
	Ellipse(res[START_BACKGROUND].hdc,1160, 324, 1209, 373);

	hBrush = CreateSolidBrush(RGB(141,128,246));
	hPen = CreatePen(PS_SOLID, 1, RGB(141, 128, 246));
	SelectObject(res[START_BACKGROUND].hdc, hBrush);
	SelectObject(res[START_BACKGROUND].hdc, hPen);
	Ellipse(res[START_BACKGROUND].hdc, 1250, 324, 1299, 373);

	hBrush = CreateSolidBrush(RGB(12,151,54));
	hPen = CreatePen(PS_SOLID, 1, RGB(12, 151, 54));
	SelectObject(res[START_BACKGROUND].hdc, hBrush);
	SelectObject(res[START_BACKGROUND].hdc, hPen);
	Ellipse(res[START_BACKGROUND].hdc,1338, 324,1387, 373);

	//////画按钮
	hBrush = CreateSolidBrush(RGB(107,109,229));
	hPen = CreatePen(PS_SOLID, 1, RGB(107, 109, 229));
	SelectObject(res[START_BACKGROUND].hdc, hBrush);
	SelectObject(res[START_BACKGROUND].hdc, hPen);
	RoundRect(res[START_BACKGROUND].hdc, 635-10, 780, 1285+10, 854, 70,70);

	hBrush = CreateSolidBrush(RGB(85,159,247));
	hPen = CreatePen(PS_SOLID, 1, RGB(85, 159, 247));
	SelectObject(res[START_BACKGROUND].hdc, hBrush);
	SelectObject(res[START_BACKGROUND].hdc, hPen);
	RoundRect(res[START_BACKGROUND].hdc, 635-10,892, 1285+10, 967, 70, 70);

	/////按钮上的文字
	hFont = CreateFont(50, 0, 0, 0, 700, false, false, 0, ANSI_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH, NULL);
	SelectObject(res[START_BACKGROUND].hdc, hFont);
	SetTextColor(res[START_BACKGROUND].hdc, RGB(100, 100, 100));
	SetBkColor(res[START_BACKGROUND].hdc, RGB(255, 255, 255));
	SetBkMode(res[START_BACKGROUND].hdc, TRANSPARENT);

	SetTextColor(res[START_BACKGROUND].hdc, RGB(255,255,255));
	TextOut(res[START_BACKGROUND].hdc, 715+10, 793, TEXT("点击鼠标左键以开始游戏"), 11);
	TextOut(res[START_BACKGROUND].hdc, 715 + 10, 906, TEXT("游戏中按空格以暂停游戏"), 11);
}
void GDraw::DrawPause()
{
	res[PAUSE].hBitmap = CreateCompatibleBitmap(console.hdc, 886, 906);
	GetObject(res[PAUSE].hBitmap, sizeof(BITMAP), &res[PAUSE].bitmap);
	SelectObject(res[PAUSE].hdc, res[PAUSE].hBitmap);
	//////初始化位图

	hBrush = CreateSolidBrush(RGB(0, 0, 0));
	hPen = CreatePen(PS_SOLID, 1, RGB(0, 0, 0));
	SelectObject(res[PAUSE].hdc, hBrush);
	SelectObject(res[PAUSE].hdc, hPen);
	Rectangle(res[PAUSE].hdc, 0, 0, 886, 906);
	//////填充黑色

	hBrush = CreateSolidBrush(RGB(249,205,173));
	hPen = CreatePen(PS_SOLID, 1, RGB(249, 205, 173));
	SelectObject(res[PAUSE].hdc, hBrush);
	SelectObject(res[PAUSE].hdc, hPen);
	RoundRect(res[PAUSE].hdc, 0, 0, 886, 906, 150, 150);

	///打印暂停
	hFont = CreateFont(150, 0, 0, 0, 700, false, false, 0, ANSI_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH, NULL);
	SelectObject(res[PAUSE].hdc, hFont);
	SetTextColor(res[PAUSE].hdc, RGB(100, 100, 100));
	SetBkColor(res[PAUSE].hdc, RGB(255, 255, 255));
	SetBkMode(res[PAUSE].hdc, TRANSPARENT);

	SetTextColor(res[PAUSE].hdc, RGB(255, 255, 255));
	TextOut(res[PAUSE].hdc,308+10, 113, TEXT("暂停"), 2);

	//////画按钮图形
	hBrush = CreateSolidBrush(RGB(131,175,155));
	hPen = CreatePen(PS_SOLID, 1, RGB(131, 175, 155));
	SelectObject(res[PAUSE].hdc, hBrush);
	SelectObject(res[PAUSE].hdc, hPen);
	RoundRect(res[PAUSE].hdc, 83, 384+50, 792, 513+50, 120, 120);


	hBrush = CreateSolidBrush(RGB(254,67,101));
	hPen = CreatePen(PS_SOLID, 1, RGB(254, 67, 101));
	SelectObject(res[PAUSE].hdc, hBrush);
	SelectObject(res[PAUSE].hdc, hPen);
	RoundRect(res[PAUSE].hdc, 83,707-50, 792, 836-50, 120, 120);

	///////按钮上文字
	hFont = CreateFont(60, 0, 0, 0, 700, false, false, 0, ANSI_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH, NULL);
	SelectObject(res[PAUSE].hdc, hFont);
	SetTextColor(res[PAUSE].hdc, RGB(100, 100, 100));
	SetBkColor(res[PAUSE].hdc, RGB(255, 255, 255));
	SetBkMode(res[PAUSE].hdc, TRANSPARENT);

	SetTextColor(res[PAUSE].hdc, RGB(255, 255, 255));
	TextOut(res[PAUSE].hdc, 171+10, 423+50, TEXT("点击鼠标左键继续游戏"), 10);
	TextOut(res[PAUSE].hdc, 171+10, 745-50, TEXT("点击鼠标右键重新开始"), 10);
}
void GDraw::DrawEnd()
{
	res[END].hBitmap = CreateCompatibleBitmap(console.hdc, 1920, 1080);
	GetObject(res[END].hBitmap, sizeof(BITMAP), &res[END].bitmap);
	SelectObject(res[END].hdc, res[END].hBitmap);
	//////初始化位图

	hBrush = CreateSolidBrush(RGB(0, 0, 0));
	hPen = CreatePen(PS_SOLID, 1, RGB(0, 0, 0));
	SelectObject(res[END].hdc, hBrush);
	SelectObject(res[END].hdc, hPen);
	Rectangle(res[END].hdc, 0, 0, 1920, 1080);
	//////填充黑色	

	hBrush = CreateSolidBrush(RGB(233,238,244));
	hPen = CreatePen(PS_SOLID, 1, RGB(233, 238, 244));
	SelectObject(res[END].hdc, hBrush);
	SelectObject(res[END].hdc, hPen);
	Rectangle(res[END].hdc, 0, 0, 1920, 1080);

	/*hBrush = CreateSolidBrush(RGB(255, 255, 255));
	hPen = CreatePen(PS_SOLID, 3, RGB(255, 255, 255));
	SelectObject(res[END].hdc, hBrush);
	SelectObject(res[END].hdc, hPen);
	RoundRect(res[END].hdc, 312, 79, 1639, 1000, 150, 150);*/
	///////初始化框架

	hFont = CreateFont(200, 0, 0, 0, 700, false, false, 0, ANSI_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH, NULL);
	SelectObject(res[END].hdc, hFont);
	SetTextColor(res[END].hdc, RGB(162, 165, 170));
	SetBkColor(res[END].hdc, RGB(255, 255, 255));
	SetBkMode(res[END].hdc, TRANSPARENT);
	TextOut(res[END].hdc, 588+20, 112, TEXT("游戏结束"), 4);

	//////文字输出

	POINT rect[4];

	//////画飞机
	/////蓝色底

	rect[0] = { 960,438 };
	rect[1] = { 865,714 };
	rect[2] = { 960,669 };

	hBrush = CreateSolidBrush(RGB(187,200,208));
	hPen = CreatePen(PS_SOLID, 1, RGB(187, 200, 208));
	SelectObject(res[END].hdc, hBrush);
	SelectObject(res[END].hdc, hPen);
	Polygon(res[END].hdc, rect, 3);

	rect[0] = { 960,438 };
	rect[1] = { 1055,714 };
	rect[2] = { 960,669 };

	hBrush = CreateSolidBrush(RGB(175,187,199));
	hPen = CreatePen(PS_SOLID, 1, RGB(175, 187, 199));
	SelectObject(res[END].hdc, hBrush);
	SelectObject(res[END].hdc, hPen);
	Polygon(res[END].hdc, rect, 3);

	//////顶部红色

	rect[0] = { 960,438 };
	rect[1] = { 926,536 };
	rect[2] = { 960,521 };

	hBrush = CreateSolidBrush(RGB(223, 177, 179));
	hPen = CreatePen(PS_SOLID, 1, RGB(223, 177, 179));
	SelectObject(res[END].hdc, hBrush);
	SelectObject(res[END].hdc, hPen);
	Polygon(res[END].hdc, rect, 3);

	rect[0] = { 960,438 };
	rect[1] = { 994,536 };
	rect[2] = { 960,521 };

	hBrush = CreateSolidBrush(RGB(223,177,179));
	hPen = CreatePen(PS_SOLID, 1, RGB(223, 177, 179));
	SelectObject(res[END].hdc, hBrush);
	SelectObject(res[END].hdc, hPen);
	Polygon(res[END].hdc, rect, 3);

	//////底部红色

	rect[0] = { 960,668 };
	rect[1] = { 939,677 };
	rect[2] = { 960,699 };
	rect[3] = { 981,677 };

	hBrush = CreateSolidBrush(RGB(223,177,179));
	hPen = CreatePen(PS_SOLID, 1, RGB(223, 177, 179));
	SelectObject(res[END].hdc, hBrush);
	SelectObject(res[END].hdc, hPen);
	Polygon(res[END].hdc, rect, 4);

	//////////顶部小圆
	hBrush = CreateSolidBrush(RGB(233,190,210));
	hPen = CreatePen(PS_SOLID, 1, RGB(233, 190, 210));
	SelectObject(res[END].hdc, hBrush);
	SelectObject(res[END].hdc, hPen);
	Ellipse(res[END].hdc, 533, 324, 582, 373);

	hBrush = CreateSolidBrush(RGB(238,231,202));
	hPen = CreatePen(PS_SOLID, 1, RGB(238, 231, 202));
	SelectObject(res[END].hdc, hBrush);
	SelectObject(res[END].hdc, hPen);
	Ellipse(res[END].hdc, 623, 324, 672, 373);

	hBrush = CreateSolidBrush(RGB(189,212,243));
	hPen = CreatePen(PS_SOLID, 1, RGB(189, 212, 243));
	SelectObject(res[END].hdc, hBrush);
	SelectObject(res[END].hdc, hPen);
	Ellipse(res[END].hdc, 712, 324, 761, 373);
	//4
	hBrush = CreateSolidBrush(RGB(237,180,171));
	hPen = CreatePen(PS_SOLID, 1, RGB(237, 180, 171));
	SelectObject(res[END].hdc, hBrush);
	SelectObject(res[END].hdc, hPen);
	Ellipse(res[END].hdc, 801, 324, 850, 373);

	hBrush = CreateSolidBrush(RGB(184,203,218));
	hPen = CreatePen(PS_SOLID, 1, RGB(184, 203, 218));
	SelectObject(res[END].hdc, hBrush);
	SelectObject(res[END].hdc, hPen);
	Ellipse(res[END].hdc, 891, 324, 940, 373);
	//6
	hBrush = CreateSolidBrush(RGB(234,218,184));
	hPen = CreatePen(PS_SOLID, 1, RGB(234, 218, 184));
	SelectObject(res[END].hdc, hBrush);
	SelectObject(res[END].hdc, hPen);
	Ellipse(res[END].hdc, 981, 324, 1030, 373);
	//7
	hBrush = CreateSolidBrush(RGB(199,199,199));
	hPen = CreatePen(PS_SOLID, 1, RGB(199, 199, 199));
	SelectObject(res[END].hdc, hBrush);
	SelectObject(res[END].hdc, hPen);
	Ellipse(res[END].hdc, 1070, 324, 1118, 373);
	//8
	hBrush = CreateSolidBrush(RGB(190,205,200));
	hPen = CreatePen(PS_SOLID, 1, RGB(190, 205, 200));
	SelectObject(res[END].hdc, hBrush);
	SelectObject(res[END].hdc, hPen);
	Ellipse(res[END].hdc, 1160, 324, 1209, 373);

	hBrush = CreateSolidBrush(RGB(204,203,243));
	hPen = CreatePen(PS_SOLID, 1, RGB(204, 203, 243));
	SelectObject(res[END].hdc, hBrush);
	SelectObject(res[END].hdc, hPen);
	Ellipse(res[END].hdc, 1250, 324, 1299, 373);

	hBrush = CreateSolidBrush(RGB(165,211,185));
	hPen = CreatePen(PS_SOLID, 1, RGB(165, 211, 185));
	SelectObject(res[END].hdc, hBrush);
	SelectObject(res[END].hdc, hPen);
	Ellipse(res[END].hdc, 1338, 324, 1387, 373);

	//////画按钮
	hBrush = CreateSolidBrush(RGB(193,198,238));
	hPen = CreatePen(PS_SOLID, 1, RGB(193, 198, 238));
	SelectObject(res[END].hdc, hBrush);
	SelectObject(res[END].hdc, hPen);
	RoundRect(res[END].hdc, 635 - 10, 780, 1285 + 10, 854, 70, 70);

	hBrush = CreateSolidBrush(RGB(235,215,178));
	hPen = CreatePen(PS_SOLID, 1, RGB(235, 215, 178));
	SelectObject(res[END].hdc, hBrush);
	SelectObject(res[END].hdc, hPen);
	RoundRect(res[END].hdc, 635 - 10, 892, 1285 + 10, 967, 70, 70);

	/////按钮上的文字
	hFont = CreateFont(50, 0, 0, 0, 700, false, false, 0, ANSI_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH, NULL);
	SelectObject(res[END].hdc, hFont);
	SetTextColor(res[END].hdc, RGB(100, 100, 100));
	SetBkColor(res[END].hdc, RGB(255, 255, 255));
	SetBkMode(res[END].hdc, TRANSPARENT);

	SetTextColor(res[END].hdc, RGB(255, 255, 255));
	TextOut(res[END].hdc, 715 , 793, TEXT("点击鼠标左键重新开始游戏"), 12);
	TextOut(res[END].hdc, 715 + 40, 906, TEXT("点击鼠标右键退出游戏"), 10);
}
