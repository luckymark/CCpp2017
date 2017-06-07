 #include "stdafx.h"
 #include "Plane.h"
 #include "game.h"
 #include "burst.h"
 #include "StrUpdate.h"

sf::RenderWindow mainWindow;
Enemy enemy[enenumber];

void Game::play()
{
	mainWindow.create(sf::VideoMode(width, height, 32), "PlaneGame!");
	Plane plane(width, height);
	Bullet bullet[bulnumber];
	Burst burst[enenumber];
	
	ObjectManager manager;
	while (1)
	{
		mainWindow.clear();
		manager.BackgroundUpdate();
		manager.PlaneUpdate(plane);
		manager.BulletUpdate(bullet);
		manager.EnemyUpdate(enemy);
		manager.BurstUpdate(burst,bullet);
		StrUpdate::update();
		mainWindow.display();
	}
}



int Game::head = 0;
int Game::tail = 0;
int Game::flag = 1;
bool Game::empty = true;

int Game::ehead = 0;
int Game::etail = 0;
bool Game::eempty = true;

int Game::ebhead = 0;
int Game::ebtail = 0;
bool Game::ebempty = true;