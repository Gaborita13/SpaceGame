#ifndef GAME_H
#define GAME_H

#include "raylib.h"
#include "util.hpp"
#include "PlayerShip.hpp"
#include "Planet.hpp"
#include "Projectile.hpp"
#include "Asteroid.hpp"
#include <vector>

class Game{
	public:
	Game();
	~Game();
	void Draw();
	void Update();
	void HandleInput();
	void DeleteInactiveProjectiles();
	

	int counter;
	PlayerShip player;
	Asteroid asteroid1;
	Projectile bullet;
	std::vector<Planet> planets;


};

#endif
