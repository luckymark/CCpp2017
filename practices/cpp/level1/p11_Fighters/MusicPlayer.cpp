#include "MusicPlayer.h"

MusicPlayer::MusicPlayer()
	:mMusic()
	,mFilenames()
	,mVolume(100.f)
{
	mFilenames[Music::MenuTheme] = "MenuTheme.ogg";
	mFilenames[Music::MissionTheme] = "MissionTheme.ogg";
}

void MusicPlayer::play(Music::ID theme)
{
	std::string filename = mFilenames[theme];
	if (!mMusic.openFromFile(filename))
	{
		throw std::runtime_error("Music " + filename + " counld not be loaded.");
	}

	mMusic.setVolume(mVolume);
	mMusic.setLoop(true);
	mMusic.play();
}

void MusicPlayer::stop()
{
	mMusic.stop();
}

void MusicPlayer::setPaused(bool paused)
{
	if(paused)
	{
		mMusic.pause();
	}
	else
	{
		mMusic.play();
	}
}

void MusicPlayer::setVolume(float volume)
{
	mVolume = volume;
}
