#pragma once
#include"GSprite.h"
#include<Windows.h>
class GAnimationSprite
	: public GSprite
{
public:
	GAnimationSprite(int tw,int th,int fps,int fram, HDC hdcD, HDC hdcS, BITMAP bitmap, int spe, int z);
	void Render(int,int);
	void Update(double);//��ÿһ֡�����ã��ڶ��������У������������Ҫ���Ƶ�ǰ����������ʾ��һ֡
	void SetFrame(int);//���ö������鵱ǰ��ʾ��һ֡
	void Play();//���Ŷ�������
	void Stop();//ֹͣ�������鲥��
	void Resume();//�ָ���������Ĳ���
	void SetTexture(int,int );//���ö������������
	void SetFrames(int);//���ö����������֡��
	void SetnFps(int);//���ö�������Ĳ����ٶ�
	int GetHalftexWidth()const;
	int GetHalftexHeight()const;
protected:
	int txStart=0;//�ض�����ĺ�����
	int tyStart=0;//�ض������������
	int texWidth;//��������ͼƬ�Ŀ��
	int texHeight;//��������ͼƬ�ĸ߶�
	bool play=false;//�����Ƿ񲥷Ŷ���
	double interval;//ÿһ֮֡���ʱ����
	int nFps;//ÿ�����֡
	double sinceLastFrame=0;//��¼��һ�θ����Ժ����ڵ�ʱ��
	int frames;//��֡��
	int currentFrames=0;//��ǰ֡��������ֵ
	short mode = 0;//���ƶ������ŵ�ģʽ
};