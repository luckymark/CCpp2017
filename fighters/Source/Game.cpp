#include"Include\Game.h"
#include "Include\StringHelpers.hpp"
#include<SFML/Graphics/Text.hpp>
#include<SFML/Graphics/Font.hpp>



Game::Game():
	 mStatisticsNumFrames(0)
	, myTime(sf::seconds(0))
	, mMode(640, 700)
	, mTitle("F I G H T E R S")
{
	loadMedia();	//��ȡ��Ҫ�ļ�
	initialize();	//������Ϸ����
	buildWorld();	//��������

}
void Game::run()
{
	sf::Time timeSinceLastUpdate = sf::Time::Zero;

	while (mWindow->isOpen())
	{
		sf::Time elapsedTime = clock.restart();
		timeSinceLastUpdate += elapsedTime;

		while (timeSinceLastUpdate > TimePerFrame)
		{
			timeSinceLastUpdate -= TimePerFrame;
			//ֻ����Start Reborn ���棬��Ҳ�������ϷҪ�ػ���
			if (curStatus == gameStatus::Start || curStatus == gameStatus::Reborn)
			{
				processInput();	
				update(TimePerFrame);
				updateStatistics(elapsedTime);

			}
			//����ֻ������滥��
			updateStatus();
		}
		
		render();
	}
}

void Game::updateStatus()
{
	sf::Event event;
	while (mWindow->pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::KeyPressed:
			handlePlayerInput(event.key.code, true);		//��ҶԽ����Ӱ��
			break;
		case sf::Event::Closed:
			mWindow->close();
			break;
		}
	}
	handleGameOutput();		//��ϷҪ�ضԽ����Ӱ��


}

void Game::processInput()
{

	CommandQueue& mCommands = mWorld->getCommandQueue();

	sf::Event event;
	while (mWindow->pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::KeyPressed:
			handlePlayerInput(event.key.code, true);
			break;
		case sf::Event::Closed:
			mWindow->close();
			break;
		}

		mPlayer->handleEvent(event, mCommands);

		if (event.type == sf::Event::Closed)
			mWindow->close();
	}

	mPlayer->handleRealtimeInput(mCommands);
}



void Game::update(sf::Time deltaTime)
{
	updateGameStatus(deltaTime);		//��ϷҪ�ضԽ���ļ�ʱӰ��
	mWorld->update(deltaTime);
}
void Game::render()
{		

	mWindow->clear();
	mWorld->draw();

	mWindow->setView(mWindow->getDefaultView());
	mWindow->draw(mStatisticsText);
	drawCurScene();		//��ʾ��ǰ����

	mWindow->display();


}

void Game::updateStatistics(sf::Time elapsedTime)
{
	myTime += elapsedTime;

	mStatisticsText.setString("Score: " + toString(myScore));
	
}


void Game::handleGameOutput()
{
	switch (curStatus)		//�����л�
	{
	case gameStatus::Start:				//Start ת�� Reborn
		if (!mPlayer->isPlayerAlive())
		{
			curStatus = gameStatus::Reborn;
			BattleTheme.setPaused(true);
			DefeatedTheme.play(Music::DefeatedTheme);

			mRebornNode->removeWrecks();

			std::unique_ptr<Flash> mflash(new Flash(mRebornTexture, Textures::RebornCircle));		//���֮ǰ��circle�������µ�
			mflash->setPosition(100, 70);
			mRebornCircle = mflash.get();
			mRebornNode->attachChild(std::move(mflash));

		}
		break;
	case gameStatus::Reborn:				//Reborn ת�� Start
		if (mPlayer->isPlayerAlive())
		{
			getReborn();
		}	
		break;
	}

	if (mWorld->getViewCenter().y < mWorld->getWorldLength()/2 +1500 &&!BattleThemeShifted)
	{
		BattleTheme.setVolume(-50.f);

			if (mWorld->getViewCenter().y < mWorld->getWorldLength() / 2 + 800 && !BattleThemeShifted)
			{
				BattleThemeShifted = true;
				BattleTheme.setVolume(50);
				BattleTheme.play(Music::BattleTheme2);
			}


		
	}
}


void Game::handlePlayerInput(sf::Keyboard::Key key, bool isPressed)
{
	switch (curStatus)
	{
	case gameStatus::Intro:
		introInterface(key);		//intro����
		break;
	case gameStatus::Start:
	case gameStatus::Pause:
		startInterface(key);		//Start��Pause�л�
		break;
	case gameStatus::Reborn:
		if (key == sf::Keyboard::Num1)
		{
//			mPlayer->Reborn();
//			getReborn();
		}
	case gameStatus::Over:
		if (key == sf::Keyboard::Space&&mRebornCircle->isMarkedForRemoval())
		{
			Restart();
		}
		break;
	}

}

