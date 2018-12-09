#pragma once

#include "Geometry.h"
#include "..\Constantes.h"
#include "../Vec3.h"

class Circle :
	public Geometry {

public:
	Vec3<float> center;
	float radius;

	Circle();
	Circle(const Vec3<float> o, const float &r);
	
	float area() const;
	float perimeter() const;
	void shrink(float t);
};

