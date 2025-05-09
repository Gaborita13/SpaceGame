#include "Planet.hpp"

float Planet::scrolling = 200;


Planet::Planet(int type){
	this->type = type;
	switch (type){
	case 1:
		image = LoadTexture("../Assets/Pixel_Art_Space/Pixel_Art_Space/Earth.png");
		XPos = 400;
		YPos = 150;
		ratio = 2;
		break;
	case 2:
		image = LoadTexture("../Assets/Pixel_Art_Space/Pixel_Art_Space/Moon.png");
		XPos = 600;
		YPos = 50;
		ratio = 1;
		break;
	case 3:
		image = LoadTexture("../Assets/Pixel_Art_Space/Pixel_Art_Space/Sun1.png");
		XPos = 0;
		YPos = 300;
		ratio = 4;
		break;
	case 4:
		image = LoadTexture("../Assets/Pixel_Art_Space/Pixel_Art_Space/Planet1.png");
		XPos = 1000;
		YPos = 80;
		ratio = 7;
		break;
	case 5:
		image = LoadTexture("../Assets/Pixel_Art_Space/Pixel_Art_Space/Planet3.png");
		XPos = 1800;
		YPos = 50;
		ratio = 7;
		break;
	case 6:
		image = LoadTexture("../Assets/Pixel_Art_Space/Pixel_Art_Space/Planet2.png");
		XPos = 2500;
		YPos = 125;
		ratio = 6;
		break;
	case 7:
		image = LoadTexture("../Assets/Pixel_Art_Space/Pixel_Art_Space/Planet4.png");
		XPos = 3200;
		YPos = 100;
		ratio = 8;
		break;
	case 8:
		image = LoadTexture("../Assets/Pixel_Art_Space/Pixel_Art_Space/Planet5.png");
		XPos = 3700;
		YPos = 50;
		ratio = 6;
		break;
	case 9:
		image = LoadTexture("../Assets/Pixel_Art_Space/Pixel_Art_Space/Planet.png");
		XPos = 4700;
		YPos = 100;
		ratio = 9;
		break;					

	}
}

Planet::~Planet(){

}

void Planet::unloadimage(){
	UnloadTexture(image);
}

void Planet::Draw(){
	DrawTextureEx(image, {(float)scrolling + XPos, (float)YPos}, 0.0, ratio, WHITE);
}