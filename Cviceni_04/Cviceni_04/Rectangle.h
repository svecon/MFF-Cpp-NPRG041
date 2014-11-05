#pragma once
#include "Shape.h"
class Rectangle :
	public Shape
{
public:
	Rectangle(float a, float b);
	~Rectangle();

	float _a, _b;

	std::string toString();
};

