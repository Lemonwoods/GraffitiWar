#include "GTimer.h"
GTimer::GTimer(HDC hdc)
{
	hdcDest = hdc;
	time = 0;
	score = 0;
	hFont= CreateFont(50, 0, 0, 0, 700, false, false, 0, ANSI_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH, NULL);
}


void  GTimer::Update(double deltaTime)
{
	int temp=0; int tdigit=0;
	time += deltaTime;
	score = time;
	temp = score;
	while (temp != 0)
	{
		temp /= 10;
		tdigit +=1;
	}
	digit = tdigit;
}

void GTimer::Initial()
{
	time = 0;
	score = 0;
	digit = 0;
}

void GTimer::Render(int x, int y)
{
	TCHAR  space[20];
	size_t charLength;
	SelectObject(hdcDest, hFont);
	SetTextColor(hdcDest, RGB(252, 157, 154));
	SetBkColor(hdcDest, RGB(255, 255, 255));
	SetBkMode(hdcDest, TRANSPARENT);
	SetTextAlign(hdcDest, TA_CENTER);
	switch (digit)
	{
	case 0:
		StringCchPrintf(space, 20, TEXT("Score %d%d%d%d"), 0,0,0,0);
		StringCchLength(space, 20, &charLength);
		TextOut(hdcDest, x, y, space, charLength);
		break;
	case 1:
		StringCchPrintf(space, 20, TEXT("Score %d%d%d%d"),0,0,0, score);
		StringCchLength(space, 20, &charLength);
		TextOut(hdcDest, x, y, space, charLength);
		break;
	case 2:
		StringCchPrintf(space, 20, TEXT("Score %d%d%d"), 0, 0, score);
		StringCchLength(space, 20, &charLength);
		TextOut(hdcDest, x, y, space, charLength);
		break;
	case 3:
		StringCchPrintf(space, 20, TEXT("Score %d%d"), 0, score);
		StringCchLength(space, 20, &charLength);
		TextOut(hdcDest, x, y, space, charLength);
		break;
	case 4:
		StringCchPrintf(space, 20, TEXT("Score %d"), score);
		StringCchLength(space, 20, &charLength);
		TextOut(hdcDest, x, y, space, charLength);
		break;
	default:
		StringCchPrintf(space, 20, TEXT("Score %d%d%d%d"), 9, 9, 9, 9);
		StringCchLength(space, 20, &charLength);
		TextOut(hdcDest, x, y, space, charLength);
		break;
	}
}