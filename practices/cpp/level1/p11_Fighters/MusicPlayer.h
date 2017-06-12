#pragma once
#ifndef MUSICPLAYER_H_
#define MUSICPLAYER_H_
#include "YOUneedTHIS.h"
class MusicPlayer :private sf::NonCopyable
{
public:
	MusicPlayer();
	void play(Music::ID theme);
	void stop();
	void setPaused(bool paused);
	void setVolume(float volume);
private:
	sf::Music mMusic;
	std::map<Music::ID, std::string> mFilenames;
	float mVolume;
};
#endif // !MUSICPLAYER_H_
