#include"GProp.h"
#include<Windows.h>
#include<math.h>
#include"GMoveDot.h"
using namespace std;

GProp::GProp(POINT point,short mo,HDC hdcD, HDC hdcS, BITMAP temp, int spe, int z)
	:GSprite(hdcD, hdcS, temp, spe, z)
{
	SetPos(point);
	visibility = false;
	existence = false;
	mode = mo;
	redius = width / 2;
}

void GProp::SetPos(POINT point)//随机产生点的位置
{
	do
	{
		currentPos.x = rand() % (GetSystemMetrics(SM_CXSCREEN)-width)+1;
		currentPos.y = rand() % (GetSystemMetrics(SM_CYSCREEN) - height)+1;
		hotPoint.x = currentPos.x + width / 2;
		hotPoint.y = currentPos.y + height / 2;
	} while (!IsPosValid(point));
}
bool GProp::IsCrashed(POINT positionPoint, int Positionredius)//判断是否发生了碰撞
{
	if (existence)
	{
		int distance = sqrt(pow((hotPoint.x - positionPoint.x), 2) + pow((hotPoint.y - positionPoint.y), 2));
		if (distance <= (redius + Positionredius))
		{
			crashed = true;
			visibility = false;
			existence = false;
		}
	}
	return crashed;
}
void GProp::ResetPos(POINT point)
{
	visibility = true;
	existence = true;
	crashed = false;
	SetPos(point);
}
bool GProp::IsPosValid(POINT positionPos)
{
	double temp;
	temp = pow(positionPos.x - hotPoint.x, 2) + pow(positionPos.y - hotPoint.y, 2);
	temp = sqrt(temp);
	if (temp <= posRedius)
		return false;
	return true;
}
void GProp::SetMode(short m)
{
	mode = m;
}
short GProp::GetMode()const
{
	return mode;
}
//void GProp::ToMoveDot(GMoveDot& moveDot)
//{
//	if (!crashed)
//		return;
//	else
//	{
//		moveDot.SetHaveProp(true);
//		moveDot.SetPropKind(mode);
//	}
//}