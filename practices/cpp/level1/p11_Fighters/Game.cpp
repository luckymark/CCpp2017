#include "Game.h"
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <windows.h>//Delete it when project completes
#include <algorithm>
#include <list>
#include <vector>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#define PI 3.1415926
#define EPS 0.00001
using namespace std;

Game::Game()
	:mWindow(sf::VideoMode(1280, 960), "TouHou20.0-chs")
	, font()
	, player(1)
{
	NowLoading();

	loadBackgrounds();

	srand((unsigned)time(NULL));
	remnant = 3;
	mIsMovingUp = false;
	mIsMovingDown = false;
	mIsMovingLeft = false;
	mIsMovingRight = false;
	mIsGrazing = false;
	mIsFire = false;

	loadPrimeFrame();

	loadPointsAndEffs();

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
	loadingUISub.setScale(1.5, 1.5);
	loadingUISub.setPosition(sf::Vector2f(1000, 800));
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

	if (!Title1.loadFromFile("E:\\Media\\Sources\\Jpg&Png\\TH\\Ex.15\\front\\logo\\stg01logo.png"))
	{
		puts("Error: Load stg01logo failed!");
	}
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
void Game::loadPointsAndEffs()
{
	if (!julgePointArray.loadFromFile("E:\\Media\\Sources\\Jpg&Png\\TH\\Ex\\bullet\\etama2.png"))//into player
	{
		puts("Error: Load julgePointArray failed!");
	}

	julgePoint.setTexture(julgePointArray);
	julgePoint.setTextureRect(sf::IntRect(0, 16, 64, 64));
	julgePoint.setScale(1.5, 1.5);

	if (!bullets.loadFromFile("E:\\Media\\Sources\\Jpg&Png\\TH\\Ex\\bullet\\etama.png"))
	{
		puts("Error: Load bullets failed!");
	}
	if (!buffetsEff.loadFromFile("E:\\Media\\Sources\\Jpg&Png\\TH\\Ex.15\\enemy\\enemy_aura.png"))
	{
		puts("Error: Load buffetsEff failed!");
	}
	if (!deathCircle.loadFromFile("E:\\Media\\Sources\\Jpg&Png\\TH\\Ex.15\\effect\\eff_deadcircle.png"))
	{
		puts("Error: Load deathCircle failed!");
	}
	if (!allBullets1.loadFromFile("E:\\Media\\Sources\\Jpg&Png\\TH\\Ex.15\\bullet\\bullet1.png"))
	{
		puts("Error: Load deathCircle failed!");
	}
	if (!allBullets2.loadFromFile("E:\\Media\\Sources\\Jpg&Png\\TH\\Ex.15\\bullet\\bullet2.png"))
	{
		puts("Error: Load deathCircle failed!");
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
	enemyBulletSound.setVolume(30);
	if (!breakSoundBuffer.loadFromFile("E:\\Media\\Sources\\Jpg&Png\\TH\\origin.12\\se_enep00.wav"))
	{
		puts("Error: Open se_enep02.wav failed!");
	}
	breakSound.setBuffer(breakSoundBuffer);
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
	
	static int evts[20] = { 0 };

	static int curTime = 1;
	if (curTime < elapsed1.asSeconds())
	{
		printf("%.0f\n", elapsed1.asSeconds());
		curTime++;
	}

	switch ((int)elapsed1.asSeconds())
	{
	case 1:
		//pre
		evts[1] = 1;
		break;
	case 12:
		//title
		evts[2] = 1;
		break;
	case 17:
		evts[3] = 1;
		break;
	case 37:
		//wave

		break;
	case 50:
		//middle

		break;
	case 63:
		//spellCard1

		break;
	case 100:
		//boss
		break;
	}

	if (evts[1])
	{
		if (S1E1())
		{
			evts[1] = 0;
		}
	}
	if (evts[2])
	{
		if (S1E2())
		{
			evts[2] = 0;
		}
	}
}

int Game::S1E1()
{
	static int i1 = 0;
	i1++;
	static list<FO> wave1, wave2;
	double gapTime = 0.4;
	int gapFrame = gapTime * 60;
	static int gap = 0, temp = 0;
	if (i1 % gapFrame == 1 && i1 < 15 * gapFrame)
	{
		FO sButterfly(2);
		sButterfly.hero.setTexture(Enemy1);
		sButterfly.hero.setTextureRect(sf::IntRect(0, 320, sButterfly.width, sButterfly.height));
		sButterfly.hero.setScale(sf::Vector2f(1.5, 1.5));
		sButterfly.hero.setPosition(sf::Vector2f(400 + pow(-1.0, i1 / gapFrame) * 0.8 * i1, 20.0));
		//sButterfly.setSButterfly(400 + pow(-1.0, i1 / gapFrame) * i1, 20.0);
		sButterfly.born = i1;
		sButterfly.gap = gap;
		gap++;
		//printf("Now %x\n", sButterfly.hero);
		
		wave1.push_back(sButterfly);
	}
	if (i1 == 270)
	{
		FO mButterfly(5);
		mButterfly.hero.setTexture(Enemy1);
		mButterfly.hero.setTextureRect(sf::IntRect(0, 448, mButterfly.width, mButterfly.height));
		mButterfly.hero.setScale(sf::Vector2f(1.5, 1.5));
		mButterfly.hero.setOrigin(mButterfly.width*0.5, mButterfly.height*0.5 - 24);
		mButterfly.hero.setPosition(sf::Vector2f(400 + 200, -20.0));
		mButterfly.born = i1;
		wave2.push_back(mButterfly);
		mButterfly.hero.setPosition(sf::Vector2f(400 - 200, -20.0));
		wave2.push_back(mButterfly);
	}
	wave1.remove_if(isFOOutOfBoard);
	for (list<FO>::iterator it = wave1.begin(); it != wave1.end(); it++)
	{
		
		temp = i1 - it->gap * gapFrame;
		if (temp < 200)//phase1
		{
			if (i1 % 20 == 0)
			{
				setRoundSnipe(it, 5.0);
			}
			it->speed = 50.0 / (temp + 1.0);
			it->theta = 0.5*PI;
			it->hero.setTextureRect(sf::IntRect(i1 % 35 / 7 * it->width, 320, it->width, it->height));
		}
		else//phase2
		{
			it->speed = (temp - 200) / 10.0;
			it->theta = 0.5 * PI + pow(-1.0, it->gap + 1.0) * 10.0*PI / 360.0;

			if (it->speed <= 11)
			{
				it->hero.setTextureRect(sf::IntRect((int)it->speed * it->width, 320, it->width, it->height));
			}
			else
			{
				it->hero.setTextureRect(sf::IntRect((int)11 * it->width, 320, it->width, it->height));
			}
			if (it->theta > PI / 2.0)
			{
				it->hero.setScale(-1.5, 1.5);

				if (!it->isSym)
				{
					it->hero.move(1.5*it->width, 0);
					it->isSym = true;
				}
			}
		}

		enemyCollisionProcessing(it);
		
		pushToDraw(it);
	}
	wave2.remove_if(isFOOutOfBoard);
	for (list<FO>::iterator it = wave2.begin(); it != wave2.end(); it++)
	{
		it->hero.setTextureRect(sf::IntRect(i1 % 50 / 10 * it->width, 448, it->width, it->height));
		if (i1 < 400)
		{
			it->speed = (650.0 - i1) / 240;
			it->theta = 0.5 * PI;
		}
		else if (i1 >= 400 && i1 < 500)
		{
			it->speed = 0.0;
			
			setSharpRandom(it, 3.0);
			setSharpRandom(it, 3.0);
			
		}
		else
		{
			it->speed = (i1 - 500) / 60.0;
			it->theta = 1.5 * PI;
		}

		enemyCollisionProcessing(it);

		pushToDraw(it);
	}

	if (i1 > 15 * 60)
	{
		wave1.clear();//Final clear for accident
		wave2.clear();
		return 1;
	}
	return 0;
}

int Game::S1E2()
{
	static int i1 = 0;
	i1++;
	static list<FO> wave1;

	if (i1 == 1)
	{
		FO mainTitle(0);
		mainTitle.hero.setTexture(Title1);
		mainTitle.hero.setTextureRect(sf::IntRect(0, 0, 512, 256));
		//mainTitle.hero.setScale(sf::Vector2f(1.5, 1.5));
		mainTitle.speed = 0.0;
		mainTitle.hero.setPosition(sf::Vector2f(200.0, 150.0));
		mainTitle.hero.setColor(sf::Color(255, 255, 255, 0));

		wave1.push_back(mainTitle);
	}

	for (list<FO>::iterator it = wave1.begin(); it != wave1.end(); it++)
	{
		it->hero.setColor(sf::Color(255, 255, 255, -i1*(i1-301) / (151.0*150.0) * 255));
		pushToDraw(it);
	}
	if (i1 > 5 * 60)
	{
		wave1.clear();//Final clear for accident
		return 1;
	}
	return 0;
}

int Game::S1E3()
{
	static int i1 = 0;
	i1++;
	static list<FO> wave1, wave2;
	double gapTime = 0.4;
	int gapFrame = gapTime * 60;
	static int gap = 0, temp = 0;

	if (i1 > 10 * 60)
	{
		wave1.clear();//Final clear for accident
		wave2.clear();
		return 1;
	}
	return 0;
}

void Game::pushToDraw(list<FO>::iterator it)
{
	if (it->speed > EPS)
	{
		it->velocity.x = it->speed * cos(it->theta);
		it->velocity.y = it->speed * sin(it->theta);
		it->hero.move(it->velocity);
	}
	
	enemies.push_back(it->hero);
}

void Game::frameDisplay()//ammo->front->player->jpoint
{
	
	player.staticFrame = player.staticFrame % 56;
	player.staticFrame++;
	mWindow.clear();
	
	backgroundDisplay();

	playerAmmoDisplay();

	enemiesDisplay();
	
	enemyBulletsDisplay();

	effsDisplay();
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
		//printf("Now %lf %lf!\n", it->getPosition().x, it->getPosition().y);
		mWindow.draw(*it);
	}
	enemies.clear();
}
//
void Game::enemyBulletsDisplay()
{
	for (list<FO>::iterator it = enemyBullets.begin(); it != enemyBullets.end(); it++)
	{
		pushToDraw(it);
	}
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

	
	static int julgeRotate = 0;
	julgeRotate++;
	julgeRotate %= 360;
	julgePoint.setOrigin(32, 32);
	julgePoint.setRotation(julgeRotate);
	julgePoint.setPosition(sf::Vector2f(player.hero.getPosition().x - 22 + 48, player.hero.getPosition().y - 8 + 48));
	if (mIsGrazing)
	{	
		mWindow.draw(julgePoint);
	}
}
//
void Game::effsDisplay()
{
	for (list<sf::Sprite>::iterator it = playerBulletsEffs.begin(); it != playerBulletsEffs.end(); it++)
	{
		mWindow.draw(*it);
	}
	playerBulletsEffs.clear();
	for (list<sf::Sprite>::iterator it = deathEffs.begin(); it != deathEffs.end(); it++)
	{
		double i = it->getScale().x, j = it->getScale().y / it->getScale().x;
		i += 0.1;
		it->setScale(i, i*j);
		it->setColor(sf::Color(255, 255, 255, 255 * (1.2 - 0.5*i)));
		/*if (it->getRotation() > EPS)
		{
		//	it->setScale(i + 0.3, (i + 0.3)*j);
			it->setColor(sf::Color(255, 255, 255, 255 * (1 - 0.5*(i - 0.3))));
		}*/
		
		mWindow.draw(*it);
	}
	deathEffs.remove_if([](sf::Sprite obj) { if (obj.getScale().x > 2.3 || (obj.getRotation() < EPS && obj.getScale().x > 2.0))/* * 1.0 && obj.getRotation() == 0) || (obj.getScale().x > 2.3 && obj.getRotation() != 0))*/ return true; else return false; });
}

void Game::enemyCollisionProcessing(list<FO>::iterator it)
{
	for (list<sf::Sprite>::iterator itAmmo = playerBullets.begin(); itAmmo != playerBullets.end(); itAmmo++)
	{
		if (checkCollision(it->hero, *itAmmo))
		{
			enemyUnderAttack(it, itAmmo);

			if (it->HealthPoint <= 0)
			{
				enemyCrash(it);
			}
		}
	}
}

void Game::enemyUnderAttack(list<FO>::iterator it, list<sf::Sprite>::iterator itAmmo)
{
	//printf("%d\n", it->HealthPoint);
	it->HealthPoint -= player.damage;
	AmmoEff.setTexture(buffetsEff);
	AmmoEff.setTextureRect(sf::IntRect(player.staticFrame % 7 * 48, 0, 48, 48));
	AmmoEff.setPosition(itAmmo->getPosition().x - 10, it->hero.getPosition().y + it->height - 10);
	playerBulletsEffs.push_back(AmmoEff);
	itAmmo->setPosition(-100, -100);
}

void Game::enemyCrash(list<FO>::iterator it)
{
	breakSound.play();
	deathEff.setTexture(deathCircle);
	deathEff.setTextureRect(sf::IntRect(64, 0, 64, 64));
	deathEff.setOrigin(32, 32);
	deathEff.setPosition(it->hero.getPosition().x + it->width * 0.5, it->hero.getPosition().y + it->height * 0.5);
	deathEff.setScale(0.1, 0.1);
	deathEffs.push_back(deathEff);
	deathEff.setScale(0.3, 0.06);
	deathEff.setRotation(rand() % 360);
	deathEffs.push_back(deathEff);
	it->hero.setPosition(-100, -100);
}

void Game::setRoundSnipe(list<FO>::iterator it, double speed)
{
	enemyBulletSound.play();
	FO RoundSnipe;
	RoundSnipe.speed = speed;
	RoundSnipe.hero.setTexture(allBullets1);
	RoundSnipe.hero.setTextureRect(sf::IntRect(80, 32, 16, 16));
	RoundSnipe.hero.setOrigin(8, 8);
	RoundSnipe.hero.setScale(1.5, 1.5);
	RoundSnipe.hero.setPosition(it->hero.getPosition().x, it->hero.getPosition().y + it->height);
	RoundSnipe.theta = atan2(julgePoint.getPosition().y - RoundSnipe.hero.getPosition().y, julgePoint.getPosition().x - RoundSnipe.hero.getPosition().x);
	enemyBullets.push_back(RoundSnipe);
}

void Game::setSharpRandom(list<FO>::iterator it, double speed)
{
	enemyBulletSound.play();
	FO SharpRandom;
	SharpRandom.speed = speed;
	SharpRandom.theta = rand()%360;
	SharpRandom.hero.setTexture(allBullets1);
	SharpRandom.hero.setTextureRect(sf::IntRect(80, 96, 16, 16));
	SharpRandom.hero.setOrigin(8, 8);
	SharpRandom.hero.setScale(1.5, 1.5);
	SharpRandom.hero.setPosition(it->hero.getPosition().x, it->hero.getPosition().y + it->height);
	SharpRandom.hero.setRotation(SharpRandom.theta  / PI * 180.0 + 90);
	enemyBullets.push_back(SharpRandom);
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
	if (value.getPosition().y >= 0 && value.getPosition().y <= 960 && value.getPosition().x >= 0 && value.getPosition().x <= 960)
	{
		return false;
	}
	return true;
}

bool isFOOutOfBoard(const FO value)
{
	if (value.hero.getPosition().y >= -100 && value.hero.getPosition().y <= 960 && value.hero.getPosition().x >= 0 && value.hero.getPosition().x <= 960)
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

bool Game::checkCollision(sf::Sprite obj1, sf::Sprite obj2)
{
	sf::FloatRect f1 = obj1.getGlobalBounds();
	sf::FloatRect f2 = obj2.getGlobalBounds();
	if (f1.intersects(f2))
	{
		return true;
	}
	return false;
}

/*bool Game::checkCollision(sf::Sprite obj1, sf::Sprite obj2)
{
	double x1, y1, th1, x2, y2, th2;
	sf::Vector2f v1[4], v2[4];
	x1 = obj1.getPosition().x;
	y1 = obj1.getPosition().y;
	th1 = obj1.getRotation();
	x2 = obj2.getPosition().x;
	y2 = obj2.getPosition().y;
	th2 = obj1.getRotation();
	v1[0].x = x1;
	v1[0].y = y1;
	v1[1].x = x1 + obj1.getTextureRect().width + cos(obj1.getRotation());
	v1[1].y = y1;
	v1[2].x = x1;
	v1[2].y = y1 + obj1.getTextureRect().height + sin(obj1.getRotation());
	v1[3].x = x1 + obj1.getTextureRect().width + cos(obj1.getRotation());
	v1[3].y = y1 + obj1.getTextureRect().height + sin(obj1.getRotation());
	v2[0].x = x2;
	v2[0].y = y2;
	v2[1].x = x2 + obj2.getTextureRect().width + cos(obj2.getRotation());
	v2[1].y = y2;
	v2[2].x = x2;
	v2[2].y = y2 + obj2.getTextureRect().height + sin(obj2.getRotation());
	v2[3].x = x2 + obj2.getTextureRect().width + cos(obj2.getRotation());
	v2[3].y = y2 + obj2.getTextureRect().height + sin(obj2.getRotation());
	if (max(x1, x1 + obj1.getTextureRect().width) < min(x2, x2 + obj2.getTextureRect().width) || min(x1, x1 + obj1.getTextureRect().width) > max(x2, x2 + obj2.getTextureRect().width))
	{
		return false;
	}
	if (max(y1, y1 + obj1.getTextureRect().height) < min(y2, y2 + obj2.getTextureRect().height) || min(y1, y1 + obj1.getTextureRect().height) > max(y2, y2 + obj2.getTextureRect().height))
	{
		return false;
	}

	return true;
}*/

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
