#include "Music.h"
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
sf::Music Music::BGM;
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
    BGM.openFromFile("resource/music/BGM.wav");
}
