#pragma once
#include <iostream>
#include "Camera.h"
#include "Scene\Scene.h"
class Renderer
{
	Camera c;
	Scene s;
	Film f;
	ColorRGB ambiant = ColorRGB{ 0.75f, 0.75f, 0.75f } *255.f;
public:
	Renderer();
	void render();
	ColorRGB radiance(Ray r);
	ColorRGB shade(Point p, Normals n, Point eye, ColorRGB color);
	~Renderer();
};

