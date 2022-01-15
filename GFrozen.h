#pragma once
#include<Windows.h>
#include"GAnimationSprite.h"
#include"GObstacleDotArray.h"

class GFrozen :public GAnimationSprite
{
public:
	GFrozen(int tw, int th, int fps, int fram, HDC hdcD, HDC hdcS, BITMAP bitmap, int spe, int z);
	void Frozen(GObstacleDotArray&);
	void Unfreeze(GObstacleDotArray&);
	void Update(double,GObstacleDotArray&);
	bool GetWorking()const;
	void SetBeenFrozon(bool);
	bool GetBeenFrozen()const;
	void Render();
	void Initial(GObstacleDotArray&);
private:
	double frozenTime=2;
	double sinceStart = 0;
	int frozenSpeed=0;
	bool working=false;
	bool beenFrozen = false;
};