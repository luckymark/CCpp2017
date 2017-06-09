#ifndef MUSIC_H
#define MUSIC_H
#include <SFML/Audio.hpp>

class Music
{
public:
	Music();
	virtual ~Music();
	static sf::Music BGM;
	static sf::Music BOOM;
	static sf::Music Fire;
	static sf::Music ENEMY_BOOM;
	static sf::Music BOSS_BOOM;
	static void load();

protected:

private:
};

#endif // MUSIC_H
