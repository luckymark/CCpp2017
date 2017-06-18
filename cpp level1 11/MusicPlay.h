#pragma once
#include "stdafx.h"
class MusicPlay
{
public:
	static int useMusic;
	sf::Music gameMusic;
	sf::Music burstMusic;
	sf::Music againMusic;
	void GameMusic();
	void BurstMusic();
	void AgainMusic();
};