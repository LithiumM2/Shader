#pragma once

#include "..\Geometry\Vector.h"
#include "Terrain.h"
#include "..\Noise\Noise.h"

class TerrainFractal :
	public Terrain {

public:
	// Renvoi un terrain géneré aléatoirement
	TerrainFractal ( unsigned terrain_width_, unsigned int terrain_height_ );

	Vector getPoint ( double x, double y ) const;

	// Renvoi la normal du terrain au point p
	Vector normal ( const Vector & p ) const;

	Vector getColor ( const Vector & p ) const;
};

