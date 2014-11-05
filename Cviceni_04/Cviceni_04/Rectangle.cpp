#include "Rectangle.h"

Rectangle::Rectangle(float a, float b) : _a(a), _b(b)
{
}


Rectangle::~Rectangle()
{
}

std::string Rectangle::toString(){
	return "Rectangle with sides of [" + std::to_string(_a) + ", " + std::to_string(_b) + "].";
}