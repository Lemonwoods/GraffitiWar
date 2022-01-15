#include<Windows.h>
#include"GMyConsole.h"
#include<iostream>
using namespace std;


GMyConsole::GMyConsole()
{
	DWORD mode;
	mode = ENABLE_WINDOW_INPUT;
	SetConsoleMode(hIN, mode);
	hwnd = GetConsoleWindow();
	hdc = GetDC(hwnd);
	hdcFro = CreateCompatibleDC(hdc);
	hOUT = GetStdHandle(STD_OUTPUT_HANDLE);
	hIN = GetStdHandle(STD_INPUT_HANDLE);
	SetGraphicsMode(hdcFro, GM_ADVANCED);
	SetGraphicsMode(hdc, GM_ADVANCED);
	HideScroll();
	HideCursor();
	AllowMouseInput();
	InitialHdcFro();
	FullScreen();
}


void GMyConsole::HideScroll()
{
	short Cxmax, Cymax;
	Cxmax = GetSystemMetrics(SM_CXSCREEN);
	Cymax = GetSystemMetrics(SM_CYSCREEN);
	COORD a = { Cxmax, Cymax };
	SMALL_RECT rect = { 0,0,Cxmax-1, Cymax-1 };
	SetConsoleScreenBufferSize(hOUT, a);
	SetConsoleWindowInfo(hOUT, true, &rect);
}


void GMyConsole::HideCursor()
{
	CONSOLE_CURSOR_INFO cursor_info = { 1,0 };
	SetConsoleCursorInfo(hOUT, &cursor_info);
}


void GMyConsole::AllowMouseInput()
{
	outMode = ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT | ENABLE_EXTENDED_FLAGS;
	SetConsoleMode(GetStdHandle(STD_INPUT_HANDLE), outMode);
	//用于关闭快速编辑模式和允许鼠标输入
}


POINT GMyConsole::GetRealMousePos()
{
	GetCursorPos(&mousePos);
	ScreenToClient(hwnd, &mousePos);
	return mousePos;
}


void GMyConsole::FullScreen()
{
	HWND hwnd = GetForegroundWindow();
	int cx = GetSystemMetrics(SM_CXSCREEN)+100;            /* 屏幕宽度 像素(new) */
	int cy = GetSystemMetrics(SM_CYSCREEN)+100;            /* 屏幕高度 像素 */

	LONG l_WinStyle = GetWindowLong(hwnd, GWL_STYLE);   /* 获取窗口信息 */
	/* 设置窗口信息 最大化 取消标题栏及边框 */
	SetWindowLong(hwnd, GWL_STYLE, (l_WinStyle | WS_POPUP | WS_MAXIMIZE) & ~WS_CAPTION & ~WS_THICKFRAME & ~WS_BORDER);

	SetWindowPos(hwnd, HWND_TOP, 0, 0, cx, cy, 0);
}


void GMyConsole::InitialHdcFro()
{
	xScreen = GetSystemMetrics(SM_CXSCREEN);
	yScreen = GetSystemMetrics(SM_CYSCREEN);
	hBitmap = CreateCompatibleBitmap(hdc, xScreen, yScreen);
	SelectObject(hdcFro, hBitmap);
}


bool GMyConsole::IsChangeDisplayScale()
{
	int zoom = GetDpiForWindow(hwnd);
	switch (zoom)
	{
	case 96:
		return true;
	default:
		MessageBox(hwnd, TEXT("您的电脑屏幕显示比例不为100%，程序无法正常运行，请在设置中将电脑屏幕的屏幕显示比例更改为100%，否则无法进行游戏！ 你可以在windows设置---系统---显示--缩放与布局中--修改比例为100%"), TEXT("重要提示!"), MB_OK| MB_ICONSTOP);
		return false;
	}
}

GMyConsole::~GMyConsole()
{
	DeleteObject(hBitmap);
	ReleaseDC(hwnd, hdc);
	DeleteDC(hdcFro);
}