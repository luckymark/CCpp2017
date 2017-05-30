#include "Game.h"
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <windows.h>//Delete when project completes
#include <list>
#include <vector>
#include <math.h>
#define PI 3.1415926
using namespace std;

Game::Game()
	:mWindow(sf::VideoMode(1280, 960), "TouHou20.0-chs")
	, font()
	, player(1)
{
	NowLoading();

	loadBackgrounds();

	mIsMovingUp = false;
	mIsMovingDown = false;
	mIsMovingLeft = false;
	mIsMovingRight = false;
	mIsGrazing = false;
	mIsFire = false;

	loadPrimeFrame();

	loadPlayer();

	loadEnemy();

	// Create a graphical text to display
	if (!font.loadFromFile("C:\\Users\\Administrator\\Documents\\Rainmeter\\Skins\\Ultralight\\@Resources\\Fonts\\RobotoCondensed-Regular.ttf"))
	{
		puts("Error: Load RobotoCondensed-Regular.ttf failed!");
	}
	text.setString("Testing...");
	text.setFont(font);
	text.setCharacterSize(50);

	loadMusicAndSounds();

	Sleep(1000);//Cancel it when Game project completes

}
//
void Game::NowLoading()
{
	// Create the loading window
	if (!loading.loadFromFile("E:\\Media\\Sources\\Jpg&Png\\TH\\Ex\\loading\\sig.png"))
	{
		puts("Error: Load loading failed!");
	}
	if (!nowLoading.loadFromFile("E:\\Media\\Sources\\Jpg&Png\\TH\\Ex\\ascii\\loading.png", sf::IntRect(0, 0, 128, 64)))
	{
		puts("Error: Load nowloading failed!");
	}
	loadingUI.setTexture(loading);
	loadingUISub.setTexture(nowLoading);
	loadingUISub.setPosition(sf::Vector2f(1100, 860));
	mWindow.clear();
	mWindow.draw(loadingUI);
	mWindow.draw(loadingUISub);
	mWindow.display();
}
//
void Game::loadBackgrounds()
{
	if (!bg1.loadFromFile("E:\\Media\\Sources\\Jpg&Png\\TH\\Ex\\background\\stage02\\stage02a.png"))
	{
		puts("Error: Load stage02a failed!");
	}
	if (!bgEff1.loadFromFile("E:\\Media\\Sources\\Jpg&Png\\TH\\Ex\\background\\stage02\\stage02b.png"))
	{
		puts("Error: Load stage02b failed!");
	}
	if (!bg2.loadFromFile("E:\\Media\\Sources\\Jpg&Png\\TH\\Ex.10\\background\\stg3bg.png"))
	{
		puts("Error: Load stage3bg failed!");
	}
	if (!bgEff2.loadFromFile("E:\\Media\\Sources\\Jpg&Png\\TH\\Ex.10\\background\\stg3bg2.png"))
	{
		puts("Error: Load stage3bg failed!");
	}
	for (int i = 0; i < 6; i++)
	{
		back[i].setTexture(bg1);
		back[i].setScale(sf::Vector2f(1.5, 1.5));
		back[i].setPosition((float)65.0, (float)(i - 1)*192.0 + 35.0);
		backEff[i].setTexture(bgEff1);
		backEff[i].setScale(sf::Vector2f(1.5, 1.5));
		backEff[i].setPosition(65.0, (i - 1)*384.0 + 35.0);
	}

	/*for (int i = 0; i < 6; i++)
	{
	back[i].setTexture(bg2);
	back[i].setScale(sf::Vector2f(3.0, 3.0));
	back[i].setPosition(65.0, (i - 1)*4*192.0 + 35.0);
	backEff[i].setTexture(bgEff2);
	backEff[i].setScale(sf::Vector2f(6.0, 6.0));
	backEff[i].setPosition(65.0, (i - 1)*384.0/2.0 + 35.0);
	}*/
}
//
void Game::loadPrimeFrame()
{
	// Load a windowsframe to display
	if (!front00.loadFromFile("E:\\Media\\Sources\\Jpg&Png\\TH\\Ex\\front\\front00.png"))
	{
		puts("Error: Load front failed!");
	}
	front01.setTexture(front00);
	front01.setTextureRect(sf::IntRect(65, 0, 490, 1280));
	front01.setPosition(sf::Vector2f(795, 0));
	front02.setTexture(front00);
	front02.setTextureRect(sf::IntRect(69, 1030, 730, 39));
	front02.setPosition(sf::Vector2f(65, 0));
	front03.setTexture(front00);
	front03.setTextureRect(sf::IntRect(69, 1062, 739, 38));
	front03.setPosition(sf::Vector2f(65, 922));
	front04.setTexture(front00);
	front04.setTextureRect(sf::IntRect(0, 0, 70, 1280));
	front04.setPosition(sf::Vector2f(0, 0));
}
//
void Game::loadPlayer()
{
	// Load a player to display
	if (!Reimu.loadFromFile("E:\\Media\\Sources\\Jpg&Png\\TH\\Ex\\player\\pl00\\pl00.png"))
	{
		puts("Error: Load Reimu failed!");
	}
	if (!Marisa.loadFromFile("E:\\Media\\Sources\\Jpg&Png\\TH\\Ex\\player\\pl01\\pl01.png"))
	{
		puts("Error: Load Marisa failed!");
	}
	if (!Sanae.loadFromFile("E:\\Media\\Sources\\Jpg&Png\\TH\\Ex\\player\\pl02\\pl02.png"))
	{
		puts("Error: Load Marisa failed!");
	}

	player.hero.setTexture(Reimu);
	player.hero.setTextureRect(sf::IntRect(0, 0, player.width, player.height));
	player.hero.setPosition(sf::Vector2f(400, 820));
	player.HSAmmo.setTexture(Reimu);
	player.HSAmmo.setTextureRect(sf::IntRect(0, 3 * player.height + 0, 2.0 / 3.0 * player.width, 24));
	player.HSAmmo.setRotation(270);
	player.LSAmmo.setTexture(Reimu);
	player.LSAmmo.setTextureRect(sf::IntRect(4 * player.width, 3 * player.height + 48, 2 * player.width, 24));
	player.LSAmmo.setRotation(270);


	if (!julgePointArray.loadFromFile("E:\\Media\\Sources\\Jpg&Png\\TH\\Ex\\bullet\\etama2.png"))//into player
	{
		puts("Error: Load julgePointArray failed!");
	}

	julgePoint.setTexture(julgePointArray);
	julgePoint.setTextureRect(sf::IntRect(0, 16, 64, 64));

	if (!bullets.loadFromFile("E:\\Media\\Sources\\Jpg&Png\\TH\\Ex\\bullet\\etama.png"))
	{
		puts("Error: Load bullets failed!");
	}
}
//
void Game::loadEnemy()
{
	// Load a enemy to display
	if (!Enemy1.loadFromFile("E:\\Media\\Sources\\Jpg&Png\\TH\\Ex.15\\enemy\\enemy.png"))
	{
		puts("Error: Load enemy1 failed!");
	}
	if (!Enemy2.loadFromFile("E:\\Media\\Sources\\Jpg&Png\\TH\\Ex.15\\enemy\\enemy.png"))
	{
		puts("Error: Load enemy2 failed!");
	}
}
//
void Game::loadMusicAndSounds()
{
	if (!menuMusic.openFromFile("C:\\Users\\Administrator\\Documents\\Visual Studio 2017\\Projects\\Canvas\\x64\\Debug\\上海アリス幻樂団 - 不思議なお祓い棒.wav"))
	{
		puts("Error: Open 上海アリス幻樂団 - 不思議なお祓い棒.wav failed!");
	}
	if (!stage1BGM.openFromFile("C:\\Users\\Administrator\\Documents\\Visual Studio 2017\\Projects\\Canvas\\x64\\Debug\\上海アリス幻樂団 - 春の凑に.wav"))
	{
		puts("Error: Open 上海アリス幻樂団 - 春の凑に.wav failed!");
	}
	if (!stage2BGM.openFromFile("C:\\Users\\Administrator\\Documents\\Visual Studio 2017\\Projects\\Canvas\\x64\\Debug\\上海アリス幻樂団 - 神々が恋した幻想郷.wav"))
	{
		puts("Error: Open 上海アリス幻樂団 - 厄神様の通り道 ～ Dark Road.wav failed!");
	}
	if (!stage3BGM.openFromFile("C:\\Users\\Administrator\\Documents\\Visual Studio 2017\\Projects\\Canvas\\x64\\Debug\\上海アリス幻樂団 - 神々が恋した幻想郷.wav"))
	{
		puts("Error: Open 上海アリス幻樂団 - 神々が恋した幻想郷.wav failed!");
	}
	if (!playerBulletSoundBuffer.loadFromFile("E:\\Media\\Sources\\Jpg&Png\\TH\\origin.15\\se_damage00.wav"))
	{
		puts("Error: Open se_damage00.wav failed!");
	}
	playerBulletSound.setBuffer(playerBulletSoundBuffer);
	playerBulletSound.setVolume(50);
	if (!enemyBulletSoundBuffer.loadFromFile("E:\\Media\\Sources\\Jpg&Png\\TH\\origin.12\\se_tan00.wav"))
	{
		puts("Error: Open se_tan00.wav failed!");
	}
	enemyBulletSound.setBuffer(enemyBulletSoundBuffer);
}

