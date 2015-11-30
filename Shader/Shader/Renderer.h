#pragma once
#include <iostream>
#include "Camera.h"
#include "Scene\Scene.h"
class Renderer
{
	Camera c;
	Scene s;
	Film f;

public:
	Renderer();
	void render();
	ColorRGB radiance(Ray r);
	ColorRGB shade(Point p, Normals n, Point eye, ColorRGB color);
	~Renderer();
};

