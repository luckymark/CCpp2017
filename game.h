#pragma once
#include <SFML/Graphics.hpp>                                                 ¡£  
#include "Plane.h"
#include "Bullet.h"
#include "ObjectManager.h"
#include "stdafx.h"
#define width 1024
#define height 770

class Game
{
public:
	static int head ;
	static int tail ;
	static int flag ;
	static bool empty ;
	sf::Clock clock1;
	
	float time = 0;
	float timeDelta = 0;

	void play();
	bool FullOrEmpty(int i);
};
