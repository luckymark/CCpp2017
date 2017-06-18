#pragma once
#include "stdafx.h"
#include <SFML/Graphics.hpp>                                                 ¡£  
#include "Plane.h"
#include "NormalBullet.h"
#include "ObjectManager.h"
#include "EnemyBullet.h"
#include "MusicPlay.h"
#define width 1224
#define height 800

class Game
{
public:
	static int head ;
	static int tail ;
	static int flag ;
	static bool empty;

	static int mhead;
	static int mtail;
	static int mflag;
	static bool mempty;

	static int ehead;
	static int etail;
	static bool eempty;

	static int ebhead;
	static int ebtail;
	static bool ebempty;

	static int bhead;
	static int btail;
	static bool bempty;

	static int bbhead;
	static int bbtail;
	static bool bbempty;

	sf::Clock clock1;
	
	float time = 0;
	float timeDelta = 0;
	int menuMark = 0;
	void play();
	void start();
	void help();
	void again();
};
