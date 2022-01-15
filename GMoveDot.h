#pragma once
#include"GSprite.h"
#include"GAnimationSprite.h"
#include<Windows.h>
#include"GProp.h"
#include"GObstacleDotArray.h"

#define PLANE_SPEED 20

class GMoveDot :public GAnimationSprite
{
public:
	GMoveDot(int tw, int th, int fps, int fram, HDC hdcD, HDC hdcS, BITMAP temp, int spe, int z);
	~GMoveDot();
	void SethPen(COLORREF, int);
	void Render(int, int);
	void SetPropKind(short);
	short GetPropKind()const;
	short IsGameOver(GObstacleDotArray& obstacle);//�ж���Ϸ�Ƿ����(new) ����ͨ������ֵ�ж� 0û���� 1���� 2�б�������
	void SetShield(bool);//(new)
	bool GetShield();//(new)
	void DrawLine(int,int);
	void SetLineState(bool);
	void Initial();
private:
	bool IsCrashed = false;//�Ƿ�������ײ
	int redius=7;//�뾶

	HPEN hPen;
	HPEN hPenOld;
	bool HasShield=false;//�Ƿ��б�����(new)
	short propKind=-1;//���ߵ�����

	bool lineState = true;
};