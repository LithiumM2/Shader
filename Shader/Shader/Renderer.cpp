#include "Renderer.h"


Renderer::Renderer() :c(Camera(Point(50.f, 52.f, 295.6f), normalize(Vector(0.f, -0.042612f, -1.f)), Vector(0, 1, 0), 768, 768, 1.f, 10000.f, 54.5f)),
f(Film(768, 768, "test.ppm", ColorRGB{ 1.0f, 1.0f, 1.0f })), s(Scene())
{
}



ColorRGB Renderer::radiance(Ray r)
{
	float t;
	Object * obj = nullptr;
	if (s.getBound().intersect(r, nullptr, nullptr))
	{
		if ((obj = s.intersect(r, t)) != nullptr)
		{
			Point p = r.o + (r.d * t);
		
			return shade(p, obj->shape->getNormal(p), r.o, obj->c);
		}
	}
	return ColorRGB{ 0.f, 0.f, 0.f };
}

ColorRGB Renderer::shade(Point p, Normals n, Point eye, ColorRGB color)
{
	return color;
}
void Renderer::render()
{
	int h = f.yResolution;
	int w = f.xResolution;
	//BBox sceneBBox = 
#pragma omp parallel for
	for (int y = 0; y < h; y++)
	{
		std::cerr << "\rRendering: " << 100 * y / (h - 1) << "%";
		for (int x = 0; x < w; x++)
		{
			
			f.colors[x][y] = radiance(c.getRay(x, y));
		}
	}
	f.writePpm();

}


Renderer::~Renderer()
{
}
