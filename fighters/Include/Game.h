#ifndef GAME_H_
#define GAME_H_

#include<SFML/Graphics.hpp>
#include"ResourceHolder.hpp"
#include"Include\Aircraft.hpp"
#include"SceneNode.hpp"
#include"World.hpp"
#include"Player.hpp"
#include"MusicPlayer.h"

class Game 
{
public:                          
					Game();        
	void			run();
	void			processInput();
private:        
	void			processEvents();             
	void			update(sf::Time deltaTime);
	void			updateStatistics(sf::Time elapsedTime);
	void			render();

	void					handlePlayerInput(sf::Keyboard::Key key, bool isPressed);
	void					handlePlayerOption();
private:    
	Player						mPlayer;
	sf::RenderWindow			mWindow;     
	World						mWorld;
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
	sf::Time					mStatisticsUpdateTime;
	std::size_t					mStatisticsNumFrames;
	sf::Time					TimePerFrame;

	sf::Texture					pauseTexture;

	sf::Sprite					pauseSprite;

	int							myScore;
	sf::Time					myTime;

	bool						isPaused;
	bool						isStarted;
	int							introCount;


};


#endif // !GAME_H_

