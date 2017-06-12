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
class Game
{
public:
	Game();
	void run();
	void processEvents();
	void update();
	void render();
	void check_bound();
	void handlePlayerInput(sf::Keyboard::Key key, bool isPressed);
	void play_hit();
	void add_enemy_bullet();
	void load_text();
	void again_game();
	void begin_game();
private:
	sf::Font font;
	sf::Font lovely_font;
	sf::Text score_text;
	sf::Text escape_enemy;
	sf::Text health_text;
	sf::Text begin_text;
	sf::Text gameover_text;
	sf::RenderWindow my_window;
	Player player;
	Bullet bullet;
	Enemy enemy;
	bool esc = false;
	bool is_destroy = false;
	bool game_begin = false;
	int num = 0;
	sf::Sprite background_sp;
	sf::Sprite gameover_sp;
	sf::Sprite destroy;
	sf::Sprite enemy_boss;
	sf::Sprite final_score;
	int score = 0;
	int time = 0;
	int destroy_time = 5;
	bool is_game = true;
	bool new_game = false;
};
