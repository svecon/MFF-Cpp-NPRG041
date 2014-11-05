#include "Circle.h"

Circle::Circle(float r) :_r(r)
{
}


Circle::~Circle()
{
}

std::string Circle::toString(){
	return "Circle with diameter of [" + std::to_string(_r) + "]";
}