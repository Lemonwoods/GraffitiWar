#pragma once
#include<Windows.h>

#define OBSTACLE_DOT_SPEED 1

class GObstacleDot
{
public:
	
	//计算碰撞由这个类实现 由飞机类实现
	GObstacleDot(HDC hdc);
	~GObstacleDot();
	void SetSpeed(int Speed);
	void SetHpenAndHbrush();//获取随机画笔 画刷功能
	void SetBlue();
	void SetRed();
	void SetRandColor();
	void SetPos(POINT positionPosint);//随机产生点的位置(new)
	void CalculateNextPos(POINT positionPos);//计算下一个点的位置
	void SetNextPos();//将当前位置设置为下一个位置
	void IsCrashed(POINT positionPoint, int Positionredius);//判断是否发生了碰撞（道具与球之间的判断）
	void IsCrashed(RECT&);//判断是否在矩形范围内，用于刷子的判定（new）
	bool IsGameOver(POINT positionPoint, int Positionredius);//判断游戏是否结束（精灵与球之间的判断）
	void ResetPos(POINT positionPosint);//重新使用点//(new)
	bool IsPosValid(POINT positionPosint);//判断点的位置是否合法（在重设点的位置后使用）（new）
	void SetConsoleSize(POINT Boundary);
	void SetHdcDest(HDC hdc);//设置渲染目标dc
	bool Getvisibility();
	void Render(POINT positionPos);//渲染
	void CrashWithLine(double, double, int);//new
	void CrashWithVerticalLine(int, int);//new
	POINT GetCurrentPos()const;//new
	void SetVisibility(bool);
private:
	HDC hdcDest;//渲染目标DC
	HPEN hPenOld;
	HBRUSH hBrushOld;
	POINT rBoundary = { GetSystemMetrics(SM_CXSCREEN),GetSystemMetrics(SM_CYSCREEN) };//随机产生数字边界的大小
	int distance;
	bool visibility;//设置对象是否可见
	bool existence;//设置对象是否可以碰撞

	HBRUSH hBrush;//设置对象的填充颜色
	HPEN hPen;//设置对象的边框颜色
	HPEN hPenBlue;
	HBRUSH hBrushBlue;
	HPEN hPenRed;
	HBRUSH hBrushRed;
	short colorMode = 1;

	POINT currentPos;//当前位置
	POINT nextPos;//下一个位置
	int redius;//(改成半径)
	static int speed;//每一帧移动距离
	int produceRedius = 250;//不会出现的范围(new)
};