#pragma once
#include <string>

class Shape
{
public:
	Shape();
	virtual ~Shape();

	virtual std::string toString();
};

