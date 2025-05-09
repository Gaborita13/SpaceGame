#include "Projectile.hpp"

// Image Projectile::ProjectileImage = LoadImage("Assets/Foozle/Main ship weapons/PNGs/Bullet.png");

Sound Projectile::BulletSound;




Projectile::Projectile(Vector2 Position, int speed, std::vector<Texture2D> ProjectileAnim) : Entity(Position){
	this->speed = speed;
	this -> ProjectileAnim = ProjectileAnim;
	active = true;
	// HitBox = {}
	HitBox = {Position.x - 20, Position.y + 11, 12, 10};

	BulletFrameCounter = 0;
	BulletFrameNumber = 4;
	BulletFrameDelay = 8;
	BulletFrame = 0;
	if(BulletSound.frameCount == 0){
		BulletSound = LoadSound("../Assets/Sound/heavy_machinegun.ogg");
	}
	SetSoundVolume(BulletSound, 0.5);
	PlaySound(BulletSound);

	ProjectileAnimation = Anim(BulletFrameDelay, BulletFrameCounter, BulletFrameNumber, BulletFrame, ProjectileAnim);
	// ProjectileAnim.clear(); 
}

Projectile::Projectile(){

}

Projectile::~Projectile(){


}

void Projectile::Draw(){
	if(active){
		// DrawRectangleLines(position.x - 20, position.y + 11, 12, 10, RED);
		ProjectileAnimation.DrawAnim(1, 90, Position);
	}

}

void Projectile::Update(){
	Position.x += speed;
	HitBox = {Position.x - 20, Position.y + 11, 12, 10};
	if(Position.x - ProjectileAnim[0].width > GetScreenWidth() && active){
		active = false;
		UnloadAnim();		// UnloadProjectileImage();
	} 
}



void Projectile::UnloadAnim(){
	ProjectileAnimation.UnloadAnim();
}

void Projectile::UnloadProjectileImage(){
	ProjectileAnim.clear();
} 