#ifndef PLANET_H
#define PLANET_H

#include "raylib.h"
#include "util.hpp"

class Planet{
public:
	Planet(int type);
	~Planet();
	void Draw();
	void Update();
	static float scrolling;
	static constexpr float scrollingspeed = 0.3;
	void unloadimage();
	int type;
	int XPos;
	int YPos;
	float ratio;
	Texture2D image;
};

#endif