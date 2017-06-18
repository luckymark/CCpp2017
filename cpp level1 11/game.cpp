 #include "stdafx.h"
 #include "Plane.h"
 #include "game.h"
 #include "EnemyBurst.h"
 #include "StrUpdate.h"
 #include "StartMenu.h"
 #include "HelpMenu.h"
 #include "AgainMenu.h"
 #include "BossBurst.h"
sf::RenderWindow mainWindow;

MusicPlay musicPlay;

void Game::play()
{
	
	Plane plane(width, height);
	NormalBullet bullet[bulnumber];
	MultiBullet multiBullet[multionce*multinumber];
	Enemy enemy[enenumber];
	EnemyBurst enemyBurst[enenumber];
	Boss boss[bossnumber];
	BossBurst bossBurst[bossnumber];
	ObjectManager manager;
	
	musicPlay.GameMusic();
	//µÚÒ»´¦ÉùÒô
	
	while (StartMenu::number==0&&StrUpdate::life>0)
	{
	
		mainWindow.clear();
		manager.BackgroundUpdate();
		manager.PlaneUpdate(plane);

		manager.BulletUpdate(bullet);
		manager.MultiBulletUpdate(multiBullet);
		manager.EnemyUpdate(enemy);
		manager.EnemyBurstUpdate(enemyBurst,bullet,multiBullet,enemy);
		manager.BossUpdate(boss);
		manager.BossBurstUpdate(bossBurst,bullet,multiBullet,boss);
		StrUpdate::update();
		LevelControl::Change();
		mainWindow.display();
	}
}

void Game::start()
{
	if (StartMenu::number == -1)
	{
		mainWindow.create(sf::VideoMode(width, height, 32), "PlaneGame!");
		StartMenu start;
		start.Draw();
		mainWindow.display();
		start.Choose();
	}
}

void Game::help()
{
	if (StartMenu::number == 1)
	{
		HelpMenu help;
		help.Draw();
		mainWindow.display();
		help.Choose();
	}
}

void Game::again()
{
	if (StartMenu::number != 2)
	{
		AgainMenu again;
		again.Draw();
		mainWindow.display();
		musicPlay.AgainMusic();
		again.Choose();

	}
}

int Game::head = 0;
int Game::tail = 0;
int Game::flag = 1;
bool Game::empty = true;

int Game::mhead = 0;
int Game::mtail = 0;
int Game::mflag = 1;
bool Game::mempty = true;

int Game::ehead = 0;
int Game::etail = 0;
bool Game::eempty = true;

int Game::ebhead = 0;
int Game::ebtail = 0;
bool Game::ebempty = true;

int Game::bhead = 0;
int Game::btail = 0;
bool Game::bempty = true;

int Game::bbhead = 0;
int Game::bbtail = 0;
bool Game::bbempty = true;