void Game::run()
{
	// Play the music
	//menuMusic.play();
	//menuMusic.setLoop(true);
	//Menu();
	int level = 1;
	switch (level)
	{
	case 1:
		stage1BGM.play();
		stage1BGM.setLoop(true);
		break;
	}
	// Start the game loop
	mWindow.setFramerateLimit(60);
	mWindow.draw(player.hero);//updating
	frameDisplay();
	/*HANDLE hThread_1 = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)BGMPlay, self, 0, NULL);*/
	while (mWindow.isOpen())
	{
		mWindow.clear();
		
		switch (level)
		{
		case 1:
			Stage1();
			break;
		}
		processTaps(); 
		mainProcessing();
		
		frameDisplay();
	}
}

void Game::Stage1()
{
	static sf::Time elapsed1 = clock.restart();
	elapsed1 = clock.getElapsedTime();
	static int Evt = 0;
	static int evts[20] = { 0 };
	printf("%.0f\n", elapsed1.asSeconds());
	switch ((int)elapsed1.asSeconds())
	{
	case 12:
		//title
		if (Evt < 1)
		{
			Evt = 1;
			evts[1] = 1;
			printf("1s\n");
		}
		break;
	case 37:
		//wave
		if (Evt < 2)
		{
			Evt = 2;
			printf("2s\n");
		}
		break;
	case 50:
		//middle
		if (Evt < 3)
		{
			Evt = 3;
			printf("3s\n");
		}
		break;
	case 63:
		//spellCard1
		if (Evt < 4)
		{
			Evt = 4;
			printf("4s\n");
		}
		break;
	case 100:
		//boss
		;
	}

	if (evts[1])
	{
		static int i1 = 0;
		static list<FO> wave1;
		i1++;

		if (i1 == 1)
		{
			FO sButterfly(2);
			sButterfly.hero.setTexture(Enemy1);
			sButterfly.hero.setTextureRect(sf::IntRect(0, 64, sButterfly.width, sButterfly.height));
			sButterfly.hero.setPosition(sf::Vector2f(400, 420));
			wave1.push_back(sButterfly);


		}
		for (list<FO>::iterator it = wave1.begin(); it != wave1.end(); it++)
		{
			it->hero.move(0.0, 1.0);
			enemies.push_back(it->hero);
			//mWindow.draw(it->hero);
		}

		if (i1 > 3000)
		{
			evts[1] = 0;
		}
	}
}

