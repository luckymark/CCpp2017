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
class Texture {
public:
	static sf::Texture player_texture;
	static sf::Texture enemy_texture;
	static sf::Texture player_bullet_texture;
	static sf::Texture enemy_bullet_texture;
	static sf::Texture background_texture;
	static sf::Texture gameover_texture;
	static sf::Texture player_destory;
	static sf::Texture enemy_boss_texture;
	static sf::Texture score_texture[10];
	static void load();
};
