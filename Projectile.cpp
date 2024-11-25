#include "include/Projectile.hpp"

// Image Projectile::ProjectileImage = LoadImage("Assets/Foozle/Main ship weapons/PNGs/Bullet.png");




Projectile::Projectile(Vector2 position, int speed, std::vector<Texture2D> ProjectileAnim){
	this->position = position;
	this->speed = speed;
	this -> ProjectileAnim = ProjectileAnim;
	active = true;

	BulletFrameCounter = 0;
	BulletFrameNumber = 4;
	BulletFrameDelay = 8;
	BulletFrame = 0;

	ProjectileAnimation = Anim(BulletFrameDelay, BulletFrameCounter, BulletFrameNumber, BulletFrame, ProjectileAnim);
	// ProjectileAnim.clear(); 
}

Projectile::Projectile(){

}

Projectile::~Projectile(){


}

void Projectile::Draw(){
	if(active){
		ProjectileAnimation.DrawAnim(1, 90, position);
	}
}

void Projectile::Update(){
	position.x += speed;
	if(position.x - ProjectileAnim[0].width > GetScreenWidth() && active){
		active = false;
		UnloadAnim();
		// UnloadProjectileImage();
	} 
}



void Projectile::UnloadAnim(){
	ProjectileAnimation.UnloadAnim();
}

void Projectile::UnloadProjectileImage(){
	ProjectileAnim.clear();
} 