 #include "stdafx.h"
 #include "Plane.h"
 #include "game.h"
sf::RenderWindow mainWindow;
void Game::play()
{
	mainWindow.create(sf::VideoMode(width, height, 32), "PlaneGame!");
	Plane plane(width, height);
	Bullet bullet[bulnumber];
	ObjectManager manager;
	while (1)
	{
		mainWindow.clear();
		manager.PlaneUpdate(plane);
		manager.BulletUpdate(bullet);	
		mainWindow.display();
	}
}



int Game::head = 0;
int Game::tail = 0;
int Game::flag = 1;
bool Game::empty = true;