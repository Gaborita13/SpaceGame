#include "include/Game.hpp"


Game::Game(){
	Distance = 0;
	Background background;
	BackGroundMusic = LoadMusicStream("Assets/Music/MergeOST.wav");
	PlayMusicStream(BackGroundMusic);
	for(int i = 1; i < 10; i++){
		planets.push_back(Planet(i));
	}
	counter = 0;
	asteroid = Asteroid();
	LastAsteroidSpawn = 0.0;
	// asteroid1 = Asteroid({500, 100},0 , 4, -1, -1, 3);
	counter = 0;
	SpawnCounter = 0;
	MainGUI = GUI(player.ShieldTime);
	// polygonpoints.push_back({200,200});
	// polygonpoints.push_back({250, 200});
	// polygonpoints.push_back({200, 250});
	// polygon = Poly(polygonpoints, {0, 0}, 90);
	// bullet = Projectile({100, 100}, 2);
	
}

Game::~Game(){
	UnloadMusicStream(BackGroundMusic);
	for(Planet planet : planets){
		planet.unloadimage();
	}
	Asteroid::UnloadImages();
	UnloadTexture(background.BackgroundTexture);
	UnloadSound(Asteroid::AsteroidExplosionSound);
}

void Game::Draw(){
	
	background.Draw();
	
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
	MainGUI.Draw();
	// asteroid1.Draw();

	// polygon.Draw();
}

void Game::Update(){

	background.Update();
	Planet lastplanet = planets.back();
	if(Planet::scrolling + lastplanet.XPos <= - lastplanet.ratio * lastplanet.image.width){
		Planet::scrolling = 900;
	}
	if(player.hp > 0){
		Distance++;
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

	MainGUI.ShieldTime = player.ShieldTime;
	MainGUI.Distance = Distance;

	MainGUI.Update();
	
	// polygon.Rotate(1);
	// polygon.Translate({1, 0});
	// HandleCollisions();
}

void Game::HandleInput(){
	
	if(IsKeyDown(KEY_UP) && player.hp > 0){
		player.MoveUp();
		
	}
	if(IsKeyDown(KEY_DOWN) && player.hp > 0){
		player.MoveDown();
		
		
	}
	if(IsKeyDown(KEY_RIGHT) && player.hp > 0){
		player.MoveRight();
		
	}
	if(IsKeyDown(KEY_LEFT) && player.hp > 0){
		player.MoveLeft();
	}

	if(IsKeyDown(KEY_SPACE) && player.hp > 0){
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
	if(IsKeyDown(KEY_R) && player.hp == 0){
		player.Revive();
		Distance = 0;
	}
	if(IsKeyDown(KEY_L)){
		player.ShieldTime += 20;
	}
	if(IsKeyDown(KEY_S) && player.hp > 0 && player.ShieldTime > 0){
		player.ActiveShield = true;
	}
	else{
		player.ActiveShield = false;
	}
	// std::cout << player.ShieldTime << std::endl;
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
			// UnloadSound(it -> LocalAsteroidExplosionSound);
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
				int randhp = randratio * 3;
				float xpos = 900;
				asteroids.push_back(Asteroid({xpos, randypos}, randorientation, randhp, -randspeed, -randrotspeed, randratio));
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
		 it -> HitBoxRadius, player.HitBox) && it -> Alive && player.hp > 0){
			if(player.hp > 0){
				player.hp--;
			}
			player.touched = true;
			it -> hp = 0;

		}
		++ it;
	}
	if(player.ActiveShield){
		auto it = asteroids.begin();
		while(it != asteroids.end()){
		if(CheckCollisionCircles({it -> Position.x, it -> Position.y},
		 it -> HitBoxRadius, player.HitBoxCircleCenter, player.HitBoxCircleRadius) && it -> Alive && player.hp > 0){
			it -> hp = 0;

		}
		++ it;
		}
	}

}