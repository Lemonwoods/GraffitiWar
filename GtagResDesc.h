#pragma once
#ifndef GTAGRESDES
#define GTAGRESDES
#include<Windows.h>
typedef struct GtagResDesc
{
	int ID;//切换成通过ID删除
	HBITMAP hBitmap;//存储位图
	BITMAP bitmap;//存储位图结构信息
	HDC hdc;
} ResDesc, * PResDesc;
#endif // !GTAGRESDES
