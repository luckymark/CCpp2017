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

class Plane
{
public:
	bool right = false, left = false, up = false, down = false;
	virtual void move(double speed);
	sf::Sprite sprite;
	double speed;
	int health;
};
