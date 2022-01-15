#include"GBomb.h"
#include<Windows.h>
GBomb::GBomb(int tw, int th, int fps, int fram, HDC hdcD, HDC hdcS, BITMAP temp, int spe, int z)//300 100 3 3
	:GAnimationSprite(tw, th, fps, fram, hdcD, hdcS, temp, spe, z)
{
	mode=1;
	play = true;
	visibility = true;
}

void GBomb::Initial()
{
	working = false;
	sinceStart = 0;
	currentFrames = 0;
	sinceLastFrame = 0;
	txStart = 0;
	explosionredius = 50;
}


void GBomb::BombUpdate(double deltaTime)
{
	sinceStart += deltaTime;
	if (sinceStart >= duration)
	{
		working = false;
		sinceStart = 0;
		currentFrames = 0;
		sinceLastFrame = 0;
		txStart = 0;
	}
}

void  GBomb::ClearPos(GObstacleDotArray& obstacle)
{
	obstacle.IsAnyCrashed(hotPoint, explosionredius*(currentFrames+1));
}


void GBomb::Working()
{
	working = true;
	sinceStart = 0;
	currentFrames = 0;
	sinceLastFrame = 0;
	txStart = 0;
	explosionredius = 50;
}

bool GBomb::GetWorking()const
{
	return working;
}

void GBomb::SetexplosionPoint(POINT position)
{
	explosionPoint = position;
	SetHotPoint(position);
	SetPos(POINT{ hotPoint.x - texWidth / 2,hotPoint.y - texHeight / 2 });
}

void  GBomb::BombRender(double deltaTime, GObstacleDotArray& obstacle)
{
	if (working)
	{
		GAnimationSprite::Render(currentPos.x, currentPos.y);
		ClearPos(obstacle);
		Update(deltaTime);
		BombUpdate(deltaTime);
	}
}

void GBomb::BombSpecialRender()
{
	if (currentFrames == frames - 1)
	{
		double temp;
		TransparentBlt(hdcDest, explosionPoint.x- texWidth/2, explosionPoint.y-texHeight/2, texWidth, texHeight, hdcSprite, 900, 0, texWidth, texHeight, RGB(255,0,0));
		explosionPoint.y -= sinceStart/2;
	}
}