#pragma once
#include"GSprite.h"
#include<Windows.h>
class GAnimationSprite
	: public GSprite
{
public:
	GAnimationSprite(int tw,int th,int fps,int fram, HDC hdcD, HDC hdcS, BITMAP bitmap, int spe, int z);
	void Render(int,int);
	void Update(double);//在每一帧被调用，在动画精灵中，这个函数将主要控制当前动画精灵显示哪一帧
	void SetFrame(int);//设置动画精灵当前显示哪一帧
	void Play();//播放动画精灵
	void Stop();//停止动画精灵播放
	void Resume();//恢复动画精灵的播放
	void SetTexture(int,int );//设置动画精灵的纹理
	void SetFrames(int);//设置动画精灵的总帧数
	void SetnFps(int);//设置动画精灵的播放速度
	int GetHalftexWidth()const;
	int GetHalftexHeight()const;
protected:
	int txStart=0;//截断坐标的横坐标
	int tyStart=0;//截断坐标的纵坐标
	int texWidth;//精灵纹理图片的宽度
	int texHeight;//精灵纹理图片的高度
	bool play=false;//控制是否播放动画
	double interval;//每一帧之间的时间间隔
	int nFps;//每秒多少帧
	double sinceLastFrame=0;//记录上一次更新以后到现在的时间
	int frames;//总帧数
	int currentFrames=0;//当前帧数的索引值
	short mode = 0;//控制动画播放的模式
};