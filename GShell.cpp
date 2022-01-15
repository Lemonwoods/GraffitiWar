#include "GShell.h"
GShell::GShell(int tw, int th, int fps, int fram, HDC hdcD, HDC hdcS, BITMAP temp, int spe, int z)
	:GAnimationSprite(tw, th, fps, fram, hdcD, hdcS, temp, spe, z)
{
	visibility = true;
}

void  GShell::Initial()
{
	working = false;
}

void GShell::Working()
{
	working = true;
}

void GShell::ShellRender(GMoveDot& moveDot)
{
	SetHotPoint(moveDot.GetHotPoint());
	SetPos(POINT{ moveDot.GetHotPoint().x-width/2 ,moveDot.GetHotPoint().y - height/ 2 });
	GSprite:: Render(currentPos.x,currentPos.y);
}