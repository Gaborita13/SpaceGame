#include "include/Game.hpp"


Game::Game(){

	for(int i = 1; i < 10; i++){
		planets.push_back(Planet(i));
	}
	counter = 0;
	// bullet = Projectile({100, 100}, 2);
}

Game::~Game(){
	for(Planet planet : planets){
		planet.unloadimage();
	}
}

void Game::Draw(){
	for(Planet planet : planets){
		planet.Draw();
	}
	player.Draw();
	for(Projectile& bullet : player.projectiles){
		bullet.Draw();
	}

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
	DeleteInactiveProjectiles();

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
