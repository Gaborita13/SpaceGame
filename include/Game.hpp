#ifndef GAME_H
#define GAME_H

#include "raylib.h"
#include "util.hpp"
#include "Poly.hpp"
#include "PlayerShip.hpp"
#include "Background.hpp"
#include "Planet.hpp"
#include "Projectile.hpp"
#include "Asteroid.hpp"
#include "Shield.hpp"
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
	Music BackGroundMusic;
	std::vector<Vector2> polygonpoints;
	Poly polygon;
	int SpawnCounter;
	float LastAsteroidSpawn;
	PlayerShip player;
	Shield shield1;
	Asteroid asteroid1;
	Projectile bullet;
	Background background;
	std::vector<Planet> planets;
	std::vector<Asteroid> asteroids;
	Asteroid asteroid; 


};

#endif
