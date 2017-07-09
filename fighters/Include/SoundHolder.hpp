#ifndef SOUNDHOLDER_H_
#define SOUNDHOLDER_H_

#include"ResourceIdentifiers.hpp"
#include"ResourceHolder.hpp"

#include <SFML/Audio/SoundBuffer.hpp>
#include <SFML/Audio/Sound.hpp>
#include<queue>

class SoundHolder 
{
public:
	SoundHolder();

	void play(SoundEffect::ID type);;
	void emptyQueue();


private:
	SoundBufferHolder mSounds;
	std::queue<sf::Sound> soundQueue;

};

#endif // !SOUNDHOLER_H_
