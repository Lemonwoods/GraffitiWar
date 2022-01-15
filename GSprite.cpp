#include"GSprite.h"
#include<Windows.h>
#include<math.h>
#pragma comment(lib,"msimg32.lib")
GSprite::GSprite(HDC hdcD, HDC hdcS,BITMAP temp,int spe,int z)
{
	//初始化恢复矩阵
	reWorld.eDx = 0;
	reWorld.eDy = 0;
	reWorld.eM11 = 1;
	reWorld.eM12 = 0;
	reWorld.eM21 = 0;
	reWorld.eM22 = 1;

	hdcDest = hdcD;
	hdcSprite = hdcS;
	SetBitmap(temp);
	width = bitmap.bmWidth;
	height = bitmap.bmHeight;
	speed = spe;
	transparent = true;
	Z_Order = z;
	SetPos(POINT{ GetSystemMetrics(SM_CXSCREEN)/2,GetSystemMetrics(SM_CYSCREEN) /2 });
	SetHotPoint(POINT{ currentPos.x+ width/2,currentPos.y+ height/2 });
	SetKeyColor(RGB(0, 0, 0));
}
GSprite::~GSprite()
{
	
}

void GSprite::SetSinAndCosValue(double x,double y)
{	
	double lens_2 = pow((x - hotPoint.x), 2) + pow((y - hotPoint.y), 2);
	double lens = sqrt(lens_2);
	if (lens_2 == 0)
		return;
	if (Distance(x, y) <= speed)
		return;
	sinValue = (x - hotPoint.x) / lens;
	cosValue = -(y - hotPoint.y) / lens;
}
void GSprite::SetSinAndCosValue(double angle)
{
	double c = 180;
	double angle_h = angle * 3.1415926 / c;
	sinValue = sin(angle_h);
	cosValue = cos(angle_h);
}
void GSprite::SetxFormAngle()
{
	xFormAngle.eDx = 0;
	xFormAngle.eDy = 0;
	xFormAngle.eM11 = cosValue;
	xFormAngle.eM12 = sinValue;
	xFormAngle.eM21 = -sinValue;
	xFormAngle.eM22 = cosValue;
	
}
void GSprite::SetxFormScale()
{
	xFormScale.eDx = 0;
	xFormScale.eDy = 0;
	xFormScale.eM11 = xScaleFactor;
	xFormScale.eM12 = 0;
	xFormScale.eM21 = 0;
	xFormScale.eM22 = yScaleFactor;

}
void GSprite::SetxFormPos(int dx,int dy)
{
	xFormPos.eDx = dx;
	xFormPos.eDy = dy;
	xFormPos.eM11 = 1;
	xFormPos.eM12 = 0;
	xFormPos.eM21 = 0;
	xFormPos.eM22 = 1;

}
void GSprite::SetHotPoint(const POINT temp)
{
	hotPoint = temp;
}
void GSprite::SetBitmap(BITMAP temp)
{
	bitmap = temp;
}
void GSprite::SetSpriteDC(HDC thdcSprite)
{
	hdcSprite = thdcSprite;
}
void GSprite::SetDestDC(HDC thdcDest)
{
	hdcDest = thdcDest;
}void GSprite::SetPos(const POINT temp)
{
	currentPos = temp;
}
void GSprite::SetKeyColor(COLORREF Color)//设置关键色
{
	keyColor = Color;
}
void GSprite::SetVisibility(bool Judge)//设置精灵的可见性
{
	visibility = Judge;
}
void GSprite::SetTransparent(bool Judge)//设置是否进行透明渲染
{
	transparent = Judge;
}
void GSprite::SetZ_Order(int z)
{
	Z_Order = z;
}
void GSprite::SetAngle(double a)
{
	angle = a;
}
void GSprite::SetScaleFactor(double x, double y)
{
	xScaleFactor = x;
	yScaleFactor = x;
}

POINT GSprite::GetnextHotPoint()
{
	return nextHotPoint;
}
POINT GSprite::GetHotPoint()
{
	return hotPoint;
}
POINT GSprite::GetCurrentPos()
{
	return currentPos;
}
int GSprite::GetWidth()
{
	return width;
}
int GSprite::GetHeight()
{
	return height;
}
POINT GSprite::GetPos()
{
	return currentPos;
}
bool GSprite::GetVisibility()//获得精灵的可见性
{
	return visibility;
}
bool GSprite::GetTransparent()//获取是否进行透明渲染
{
	return transparent;
}
double GSprite::GetSinValue()
{
	return sinValue;
}
double GSprite::GetCosValue()
{
	return cosValue;
}

