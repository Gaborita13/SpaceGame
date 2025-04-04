#include "include/Asteroid.hpp"
#include <cmath>

Texture2D Asteroid::AsteroidImage;
std::vector<Texture2D> Asteroid::ExplosionTextures;

Sound Asteroid::AsteroidExplosionSound;


Asteroid::Asteroid(){
	Alive = false;
	hp = -20;
}

Asteroid::Asteroid(Vector2 Position, float orientation, int hp, float speed, float rotspeed, int ratio, std::vector<Texture2D> ExplosionAnim){

}


Asteroid::Asteroid(Vector2 Position, float orientation, int hp, float speed, float rotspeed, float ratio) : Entity(Position){
	this -> orientation = orientation;
	this -> hp = hp;
	this -> speed = speed;
	this -> rotspeed = rotspeed;
	this-> ratio = ratio;
	touched = false;
	AsteroidRadius = 16;
	HitBoxRadius = AsteroidRadius * ratio;
	// polygonpoints.push_back({0* ratio, -15* ratio});
	// polygonpoints.push_back({10* ratio, -10* ratio});
	// polygonpoints.push_back({15* ratio, -5* ratio});
	// polygonpoints.push_back({18* ratio, 0* ratio});
	// polygonpoints.push_back({17* ratio, 2* ratio});
	// polygonpoints.push_back({15* ratio, 5* ratio});
	// polygonpoints.push_back({12* ratio, 10* ratio});

	// polygon = Poly(polygonpoints, {Position.x, Position.y}, 0);

	AsteroidFrameCounter = 0;
	AsteroidFrameNumber = 8;
	AsteroidFrameDelay = 4;
	AsteroidFrame = 0;
	Exploded = false;

	Alive = true;

	if(AsteroidImage.id == 0){
		AsteroidImage = LoadTexture("Assets/Foozle/Asteroids/PNGs/Asteroid.png");
	}
	if(AsteroidExplosionSound.frameCount == 0){
		AsteroidExplosionSound = LoadSound("Assets/Sound/Asteroid_Explosion.mp3");
	}

	LocalAsteroidExplosionSound = LoadSoundAlias(AsteroidExplosionSound);
	
if(ExplosionTextures.empty()){
		ExplosionTextures = util::PNGtoAnim(LoadImage("Assets/Foozle/Asteroids/PNGs/asteroid_explosion.png"),8);
		
	}
ExplosionAnim = Anim(AsteroidFrameDelay, AsteroidFrameCounter, AsteroidFrameNumber, AsteroidFrame, ExplosionTextures);
}

void Asteroid::UnloadImages(){
	UnloadTexture(AsteroidImage);
	ExplosionTextures.clear();
	std::cout << "anim unloaded\n\n\n";
}


void Asteroid::Draw(){

	if(Alive){
		
		if(!touched){
			DrawTexturePro(AsteroidImage, (Rectangle){0, 0, (float)AsteroidImage.width, (float)AsteroidImage.height },
	 		(Rectangle){Position.x, Position.y, ratio * (float)AsteroidImage.width, ratio *  (float)AsteroidImage.height},
	  		{ratio * AsteroidImage.width / 2, ratio * AsteroidImage.height / 2}, orientation, WHITE);
		}
		else{
			DrawTexturePro(AsteroidImage, (Rectangle){0, 0, (float)AsteroidImage.width, (float)AsteroidImage.height },
	 		(Rectangle){Position.x, Position.y, ratio * (float)AsteroidImage.width, ratio *  (float)AsteroidImage.height},
	  		{ratio * AsteroidImage.width / 2, ratio * AsteroidImage.height / 2}, orientation, RED);
	  		touched = false;			
		}
		// DrawCircleLinesV(Position, HitBoxRadius, RED);

	}
	if(!Alive && hp > -4)
	{	
		
		ExplosionAnim.DrawAnimProOnce(ratio, orientation, Position);
		
		
		
	}
	// polygon.Draw();

}

void Asteroid::Update(){
	if(Alive){
		if(Position.x + ratio * AsteroidImage.width > 0){
			Position.x += speed;
			orientation += rotspeed;
			// polygon.Translate({speed , 0});
			// polygon.Rotate(rotspeed);
		}

		else{
			Alive = false;
			HitBoxRadius = 0;
		}
		if(hp <= 0){
			PlaySound(LocalAsteroidExplosionSound);
			Alive = false;
			HitBoxRadius = 0;
		}


	}
	if(!Alive && ExplosionAnim.FrameCounter > 6){
		// std::cout << Exploded << "\n";
		Exploded = true;
	}





}

