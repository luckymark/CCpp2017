#include "stdafx.h"
#include "MusicPlay.h"

void MusicPlay::GameMusic()
{
	if (!gameMusic.openFromFile("sound/game_music.ogg"))
	{
		return;
	}
	if (useMusic)
	{
		gameMusic.setLoop(true);
		gameMusic.play();
	}
}

void MusicPlay::BurstMusic()
{
	if (!burstMusic.openFromFile("sound/explode.ogg"))
	{
		return;
	}
	if (MusicPlay::useMusic)
	{
		burstMusic.play();
	}
}

void MusicPlay::AgainMusic()
{
	gameMusic.stop();
	if (!againMusic.openFromFile("sound/gameover.ogg"))
	{
		return;
	}
	if (MusicPlay::useMusic)
	{
		againMusic.play();
	}
}


int MusicPlay::useMusic = 1;