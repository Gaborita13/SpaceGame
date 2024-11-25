#include "include/raylib.h"
#include "include/util.hpp"
#include "include/Game.hpp"
#include <iostream>
#include <vector>
#include <numeric>

std::string FormatWithLeadingZeros(int number, int width){
	std::string numberText = std::to_string(number);
	int leadingZeros = width - numberText.length();
	return numberText = std::string(leadingZeros, '0') + numberText;	
}

int main(){
	float scrollingBackground = 0;
	
	InitWindow(util::windowswidth, util::windowheight, util::title);
	SetTargetFPS(util::FPS);
	Texture2D BackGround = LoadTexture("Assets/Pixel_Art_Space/Pixel_Art_Space/Back.png");

	

	

	Game game;
	
	while(!WindowShouldClose()){
		

		if(scrollingBackground <= - 4.5 * BackGround.width){
			scrollingBackground = 0;
		}
		
		scrollingBackground -= 0.1;

		game.Update();
		
		BeginDrawing();
		
		DrawTextureEx(BackGround, {scrollingBackground, 0}, 0.0, 4.5, WHITE);
		DrawTextureEx(BackGround, {BackGround.width * 4.5 + scrollingBackground, 0}, 0.0, 4.5, WHITE);
		

		
		
		game.Draw();
		

		EndDrawing();
		
	}
	
	




	CloseWindow();
	
	
	
	
	
	return 0;
}

