#ifndef ASTEROID_H
#define ASTEROID_H

#include <vector>
#include "Anim.hpp"
#include "raylib.h"

class Asteroid{
public:
	Asteroid();
	Asteroid(Vector2 Position, float orientation, int hp, float speed, float rotspeed, std::vector<Texture2D> ExplosionAnim);
	Asteroid(Vector2 Position, float orientation, int hp, float speed, float rotspeed);
	int hp;
	Vector2 Position;
	float orientation;

	float speed;
	float rotspeed;
	static Texture2D AsteroidImage;

	void Update(); 
	void Draw();
	void getCircle();

};


#endif