void GSprite::Render(int x,int y)
{
	if (!visibility)
		return;
	if (transparent)
	{
		TransparentBlt(hdcDest, x, y, width, height, hdcSprite, 0, 0, width, height, keyColor);
	}
	else
	{
		BitBlt(hdcDest, x, y, width, height, hdcSprite, 0, 0, SRCCOPY);
	}
}
void GSprite::RotateAroundHotPoint(double x, double y)
{	
	SetSinAndCosValue(x, y);	
	SetxFormAngle();
	SetxFormPos(hotPoint.x, hotPoint.y);	
	CombineTransform(&world, &xFormAngle, &xFormPos);
	SetWorldTransform(hdcDest, &world);
}
void GSprite::ReSetTransformWorld()
{
	SetWorldTransform(hdcDest, &reWorld);
}
void GSprite::RotateAroundHotPoint(double angle)
{
	SetSinAndCosValue(angle);
	SetxFormAngle();
	SetxFormPos(hotPoint.x, hotPoint.y);
	CombineTransform(&world, &xFormAngle, &xFormPos);
	SetWorldTransform(hdcDest, &world);		
}
void GSprite::SetSpeed(int s)
{
	speed = s;
}
void GSprite::CalculateNextPos(const POINT PositionPos)
{
	int dx = abs(PositionPos.x - hotPoint.x);
	int dy = abs(PositionPos.y - hotPoint.y);
	int StepX = 1;//默认向右
	int StepY = 1;//默认向下
	if (PositionPos.x < hotPoint.x)
		StepX = -1;
	if (PositionPos.y < hotPoint.y)
		StepY = -1;
	if (dx == 0 && dy == 0||speed<=0)
	{
		nextHotPoint = hotPoint;
	}
	else if (dx > dy)
	{
		if (dy == 0)
		{
			if (StepX == 1)
				nextHotPoint.x = hotPoint.x + speed;
			else
				nextHotPoint.x = hotPoint.x - speed;
			nextHotPoint.y = hotPoint.y;
		}
		else
		{
			nextHotPoint = hotPoint;
			double k = (double)dy / (double)dx;
			int dxs = speed / sqrt(1 + pow(k, 2));//在x轴上的位移 会出现一点点误差
			int e = dy * 2 - dx;
			for (int i = 0; i <= dxs; i++)
			{
				nextHotPoint.x += StepX;
				e += 2 * dy;
				if (e >= 0)
				{
					nextHotPoint.y += StepY;
					e -= 2 * dx;
				}
			}
		}
	}
	else
	{
		if (dx == 0)
		{
			if (StepY == 1)
				nextHotPoint.y = hotPoint.y + speed;
			else
				nextHotPoint.y = hotPoint.y - speed;
			nextHotPoint.x = hotPoint.x;
		}
		else
		{
			nextHotPoint = hotPoint;
			double ck = (double)dx / (double)dy;//k的倒数
			int dys = speed / sqrt(1 + pow(ck, 2));//在y轴上位移
			int e = dx * 2 - dy;
			for (int i = 0; i <= dys; i++)
			{
				nextHotPoint.y += StepY;
				e += 2 * dx;
				if (e >= 0)
				{
					nextHotPoint.x += StepX;
					e -= 2 * dy;
				}
			}
		}
	}
	POINT temp = currentPos;
	temp.x += nextHotPoint.x - hotPoint.x;
	temp.y += nextHotPoint.y - hotPoint.y;
	SetPos(temp);//通过接口改变精灵的当前位置
}
void GSprite::CalculateNextPos(POINT& PositionPos, bool Judge)//输入指定点会向那个方向一直运动（暂时未设定停止条件）
{
	int dx = abs(PositionPos.x - hotPoint.x);
	int dy = abs(PositionPos.y - hotPoint.y);
	int StepX = 1;//默认向右
	int StepY = 1;//默认向下
	if (PositionPos.x < hotPoint.x)
		StepX = -1;
	if (PositionPos.y < hotPoint.y)
		StepY = -1;
	if (dx == 0 && dy == 0||speed<=0)
	{
		nextHotPoint = hotPoint;
	}
	else if (dx > dy)
	{
		if (dy == 0)
		{
			if (StepX == 1)
			{
				nextHotPoint.x = hotPoint.x + speed;
				PositionPos.x += speed;
			}
			else
			{
				nextHotPoint.x = hotPoint.x - speed;
				PositionPos.x -= speed;
			}
			nextHotPoint.y = hotPoint.y;
		}
		else
		{
			nextHotPoint = hotPoint;
			double k = (double)dy / (double)dx;
			int dxs = speed / sqrt(1 + pow(k, 2));
			int e = dy * 2 - dx;
			for (int i = 0; i <= dxs; i++)
			{
				nextHotPoint.x += StepX;
				PositionPos.x += StepX;
				e += 2 * dy;
				if (e >= 0)
				{
					nextHotPoint.y += StepY;
					PositionPos.y += StepY;
					e -= 2 * dx;
				}
			}
		}
	}
	else
	{
		if (dx == 0)
		{
			if (StepY == 1)
			{
				nextHotPoint.y = hotPoint.y + speed;
				PositionPos.y += speed;
			}
			else
			{
				nextHotPoint.y = hotPoint.y - speed;
				PositionPos.y -= speed;
			}
			nextHotPoint.x = hotPoint.x;
		}
		else
		{
			nextHotPoint = hotPoint;
			double ck = (double)dx / (double)dy;//k的倒数
			int dys = speed / sqrt(1 + pow(ck, 2));//在y轴上位移
			int e = dx * 2 - dy;
			for (int i = 0; i <= dys; i++)
			{
				nextHotPoint.y += StepY;
				PositionPos.y += StepY;
				e += 2 * dx;
				if (e >= 0)
				{
					nextHotPoint.x += StepX;
					PositionPos.x += StepX;
					e -= 2 * dy;
				}
			}
		}
	}
	POINT temp = currentPos;
	temp.x += nextHotPoint.x - hotPoint.x;
	temp.y += nextHotPoint.y - hotPoint.y;
	SetPos(temp);//通过接口改变精灵的当前位置
}
POINT GSprite::CalculateNextPos(POINT& PositionPos, int distance)
{
	POINT temp = hotPoint;
	int dx = abs(PositionPos.x - hotPoint.x);
	int dy = abs(PositionPos.y - hotPoint.y);
	int StepX = 1;//默认向右
	int StepY = 1;//默认向下
	if (PositionPos.x < hotPoint.x)
		StepX = -1;
	if (PositionPos.y < hotPoint.y)
		StepY = -1;
	if (dx > dy)
	{
		if (dy == 0)
		{
			if (StepX == 1)
				temp.x += distance;
			else
				temp.x -= distance;
		}
		else
		{
			double k = (double)dy / (double)dx;
			int dxs = distance / sqrt(1 + pow(k, 2));//在x轴上的位移 会出现一点点误差
			int e = dy * 2 - dx;
			for (int i = 0; i <= dxs; i++)
			{
				temp.x += StepX;
				e += 2 * dy;
				if (e >= 0)
				{
					temp.y += StepY;
					e -= 2 * dx;
				}
			}
		}
	}
	else
	{
		if (dx == 0)
		{
			if (StepY == 1)
				temp.y += distance;
			else
				temp.y -= distance;
		}
		else
		{
			double ck = (double)dx / (double)dy;//k的倒数
			int dys = distance / sqrt(1 + pow(ck, 2));//在y轴上位移
			int e = dx * 2 - dy;
			for (int i = 0; i <= dys; i++)
			{
				temp.y += StepY;
				e += 2 * dx;
				if (e >= 0)
				{
					temp.x += StepX;
					e -= 2 * dy;
				}
			}
		}
	}
	return temp;
}
void GSprite::UpdateHotPoint()
{
	hotPoint = nextHotPoint;
}
double GSprite::Distance(int x, int y)
{
	double temp;
	temp = pow((x - hotPoint.x), 2) + pow((y - hotPoint.y), 2);
	temp = sqrt(temp);
	return temp;
}
