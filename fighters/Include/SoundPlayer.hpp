#ifndef SoundPlayer_H_
#define SoundPlayer_H_

#include"ResourceHolder.hpp"
#include"ResourceIdentifiers.hpp"

#include <SFML/Audio/SoundBuffer.hpp>
#include <SFML/Audio/Sound.hpp>

class SoundPlayer
{
public:
	SoundPlayer();

	void			play(SoundEffect::ID type);
private:
	SoundBufferHolder	mSounds;
};


#endif // !SoundPlayer_H_
