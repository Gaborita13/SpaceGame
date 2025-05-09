#include "GUI.hpp"	



GUI::GUI(int ShieldTime){
	this->ShieldTime = ShieldTime;
	ShieldPercent = 100;
	MaxShield = 240;
	GUIFont = LoadFontEx("../Assets/Font/monogram.ttf", 64 , 0, 0);
}

GUI::GUI(){

}

GUI::~GUI(){
	UnloadFont(GUIFont);
}

std::string GUI::FormatWithLeadingZeros(int number, int width){
	std::string numberText = std::to_string(number);
	int leadingZeros = width - numberText.length();
	numberText = std::string(leadingZeros, '0') + numberText;	
	return numberText;
}

void GUI::Draw(){
	std::string ShieldString = FormatWithLeadingZeros(ShieldPercent, 3);
	DrawTextEx(GUIFont, "SHIELD", {5, 5}, 34, 2, WHITE);
	DrawTextEx(GUIFont, ShieldString.c_str(), {135, 5}, 34, 2, WHITE);
	DrawTextEx(GUIFont, "%", {195, 5}, 34, 2, WHITE);

	std::string DistanceString = FormatWithLeadingZeros(Distance, 6);
	DrawTextEx(GUIFont, "DISTANCE", {470, 5}, 34, 2, WHITE);
	DrawTextEx(GUIFont, DistanceString.c_str(), {650, 5}, 34, 2, WHITE);
	DrawTextEx(GUIFont, "M", {770, 5}, 34, 2, WHITE);
}

void GUI::Update(){
		ShieldPercent = (float)ShieldTime / MaxShield * 100;
	

	// std::cout << ShieldPercent << std::endl;
}