#include"GObstacleDot.h"
#include<iostream>
#include<math.h>
#include<time.h>
using namespace std;
int GObstacleDot::speed = OBSTACLE_DOT_SPEED;
GObstacleDot::GObstacleDot(HDC hdc)//��ʼ����ʱ��ֱ�ӳ�ʼ��������Ϊ�ɼ�����ʼ����ͼ��� ����ʼ���뾶���ٶȣ�
{
	SetHdcDest(hdc);
	redius = 20;
	SetHpenAndHbrush();
	hPenBlue = CreatePen(PS_SOLID, 1, RGB(38, 188, 213));
	hBrushBlue = CreateSolidBrush(RGB(38, 188, 213));
	hPenRed = CreatePen(PS_SOLID, 1, RGB(252,157,154));
	hBrushRed = CreateSolidBrush(RGB(252, 157, 154));
	visibility = false;//һ��ʼ�㲻�ɼ� ������ײ
	existence = false;
}
void GObstacleDot::CalculateNextPos(POINT positionPos)//������һ�����λ��
{
	int dx = abs(positionPos.x - currentPos.x);
	int dy = abs(positionPos.y - currentPos.y);
	int StepX = 1;
	int StepY = 1;
	if (positionPos.x < currentPos.x)
		StepX = -1;
	if (positionPos.y < currentPos.y)
		StepY = -1;
	if (dx == 0 && dy == 0 || speed <= 0)
	{
		nextPos = currentPos;
	}
	else if (dx > dy)
	{
		if (dy == 0)
		{
			if (StepX == 1)
				nextPos.x = currentPos.x + speed;
			else
				nextPos.x = currentPos.x - speed;
			nextPos.y = currentPos.y;
		}
		else
		{
			nextPos = currentPos;
			double k = (double)dy / (double)dx;
			int dxs = speed / sqrt(1 + pow(k, 2));
			int e = dy * 2 - dx;
			for (int i = 0; i <= dxs; i++)
			{
				nextPos.x += StepX;
				e += 2 * dy;
				if (e >= 0)
				{
					nextPos.y += StepY;
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
				nextPos.y = currentPos.y + speed;
			else
				nextPos.y = currentPos.y - speed;
			nextPos.x = currentPos.x;
		}
		else
		{
			nextPos = currentPos;
			double ck = (double)dx / (double)dy;
			int dys = speed / sqrt(1 + pow(ck, 2));
			int e = dx * 2 - dy;
			for (int i = 0; i <= dys; i++)
			{
				nextPos.y += StepY;
				e += 2 * dx;
				if (e >= 0)
				{
					nextPos.x += StepX;
					e -= 2 * dy;
				}
			}
		}
	}
}
void GObstacleDot::SetSpeed(int Speed)
{
	speed = Speed;
}
void GObstacleDot::SetConsoleSize(POINT Boundary)
{
	rBoundary = Boundary;
}
void GObstacleDot::SetPos(POINT positionPosint)//����������λ��
{
	do
	{
		currentPos.x = rand() % rBoundary.x + redius + 1;
		currentPos.y = rand() % rBoundary.y + redius + 1;
	} while (!(IsPosValid(positionPosint)));
}
void GObstacleDot::SetNextPos()//����ǰλ������Ϊ��һ��λ��
{
	currentPos = nextPos;
}
void GObstacleDot::IsCrashed(POINT positionPoint,int Positionredius)//�ж��Ƿ�������ײ
{
	if (existence)
	{
		int distance = sqrt(pow((currentPos.x - positionPoint.x), 2) + pow((currentPos.y - positionPoint.y), 2));
		if (distance <= (redius + Positionredius))
		{
			visibility = false;
			existence = false;
		}
	}
}
void GObstacleDot::IsCrashed(RECT& rect)
{
	if (existence)
		if (PtInRect(&rect, currentPos))
		{
			visibility = false;
			existence = false;
		}
}
bool GObstacleDot::IsGameOver(POINT positionPoint, int Positionredius)//�ж���Ϸ�Ƿ����
{
	if (existence)
	{
		int distance = sqrt(pow((currentPos.x - positionPoint.x), 2) + pow((currentPos.y - positionPoint.y), 2));
		if (distance <= (redius + Positionredius))
		{
			return true;//��������ײ
		}
	}
	return false;//û�з�����ײ
}
bool GObstacleDot::IsPosValid(POINT positionPosint)//�жϵ��λ���Ƿ�Ϸ�����������λ�ú�ʹ�ã�
{
	double distance = sqrt(pow((currentPos.x - positionPosint.x), 2) + pow((currentPos.y - positionPosint.y), 2));
	if (distance <= (redius + produceRedius))
		return false;
	return true;
}
void GObstacleDot::ResetPos(POINT positionPosint)
{
	visibility = true;
	existence = true;
	SetPos(positionPosint);
}
void GObstacleDot::SetHpenAndHbrush()//���Ҫ�ָ��ɼ�ʱ������ɫ Ҫ�ǵû���ȥ
{

	int R = rand() % 80 + 161;
	int G = rand() % 80 + 161;
	int B = rand() % 80+ 161;
	hBrush = CreateSolidBrush(RGB(R, G, B));
	hPen = CreatePen(PS_INSIDEFRAME, 0, RGB(R, G, B));
}
void GObstacleDot::SetBlue()
{
	colorMode = 2;
}
void GObstacleDot::SetRed()
{
	colorMode = 3;
}
void GObstacleDot::SetRandColor()
{
	colorMode = 1;
}
void GObstacleDot::SetHdcDest(HDC hdc)
{
	hdcDest = hdc;
}
bool GObstacleDot::Getvisibility()
{
	return visibility;
}
void GObstacleDot::Render(POINT positionPos)//��Ⱦ
{
	if (visibility)
	{
		if (colorMode==2)
		{
			hPenOld = (HPEN)SelectObject(hdcDest, hPenBlue);
			hBrushOld = (HBRUSH)SelectObject(hdcDest, hBrushBlue);
		}
		else if (colorMode==3)
		{
			hPenOld = (HPEN)SelectObject(hdcDest, hPenRed);
			hBrushOld = (HBRUSH)SelectObject(hdcDest, hBrushRed);
		}
		else if(colorMode==1)
		{
			hPenOld = (HPEN)SelectObject(hdcDest, hPen);
			hBrushOld = (HBRUSH)SelectObject(hdcDest, hBrush);
		}
		Chord(hdcDest, currentPos.x - redius, currentPos.y - redius, currentPos.x + redius, currentPos.y + redius, 0, 0, 0, 0);
	}
	SelectObject(hdcDest, hPenOld);
	SelectObject(hdcDest, hBrushOld);
	CalculateNextPos(positionPos);
	SetNextPos();
}
void GObstacleDot::CrashWithLine(double k, double b, int distance)
{
	double fenZ = currentPos.y - k * currentPos.x - b;
	if (fenZ < 0)
		fenZ = -fenZ;
	double fenM = sqrt(1 + pow(k, 2));
	int dis = fenZ / fenM;
	if (dis <= distance + redius)
	{
		visibility = false;
		existence = false;
	}
}
void GObstacleDot::CrashWithVerticalLine(int x, int distance)
{
	int dis = currentPos.x - x;
	if (dis < 0)
	{
		dis = -dis;
	}
	if (dis <= distance + redius)
	{
		visibility = false;
		existence = false;
	}
}
POINT GObstacleDot::GetCurrentPos()const
{
	return currentPos;
}
void GObstacleDot::SetVisibility(bool v)
{
	visibility = v;
}
GObstacleDot::~GObstacleDot()
{
	DeleteObject(hPenOld);
	DeleteObject(hPen);
	DeleteObject(hPenBlue);
	DeleteObject(hPenRed);
	DeleteObject(hBrushOld);
	DeleteObject(hBrush);
	DeleteObject(hBrushBlue);
	DeleteObject(hBrushRed);
}