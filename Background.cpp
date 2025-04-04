#include "include/Background.hpp"


Background::Background(){
	ScrollingBackground = 0;
	BackgroundTexture = LoadTexture("Assets/Pixel_Art_Space/Pixel_Art_Space/Back.png");
}

Background::~Background(){

}


void Background::Update(){
	if(ScrollingBackground <= - 4.5 * BackgroundTexture.width){
		ScrollingBackground = 0;
	}
	ScrollingBackground -= 0.1;
}

void Background::Draw(){
	DrawTextureEx(BackgroundTexture, {ScrollingBackground, 0}, 0.0, 4.5, WHITE);
	DrawTextureEx(BackgroundTexture, {BackgroundTexture.width * 4.5 +  ScrollingBackground,(float) 0}, 0.0, 4.5, WHITE);
}