#pragma once
#ifndef GMYCONSOLE
#define GMYCONSOLE
#include<Windows.h>
class GMyConsole
{
public:
	GMyConsole();
	void HideScroll();
	void HideCursor();
	void AllowMouseInput();
	POINT GetRealMousePos();//获取鼠标的真实位置：屏幕缩放100%
	void FullScreen();
	void InitialHdcFro();
	bool IsChangeDisplayScale();
	~GMyConsole();
public:
	HBITMAP hBitmap;
	HWND hwnd;
	HANDLE hOUT;
	HANDLE hIN;
	HDC hdc;
	HDC hdcFro;//用于双缓存，是屏幕hdc前的一个hdc
	DWORD outMode;//保存了控制台的模式信息
	DWORD mouseInfo;
	POINT mousePos;//保存鼠标信息
	INPUT_RECORD mouseRecord;//保存鼠标事件的信息
	int xScreen;
	int yScreen;
};
#endif // !GMYCONSOLE

