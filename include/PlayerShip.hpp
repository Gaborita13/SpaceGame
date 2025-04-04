#ifndef PLAYERSHIP_H
#define PLAYERSHIP_H

#include "raylib.h"
#include "Anim.hpp"
#include "Entity.hpp"
#include "Projectile.hpp"
#include "util.hpp"
#include "Shield.hpp"
#include <vector>


class PlayerShip : public Entity{
	public:
		PlayerShip();
		~PlayerShip();
		void MoveLeft();
		void MoveRight();
		void MoveUp();
		void MoveDown();
		void ShootProjectile();
		void Revive();
		void Draw();
		void Update();
		bool moving;
		int hp;
		bool touched;
		bool shooting;
		bool Exploded;
		bool ActiveShield;
		int ShieldTime;
		float LastFireTime;
		
		int ProjectileFrameNumber;

		int EngineFrameDelay;
		int EngineFrameCounter;
		int EngineFrameNumber;
		int EngineFrame;
		Anim EngineAnimation;

		int ExplosionFrameDelay;
		int ExplosionFrameCounter;
		int ExplosionFrameNumber;
		int ExplosionFrame;
		Anim ExplosionAnimation;
		
		int GunFrameDelay;
		int GunFrameCounter;
		int GunFrameNumber;
		int GunFrame;
		Anim GunAnimation;
		Rectangle HitBox;
		int HitBoxCircleRadius;
		Vector2 HitBoxCircleCenter;
		
		Texture2D image;
		std::vector<Texture2D> ShipImages;
		Sound ShipExplosionSound;
		Shield PlayerShield;

		Texture2D Thruster;
		Texture2D Gun;
		std::vector<Texture2D> EngineAnim;
		std::vector<Texture2D> GunAnim;
		std::vector<Texture2D> ProjectileAnim;
		std::vector<Texture2D> ShipExplosionAnim;
		std::vector<Projectile> projectiles;
};

#endif
