#pragma once
#include "..\Geometry\Ray.h"
#include "..\Geometry\BBox.h"
#include "..\Global\Global.h"
#include "..\Film.h"
#include "..\ColorRGB.h"

class Shapes
{
public:
	Shapes();
	virtual bool canIntersect();
	virtual bool intersect(const Ray &ray, float * tHit) const = 0;
	virtual BBox getBound() const = 0;
	virtual Normals getNormal(Point p) const = 0;
	~Shapes();
};