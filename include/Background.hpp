#ifndef BACKGROUND_H
#define BACKGROUND_H

#include "raylib.h"

class Background{
public:

	Background();
	~Background();
	float ScrollingBackground;
	Texture2D BackgroundTexture;

	void Update();
	void Draw();
};


#endif