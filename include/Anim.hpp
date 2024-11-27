#ifndef ANIM_H
#define ANIM_H

#include "raylib.h"
#include "util.hpp"
#include <vector>


class Anim{

public:
	Anim();
	Anim(int FrameDelay, int FrameCounter, int FrameNumber, int Frame, std::vector<Texture2D> animation);
	int FrameDelay;
	int FrameCounter;
	int FrameNumber;
	int Frame;

	std::vector<Texture2D> animation;

	
	void DrawAnim(float ratio, float angle, Vector2 Position);
	void DrawAnimPro(float ratio, float angle, Vector2 Position, bool once);
	void DrawAnimProOnce(float ratio, float angle, Vector2 Position);
	void UnloadAnim();

};

#endif