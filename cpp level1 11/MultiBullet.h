#pragma once
#include "stdafx.h"
#include "Plane.h"
#include "Enemy.h"
#include "MyBullet.h"
#define multionce 5
#define multinumber 12
#define multi multionce*multinumber
class MultiBullet :public MyBullet
{
public:
	sf::Clock clock3;
	sf::Texture image;
	int mark = 0;
	int total = 0;
	int begin = 0;
	int addtotal = 0;
	
	static int flag[multionce*multinumber] ;
	static int right[multinumber*multionce];
	static int left[multinumber*multionce];
	static int direction[multi];
	MultiBullet();
	void draw();
	void move(float timeDelta,int num);
	static bool Judge();
	
	
};