void Game::updateGameStatus(sf::Time dt)
{

	if (curStatus == gameStatus::Reborn)
	{
		mRebornNode->update(dt);

		if (mRebornCircle->isMarkedForRemoval())
			curStatus = gameStatus::Over;
	}

}

void Game::loadMedia()
{
	mFont.loadFromFile("Media/Sansation.ttf");
	pauseTexture.loadFromFile("Media/Textures/Interface/pause.png");
	Intro1.loadFromFile("Media/Textures/Interface/intro1.png");
	Intro2.loadFromFile("Media/Textures/Interface/intro2.png");
	Intro3.loadFromFile("Media/Textures/Interface/intro3.png");
	Intro4.loadFromFile("Media/Textures/Interface/intro4.png");
	Intro5.loadFromFile("Media/Textures/Interface/intro5.png");
	mRebornTexture.loadFromFile("Media/Flash/circles.png");
}

void Game::initialize()
{
	

	curStatus = gameStatus::Intro;
	introCount = 1;

	mStatisticsText.setFont(mFont);
	mStatisticsText.setPosition(5.f, 5.f);
	mStatisticsText.setCharacterSize(30);

	mGameOver.loadFromFile("Media/Textures/Interface/GameOver.png");
	GameoverSprite.setTexture(mGameOver);
	GameoverSprite.setPosition(15.f, 310.f);

	mReborn.loadFromFile("Media/Textures/Interface/Reborn.png");
	RebornSprite.setTexture(mReborn);
	RebornSprite.setPosition(15.f, 320.f);


	TimePerFrame = sf::seconds(1.f /60.f);


	pauseSprite.setTexture(pauseTexture);
	pauseSprite.setPosition(210, 100);


	introSprite.setTexture(Intro1);
	introSprite.setPosition(0, 0);

	IntroTheme.play(Music::IntroTheme);

	BattleThemeShifted = false;

}

void Game::buildWorld()		//�������Ⱥ�˳����Ҫ
{
	mPlayer = new Player;
	mWindow = new sf::RenderWindow(mMode, mTitle);
	mWorld = new World(*mWindow, myScore, mPlayer);
	mRebornNode = new SceneNode;
}

void Game::Restart()
{
	delete mPlayer;
	delete mWindow;
	delete mWorld;
	delete mRebornNode;



	DefeatedTheme.stop();

	initialize();
	buildWorld();
}

void Game::getReborn()
{
		mRebornCircle->remove();	//�������Ƴ���������δ������circle

		curStatus = gameStatus::Start;
		BattleTheme.setPaused(false);
		DefeatedTheme.stop();
}

void Game::drawCurScene()
{
	if (curStatus == gameStatus::Pause)
	{
		mWindow->draw(pauseSprite);
	}
	else if (curStatus == gameStatus::Intro)
	{
		mWindow->draw(introSprite);
	}
	else if (curStatus == gameStatus::Reborn)
	{
		mWindow->draw(*mRebornNode);
		mWindow->draw(RebornSprite);
	}
	else if (curStatus == gameStatus::Over)
	{
		mWindow->draw(GameoverSprite);
	}
}


void Game::introInterface(sf::Keyboard::Key key)
{
	if (curStatus == gameStatus::Intro)			//����Intro�˵�
	{
		switch (key)
		{
		case sf::Keyboard::Q:
			if (introCount == 1)
			{
				introCount = 2;
				introSprite.setTexture(Intro2);
			}
			else if (introCount == 2)
			{
				introCount = 3;
				introSprite.setTexture(Intro3);
			}
			break;
		case sf::Keyboard::E:
			if (introCount == 3)
			{
				introCount = 4;
				introSprite.setTexture(Intro4);
			}
			else if (introCount == 4)
			{
				introCount = 5;
				introSprite.setTexture(Intro5);
			}
			break;
		case sf::Keyboard::Up:
			if (introCount == 5)
			{
				IntroTheme.stop();
				BattleTheme.play(Music::BattleTheme1);
				curStatus = gameStatus::Start;
				clock.restart();
			}
			break;
		}
	}
}

void Game::startInterface(sf::Keyboard::Key key)
{
	if (key == sf::Keyboard::Escape)
	{
		if (curStatus == gameStatus::Pause)
		{
			curStatus = gameStatus::Start;
			BattleTheme.setPaused(false);
			PauseTheme.stop();
			clock.restart();
		}
		else
		{
			curStatus = gameStatus::Pause;
			BattleTheme.setPaused(true);
			PauseTheme.play(Music::PauseTheme);
		}
	}
}

