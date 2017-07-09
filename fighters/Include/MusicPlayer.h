#ifndef BOOK_MUSICPLAYER_HPP
#define BOOK_MUSICPLAYER_HPP

#include "ResourceHolder.hpp"
#include "ResourceIdentifiers.hpp"

#include <SFML/Audio/Music.hpp>
#include <map>
#include <string>


class MusicPlayer
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

#endif // BOOK_MUSICPLAYER_HPP
#pragma once
