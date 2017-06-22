#include"Game.h"
sound::sound(){
	backbuf.loadFromFile("Sounds/Sound_267.ogg");
	backmusic.setBuffer(backbuf);
	backmusic.setLoop(true);
	shootbuf.loadFromFile("Sounds/Sound 271.ogg");
	shootmusic.setBuffer(shootbuf);
	boombuf.loadFromFile("Sounds/Sound 276.ogg");
	boommusic.setBuffer(boombuf);
	restbuf.loadFromFile("Sounds/Sound 273.ogg");
	restmusic.setBuffer(restbuf);
	startbuf.loadFromFile("Sounds/Sound 272.ogg");
	startmusic.setBuffer(startbuf);
}

void sound::isShoot()
{
	shootmusic.play();
}

sound::~sound(){}

void sound::playback()
{
	backmusic.play();
}

void sound::playboom()
{
	boommusic.play();
}
void sound::playrest()
{
	restmusic.play();
}

void sound::playstart()
{
	startmusic.play();
}