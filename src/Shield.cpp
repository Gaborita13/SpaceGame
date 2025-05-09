#include "Shield.hpp"


Shield::Shield( Vector2 Position){
	this->Position = Position;
	ShieldFrameDelay = 2;
	ShieldFrameCounter = 0;
	ShieldFrameNumber = 12;
	ShieldFrame = 0;
	Image ShieldEffect = LoadImage("../Assets/Foozle/Main/Shields/PNGs/MainShieldRS.png");
	ShieldAnimVector = util::PNGtoAnim(ShieldEffect, ShieldFrameNumber);
	UnloadImage(ShieldEffect);
	ShieldAnim = Anim(ShieldFrameDelay, ShieldFrameCounter, ShieldFrameNumber, ShieldFrame, ShieldAnimVector);




	
}
Shield::Shield(){

}

void Shield::Draw(){

	ShieldAnim.DrawAnim(1, 90, {Position.x + 6, Position.y - 15});



}

void Shield::Update(){



}