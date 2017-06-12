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

class Enemy : public Plane
{
public:
	Enemy() {}
	Enemy(double speed, sf::Vector2f pos, int hp, int score);
	std::vector <Enemy> all_enemy;
	void add_enemy();
	void move();
	friend class Game;
private:
	sf::Vector2f pos;
	int enemy_limit = 20;
	int enemy_time = 0;
	static int tot_enemy;
	int enemy_boss_health = 10;
	int enemy_score = 5;
	int enemy_boss_score = 50;
	static int escape_enemy;
	int score;
};