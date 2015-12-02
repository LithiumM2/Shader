#include "Terrain.h"

// Fonction pour trouver la hauteur max et min
void Terrain::MaxMin ( double x ) {
	high = std::max ( high, x );
	low = std::min ( low, x );
}

// Renvoie vrai si le point p est en dehors du terrain, faux sinon.
bool Terrain::inside ( const Vector &  p ) const {
	return ( p.z > getPoint ( p.x, p.y ).z );
}

// calcul la distance en hauteur entre le point p et le terrain
double Terrain::distance ( const Vector &  p ) const {
	Vector pointTerrain = getPoint ( p.x, p.y );

	if ( pointTerrain != noIntersectVec ) // Car distance en z en attendant box.
		return ( p.z - pointTerrain.z ) * k; // 0.5 = pente maximale

	return noIntersect;
}

// Calcul la pente maximale du terrain
void Terrain::calcK ( ) {
	k = std::abs ( getPoint ( 0., 0. ).z - getPoint ( 0., 1. ).z );
	for ( unsigned int j = 0; j < terrain_height - 1; j++ ) {
		for ( unsigned int i = 0; i < terrain_width - 1; i++ ) {
			k = std::max (
				std::max (
				std::max ( k, double ( std::abs ( getPoint ( i, j ).z - getPoint ( i, j + 1 ).z ) ) ),
				std::abs ( double ( getPoint ( i, j ).z - getPoint ( i + 1, j ).z ) ) ),
				std::abs ( double ( getPoint ( i, j ).z - getPoint ( i + 1, j + 1 ).z ) ) );
		}
	}
	k /= high;
}
