#include "Triangle.h"

Triangle::Triangle(float a, float b, float c) : _a(a), _b(b), _c(c)
{
}


Triangle::~Triangle()
{
}

std::string Triangle::toString(){
	return "Triangle with sides of [" + std::to_string(_a) + ", " + std::to_string(_b) + ", " + std::to_string(_c) + "].";
}