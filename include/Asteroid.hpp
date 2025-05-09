#ifndef ASTEROID_H
#define ASTEROID_H

#include <vector>
#include "Anim.hpp"
#include "Entity.hpp"
#include "raylib.h"
#include "Poly.hpp"

class Asteroid : public Entity{
public:

	Asteroid();
	Asteroid(Vector2 Position, float orientation, int hp, float speed, float rotspeed, int ratio, std::vector<Texture2D> ExplosionAnim);
	Asteroid(Vector2 Position, float orientation, int hp, float speed, float rotspeed, float ratio);
	int hp;
	float ratio;
	bool Alive;
	bool Exploded;
	bool touched;
	float orientation;
	float AsteroidRadius;
	float HitBoxRadius;
	Vector2 HitBoxCenter;

	std::vector<Vector2> polygonpoints;
	Poly polygon;

	int AsteroidFrameCounter;
	int AsteroidFrameNumber;
	int AsteroidFrameDelay;
	int AsteroidFrame;

	float speed;
	float rotspeed;
	Anim ExplosionAnim;
	static Texture2D AsteroidImage;
	static Sound AsteroidExplosionSound;
	Sound LocalAsteroidExplosionSound;
	static std::vector<Texture2D> ExplosionTextures;
 
 
	static void UnloadImages();
	void Update();
	void Draw();
	void getCircle();

};


#endif