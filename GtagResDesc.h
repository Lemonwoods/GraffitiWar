#pragma once
#ifndef GTAGRESDES
#define GTAGRESDES
#include<Windows.h>
typedef struct GtagResDesc
{
	int ID;//�л���ͨ��IDɾ��
	HBITMAP hBitmap;//�洢λͼ
	BITMAP bitmap;//�洢λͼ�ṹ��Ϣ
	HDC hdc;
} ResDesc, * PResDesc;
#endif // !GTAGRESDES
