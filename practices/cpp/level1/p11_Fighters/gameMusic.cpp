#include "stdafx.h"
#include"gameMusic.h"
gameMusic::gameMusic(int type) {
	if (type == 1) {
		gameBuffer.loadFromFile("bgm1.flac");
		gameSound.setBuffer(gameBuffer);
	}
	
}
void gameMusic::playMusic() {
	gameSound.play();
}