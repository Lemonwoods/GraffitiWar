#pragma once
#include "GAnimationSprite.h"
#include"GObstacleDotArray.h"
class GBrush :
	public GAnimationSprite
{
public:
	GBrush(int, int, int, int , HDC , HDC , BITMAP , int, int);//速度设成300 刷头部分长70
	void Initial();
	void Brushing();//开始工作
	bool GetWorking();
	void ClearObstacleDot(GObstacleDotArray&);
	void BrushRender(double , GObstacleDotArray& );
	void IsWorking();
private:
	bool working=false;
	RECT  brushHead;
	
};

