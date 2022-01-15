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
	POINT GetRealMousePos();//��ȡ������ʵλ�ã���Ļ����100%
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
	HDC hdcFro;//����˫���棬����Ļhdcǰ��һ��hdc
	DWORD outMode;//�����˿���̨��ģʽ��Ϣ
	DWORD mouseInfo;
	POINT mousePos;//���������Ϣ
	INPUT_RECORD mouseRecord;//��������¼�����Ϣ
	int xScreen;
	int yScreen;
};
#endif // !GMYCONSOLE

