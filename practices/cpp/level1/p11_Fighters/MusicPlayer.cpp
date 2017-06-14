#include "MusicPlayer.h"

MusicPlayer::MusicPlayer()
: mMusic()
, mFilenames()
, mVolume(100.f)
{
	mFilenames[Music::MenuTheme]    = "resources/sound/MenuTheme.ogg";
	mFilenames[Music::MissionTheme] = "resources/sound/MissionTheme.ogg";
}

void MusicPlayer::play(Music::ID theme)
{
	std::string filename = mFilenames[theme];
	if (!mMusic.openFromFile(filename))
		throw std::runtime_error("Music " + filename + " could not be loaded.");
	mMusic.setVolume(mVolume);
	mMusic.setLoop(true);
	mMusic.play();
}

void MusicPlayer::stop()
{
	mMusic.stop();
}

void MusicPlayer::setVolume(float volume)
{
	mVolume = volume;
}

void MusicPlayer::setPaused(bool paused)
{
	if (paused)
		mMusic.pause();
	else
		mMusic.play();
}
