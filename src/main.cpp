#include "raylib.h"
#include "util.hpp"
#include "Game.hpp"
#include <iostream>
#include <vector>
#include <numeric>

std::string FormatWithLeadingZeros(int number, int width){
	std::string numberText = std::to_string(number);
	int leadingZeros = width - numberText.length();
	return numberText = std::string(leadingZeros, '0') + numberText;	
}

int main(){

	
	InitWindow(util::windowswidth, util::windowheight, util::title);
	InitAudioDevice();
	SetTargetFPS(util::FPS);


	

	

	Game game;
	
	while(!WindowShouldClose()){
		



		game.Update();
		UpdateMusicStream(game.BackGroundMusic);
		
		BeginDrawing();

		

		
		
		game.Draw();
		

		EndDrawing();
		
	}
	




	CloseAudioDevice();
	CloseWindow();
	
	
	
	
	
	return 0;
}

