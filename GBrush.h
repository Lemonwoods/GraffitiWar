#pragma once
#include "GAnimationSprite.h"
#include"GObstacleDotArray.h"
class GBrush :
	public GAnimationSprite
{
public:
	GBrush(int, int, int, int , HDC , HDC , BITMAP , int, int);//�ٶ����300 ˢͷ���ֳ�70
	void Initial();
	void Brushing();//��ʼ����
	bool GetWorking();
	void ClearObstacleDot(GObstacleDotArray&);
	void BrushRender(double , GObstacleDotArray& );
	void IsWorking();
private:
	bool working=false;
	RECT  brushHead;
	
};

