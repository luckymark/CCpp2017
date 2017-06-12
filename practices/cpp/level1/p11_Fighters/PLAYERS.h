#pragma once
#include <stdio.h>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include "GAME.h"
#include "PLAYERS.h"
#include <vector>
#include "bullet.h"
#include "enemys.h"
#include <cmath>
#include "RESOURCE.h"
#include <time.h>
#include "TEXTURE.h"

class Player : public Plane
{
public:
	Player(double speed);
	friend class Game;
private:
	int health_time = 150; 
	bool hit = false;
};