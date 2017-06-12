#pragma once
#ifndef SOUNDPLAYER_H_
#define SOUNDPLAYER_H_
#include "YOUneedTHIS.h"
class SoundPlayer :private sf::NonCopyable
{
public:
	SoundPlayer();
	void play(SoundEffect::ID effect);
	void play(SoundEffect::ID effect, sf::Vector2f position);
	void removeStoppedSounds();
	void setListenerPosition(sf::Vector2f position);
	sf::Vector2f getListenerPosition() const;
private:
	SoundBufferHolder mSoundBuffers;
	std::list<sf::Sound> mSounds;
};
#endif // !SOUNDPLAYER_H_
