#include "include/Anim.hpp"

Anim::Anim(){

}

Anim::Anim(int FrameDelay, int FrameCounter, int FrameNumber, int Frame, std::vector<Texture2D> animation){
	this -> FrameDelay = FrameDelay;
	this -> FrameCounter = FrameCounter;
	this -> FrameNumber = FrameNumber;
	this -> Frame = Frame;
	this -> animation = animation;
}

void Anim::DrawAnim(float ratio, float angle, Vector2 Position){
	Frame++;
	if(Frame >= FrameDelay){
		
		FrameCounter++;
		if( FrameCounter > FrameNumber - 1){
			
			FrameCounter = 0;
		}
		Frame = 0;
	}
	DrawTextureEx(animation[FrameCounter], Position, angle, ratio, WHITE);
}

void Anim::UnloadAnim(){
	// std::cout << "Call\n";
	animation.clear();
}