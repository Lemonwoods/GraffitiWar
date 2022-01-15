#include "GFlame.h"
POINT  temp;//new

GFlame::GFlame(int tw, int th, int fps, int fram, HDC hdcD, HDC hdcS, HDC hbeforeflame,BITMAP temp, BITMAP bbeforeflame,int spe, int z)
	:GAnimationSprite(tw, th, fps, fram, hdcD, hdcS, temp, spe, z)
{
	mode = 1;
	hbeforeFlame = hbeforeflame;
	bbeforeFlame = bbeforeflame;
	hFlame = hdcS;
	bFlame = temp;
	texWidth = bbeforeflame.bmWidth/fram;
	texHeight = bbeforeflame.bmHeight;
	SetTransparent(true);
	SetKeyColor(RGB(0, 0, 0));
	play = true;
	visibility = true;
}


void GFlame::Initial()
{
	working = false;
	hdcSprite = hbeforeFlame;
	bitmap = bbeforeFlame;
	sinceLastTime = 0;
	sinceLastFrame = 0;
	currentFrames = 0;
	txStart = 0;
}

void GFlame::ClearObstacleDot(GObstacleDotArray& obstaclearry)
{
	obstaclearry.IsAnyCrashed(hotPoint, width/2);
}



void GFlame::Launch(POINT mouse, GMoveDot& moveDot)
{
	hdcSprite = hbeforeFlame;
	bitmap = bbeforeFlame;
	temp.x = 0; temp.y = moveDot.GetHotPoint().y;
	sinceLastTime = 0;
	sinceLastFrame = 0;
	currentFrames = 0;
	txStart = 0;
	working = true;
	orientationpos.x = 0; orientationpos.y = moveDot.GetHotPoint().y;
	moveDot.Render(0, moveDot.GetHotPoint().y);
}

void GFlame::CalculatePosition(POINT position, GMoveDot&moveDot)
{
	SetHotPoint(moveDot.CalculateNextPos(position,100));
	SetPos(POINT{ hotPoint.x-width/2,hotPoint.y-height/2 });
}

void GFlame::IsLaunch()
{
	if (currentPos.x >= GetSystemMetrics(SM_CXSCREEN)+width || currentPos.y >= GetSystemMetrics(SM_CYSCREEN)+height|| currentPos.x<=-width|| currentPos.y<=-height)
		working = false;
}

bool GFlame::GetWorking()
{
	return working;
}

void GFlame::FlameRender(double deltaTime, POINT mouse, GMoveDot& moveDot,GObstacleDotArray& obstaclearry)
{
	if (sinceLastTime>= storageTime)
	{
		ClearObstacleDot(obstaclearry);
		RotateAroundHotPoint(orientationpos.x, orientationpos.y);
		GSprite::Render(currentPos.x - hotPoint.x, currentPos.y - hotPoint.y);
		ReSetTransformWorld();
		CalculateNextPos(orientationpos, true);
		UpdateHotPoint();
		IsLaunch();
	}

	else
	{
		Storge(deltaTime,mouse, moveDot);
		if (sinceLastTime >= storageTime)
		{
			hdcSprite = hFlame;
			bitmap = bFlame;
			CalculatePosition(orientationpos, moveDot);
			orientationpos = moveDot.CalculateNextPos(orientationpos, 300);
		}
	}

}

void GFlame::Storge(double deltaTime, POINT mouse, GMoveDot& moveDot)//new
{
	
	if ( moveDot.Distance(mouse.x, mouse.y) >= PLANE_SPEED)
	{
		SetHotPoint(moveDot.CalculateNextPos(mouse, 45));
		temp = moveDot.CalculateNextPos(mouse, 100);
		SetPos(POINT{ hotPoint.x - texWidth / 2,hotPoint.y - texHeight / 2 });
	}

	else
	{
		SetHotPoint(moveDot.CalculateNextPos(temp, 45));
		SetPos(POINT{ hotPoint.x - texWidth / 2,hotPoint.y - texHeight / 2 });
	}

	RotateAroundHotPoint(temp.x, temp.y);
	GAnimationSprite::Render(currentPos.x - hotPoint.x, currentPos.y - hotPoint.y);
	ReSetTransformWorld();
	Update(deltaTime);

	if (moveDot.Distance(mouse.x, mouse.y) >= PLANE_SPEED)
	{
		orientationpos = mouse;
	}

	sinceLastTime += deltaTime;
}