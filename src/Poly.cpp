#include "Poly.hpp"
#include <cmath>


Poly::Poly(std::vector<Vector2> Points, Vector2 Position, float orientation){
	this->Position = Position;
	size = 0;
	this->orientation = orientation;
	this->Points = Points;
	size = Points.size();
	float xsum = 0;
	float ysum = 0;
	for(Vector2& point : this->Points){
		point.x += Position.x;
		point.y += Position.y;
	}
	for(Vector2& point : this->Points){
		xsum += point.x;
		ysum += point.y;

	}
	Centroid = {xsum / size, ysum / size};
	std::cout << Centroid.x << " " << Centroid.y << "\n";
	for(Vector2& point : this->Points){
		std::cout << "HERE\n";
		float temp = cos(orientation * PI /180.0) * (point.x - Position.x) - sin(orientation * PI / 180.0) * (point.y - Position.y) + Position.x ;
		point.y = sin(orientation * PI /180.0) * (point.x - Position.x) + cos(orientation * PI / 180.0) * (point.y - Position.y) + Position.y ;
		point.x = temp; 
	}


}

Poly::Poly(){

}

void Poly::Draw(){
	std::cout << Points[0].x << "\n";

	for(int i = 0 ; i < size - 1; i ++){

		DrawLineV(Points[i], Points[i+1], RED);
	}
	DrawLineV(Points[size-1], Points[0], RED);
}

void Poly::Translate(Vector2 translation){
	float xsum = 0;
	float ysum = 0;
	for(Vector2& point : Points){
		point.x += translation.x;
		point.y += translation.y;
		Position.x += translation.x;
		Position.y += translation.y;
		xsum += point.x;
		ysum += point.y;
	}
	Centroid = {xsum / size, ysum / size};

}

void Poly::Rotate(float rotation){
	for(Vector2& point : Points){
		std::cout << "HERE\n";
		float temp = cos(rotation * PI /180.0) * (point.x - Position.x + Position.x / 2) - sin(rotation * PI / 180.0) * (point.y - Position.y + Position.y / 2) + Position.x ;
		point.y = sin(rotation * PI /180.0) * (point.x - Position.x + Position.x / 2) + cos(rotation * PI / 180.0) * (point.y - Position.y + Position.y / 2) + Position.y ;
		point.x = temp; 
	}
}