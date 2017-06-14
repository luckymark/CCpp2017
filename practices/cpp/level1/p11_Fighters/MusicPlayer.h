#ifndef MUSICPLAYER_H_
#define MUSICPLAYER_H_

#include "ResourceHolder.h"
#include "ResourceIdentifiers.h"
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <map>
#include <string>

class MusicPlayer : private sf::NonCopyable
{
	public:
									MusicPlayer();

		void						play(Music::ID theme);
		void						stop();
		void						setPaused(bool paused);
		void						setVolume(float volume);

	private:
		sf::Music							mMusic;
		std::map<Music::ID, std::string>	mFilenames;
		float								mVolume;
};

#endif // MUSICPLAYER_H_
