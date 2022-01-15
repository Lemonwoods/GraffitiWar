#include "GBrush.h"
GBrush::GBrush(int tw, int th, int fps, int fram, HDC hdcD, HDC hdcS, BITMAP temp, int spe, int z)
	:GAnimationSprite(tw, th, fps, fram, hdcD, hdcS, temp, spe, z)
{
	mode == 1;
	play = true;
	visibility = true;
}

void GBrush::Initial()
{
	working = false;
}

void GBrush::ClearObstacleDot(GObstacleDotArray& ObstacleDotArray)
{
	ObstacleDotArray.IsAnyCrashed(brushHead);
}



void GBrush::Brushing()//开始工作
{
	brushHead = { -70,0,0, GetSystemMetrics(SM_CYSCREEN) };
	currentPos = { -width,0 };
	hotPoint = { -width/2, GetSystemMetrics(SM_CYSCREEN) / 2 };
	working = true;
}

bool GBrush::GetWorking()
{
	return working;
}

void GBrush::IsWorking()//当画刷运动出屏幕时停止工作
{
	if (currentPos.x >= GetSystemMetrics(SM_CXSCREEN)+width)
		working = false;
}

void GBrush::BrushRender(double deltaTime, GObstacleDotArray& obstacle)
{
	if (working)
	{
		CalculateNextPos(POINT{ GetSystemMetrics(SM_CXSCREEN)+width ,GetSystemMetrics(SM_CYSCREEN) / 2 });
		GSprite::Render(hotPoint.x - width / 2, 0);//渲染上图像
		ClearObstacleDot(obstacle);//清除范围内的点
		brushHead = { hotPoint.x+280,0, hotPoint.x + 350,GetSystemMetrics(SM_CYSCREEN) };
		UpdateHotPoint();//（更新热点位置）
		IsWorking();
	}
}