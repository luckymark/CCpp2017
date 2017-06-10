#ifndef GAME_H
#define GAME_H
#include <SFML/Audio.hpp>
#include <random>
#include "World.h"
#include <string.h>
#include<iostream>
#include "MMusic.h"
#include <SFML/Graphics.hpp>
class Game
{
public:
	static std::default_random_engine random;
	Game(World *world);
	virtual ~Game();
	void init();
	void MainLoop();
	void GameOvers(bool win);
	void ShowInfo();

protected:

private:
	World *world;
	int life_now;
	sf::Text Score;
	sf::Text Loading;
	sf::Text GameOver;
	bool win = false;
	int gameover_mark = 0;
	int restart = 0;
	void play_music();
	void pause_music();
	sf::Music &BGM = Music::BGM;
};

#endif // GAME_H
