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


void Anim::DrawAnimPro(float ratio, float angle, Vector2 Position, bool once){
	Frame++;
	if(Frame >= FrameDelay){
		
		
		FrameCounter++;
		if(!once){
			if( FrameCounter > FrameNumber - 1){
			
				FrameCounter = 0;
			}
		}

		Frame = 0;
	}
	DrawTexturePro(animation[FrameCounter], (Rectangle) {0, 0, (float)animation[FrameCounter].width, (float)animation[FrameCounter].height},
			(Rectangle){Position.x, Position.y, ratio * (float)animation[FrameCounter].width, ratio *  (float)animation[FrameCounter].height},
			{ratio * animation[FrameCounter].width / 2, ratio * animation[FrameCounter].height / 2}, angle, WHITE);
}

void Anim::DrawAnimProOnce(float ratio, float angle, Vector2 Position){
	Frame++;
	if(Frame >= FrameDelay && FrameCounter < FrameNumber - 1){
		
		
		FrameCounter++;
		Frame = 0;


	}

	DrawTexturePro(animation[FrameCounter], (Rectangle) {0, 0, (float)animation[FrameCounter].width, (float)animation[FrameCounter].height},
			(Rectangle){Position.x, Position.y, ratio * (float)animation[FrameCounter].width, ratio *  (float)animation[FrameCounter].height},
			{ratio * animation[FrameCounter].width / 2, ratio * animation[FrameCounter].height / 2}, angle, WHITE);
}

void Anim::UnloadAnim(){
	// std::cout << "Call\n";
	animation.clear();
}