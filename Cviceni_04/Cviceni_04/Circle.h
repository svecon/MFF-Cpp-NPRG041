#pragma once
#include "Shape.h"
class Circle :
	public Shape
{
public:
	Circle(float r);
	~Circle();

	float _r;

	std::string toString();
};

