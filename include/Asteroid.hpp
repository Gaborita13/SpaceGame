#ifndef ASTEROID_H
#define ASTEROID_H

#include <vector>
#include "Anim.hpp"
#include "raylib.h"

class Asteroid{
public:
	Asteroid();
	Asteroid(Vector2 Position, float orientation, int hp, float speed, float rotspeed, int ratio, std::vector<Texture2D> ExplosionAnim);
	Asteroid(Vector2 Position, float orientation, int hp, float speed, float rotspeed, int ratio);
	int hp;
	int ratio;
	bool Alive;
	Vector2 Position;
	float orientation;

	int AsteroidFrameCounter;
	int AsteroidFrameNumber;
	int AsteroidFrameDelay;
	int AsteroidFrame;

	float speed;
	float rotspeed;
	static Anim ExplosionAnim;
	static Texture2D AsteroidImage;
 
	void Update(); 
	static void UnloadImages();
	void Draw();
	void getCircle();

};


#endif