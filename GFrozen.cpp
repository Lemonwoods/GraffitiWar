#include"GAnimationSprite.h"
#include"GFrozen.h"
#include"GObstacleDot.h"
#include<Windows.h>

GFrozen::GFrozen(int tw, int th, int fps, int fram, HDC hdcD, HDC hdcS, BITMAP bitmap, int spe, int z)
	:GAnimationSprite(tw, th,fps, fram, hdcD, hdcS,bitmap, spe, z)
{
	currentPos.x = GetSystemMetrics(SM_CXSCREEN)/2 - 250;
	currentPos.y = GetSystemMetrics(SM_CYSCREEN)/2 - 250;
	SetHotPoint(POINT{ currentPos.x + texWidth / 2,currentPos.y + texHeight / 2 });
}

void GFrozen::Frozen(GObstacleDotArray& obstacleDotArray)
{
	obstacleDotArray.SetSpeed(frozenSpeed);
	obstacleDotArray.SetBlue();
	working = true;
}

void GFrozen::Unfreeze(GObstacleDotArray& obstacleDotArray)
{
	obstacleDotArray.SetSpeed(OBSTACLE_DOT_SPEED);
	obstacleDotArray.SetRandColor();
	working = false;
}
void GFrozen::Update(double deltaTime,GObstacleDotArray&obstacleDotArray)
{
	if (sinceStart >= frozenTime)
	{
		sinceStart = 0;
		Unfreeze(obstacleDotArray);
	}
	else
		sinceStart += deltaTime;
}
bool GFrozen::GetWorking()const
{
	return working;
}
void GFrozen::SetBeenFrozon(bool b)
{
	beenFrozen = b;
}
bool GFrozen::GetBeenFrozen()const
{
	return beenFrozen;
}
void GFrozen::Render()
{
	visibility = true;	
	GAnimationSprite::Render(currentPos.x, currentPos.y);
}
void GFrozen::Initial(GObstacleDotArray&obstacleDotArray)
{
	obstacleDotArray.SetRandColor();
	sinceStart = 0;
	sinceLastFrame = 0;
	working = false;
	beenFrozen = false;
}