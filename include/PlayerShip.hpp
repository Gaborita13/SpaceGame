#ifndef PLAYERSHIP_H
#define PLAYERSHIP_H

#include "raylib.h"
#include "Anim.hpp"
#include "Projectile.hpp"
#include "util.hpp"
#include <vector>


class PlayerShip{
	public:
		PlayerShip();
		~PlayerShip();
		void MoveLeft();
		void MoveRight();
		void MoveUp();
		void MoveDown();
		void ShootProjectile();
		void Draw();
		bool moving;
		bool shooting;
		float LastFireTime;
		
		int ProjectileFrameNumber;


		int EngineFrameDelay;
		int EngineFrameCounter;
		int EngineFrameNumber;
		int EngineFrame;
		Anim EngineAnimation;
		
		int GunFrameDelay;
		int GunFrameCounter;
		int GunFrameNumber;
		int GunFrame;
		Anim GunAnimation;
		
		Vector2 Position;
		Texture2D image;
		Texture2D Thruster;
		Texture2D Gun;
		std::vector<Texture2D> EngineAnim;
		std::vector<Texture2D> GunAnim;
		std::vector<Texture2D> ProjectileAnim;
		std::vector<Projectile> projectiles;
};

#endif
