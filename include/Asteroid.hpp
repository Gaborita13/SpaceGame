#ifndef ASTEROID_H
#define ASTEROID_H

#include <vector>
#include "Anim.hpp"
#include "raylib.h"

class Asteroid{
public:
	Asteroid();
	Asteroid(Vector2 Position, float orientation, int hp, float speed, float rotspeed, int ratio, std::vector<Texture2D> ExplosionAnim);
	Asteroid(Vector2 Position, float orientation, int hp, float speed, float rotspeed, float ratio);
	int hp;
	float ratio;
	bool Alive;
	bool touched;
	Vector2 Position;
	Vector2 NextPosition;
	float orientation;
	float AsteroidRadius;
	float HitBoxRadius;
	Vector2 HitBoxCenter;

	int AsteroidFrameCounter;
	int AsteroidFrameNumber;
	int AsteroidFrameDelay;
	int AsteroidFrame;

	float speed;
	float rotspeed;
	Anim ExplosionAnim;
	static Texture2D AsteroidImage;
	static std::vector<Texture2D> ExplosionTextures;
 
	void Update(); 
	static void UnloadImages();
	void Draw();
	void getCircle();

};


#endif