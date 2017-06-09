#include "MMusic.h"
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
sf::Music Music::BGM;
sf::Music Music::BOOM;
sf::Music Music::Fire;
sf::Music Music::ENEMY_BOOM;
sf::Music Music::BOSS_BOOM;
Music::Music()
{
	//ctor
}

Music::~Music()
{
	//dtor
}

void Music::load()
{
	BGM.openFromFile("resource/music/BGM.ogg");
	BOOM.openFromFile("resource/music/BOOM.wav");
	Fire.openFromFile("resource/music/fire.wav");
	BOSS_BOOM.openFromFile("resource/music/boss_boom.wav");
	ENEMY_BOOM.openFromFile("resource/music/enemy_boom.wav");
}
