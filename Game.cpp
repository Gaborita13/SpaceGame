#include "include/Game.hpp"


Game::Game(){

	for(int i = 1; i < 10; i++){
		planets.push_back(Planet(i));
	}
	counter = 0;
	asteroid = Asteroid();
	LastAsteroidSpawn = 0.0;
	// asteroid1 = Asteroid({500, 100},0 , 4, -1, -1, 3);
	counter = 0;
	SpawnCounter = 0;
	// bullet = Projectile({100, 100}, 2);
	
}

Game::~Game(){
	for(Planet planet : planets){
		planet.unloadimage();
	}
	Asteroid::UnloadImages();
}

void Game::Draw(){
	for(Planet planet : planets){
		planet.Draw();
	}
	player.Draw();
	for(Projectile& bullet : player.projectiles){
		bullet.Draw();
	}

	for(Asteroid& asteroid : asteroids){
		asteroid.Draw();
	}
	// asteroid1.Draw();


}

void Game::Update(){
	Planet lastplanet = planets.back();
	if(Planet::scrolling + lastplanet.XPos <= - lastplanet.ratio * lastplanet.image.width){
		Planet::scrolling = 900;
	}
	Planet::scrolling  = Planet::scrolling - Planet::scrollingspeed; 
	HandleInput();
	player.Update();
	for(Projectile& bullet : player.projectiles){
		bullet.Update();
	}
	HandleCollisions();
	DeleteInactiveProjectiles();
	SpawnAsteroid();
	// if(asteroid.Alive){
	// 	asteroid.Update();
	// 	std::cout << asteroid.hp << "\n";

	// }
	DeleteInactiveAsteroids();
	for(Asteroid& asteroid : asteroids){
		asteroid.Update();
	}
	
	
	// HandleCollisions();
}

void Game::HandleInput(){
	
	if(IsKeyDown(KEY_UP)){
		player.MoveUp();
		
	}
	if(IsKeyDown(KEY_DOWN)){
		player.MoveDown();
		
		
	}
	if(IsKeyDown(KEY_RIGHT)){
		player.MoveRight();
		
	}
	if(IsKeyDown(KEY_LEFT)){
		player.MoveLeft();
	}
	if(IsKeyDown(KEY_SPACE)){
		counter++;
		if(counter > 10){
			player.shooting = true;
			player.ShootProjectile();
		}
	}
	else{
		counter = 0;
		player.shooting = false;
	}
}

void Game::DeleteInactiveProjectiles(){

	for(auto it = player.projectiles.begin(); it != player.projectiles.end();){
		if(!it -> active){
			// std::cout << "Erased !\n";
			it = player.projectiles.erase(it);
		}
		else{

			++it;
		}
	}
}

void Game::DeleteInactiveAsteroids(){
	// std::cout << asteroids.size() << "\n";

	for(auto it = asteroids.begin(); it != asteroids.end();){
		if(it -> Exploded){
			it = asteroids.erase(it);
			// std::cout << "Deleted\n";
		}
		else{

			++it;
		}
	}
}

void Game::SpawnAsteroid(){


	if(!asteroid.Alive){
		SpawnCounter++;
		// std::cout << SpawnCounter << "\n";
		
			if(SpawnCounter > 50){
				float randratio = (float) GetRandomValue(10, 50) / 10;
				float randorientation = (float) GetRandomValue(0, 1800) / 10;
				float randspeed = (float) GetRandomValue(10, 50) / 10;
				float randrotspeed = (float) GetRandomValue(10, 50) / 10;
				float randypos = (float) GetRandomValue(0, 5000) / 10;
				int randhp = GetRandomValue(5, 20);
				float xpos = 900;
				asteroids.push_back(Asteroid({xpos, randypos}, randorientation, 5, -randspeed, -randrotspeed, randratio));
				SpawnCounter = 0;
			}

		}
	
}

void Game::HandleCollisions(){

	for(Projectile& projectile : player.projectiles){

		auto it = asteroids.begin();
		while(it != asteroids.end()){
			if(CheckCollisionCircleRec({it -> Position.x, it -> Position.y}, it -> HitBoxRadius, projectile.HitBox) && it -> Alive){
				projectile.active = false;
				it -> hp--;
				it -> touched = true;
				
			}
			it++;

		}

	}
	if(asteroids.size() > 1){
		auto it1 = asteroids.begin();
		while(it1 != asteroids.end()){
			auto it2 = it1;
			++it2;
			while(it2 != asteroids.end()){
				if(CheckCollisionCircles({it1 -> Position.x, it1 -> Position.y}, it1 -> HitBoxRadius,
				 {it2 -> Position.x, it2 -> Position.y}, it2 -> HitBoxRadius)
				  && it1 -> Alive && it2 -> Alive){
					if(it1 -> HitBoxRadius > it2 -> HitBoxRadius){
						it2 -> hp = 0;

					}
					else{
						// std::cout << "Here\n";
						it1 -> hp = 0;
					}
				}
				it2++;

			}
			it1++;
		}

	}
	
	auto it = asteroids.begin();
	while(it != asteroids.end()){
		if(CheckCollisionCircleRec({it -> Position.x, it -> Position.y},
		 it -> HitBoxRadius, player.HitBox) && it -> Alive){
			if(player.hp > 1){
				player.hp--;
			}
			player.touched = true;
			it -> hp = 0;

		}
		++ it;
	}

}