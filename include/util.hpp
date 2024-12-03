#pragma once

#include "raylib.h"
#include <vector>
#include <iostream>

namespace util{
	const int windowswidth = 800;
	const int windowheight = 530;
	const int FPS = 60;
	const int MysteryShipPosY = 90;
	const int Basex = 100;
	const int Basey = 100;
	const int movementspeed = 7;
	const int LaserWidth = 4;
	const int LaserHeight = 15;
	const int LaserSpeedPlayer = -6;
	const int AlienCellSize = 50;
	const int BlockSize = 3;
	const int AlienOffsetX = 75;
	const int AlienOffsetY = 110;
	const int OffsetWindow = 40;
	const double AttackSpeed = 0.35;  
	extern const char *title;
	extern Color grey;
	extern Color LaserColor;
	extern Color BlockColor;
	extern std::vector<Texture2D> PNGtoAnim(Image image, int number);
	extern std::vector<Texture2D> PNGArraytoAnim(Image image, int numberline,int numbercolumn);
	extern Image BulletImage;
	
	
}


