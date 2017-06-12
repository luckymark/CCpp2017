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
class Bullet
{
public:
	Bullet() {}
	Bullet(sf::Vector2f speed, double x, double y);
	void add_bullet(sf::Vector2f pos, sf::Vector2f speed, bool direction, bool is_boss);
	void move_bullet();
	friend class Game;
private:
	sf::Vector2f bullet_speed;
	int player_bullet_limit = 10, player_bullet_time = 0;
	int enemy_bullet_limit = 50, enemy_bullet_time = 0;
	int boss_bullet_time = 0;
	bool is_fire;
	std::vector <Bullet> player_bullet;
	std::vector <Bullet> enemy_bullet;
	sf::Vector2f pos;
	sf::Sprite sprite;
};
