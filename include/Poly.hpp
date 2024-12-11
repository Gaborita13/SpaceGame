#ifndef POLY_H
#define POLY_H

#include "raylib.h"
#include <iostream>
#include <vector>

class Poly{
public:
	std::vector<Vector2> Points;
	Vector2 Position;
	Vector2 Centroid;
	float orientation;
	int size;
	Poly();
	Poly(std::vector<Vector2> staticpoints, Vector2 Position, float orientation);
	static Poly RectangleToPoly(Rectangle rec);
	void Translate(Vector2 translation);
	void Rotate(float rotation);
	void Draw();
	bool CheckCollisionPoly();
};


#endif