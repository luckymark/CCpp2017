#include "stdafx.h"
#include"gameMusic.h"
gameMusic::gameMusic(int type) {
	this->type = type;
	if (type == 1) {
		gameBuffer.loadFromFile("collision.wav");
		gameSound.setBuffer(gameBuffer);
		
	}
	else if (type == 2) {
		bigMusic.openFromFile("bgm1.flac");
	}
	
}
void gameMusic::playMusic() {
	if (type==2) {
		bigMusic.setLoop(true);
	}
	switch (type) {
		case 2:
			bigMusic.play();
			break;
		case 1:
			gameSound.play();
			break;
		default:
			;
	}
	
	
}