void Game::frameDisplay()//ammo->front->player->jpoint
{
	
	player.staticFrame = player.staticFrame % 56;
	player.staticFrame++;
	mWindow.clear();
	
	backgroundDisplay();

	playerAmmoDisplay();

	enemiesDisplay();

	// Draw the sprite
	mWindow.draw(front01);
	mWindow.draw(front02);
	mWindow.draw(front03);
	mWindow.draw(front04);

	playerDisplay();

	// Draw the string
	mWindow.draw(text);
	// Update the window
	mWindow.display();
}
//
void Game::backgroundDisplay()
{
	for (int i = 0; i < 6; i++)
	{
		if (back[i].getPosition().y >= 5 * 192 + 35)
		{
			back[i].setPosition(65.0, 35 - 192);
		}
		back[i].move(0.0, 3.0);
		mWindow.draw(back[i]);

	}
	for (int i = 0; i < 4; i++)
	{
		if (backEff[i].getPosition().y >= 3 * 384 + 35)
		{
			backEff[i].setPosition(65.0, 35 - 384);
		}
		backEff[i].move(0.0, 5.0);
		mWindow.draw(backEff[i]);
	}
}
//
void Game::playerAmmoDisplay()
{
	//Ammo
	if (mIsFire)
	{
		//playerAmmo = (mIsGrazing) ? player.LSAmmo : player.HSAmmo;
		if (player.staticFrame % 2 == 1)
		{
			player.LSAmmo.setPosition(sf::Vector2f(player.hero.getPosition().x + 4, player.hero.getPosition().y + 80));
			playerBullets.push_back(player.LSAmmo);
			player.LSAmmo.setPosition(sf::Vector2f(player.hero.getPosition().x + 20, player.hero.getPosition().y + 80));
			playerBullets.push_back(player.LSAmmo);
			player.HSAmmo.setPosition(sf::Vector2f(player.hero.getPosition().x + 4, player.hero.getPosition().y + 110));
			playerBullets.push_back(player.HSAmmo);
			player.HSAmmo.setPosition(sf::Vector2f(player.hero.getPosition().x + 20, player.hero.getPosition().y + 110));
			playerBullets.push_back(player.HSAmmo);
		}
	}
	playerBullets.remove_if(isOutOfBoard);
	for (list<sf::Sprite>::iterator it = playerBullets.begin(); it != playerBullets.end(); it++)
	{
		//it->setPosition(it->getPosition().x, it->getPosition().y - 60);
		it->move(0.0, - 60.0);
		mWindow.draw(*it);
	}
}
//
void Game::enemiesDisplay()
{
	for (list<sf::Sprite>::iterator it = enemies.begin(); it != enemies.end(); it++)
	{
		mWindow.draw(*it);
	}
	enemies.clear();
}
//
void Game::playerDisplay()
{
	//player
	if (mIsMovingLeft)
	{
		if (player.dynamicFrame < 14)
		{
			player.dynamicFrame++;
		}
		player.hero.setTextureRect(sf::IntRect(player.width * (player.dynamicFrame / 2), player.height, player.width, player.height));
	}
	else if (mIsMovingRight)
	{
		if (player.dynamicFrame < 14)
		{
			player.dynamicFrame++;
		}
		player.hero.setTextureRect(sf::IntRect(player.width * (player.dynamicFrame / 2), 2 * player.height, player.width, player.height));
	}
	else
	{
		player.hero.setTextureRect(sf::IntRect(player.width * (player.staticFrame / 8), 0, player.width, player.height));
		player.dynamicFrame = 0;
	}

	mWindow.draw(player.hero);//updating

	if (mIsGrazing)
	{
		julgePoint.setPosition(sf::Vector2f(player.hero.getPosition().x - 8, player.hero.getPosition().y + 4));
		mWindow.draw(julgePoint);
	}
}

