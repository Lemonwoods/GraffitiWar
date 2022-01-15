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
	//���ڹرտ��ٱ༭ģʽ�������������
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
	int cx = GetSystemMetrics(SM_CXSCREEN)+100;            /* ��Ļ��� ����(new) */
	int cy = GetSystemMetrics(SM_CYSCREEN)+100;            /* ��Ļ�߶� ���� */

	LONG l_WinStyle = GetWindowLong(hwnd, GWL_STYLE);   /* ��ȡ������Ϣ */
	/* ���ô�����Ϣ ��� ȡ�����������߿� */
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
		MessageBox(hwnd, TEXT("���ĵ�����Ļ��ʾ������Ϊ100%�������޷��������У����������н�������Ļ����Ļ��ʾ��������Ϊ100%�������޷�������Ϸ�� �������windows����---ϵͳ---��ʾ--�����벼����--�޸ı���Ϊ100%"), TEXT("��Ҫ��ʾ!"), MB_OK| MB_ICONSTOP);
		return false;
	}
}

GMyConsole::~GMyConsole()
{
	DeleteObject(hBitmap);
	ReleaseDC(hwnd, hdc);
	DeleteDC(hdcFro);
}