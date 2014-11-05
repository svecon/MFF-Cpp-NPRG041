#pragma once
#include "Shape.h"
class Triangle :
	public Shape
{
public:
	Triangle(float a, float b, float c);
	~Triangle();

	float _a, _b, _c;

	std::string toString();
};

