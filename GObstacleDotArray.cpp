#include "GObstacleDotArray.h"
#include<iostream>
using namespace std;
GObstacleDotArray::GObstacleDotArray(HDC hdc)
{
	sinceLastTime=interval-0.5;//最开始要生成
	for (int i = 0; i < OBSTACLE_NUMBER; i++)
	{
		GObstacleDot* temp = new GObstacleDot(hdc);
		obstacle.push_back(temp);
	}
}
void GObstacleDotArray::IsAnyCrashed(POINT positionPos, int redius)
{
	for (int i = 0; i < OBSTACLE_NUMBER; i++)
	{
		obstacle[i]->IsCrashed(positionPos, redius);
	}
}
void GObstacleDotArray::IsAnyCrashed(RECT& rect)
{
	for (int i = 0; i < OBSTACLE_NUMBER; i++)
	{
		obstacle[i]->IsCrashed(rect);
	}
}
bool GObstacleDotArray::Update(double deltaTime)
{
	if (sinceLastTime >= interval)
	{
		sinceLastTime = 0;
		return  true;
	}
	else
	{
		sinceLastTime += deltaTime;
	}
	return false;
}
void  GObstacleDotArray::SetVisibleObstacle(POINT positionPos)
{
	int visNum = rand() % (10-minuseNumber) + plusNumber;
	for (int i = 0; i < obstacle.size(); i++)
	{
		if (!(obstacle[i]->Getvisibility()))
		{
			obstacle[i]->ResetPos(positionPos);
			--visNum;
		}
		if (visNum == 0)
			break;
	}
	if (minuseNumber > 0)
		minuseNumber -= 1;
	if (plusNumber < 8)
		plusNumber += 1;
}
bool  GObstacleDotArray::IsGrameOverAll(POINT positionPos,int redius)
{
	for (int i = 0; i < obstacle.size(); i++)
	{
		if (obstacle[i]->Getvisibility())
			if (obstacle[i]->IsGameOver(positionPos, redius))
				return true;
	}
	return false;
}
void GObstacleDotArray::Render(POINT positionPos, double deltaTime)//集体渲染加是否产生多少个点
{
	if (Update(deltaTime))
	{
		SetVisibleObstacle(positionPos);
	}
	for (int i = 0; i < obstacle.size(); i++)
	{
		if (obstacle[i]->Getvisibility())
			obstacle[i]->Render(positionPos);
	}
}
void GObstacleDotArray::SetSpeed(int sp)
{
	obstacle[0]->SetSpeed(sp);
}
void GObstacleDotArray::SetBlue()//new
{
	for (int i = 0; i < OBSTACLE_NUMBER; i++)
	{
		obstacle[i]->SetBlue();
	}
}
void GObstacleDotArray::SetRed()//new
{
	for (int i = 0; i < OBSTACLE_NUMBER; i++)
	{
		obstacle[i]->SetRed();
	}
}
void GObstacleDotArray::SetRandColor()//new
{
	for (int i = 0; i < OBSTACLE_NUMBER; i++)
	{
		obstacle[i]->SetRandColor();
	}
}
void GObstacleDotArray::IsCrashWithLine(double k, double b, int distance,POINT mousePos,POINT moveDotPos)
{
	UpdateRect(moveDotPos.x,moveDotPos.y);
	SetMouseRect(mousePos);
	for (int i = 0; i < OBSTACLE_NUMBER; i++)
	{		
		if (GetMouseRect() == GetPosRect(obstacle[i]->GetCurrentPos()))
			obstacle[i]->CrashWithLine(k, b, distance);
	}
}
void GObstacleDotArray::IsCrashWithVerticalLine(int x, int distance,POINT mousePos,POINT moveDotPos)
{
	for (int i = 0; i < OBSTACLE_NUMBER; i++)
	{
		if((mousePos.y<moveDotPos.y&&obstacle[i]->GetCurrentPos().y<moveDotPos.y)
			||(mousePos.y >= moveDotPos.y && obstacle[i]->GetCurrentPos().y >= moveDotPos.y))
			obstacle[i]->CrashWithVerticalLine(x, distance);
	}
}
void GObstacleDotArray::UpdateRect(int x, int y)
{
	rect[0].left = 0;
	rect[0].top = 0;
	rect[0].right = x;
	rect[0].bottom = y;

	rect[1].left = x;
	rect[1].top = 0;
	rect[1].right = GetSystemMetrics(SM_CXSCREEN);
	rect[1].bottom = y;

	rect[2].left = 0;
	rect[2].top = y;
	rect[2].right = x;
	rect[2].bottom = GetSystemMetrics(SM_CYSCREEN);

	rect[3].left = x;
	rect[3].top = y;
	rect[3].right = GetSystemMetrics(SM_CXSCREEN);
	rect[3].bottom = GetSystemMetrics(SM_CYSCREEN);

}
int GObstacleDotArray::GetMouseRect()const
{
	return mouseRect;
}
void GObstacleDotArray::SetMouseRect(POINT mousePos)
{
	for (int i = 0; i < 4; i++)
	{
		if (PtInRect(&rect[i], mousePos))
		{
			mouseRect = i;
			break;
		}
	}
}
int GObstacleDotArray::GetPosRect(POINT pos)
{
	for (int i = 0; i < 4; i++)
	{
		if (PtInRect(&rect[i], pos))
		{
			return i;
		}
	}
}
void GObstacleDotArray::Initial()
{
	minuseNumber = 7;
	plusNumber = 1;
	mouseRect = 1;
	sinceLastTime = interval-0.5;
	SetSpeed(OBSTACLE_DOT_SPEED);
	for (int i = 0; i < OBSTACLE_NUMBER; i++)
	{
		obstacle[i]->SetVisibility(false);
	}
	SetRandColor();
}
GObstacleDotArray::~GObstacleDotArray()
{
	for (int i = 0; i < OBSTACLE_NUMBER; i++)
		delete obstacle[i];
}