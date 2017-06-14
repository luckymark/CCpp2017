#include <SFML/Audio.hpp>
#ifndef GAMEMUSIC_H
#define GAMEMUSIC_H
class gameMusic {
		sf::SoundBuffer gameBuffer;
		sf::Sound gameSound;
		sf::Music bigMusic;
		int type;
	public:
		gameMusic(int type=1);
		void playMusic();
};
#endif
