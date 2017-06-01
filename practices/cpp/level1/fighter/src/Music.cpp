#include "Music.h"
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
    BGM.openFromFile("resource/music/BGM.wav");
    BOOM.openFromFile("resource/music/BOOM.wav");
}
