#pragma once
#include"GAnimationSprite.h"
#include"GMoveDot.h"
class GShell :
	public GAnimationSprite
{
public:
	GShell(int, int, int, int, HDC, HDC, BITMAP, int, int);
	void Initial();
	void Working();
	void ShellRender(GMoveDot&);
private:
	bool working;
};

