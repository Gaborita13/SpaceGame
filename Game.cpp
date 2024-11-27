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

	asteroid.Draw();
	// asteroid1.Draw();


}

void Game::Update(){
	Planet lastplanet = planets.back();
	if(Planet::scrolling + lastplanet.XPos <= - lastplanet.ratio * lastplanet.image.width){
		Planet::scrolling = 900;
	}
	Planet::scrolling  = Planet::scrolling - Planet::scrollingspeed; 
	HandleInput();
	for(Projectile& bullet : player.projectiles){
		bullet.Update();
	}
	HandleCollisions();
	DeleteInactiveProjectiles();
	SpawnAsteroid();
	if(asteroid.Alive){
		asteroid.Update();
		std::cout << asteroid.hp << "\n";

	}
	// asteroid1.Update();
	
	HandleCollisions();
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

void Game::SpawnAsteroid(){


	if(!asteroid.Alive){
		SpawnCounter++;
		std::cout << SpawnCounter << "\n";
		
			if(SpawnCounter > 200){
				float randratio = (float) GetRandomValue(10, 50) / 10;
				float randorientation = (float) GetRandomValue(0, 1800) / 10;
				float randspeed = (float) GetRandomValue(10, 50) / 10;
				float randrotspeed = (float) GetRandomValue(10, 50) / 10;
				float randypos = (float) GetRandomValue(0, 5000) / 10;
				int randhp = GetRandomValue(5, 20);
				float xpos = 900;
				asteroid = Asteroid({xpos, randypos}, randorientation, 1, -randspeed, -randrotspeed, randratio);
				SpawnCounter = 0;
			}

		}
	
}

void Game::HandleCollisions(){

	for(Projectile& projectile : player.projectiles){
		if(CheckCollisionCircleRec({asteroid.Position.x, asteroid.Position.y}, asteroid.HitBoxRadius, projectile.HitBox)){
			projectile.active = false;
			asteroid.hp--;
			asteroid.touched = true;
		}
		// if(CheckCollisionCircleRec({asteroid1.Position.x, asteroid1.Position.y}, asteroid1.HitBoxRadius, projectile.HitBox)){
		// 	projectile.active = false;
		// 	asteroid1.hp--;
		// 	asteroid1.touched = true;
		// }
	} 
}
