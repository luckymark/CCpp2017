#include "Audio.h"
#include "SimpleAudioEngine.h"
Audio* Audio::m_instance = nullptr;
Audio* Audio::getInstance() {
	if (m_instance == nullptr) {
		m_instance = new Audio();
	}
	return m_instance;
}

void Audio::playBGM() {
	CocosDenshion::SimpleAudioEngine::getInstance()->playBackgroundMusic("sound/game_music.mp3", true);
}

void Audio::playEnemy1() {
	CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("sound/enemy1_down.mp3", false);
}

void Audio::playEnemy2()
{
	CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("sound/enemy2_down.mp3", false);
}

void Audio::playEnemy3()
{
	CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("sound/enemy3_down.mp3", false);
}

void Audio::playBullet()
{
	CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("sound/bullet.mp3", false);
}

void Audio::playBomb()
{
	CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("sound/use_bomb.mp3", false);
}

void Audio::prepare() {
	CocosDenshion::SimpleAudioEngine::getInstance()->preloadBackgroundMusic("sound/game_music.mp3");
	CocosDenshion::SimpleAudioEngine::getInstance()->preloadEffect("sound/enemy1_down.mp3");
	CocosDenshion::SimpleAudioEngine::getInstance()->preloadEffect("sound/enemy2_down.mp3");
	CocosDenshion::SimpleAudioEngine::getInstance()->preloadEffect("sound/enemy3_down.mp3");
	CocosDenshion::SimpleAudioEngine::getInstance()->preloadEffect("sound/bullet.mp3");
	CocosDenshion::SimpleAudioEngine::getInstance()->preloadEffect("sound/use_bomb.mp3");
}