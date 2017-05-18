#include "Music.h"

Music::Music()
{
    bgm.openFromFile("resource/music/music.wav");
}

Music::~Music()
{
    //dtor
}

void Music::play_bgm()
{
    bgm.play();
}
