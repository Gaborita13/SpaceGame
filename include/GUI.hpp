#ifndef GUI_H
#define GUI_H

#include "raylib.h"
#include "util.hpp"
#include <stdio.h>
#include <vector>

class GUI{
public:
	GUI(int ShieldTime);
	GUI();
	std::string FormatWithLeadingZeros(int number, int width);
	~GUI();

	Font GUIFont;
	void Draw();
	void Update();
	int ShieldTime;
	int Distance;
	int ShieldPercent;
	int MaxShield;

};

#endif