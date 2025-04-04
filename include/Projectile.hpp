#ifndef PROJECTILE_H
#define PROJECTILE_H

#include "raylib.h"
#include "Entity.hpp"
#include "util.hpp"
#include "Anim.hpp"
#include <vector>

class Projectile : public Entity{
public:
	Projectile(Vector2 position, int speed, std::vector<Texture2D> ProjectileAnim);
	Projectile();
	~Projectile();
	Rectangle HitBox;
	int speed;
	bool active;

	int BulletFrameDelay;
	int BulletFrameCounter;
	int BulletFrameNumber;
	int BulletFrame;
	static Sound BulletSound;
	Anim ProjectileAnimation;


	void Draw();
	void Update();
	void UnloadAnim();
	void UnloadProjectileImage();
	std::vector<Texture2D> ProjectileAnim;
};

#endif