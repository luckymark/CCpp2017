#ifndef APPLICATION_H_
#define APPLICATION_H_

#include "ResourceHolder.h"
#include "ResourceIdentifiers.h"
#include "Player.h"
#include "StateStack.h"
#include "YOUneedTHIS.h"
#include "State.h"
#include "StateIdentifiers.h"
#include "TitleState.h"
#include "GameState.h"
#include "MenuState.h"
#include "PauseState.h"
#include "SettingsState.h"
#include "GameOverState.h"
#include "MusicPlayer.h"
#include "SounderPlayer.h"

class Application
{
	public:
		Application();
		void run();
		

	private:
		void processInput();
		void update(sf::Time dt);
		void render();

		void updateStatistics(sf::Time dt);
		void registerStates();


	private:
		static const sf::Time TimePerFrame;

		sf::RenderWindow mWindow;
		TextureHolder mTextures;
	  	FontHolder mFonts;
		Player mPlayer;
		MusicPlayer	mMusic;
		SoundPlayer mSounds;
		StateStack mStateStack;

		sf::Text mStatisticsText;
		sf::Time mStatisticsUpdateTime;
		std::size_t	mStatisticsNumFrames;
};

#endif // !APPLICATION_H_
