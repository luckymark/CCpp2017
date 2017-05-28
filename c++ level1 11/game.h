#pragma once
#include "stdafx.h"
#include <SFML/Graphics.hpp>                                                 ¡£  
#include "Plane.h"
#include "Bullet.h"
#include "ObjectManager.h"

#define width 1024
#define height 770

class Game
{
public:
	static int head ;
	static int tail ;
	static int flag ;
	static int ehead;
	static int etail;
	static bool empty ;
	static bool eempty;
	sf::Clock clock1;
	
	float time = 0;
	float timeDelta = 0;

	void play();
};
