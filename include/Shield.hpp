#ifndef SHIELD_H
#define SHIELD_H

#include "raylib.h"
#include"Anim.hpp"
#include "Entity.hpp"
#include "Anim.hpp"
#include "util.hpp"
#include <vector>

class Shield : public Entity{

public:

	Shield( Vector2 Position);
	Shield();
	void Update();
	void Draw();

	Vector2 Position;

	bool active;
	std::vector<Texture2D> ShieldAnimVector;
	Anim ShieldAnim;
	int ShieldFrameDelay;
	int ShieldFrameCounter;
	int ShieldFrameNumber;
	int ShieldFrame;



};



#endif