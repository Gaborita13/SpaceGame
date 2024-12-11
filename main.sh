#!/bin/bash

g++ -I./include -L./lib main.cpp util.cpp Entity.cpp Anim.cpp Poly.cpp Asteroid.cpp PlayerShip.cpp Projectile.cpp Planet.cpp Game.cpp -lraylib -o main -Wextra
./main