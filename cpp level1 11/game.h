#pragma once
#include "stdafx.h"
#include <SFML/Graphics.hpp>                                                 ¡£  
#include "Plane.h"
#include "Bullet.h"
#include "ObjectManager.h"
#include "EnemyBullet.h"

#define width 1024
#define height 770

class Game
{
public:
	static int head ;
	static int tail ;
	static int flag ;
	static bool empty;

	static int ehead;
	static int etail;
	static bool eempty;

	static int ebhead;
	static int ebtail;
	static bool ebempty;

	sf::Clock clock1;
	
	float time = 0;
	float timeDelta = 0;

	void play();
};
