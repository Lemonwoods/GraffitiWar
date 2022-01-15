#include"GSprite.h"
#include<Windows.h>
#include"GAnimationSprite.h"

GAnimationSprite::GAnimationSprite(int tw, int th, int fps, int fram, HDC hdcD, HDC hdcS, BITMAP bitmap, int spe, int z)
	:GSprite(hdcD,hdcS,bitmap,spe, z)
{
	texWidth = tw;
	texHeight = th;
	nFps = fps;
	frames = fram;
	interval = 1.0 / nFps;
	SetHotPoint(POINT{ currentPos.x+texWidth/2,currentPos.y+texHeight/2 });
}

void GAnimationSprite::Play()
{
	play = true;
}
void GAnimationSprite::Stop()
{
	play = false;
}

void GAnimationSprite::SetFrame(int cd)
{
	if (cd >= frames)
	{
		if (mode==0)
		{
			currentFrames = 0;
		}
		else if (mode == 1)
		{
			currentFrames = frames - 1;
		}
	}
	else
	{
		currentFrames = cd;
	}
	txStart = currentFrames * texWidth;
	//tyStart = currentFrames * texHeight;
}
void GAnimationSprite::SetTexture(int x, int y)
{
	txStart = x;
	tyStart = y;
}
void GAnimationSprite::Resume()
{
	txStart = 0;
	tyStart = 0;
}

void GAnimationSprite::SetFrames(int f)
{
	frames = f;
}
void GAnimationSprite::SetnFps(int fps)
{
	nFps = fps;
	interval = 1.0 / nFps;
}

void GAnimationSprite::Update(double deltaTime)
{
	if (!play)
	{
		return;
	}
	sinceLastFrame += deltaTime;
	if (sinceLastFrame >= interval)
	{
		sinceLastFrame = 0;
		SetFrame(currentFrames+1);
	}
}

void GAnimationSprite::Render(int x,int y)
{
	if (!visibility)
		return;
	if (transparent)
	{
		TransparentBlt(hdcDest, x, y, texWidth, texHeight, hdcSprite, txStart, tyStart, texWidth, texHeight, keyColor);
	}
	else
	{
		BitBlt(hdcDest, x, y, texWidth, texHeight, hdcSprite, txStart, tyStart, SRCCOPY);
	}
}
int GAnimationSprite::GetHalftexWidth()const
{
	return texWidth / 2;
}
int GAnimationSprite::GetHalftexHeight()const
{
	return texHeight / 2;
}