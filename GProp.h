#pragma once
#include"GSprite.h"
#include"GMoveDot.h"
#include<Windows.h>

class GProp 
	:public GSprite
{
public:
	GProp(POINT point,short mo,HDC hdcD, HDC hdcS, BITMAP temp, int spe, int z);
	void SetPos(POINT);//����������λ��
	bool IsCrashed(POINT positionPoint, int Positionredius);//�ж��Ƿ�������ײ����������֮����жϣ�
	void ResetPos(POINT);//����ʹ�õ�
	bool IsPosValid(POINT positionPos);//�жϵ��λ���Ƿ�Ϸ�����������λ�ú�ʹ�ã�
	void SetMode(short);
	short GetMode()const;
private:
	short mode;
	POINT rBoundary = { GetSystemMetrics(SM_CXSCREEN),GetSystemMetrics(SM_CYSCREEN) };//����������ֱ߽�Ĵ�С
	bool existence = true;
	bool crashed = false;
	int posRedius = 250;//����Ŀ�����Χ250��λ�����ɵ���
	int redius;//��ײ�뾶
};