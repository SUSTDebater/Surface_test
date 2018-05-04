#pragma once
#include <vector>
#include "Circle.h"
class Surface
{
public:
	Surface();
	Surface(int num);
	~Surface();
	unsigned int size();
	const Circle& top() const;
	Circle& pushTop();
	void stick(int num);
private:
	std::vector<Circle> surs;
};

