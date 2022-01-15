#pragma once
#include<Windows.h>

#define OBSTACLE_DOT_SPEED 1

class GObstacleDot
{
public:
	
	//������ײ�������ʵ�� �ɷɻ���ʵ��
	GObstacleDot(HDC hdc);
	~GObstacleDot();
	void SetSpeed(int Speed);
	void SetHpenAndHbrush();//��ȡ������� ��ˢ����
	void SetBlue();
	void SetRed();
	void SetRandColor();
	void SetPos(POINT positionPosint);//����������λ��(new)
	void CalculateNextPos(POINT positionPos);//������һ�����λ��
	void SetNextPos();//����ǰλ������Ϊ��һ��λ��
	void IsCrashed(POINT positionPoint, int Positionredius);//�ж��Ƿ�������ײ����������֮����жϣ�
	void IsCrashed(RECT&);//�ж��Ƿ��ھ��η�Χ�ڣ�����ˢ�ӵ��ж���new��
	bool IsGameOver(POINT positionPoint, int Positionredius);//�ж���Ϸ�Ƿ��������������֮����жϣ�
	void ResetPos(POINT positionPosint);//����ʹ�õ�//(new)
	bool IsPosValid(POINT positionPosint);//�жϵ��λ���Ƿ�Ϸ�����������λ�ú�ʹ�ã���new��
	void SetConsoleSize(POINT Boundary);
	void SetHdcDest(HDC hdc);//������ȾĿ��dc
	bool Getvisibility();
	void Render(POINT positionPos);//��Ⱦ
	void CrashWithLine(double, double, int);//new
	void CrashWithVerticalLine(int, int);//new
	POINT GetCurrentPos()const;//new
	void SetVisibility(bool);
private:
	HDC hdcDest;//��ȾĿ��DC
	HPEN hPenOld;
	HBRUSH hBrushOld;
	POINT rBoundary = { GetSystemMetrics(SM_CXSCREEN),GetSystemMetrics(SM_CYSCREEN) };//����������ֱ߽�Ĵ�С
	int distance;
	bool visibility;//���ö����Ƿ�ɼ�
	bool existence;//���ö����Ƿ������ײ

	HBRUSH hBrush;//���ö���������ɫ
	HPEN hPen;//���ö���ı߿���ɫ
	HPEN hPenBlue;
	HBRUSH hBrushBlue;
	HPEN hPenRed;
	HBRUSH hBrushRed;
	short colorMode = 1;

	POINT currentPos;//��ǰλ��
	POINT nextPos;//��һ��λ��
	int redius;//(�ĳɰ뾶)
	static int speed;//ÿһ֡�ƶ�����
	int produceRedius = 250;//������ֵķ�Χ(new)
};