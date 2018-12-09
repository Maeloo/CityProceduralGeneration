#pragma once

#include "..\..\Vec3.h"
#include "..\Symbol.h"
#include "..\Map\TriangleSymbol.h"
#include "..\Map\QuadrangleSymbol.h"
#include "..\..\Geometry\Triangle.h"
#include "..\..\Geometry\Pentagone.h"

class PentagoneSymbol :
	public Symbol {

protected:
	Vec3<float> p[5], mid;

public:
	PentagoneSymbol ( const Vec3<float> &, const Vec3<float> &, const Vec3<float> &, const Vec3<float> &, const Vec3<float> &, const Vec3<float> & );
	
	void Generate ( Mesh &mesh, int compteur ) const;
};

