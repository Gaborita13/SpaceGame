#include "PlayerShip.hpp"


PlayerShip::PlayerShip() : Entity({200, 100}) {
	
	moving = true;
	shooting = false;
	
	PlayerShield = Shield(Position);
	ShieldTime = 240;
	HitBoxCircleRadius = 51;
	EngineFrameCounter = 0;
	EngineFrameNumber = 4;
	EngineFrameDelay = 8;
	EngineFrame = 0;
	LastFireTime = 0.0;
	ShipExplosionSound = LoadSound("../Assets/Sound/Ship_Explosion.mp3");
	HitBox = {Position.x - 70, Position.y + 20, 50, 58};
	Exploded = false;
	GunFrameCounter = 0;
	GunFrameNumber = 7;
	GunFrameDelay = 4;
	GunFrame = 0;
	hp = 4;
	ProjectileFrameNumber = 4;
	touched = false;

	ExplosionFrameDelay = 2;
	ExplosionFrameCounter = 0;
	ExplosionFrameNumber = 75;
	ExplosionFrame = 0;
	
	ShipImages.push_back(LoadTexture("../Assets/Foozle/Main/Base/PNGs/MainShip1HpRS.png"));
	ShipImages.push_back(LoadTexture("../Assets/Foozle/Main/Base/PNGs/MainShip2HpRS.png"));
	ShipImages.push_back(LoadTexture("../Assets/Foozle/Main/Base/PNGs/MainShip3HpRS.png"));
	ShipImages.push_back(LoadTexture("../Assets/Foozle/Main/Base/PNGs/MainShipFullRS.png"));
	image = ShipImages[hp - 1];
	Thruster = LoadTexture("../Assets/Foozle/Main/Engine/PNGs/MainShipEngineMod3.png");
	Gun = LoadTexture("../Assets/Foozle/Main/Weapons/PNGs/AutoCannon02.png");
	Image EngineEffect = LoadImage("../Assets/Foozle/Main/EngineEffects/PNGs/EngineEffect2.png");
	Image GunEffect = LoadImage("../Assets/Foozle/Main/Weapons/PNGs/AutoCannon2.png");
	Image ProjectileEffect = LoadImage("../Assets/Foozle/Main ship weapons/PNGs/Bullet.png");
	Image ExplosionEffect = LoadImage("../Assets/spritesheet/spritesheet.png");


	ShipExplosionAnim = util::PNGArraytoAnim(ExplosionEffect, 8, 10);
	EngineAnim = util::PNGtoAnim(EngineEffect, EngineFrameNumber);
	GunAnim = util::PNGtoAnim(GunEffect, GunFrameNumber);
	ProjectileAnim = util::PNGtoAnim(ProjectileEffect, ProjectileFrameNumber);
	UnloadImage(ExplosionEffect);
	UnloadImage(EngineEffect);
	UnloadImage(GunEffect);
	UnloadImage(ProjectileEffect);
	EngineAnimation = Anim(EngineFrameDelay, EngineFrameCounter, EngineFrameNumber, EngineFrame, EngineAnim);
	GunAnimation = Anim(GunFrameDelay, GunFrameCounter, GunFrameNumber, GunFrame, GunAnim);
	ExplosionAnimation = Anim(ExplosionFrameDelay, ExplosionFrameCounter, 
		ExplosionFrameNumber, ExplosionFrame, ShipExplosionAnim); 
	EngineAnim.clear();
	GunAnim.clear();
	ShipExplosionAnim.clear();

}

PlayerShip::~PlayerShip(){
	UnloadTexture(image);
	UnloadTexture(Thruster);
	UnloadTexture(Gun);
	EngineAnimation.UnloadAnim();
	GunAnimation.UnloadAnim();
	ExplosionAnimation.UnloadAnim();
	ProjectileAnim.clear();
	ShipImages.clear();
	

	
}

void PlayerShip::Draw(){
	if(hp>0){
	
	
	
		if(!shooting){
			DrawTextureEx(Gun, {Position.x + 10, Position.y}, 90, 1, WHITE);
			GunAnimation.FrameCounter = 0;
			GunAnimation.Frame = 0;	
		}
		else{
			GunAnimation.DrawAnim(1, 90, {Position.x + 10, Position.y});

		}
		if(touched){
			DrawTextureEx(image, Position, 90, 1, RED);
			touched = false;
		}
		else{
			DrawTextureEx(image, Position, 90, 1, WHITE);

		}

		EngineAnimation.DrawAnim(1 , 90 , {Position.x - 10, Position.y});
			
		
		
		DrawTextureEx(Thruster, {Position.x - 10, Position.y}, 90, 1, WHITE);
	}
	else{

		ExplosionAnimation.DrawAnimOnce(2, 90, {Position.x + image.width / 2, Position.y - image.width / 2});
		if(!Exploded){
			PlaySound(ShipExplosionSound);
		}
		Exploded = true;

	}
	if(ActiveShield){
		PlayerShield.Draw();
	}
	// DrawCircleLines(Position.x - 56, Position.y + 49, 51, RED);

	// DrawRectangleLines(Position.x - 70, Position.y + 20, 50, 58, RED);
	// std::cout << hp << "\n";

}

void PlayerShip::Update(){
	HitBoxCircleCenter = {Position.x - 56, Position.y + 49};
	if(ActiveShield && ShieldTime > 0){
		ShieldTime --;
	}
	if(hp > 0){

		HitBox = {Position.x - 70, Position.y + 20, 50, 58};
		image = ShipImages[hp - 1];
		PlayerShield.Position = Position;
	}
}

void PlayerShip::MoveLeft(){
	Position.x -= util::movementspeed;
	if(Position.x < image.width - 18){
		Position.x = image.width - 18;
	}
}

void PlayerShip::MoveRight(){
	Position.x += util::movementspeed;
	if(Position.x > GetScreenWidth() + 18){
		Position.x = GetScreenWidth() + 18;
	}
	
}

void PlayerShip::MoveUp(){
	Position.y -= util::movementspeed;
	if(Position.y < -18 ){
		Position.y = -18;
	}
	
}

void PlayerShip::MoveDown(){
	Position.y += util::movementspeed;
	if(Position.y > GetScreenHeight() - image.width + 18){
		Position.y = GetScreenHeight() - image.width + 18;
	}
}

void PlayerShip::ShootProjectile(){
	if(shooting && hp > 0){
		// if(GetTime() - LastFireTime > 0.015){
			if(GunAnimation.Frame == 2 && GunAnimation.FrameCounter == 0){
				// std::cout << GunAnimation.FrameCounter;
				projectiles.push_back(Projectile({Position.x - 5, Position.y + 12}, 8, ProjectileAnim));
			}
			if(GunAnimation.Frame == 3 && GunAnimation.FrameCounter == 0){
				// std::cout << GunAnimation.FrameCounter;
				projectiles.push_back(Projectile({Position.x - 5, Position.y + 48}, 8, ProjectileAnim));
			}
			LastFireTime = GetTime();
		// }
	}
}

void PlayerShip::Revive(){
	hp = 4;
	Position.x = 200;
	Exploded = false;
	Position.y = 100;
	ShieldTime = 240;
	ExplosionAnimation.FrameCounter = 0;
	ExplosionAnimation.Frame = 0;

}
