#pragma once
#include<Windows.h>
#include"GtagResDesc.h"
#include"GMyConsole.h"

#define RES_NUMBER 18
#define PLANE_POS 0

#define BOMB_POS 1
#define BOMB_PROP_POS 2
#define FROZEN_POS 3
#define FROZEN_PROP_POS 4
#define FLAME_POS 5
#define FLAME_PROP_POS 6
#define TANK_POS 7
#define TANK_PROP_POS 8
#define BRUSH_POS 9 
#define BRUSH_PROP_POS 10
#define SHELL_POS 11
#define SHELL_PROP_POS 12
#define SHELL_BOMB_POS 13
#define BEFORE_FLAME 14

#define START_BACKGROUND 15
#define PAUSE 16
#define END 17

class GDraw
{
public:
	GDraw(GMyConsole&);
	~GDraw();
	void InitialHDCB();
	void DrawPlane();
	void DrawBombProp();
	void DrawFrozenProp();
	void DrawFlameProp();
	void DrawTankProp();
	void DrawBrushProp();
	void DrawShellProp();
	void DrawBomb();
	void DrawFrozen();
	void DrawFlame();
	void DrawTank();
	void DrawBrush();
	void DrawShell();
	void DrawBeforeFlame();
	void DrawShellBomb();
	void UpdateConsole(GMyConsole&);
	HDC GetHDC(int);
	BITMAP GetBitmap(int);

	void DrawStartBackground();
	void DrawPause();
	void DrawEnd();

private:
	HPEN hPen;
	HBRUSH hBrush;
	HFONT hFont;
	TEXTMETRIC textMetric;
	ResDesc res[RES_NUMBER];
	GMyConsole console;
};