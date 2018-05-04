#include "stdafx.h"
#include "Circle.h"


Circle::Circle(int iX, int iY, unsigned int uR) :
	x(iX),
	y(iY),
	r(uR),
	bShow(false)
{
}


Circle::~Circle()
{
}

bool Circle::isShow() const {
	return this->bShow;
}

bool Circle::show() {

}
