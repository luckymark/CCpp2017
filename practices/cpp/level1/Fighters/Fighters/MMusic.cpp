#include "MMusic.h"
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
sf::Music Music::BGM;
sf::Music Music::BOOM;
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
}
