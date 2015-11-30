#pragma once
#include "Shapes\Shapes.h"
class Object
{
public:
	Shapes * shape;
	ColorRGB c;
	Object(Shapes * shape_, ColorRGB c_);
	~Object();
};

