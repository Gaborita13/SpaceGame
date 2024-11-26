#include "include/Asteroid.hpp"
#include <cmath>

Texture2D Asteroid::AsteroidImage;
Anim Asteroid::ExplosionAnim;


Asteroid::Asteroid(){
	Alive = false;
}

Asteroid::Asteroid(Vector2 Position, float orientation, int hp, float speed, float rotspeed, int ratio, std::vector<Texture2D> ExplosionAnim){

}


Asteroid::Asteroid(Vector2 Position, float orientation, int hp, float speed, float rotspeed, float ratio){
	this -> Position = Position;
	this -> orientation = orientation;
	this -> hp = hp;
	this -> speed = speed;
	this -> rotspeed = rotspeed;
	this -> ratio = ratio;
	touched = false;
	NextPosition = Position; 
	AsteroidRadius = 14;
	HitBoxRadius = AsteroidRadius * ratio;

	AsteroidFrameCounter = 0;
	AsteroidFrameNumber = 8;
	AsteroidFrameDelay = 8;
	AsteroidFrame = 0;

	Alive = true;

	if(AsteroidImage.id == 0){
		AsteroidImage = LoadTexture("Assets/Foozle/Asteroids/PNGs/Asteroid.png");
	}
	
	if(ExplosionAnim.animation.empty()){
		std::cout << "anim loaded\n\n\n";
		ExplosionAnim = Anim(AsteroidFrameDelay, AsteroidFrameCounter, AsteroidFrameNumber, AsteroidFrame, util::PNGtoAnim(LoadImage("Assets/Foozle/Asteroids/PNGs/asteroid_explosion.png"),8));
	}
}

void Asteroid::UnloadImages(){
	UnloadTexture(AsteroidImage);
	ExplosionAnim.UnloadAnim();
	std::cout << "anim unloaded\n\n\n";
}


void Asteroid::Draw(){
	if(Alive){
		if(!touched){
			DrawTexturePro(AsteroidImage, (Rectangle){0, 0, (float)AsteroidImage.width, (float)AsteroidImage.height },
	 		(Rectangle){Position.x, Position.y, ratio * (float)AsteroidImage.width, ratio *  (float)AsteroidImage.height + speed },
	  		{ratio * AsteroidImage.width / 2, ratio * AsteroidImage.height / 2}, orientation, WHITE);
		}
		else{
			DrawTexturePro(AsteroidImage, (Rectangle){0, 0, (float)AsteroidImage.width, (float)AsteroidImage.height },
	 		(Rectangle){Position.x, Position.y, ratio * (float)AsteroidImage.width, ratio *  (float)AsteroidImage.height + speed },
	  		{ratio * AsteroidImage.width / 2, ratio * AsteroidImage.height / 2}, orientation, RED);
	  		touched = false;			
		}

	}
}

void Asteroid::Update(){
	if(Alive){
		if(Position.x + ratio * AsteroidImage.width / 2 > 0){
			Position.x += speed;
			orientation += rotspeed;
		}

		else{
			Alive = false;
		}
		if(hp == 0){
			Alive = false;
		}

	}







	

}

