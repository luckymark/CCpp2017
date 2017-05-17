#include <SFML/Audio.hpp>
#ifndef GAMEMUSIC_H
#define GAMEMUSIC_H
class gameMusic {
		sf::SoundBuffer gameBuffer;
		sf::Sound gameSound;
	public:
		gameMusic(int type);
		void playMusic();
};
#endif
