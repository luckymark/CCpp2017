#include "stdafx.h"
#include"gameMusic.h"
gameMusic::gameMusic(int type) {
	if (type == 1) {
		gameBuffer.loadFromFile("bgm1.flac");
		gameSound.setBuffer(gameBuffer);
		
	}
	else if (type == 2) {
		gameBuffer.loadFromFile("collision.wav");
		gameSound.setBuffer(gameBuffer);
	}
	
}
void gameMusic::playMusic(bool loop) {
	if (loop) {
		gameSound.setLoop(true);
	}
	gameSound.play();
	
}