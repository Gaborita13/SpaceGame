#include "include/Asteroid.hpp"

Texture2D Asteroid::AsteroidImage;
Anim Asteroid::ExplosionAnim;


Asteroid::Asteroid(){

}

Asteroid::Asteroid(Vector2 Position, float orientation, int hp, float speed, float rotspeed, int ratio, std::vector<Texture2D> ExplosionAnim){

}


Asteroid::Asteroid(Vector2 Position, float orientation, int hp, float speed, float rotspeed, int ratio){
	this -> Position = Position;
	this -> orientation = orientation;
	this -> hp = hp;
	this -> speed = speed;
	this -> rotspeed = rotspeed;

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

}

