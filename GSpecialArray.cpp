#include"GSpecialArray.h"
#include"GFrozen.h"
#include<Windows.h>

GSpecialArray::GSpecialArray()
{
	for (int i = 0; i < SPECIAL_NUMBER; i++)
	{
		crashed[i] = false;
	}

}

void GSpecialArray::Render(GBomb&bomb, GFrozen& frozen,GFlame&flame,GTank&tank,GBrush&brush, GShell& shell, GBomb& shield,short mode,double deltaTime,GObstacleDotArray&obstacleDotArray,GMoveDot&moveDot,GMyConsole&console,POINT&position)
{
	if (mode != -1)
	{
		crashed[mode] = true;
	}
	if (crashed[BOMB])
	{
		if (mode == BOMB)//new
		{
			bomb.SetexplosionPoint(position);
			bomb.Working();
		}
		bomb.BombRender(deltaTime, obstacleDotArray);
		bomb.BombSpecialRender();
		if (!bomb.GetWorking())
			crashed[BOMB] = false;
	}
	if (crashed[FROZEN])
	{
		if (!frozen.GetBeenFrozen())
		{
			frozen.Frozen(obstacleDotArray);
			frozen.SetBeenFrozon(true);
		}
		frozen.Render();
		frozen.Update(deltaTime, obstacleDotArray);
		if (!frozen.GetWorking())
		{
			crashed[FROZEN] = false;
			frozen.SetBeenFrozon(false);
		}
	}	
	if (crashed[FLAME])
	{
		if (mode == FLAME)
			flame.Launch(console.GetRealMousePos(), moveDot);
		flame.FlameRender(deltaTime, console.GetRealMousePos(), moveDot, obstacleDotArray);
		if (!flame.GetWorking())
			crashed[FLAME] = false;
	}
	if (crashed[TANK])
	{
		if (!tank.GetBeenTank())
		{
			tank.SetBeenTank(true);
			tank.Working();
			moveDot.SetSpeed(0);
			moveDot.SetLineState(false);
		}
		tank.SetHotPoint(moveDot.GetHotPoint());
		tank.SetPos(POINT{ (tank.GetHotPoint().x - tank.GetHalftexWidth()),(tank.GetHotPoint().y - tank.GetHalftexHeight())});
		tank.Render(console.GetRealMousePos().x, console.GetRealMousePos().y, deltaTime, moveDot);
		tank.SetKAndB(moveDot);
		if (tank.GetDxIsZero())
			obstacleDotArray.IsCrashWithVerticalLine(moveDot.GetHotPoint().x, tank.GetHalfPenWidth(),console.GetRealMousePos(),moveDot.GetHotPoint());
		else
			obstacleDotArray.IsCrashWithLine(tank.GetK(), tank.GetB(), tank.GetHalfPenWidth(),console.GetRealMousePos(),moveDot.GetHotPoint());
		tank.Update(deltaTime, moveDot);
		if (!tank.GetWorking())
		{
			crashed[TANK] = false;
		}
	}
	if (crashed[BRUSH])
	{
		if (mode == BRUSH)
			brush.Brushing();
		brush.BrushRender(deltaTime, obstacleDotArray);
	}
	if (crashed[SHELL])
	{
		if (mode == SHELL)
			moveDot.SetShield(true);
		if (moveDot.IsGameOver(obstacleDotArray) == 2)
		{
			shield.SetexplosionPoint(moveDot.GetHotPoint());
			shield.Working();
			moveDot.SetShield(false);
		}
		if (!shield.GetWorking())
			shell.ShellRender(moveDot);
		shield.BombRender(deltaTime + 0.05, obstacleDotArray);
		if (!shield.GetWorking())
		{
			if (!moveDot.GetShield())
				crashed[SHELL] = false;
		}
	}
}
void GSpecialArray::Initial()
{
	for (int i = 0; i < SPECIAL_NUMBER; i++)
	{
		crashed[i] = false;
	}
}