void Game::processTaps()
{
	sf::Event event;
	while (mWindow.pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::KeyPressed:
			playerInput(event.key.code, true);
			break;
		case sf::Event::KeyReleased:
			playerInput(event.key.code, false);
			break;
		case sf::Event::Closed:
			mWindow.close();
			break;
		default:
			break;
		}
	}
}

void Game::playerInput(sf::Keyboard::Key key, bool isPressed)
{
	if (key == sf::Keyboard::Up)
		mIsMovingUp = isPressed;
	else if (key == sf::Keyboard::Down)
		mIsMovingDown = isPressed;
	else if (key == sf::Keyboard::Left)
		mIsMovingLeft = isPressed;
	else if (key == sf::Keyboard::Right)
		mIsMovingRight = isPressed;
	else if (key == sf::Keyboard::Z)
		mIsFire = isPressed;
	else if (key == sf::Keyboard::LShift)
		mIsGrazing = isPressed;
		player.speed = (mIsGrazing) ? 4.0 : 10.0;
}

bool isOutOfBoard(sf::Sprite value)
{
	if (value.getPosition().y >= 136)
	{
		return false;
	}
	return true;
}

void Game::mainProcessing()
{
	if (mIsMovingUp == true && player.hero.getPosition().y > 40)
	{
		//player.theta = PI*0.5;
		player.hero.move(0.0, float(-player.speed));
	}
	if (mIsMovingDown == true && player.hero.getPosition().y < 850)
	{
		//player.theta = PI*1.5;
		player.hero.move(0.0, float(player.speed));
	}
	if (mIsMovingLeft == true && player.hero.getPosition().x > 69)
	{
		//player.theta = PI;
		player.hero.move(float(-player.speed), 0.0);
	}
	if (mIsMovingRight == true && player.hero.getPosition().x < 751)
	{
		//player.theta = 0.0;
		player.hero.move(float(player.speed), 0.0);
	}
	/*if ((mIsMovingDown || mIsMovingLeft || mIsMovingRight || mIsMovingUp) && !isOutOfBoard(player.hero))
	{
		player.velocity.x = player.speed * cos(player.theta);
		player.velocity.y = player.speed * sin(player.theta);
		player.hero.move(player.velocity);
	}*/
	

	if (mIsFire)
	{
		if (playerBulletSound.getStatus() != playerBulletSound.Playing)
		{
			playerBulletSound.play();
		}
	}
}

/*DWORD WINAPI BGMPlay(LPVOID lpParameter)
{
	Game* game = (Game*)lpParameter;
	int i = 0;
	while (1)
	{
		i %= 10;
		i++;
		if (game->mIsFire && i == 1)
		{
			if (game->playerBulletSound.getStatus() != game->playerBulletSound.Playing)
			{
				game->playerBulletSound.play();
			}

			//
		}
	}
	return 0;
}*/

Game::~Game()
{
	;
}
