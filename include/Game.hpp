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
	void DeleteInactiveAsteroids();
	void SpawnAsteroid();
	void HandleCollisions();
	

	int counter;
	int SpawnCounter;
	float LastAsteroidSpawn;
	PlayerShip player;
	Asteroid asteroid1;
	Projectile bullet;
	std::vector<Planet> planets;
	std::vector<Asteroid> asteroids;
	Asteroid asteroid; 


};

#endif
