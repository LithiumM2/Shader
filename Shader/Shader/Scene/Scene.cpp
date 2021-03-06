#include "Scene.h"


Scene::Scene() : objects(std::vector<Object *>())
{
	const ColorRGB white = ColorRGB{ 0.75f, 0.75f, 0.75f } * 255.f;
	const ColorRGB blue = ColorRGB{ .25f, .25f, .75f } * 255.f;
	const ColorRGB red = ColorRGB{ .75f, .25f, .25f } * 255.f;
	const ColorRGB yellow = ColorRGB{ .9f, .1f, .9f } * 255.f;
	const ColorRGB purple = ColorRGB{ .9f, .9f, .1f } * 255.f;
	
	//// Left Wall
	//objects.push_back(new Object(new Triangle(Point(0.f, 0.f, 0.f), Point(0.f, 100.f, 0.f), Point(0.f, 0.f, 150.f));
	//objects.push_back(new Object(new Triangle(Point(0.f, 100.f, 150.f), Point(0.f, 100.f, 0.f), Point(0.f, 0.f, 150.f)), new Diffus(red)));

	//// Right Wall
	//objects.push_back(new Object (new Triangle(Point(100.f, 0.f, 0.f), Point(100.f, 100.f, 0.f), Point(100.f, 0.f, 150.f)), new Diffus(blue)));
	//objects.push_back(new Object (new Triangle(Point(100.f, 100.f, 150.f), Point(100.f, 100.f, 0.f), Point(100.f, 0.f, 150.f)), new Diffus (blue)));
	//// Back wall
	//objects.push_back(new Object (new Triangle(Point(0.f, 0.f, 0.f), Point(100.f, .0f, 0.f), Point(100.f, 100.f, 0.f)), new Diffus(white)));
	//objects.push_back(new Object (new Triangle(Point(0.f, 0.f, 0.f), Point(.0f, 100.f, 0.f), Point(100.f, 100.f, 0.f)), new Diffus(white)));
	//
	//// Bottom Floor
	//objects.push_back(new Object (new Triangle(Point(0.f, 0.f, 0.f), Point(100.f, .0f, 0.f), Point(100.f, 0.f, 150.f)), new Diffus(white)));
	//objects.push_back(new Object (new Triangle(Point(0.f, 0.f, 0.f), Point(.0f, 0.f, 150.f), Point(100.f, 0.f, 150.f)), new Diffus(white)));

	//// Top Ceiling
	//objects.push_back(new Object (new Triangle(Point(0.f, 100.f, 0.f), Point(100.f, 100.f, 0.f), Point(0.f, 100.f, 150.f)), new Diffus(white)));
	//objects.push_back(new Object (new Triangle(Point(100.f, 100.f, 150.f), Point(100.f, 100.f, 0.f), Point(0.f, 100.f, 150.f)), new Diffus(white)));
	//
	// Sphere
	//objects.push_back(new Object (new Sphere(16.5, Point(27, 16.5, 47)), red));
	//objects.push_back(new Object(new Sphere(16.5, Point(73, 16.5, 78)), white));
//	objects.push_back(new Object(new Cube(Point(72, 15.5, 77), Point(73, 16.5, 78)), new Diffus(white)));	
	Terrain * t = new TerrainFractal(100, 100);
	objects.push_back(new Object(t, white));
	/*
	Mesh * m = new Mesh();
	*m = Mesh::readFromObj("test.obj", Vector(50, 16.5, 50));
	objects.push_back(new Object (m, new Diffus(white)));
	*/
	light = Point(50.f, 50.f, 300.f);
	
}

Object * Scene::intersect(const Ray &r, float & t)
{
	Object * ret = nullptr;
	t = INFINITY;
	float d;
	for (Object * &object : objects)
	{
		if (object->shape->getBound().intersect(r, nullptr, nullptr))
		{
			bool isIntersect = object->shape->intersect(r, &d);
			if (isIntersect && d < t)
			{
				t = d;
				ret = object;
			}
		}
	}

	return ret;
}

BBox Scene::getBound() const
{
	if (objects.size() <= 0) return BBox();
	BBox res = objects[0]->shape->getBound();
	for (unsigned int i = 1; i < objects.size(); ++i)
	{
		unionBBox(res, objects[i]->shape->getBound());
	}
	return res;
}

Scene::~Scene()
{
//	for (unsigned int i = 0; i < objects.size(); ++i)
//		delete objects[i];
}
