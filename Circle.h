#pragma once

#include <graphics.h>

class Circle
{
public:
	Circle(int iX,int iY,unsigned int uR);
	~Circle();
	bool isShow() const;
	bool show();
	void moveTo(int x, int y);
private:
	int x, y;
	unsigned int r;
	bool bShow;
};

