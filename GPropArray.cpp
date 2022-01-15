#include"GPropArray.h"
#include<Windows.h>

GPropArray::GPropArray(POINT point, short mo, HDC hdcD, HDC hdcS, BITMAP tem, int spe, int z)
{
	for (int i = 0; i < PROP_NUMBER; i++)
	{
		GProp* temp = new GProp(point, mo, hdcD, hdcS, tem, spe, z);
		prop.push_back(temp);
	}
}
GPropArray::~GPropArray()
{
	for (int i = 0; i < PROP_NUMBER; i++)
	{
		delete prop[i];
	}
}
bool GPropArray::Update(double deltaTime)
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
bool GPropArray::IsAnyCrashed(POINT point, int r)
{
	for (int i = 0; i < PROP_NUMBER; i++)
	{
		if (prop[i]->GetVisibility())
		{
			if (prop[i]->IsCrashed(point, r))
			{
				mode = prop[i]->GetMode();
				last = prop[i]->GetMode();
				collisionPosition = prop[i]->GetHotPoint();
				return true;
			}
		}
	}
	return false;
}
void GPropArray::Render(double deltaTime,POINT point)
{
	if (Update(deltaTime))
	{
		SetVisibleProp(point);
	}
	for (int i = 0; i < prop.size(); i++)
	{
		if (prop[i]->GetVisibility())
		{
			prop[i]->Render(prop[i]->GetCurrentPos().x, prop[i]->GetCurrentPos().y);
		}
	}
}
void GPropArray::SetVisibleProp(POINT point)
{
	int visPos;
	visPos = rand() % PROP_NUMBER;
	for (int i = visPos; i < PROP_NUMBER; i++)
	{
		if (!prop[i]->GetVisibility())
		{
			if (prop[i]->GetMode() == last)
			{
				last = -1;
				continue;
			}
			else
			{
				prop[i]->ResetPos(point);
				break;
			}
		}
	}
}
void GPropArray::SetMode(int pos, int m)
{
	prop[pos]->SetMode(m);
}
void GPropArray::SetCollisionPosition(int pos)
{
	collisionPosition = prop[pos]->GetHotPoint();
}
POINT& GPropArray::GetCollisionPosition()
{
	return collisionPosition;
}
short GPropArray::GetMode()
{
	return mode;
}
void GPropArray::SetHdcSprite(int pos, HDC hdcS)
{
	prop[pos]->SetSpriteDC(hdcS);
}
void GPropArray::Initial()
{
	for (int i = 0; i < PROP_NUMBER; i++)
	{
		prop[i]->SetVisibility(false);
	}
	last = -1;
	sinceLastTime = 0;
	mode = -1;
}
void GPropArray::SetLast(int l)
{
	last = l;
}
int GPropArray::GetLast()const
{
	return last;
}