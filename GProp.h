#pragma once
#include"GSprite.h"
#include"GMoveDot.h"
#include<Windows.h>

class GProp 
	:public GSprite
{
public:
	GProp(POINT point,short mo,HDC hdcD, HDC hdcS, BITMAP temp, int spe, int z);
	void SetPos(POINT);//随机产生点的位置
	bool IsCrashed(POINT positionPoint, int Positionredius);//判断是否发生了碰撞（道具与球之间的判断）
	void ResetPos(POINT);//重新使用点
	bool IsPosValid(POINT positionPos);//判断点的位置是否合法（在重设点的位置后使用）
	void SetMode(short);
	short GetMode()const;
private:
	short mode;
	POINT rBoundary = { GetSystemMetrics(SM_CXSCREEN),GetSystemMetrics(SM_CYSCREEN) };//随机产生数字边界的大小
	bool existence = true;
	bool crashed = false;
	int posRedius = 250;//不在目标点周围250单位内生成道具
	int redius;//碰撞半径
};