#ifndef ENTITY_H
#define ENTITY_H


#include <vector>
#include "raylib.h"

class Entity{
public:
	Vector2 Position;
	Entity();
	Entity(Vector2 Position);

	virtual void Draw() = 0;
	virtual void Update() = 0;
	
};


#endif