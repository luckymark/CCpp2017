#ifndef GAME_H_
#define GAME_H_

#include<SFML/Graphics.hpp>
#include"ResourceHolder.hpp"
#include"Include\Aircraft.hpp"
#include"SceneNode.hpp"
#include"World.hpp"
#include"Player.hpp"
#include"MusicPlayer.h"
#include"Flash.h"

class Game 
{
public:                          
					Game();        
	void			run();
	void			processInput();
	void			updateGameStatus(sf::Time dt);
	void			loadMedia();
	void			initialize();
	void			buildWorld();
	void			Restart();
	void			getReborn();


private:        
	void            introInterface(sf::Keyboard::Key key);
	void			startInterface(sf::Keyboard::Key key);
	void			handleGameOutput();
	void			processEvents();             
	void			update(sf::Time deltaTime);
	void			updateStatistics(sf::Time elapsedTime);
	void			render();

	void			drawCurScene();

	void					handlePlayerInput(sf::Keyboard::Key key, bool isPressed);
	void					updateStatus();
private:    
	enum gameStatus
	{
		Intro,
		Start,
		Pause,
		Reborn,
		Over,
	};


	Player*						mPlayer;
	sf::RenderWindow*			mWindow;     
	World*						mWorld;
	sf::VideoMode				mMode;
	sf::String					mTitle;
	sf::Clock									clock;		//该clock原本在事件循环内
	MusicPlayer		IntroTheme;
	MusicPlayer		BattleTheme;
	MusicPlayer		DefeatedTheme;
	MusicPlayer		PauseTheme;

	sf::Texture		Intro1;
	sf::Texture		Intro2;
	sf::Texture		Intro3;
	sf::Texture		Intro4;
	sf::Texture		Intro5;

	sf::Sprite		introSprite;

	sf::Font					mFont;
	sf::Text					mStatisticsText;
	sf::Text					mGameOver;
	sf::Text					mReborn;
	sf::Time					mStatisticsUpdateTime;
	std::size_t					mStatisticsNumFrames;
	sf::Time					TimePerFrame;

	sf::Texture					pauseTexture;

	sf::Sprite					pauseSprite;

	int							myScore;
	sf::Time					myTime;

	int							curStatus;
	int							introCount;
	bool						BattleThemeShifted;

	sf::Texture					mRebornTexture;
	SceneNode*					mRebornNode;
	Flash*						mRebornCircle;

};


#endif // !GAME_H_

