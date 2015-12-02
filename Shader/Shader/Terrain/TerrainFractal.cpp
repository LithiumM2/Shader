#include "TerrainFractal.h"


// Renvoi un terrain généré aléatoirement
TerrainFractal::TerrainFractal ( unsigned int terrain_width_, unsigned int terrain_height_ ) : Terrain ( ) {
	terrain_width = terrain_width_;
	terrain_height = terrain_height_;
	high = ( low = Noise::noise ( 0., 0. ) );

	// Pour récuperer le Low and Height
	for ( unsigned int j = 0; j < terrain_height; j++ ) {
		for ( unsigned int i = 0; i < terrain_width; i++ ) {
			MaxMin ( Noise::noise ( i, j ) );
		}
	}

	calcK ( );
}

Vector TerrainFractal::getPoint ( double x, double y ) const {
	return x > 0 && x < terrain_width && y > 0 && y < terrain_height ? Vector ( x, y, Noise::noise ( x, y ) ) : noIntersectVec;
}

// Renvoi la normal du terrain au point p
Vector TerrainFractal::normal ( const Vector & p ) const {
	float eps = .1f;
	return ( getPoint ( p.x - eps, p.y - eps ) + getPoint ( p.x + eps, p.y + eps ) ) / ( 2 * eps );
}

Vector TerrainFractal::getColor ( const Vector & p ) const { 
	return Vector ( 1., 1., 1. ); 
}
