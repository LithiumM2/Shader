#pragma once

#include <math.h>
#include "..\Shapes\Shapes.h"
#include "..\Geometry\Vector.h"
#include "..\Global\Constants.h"

class Terrain :
	public Shapes {

protected:
	unsigned int terrain_width;
	unsigned int terrain_height;
	double k;						// Pente maximale
	double high, low;				// Paramètre pour connaitre la hauteur max et min de la map

public:
	Terrain ( ) : Shapes ( ) { }

	//Pour definir un max et un min
	void MaxMin ( double );

	// Renvoie vrai si le point p est en dehors du terrain, faux sinon.
	virtual bool inside ( const Vector & p ) const;

	// calcul la distance en hauteur entre le point p et le terrain
	virtual double distance ( const Vector & p ) const;

	virtual Vector getColor ( const Vector & p ) const = 0;

	// Renvoi la normal du terrain au point p
	virtual Vector normal ( const Vector & ) const = 0;

	// Renvoie le point x, y, z appartenant a pointList a partir du x, y (recherche matrice + interpolation).
	virtual Vector getPoint ( double x, double y ) const = 0;

	Vector getOrigin ( ) const {
		return Vector ( 0. ); // TODO
	}

	// Renvoie vrai si le Ray r touche le terrain.
	//bool intersection(Ray r, double &t) const;

	// DEBUG
	unsigned int getWidth ( ) const {
		return terrain_width;
	}

	unsigned int getHeight ( ) const {
		return terrain_height;
	}

	double getLow ( ) const {
		return low;
	}

	double getHigh ( ) const {
		return high;
	}
	
	// Calcul la pente maximale du terrain
	void calcK ( );

	//Mesh* GetMesh ( );
	
};

