#include "Object.h"



Object::Object(Shapes * shape_, ColorRGB c_) : shape(shape_), c(c_)
{
}


Object::~Object()
{
	delete shape;
}