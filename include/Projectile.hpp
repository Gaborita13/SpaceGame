#ifndef PROJECTILE_H
#define PROJECTILE_H

#include "raylib.h"
#include "util.hpp"
#include "Anim.hpp"
#include <vector>

class Projectile{
public:
	Projectile(Vector2 position, int speed, std::vector<Texture2D> ProjectileAnim);
	Projectile();
	~Projectile();
	Vector2 position;
	Rectangle HitBox;
	int speed;
	bool active;

	int BulletFrameDelay;
	int BulletFrameCounter;
	int BulletFrameNumber;
	int BulletFrame;
	Anim ProjectileAnimation;


	void Draw();
	void Update();
	void UnloadAnim();
	void UnloadProjectileImage();
	std::vector<Texture2D> ProjectileAnim;
};

#endif