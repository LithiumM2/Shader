#pragma once
#include "..\Shapes\Shapes.h"
#include "..\Object.h"
#include "..\Shapes\Triangle.h"
#include "..\Shapes\Sphere.h"
#include "..\Shapes\Cube.h"
#include "..\Shapes\Mesh.h"
#include "..\Global\Constants.h"
#include "..\Geometry\Ray.h"
class Scene
{
	std::vector<Object *> objects;
public:
	Point light;
	Scene();
	Object * intersect(const Ray &r, float & t);
	BBox getBound() const;
	~Scene();
};

