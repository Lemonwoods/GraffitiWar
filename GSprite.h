#pragma once
#include<Windows.h>
class GSprite
{
public:
	GSprite(HDC hdcD,HDC hdcS,BITMAP bitmap,int spe,int z);//new 构造函数
	~GSprite();
	void Render(int,int);//渲染
	void SetHotPoint(const POINT temp);//设置热点坐标(new)
	void SetPos(const POINT temp);//设置精灵的当前位置(new)
	void CalculateNextPos(const POINT PositionPos);//计算精灵的下一个热点坐标位置 参数是鼠标坐标(new)
	void CalculateNextPos(POINT&, bool);//与y轴负半轴之间的角度
	POINT CalculateNextPos(POINT&, int);
	void UpdateHotPoint();//更新热点坐标
	void SetZ_Order(int);//设置精灵的Z轴坐标
	void SetAngle(double);//设置精灵的旋转角度
	void SetScaleFactor(double,double);//设置精灵的缩放系数
	void SetBitmap(BITMAP temp);//设置位图文件结构信息的指针(new)
	void SetKeyColor(COLORREF Color);//设置关键色
	void SetVisibility(bool Judge);//设置精灵的可见性
	void SetDestDC(HDC thdcDest);//设置精灵渲染的目的DC
	void SetSpriteDC(HDC thdcSprite);//设置精灵位图DC
	void SetSpeed(int);
	int GetWidth();//获得精灵的宽度
	int GetHeight();//获得精灵的高度
	POINT GetPos();//获得精灵的位置(new)
	POINT GetHotPoint();//获得精灵的热点坐标
	POINT GetCurrentPos();
	bool GetVisibility();//获得精灵的可见性
	void SetTransparent(bool);//设置是否进行透明渲染
	bool GetTransparent();//获取是否进行透明渲染
	void SetSinAndCosValue(double,double);//new 重载函数，此重载用于在给定点的情况下使用
	void SetSinAndCosValue(double);//new 重载函数，此重载用于在给定角度(注意不是弧度）的情况下使用
	double GetSinValue();//new
	double GetCosValue();//new
	void SetxFormAngle();//new
	void SetxFormScale();//new
	void SetxFormPos(int, int);//new
	void RotateAroundHotPoint(double,double);//new 绕热点旋转
	void RotateAroundHotPoint(double);//new
	void ReSetTransformWorld();
	POINT GetnextHotPoint();//暂时用来测试（new）
	double Distance(int, int);//用于计算对象与目标点之间的距离

protected:
	HDC hdcDest;//渲染目的DC
	HDC hdcSprite;//精灵所指向的图片资源

	POINT currentPos;//精灵的当前位置
	POINT hotPoint;//热点坐标
	POINT nextHotPoint;//精灵的下一个热点位置

	BITMAP bitmap;
	int width;//设置精灵的宽度
	int height;//设置精灵的高度
	int Z_Order;//Z轴坐标，用于决定渲染时的叠加次序
	COLORREF keyColor;//关键色，渲染时为透明

	int speed;//精灵的速度

	double xScaleFactor;//精灵的x方向缩放系数
	double yScaleFactor;//精灵的y方向缩放系数
	double angle;//设置旋转的角度
	double sinValue;//new 用于存储旋转的sin值
	double cosValue;//new 用于存储旋转的cos值
	
	XFORM xFormAngle;//变换矩阵，用于进行位图的旋转
	XFORM xFormScale;//变换矩阵，用于进行位图的缩放
	XFORM xFormPos;//变换矩阵，用于进行位图的位移
	XFORM world;//new 合并矩阵
	XFORM reWorld;//new 合并恢复矩阵

	bool visibility=true;//设置精灵的可见性
	bool transparent;//设置是否进行透明渲染
};