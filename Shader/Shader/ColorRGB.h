#pragma once
#include "Global\Global.h"
struct ColorRGB
{
	float x, y, z;
	ColorRGB operator*(float f)
	{
		return ColorRGB{ x * f, y * f, z * f };
	}

	ColorRGB operator*(ColorRGB c)
	{
		return ColorRGB{ x * c.x, y * c.y, z * c.z };
	}


	ColorRGB operator+(ColorRGB c)
	{
		return ColorRGB{ x + c.x, y + c.y, z + c.z };
	}

	ColorRGB cclamp(float min, float max)
	{
		return ColorRGB{ clamp(x, min, max), clamp(y, min, max), clamp(z, min, max) };
	}

	ColorRGB applyGamma()
	{
		float p = 1.f / 2.2f;
		return ColorRGB{ powf(x, p), powf(y, p), powf(z, p) };
	}
	ColorRGB toRgb()
	{
		return operator*(255.f);
	}
};