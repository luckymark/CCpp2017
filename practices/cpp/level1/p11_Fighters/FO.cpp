#include "FO.h"
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>

FO::FO()
{
	phase = 1;
	bounds = 0;
	staticFrame = 0;
	dynamicFrame = 0;
	width = 0;
	height = 0;
	score = 0;
	damage = 1.0;
	isSym = false;
	HealthPoint = 1;
}

FO::FO(int flag)
{
	phase = 1;
	bounds = 0;
	staticFrame = 0;
	dynamicFrame = 0;
	width = 0;
	height = 0;
	score = 0;
	damage = 1.0;
	isSym = false;
	HealthPoint = 1;

	switch (flag)
	{
	case 0://title
		type = 0;
		width = 512;
		height = 256;
		speed = 0.0;
		theta = 0.0;
		velocity = sf::Vector2f(0.0, 0.0);
	case 1://player
		type = 1;
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
		HealthPoint = 1;
		damage = 1.0;
		width = 48;
		height = 72;
		speed = 10.0;
		hero.setTexture(Reimu);
		hero.setTextureRect(sf::IntRect(0, 0, width, height));
		hero.setPosition(sf::Vector2f(430, 820));
		HSAmmo.setTexture(Reimu);
		HSAmmo.setTextureRect(sf::IntRect(0, 3 * height + 0, 25, 24));
		HSAmmo.setRotation(270);
		LSAmmo.setTexture(Reimu);
		LSAmmo.setTextureRect(sf::IntRect(4 * width, 3 * height + 48, 2 * width, 24));
		LSAmmo.setRotation(270);
		break;
	case 2://sButterfly
		type = 2;
		// Load an enemy to display
		/*if (!Enemy1.loadFromFile("E:\\Media\\Sources\\Jpg&Png\\TH\\Ex.15\\enemy\\enemy.png"))
		{
			puts("Error: Load enemy1 failed!");
		}
		if (!Enemy2.loadFromFile("E:\\Media\\Sources\\Jpg&Png\\TH\\Ex.15\\enemy\\enemy.png"))
		{
			puts("Error: Load enemy2 failed!");
		}*/
		HealthPoint = 5;
		width = 32;
		height = 32;
		speed = 2;
		score = 50;
		//hero.setTexture(Enemy1);
		//hero.setTextureRect(sf::IntRect(0, 64, width, height));
		//hero.setScale(sf::Vector2f(1.5, 1.5));
		//printf("%x\n", hero);
		break;
	case 3://sFairy
		type = 3;
		width = 48;
		height = 32;
		score = 200;
		break;
	case 4://mFairy
		type = 4;
		width = 48;
		height = 48;
		score = 1000;
		break;
	case 5://mButterfly
		HealthPoint = 100;
		type = 5;
		width = 64;
		height = 64;
		score = 1000;
		break;
	case 6://Ghost
		HealthPoint = 1340;
		type = 6;
		width = 32;
		height = 32;
		score = 10000;
		phase = 2;
		break;
	}
}

/*void FO::setSButterfly(double x, double y)
{
	if (!Enemy1.loadFromFile("E:\\Media\\Sources\\Jpg&Png\\TH\\Ex.15\\enemy\\enemy.png"))
	{
		puts("Error: Load enemy1 failed!");
	}
	if (!Enemy2.loadFromFile("E:\\Media\\Sources\\Jpg&Png\\TH\\Ex.15\\enemy\\enemy.png"))
	{
		puts("Error: Load enemy2 failed!");
	}
	hero.setTexture(Enemy1);
	hero.setTextureRect(sf::IntRect(0, 320, width, height));
	hero.setScale(sf::Vector2f(1.5, 1.5));
	hero.setPosition(sf::Vector2f(x, y));
}*/
	

sf::Vector2f FO::getJulgeArea()
{
	float x, y;
	if (type == 1)
	{
		x = hero.getPosition().x - 24;
		y = hero.getPosition().y - 8;
	}
	else
	{
		x = hero.getPosition().x;
		y = hero.getPosition().y;
	}
	return sf::Vector2f(x, y);
}

FO::~FO()
{
}

/*Player::Player()
{
	staticFrame = 0;
	dynamicFrame = 0;
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
	width = 48;
	height = 72;
	speed = 10.0;
	hero.setTexture(Reimu);
	hero.setTextureRect(sf::IntRect(0, 0, width, height));
	hero.setPosition(sf::Vector2f(400, 820));
	HSAmmo.setTexture(Reimu);
	HSAmmo.setTextureRect(sf::IntRect(0, 3 * height + 0, 2.0 / 3.0 * width, 24));
	HSAmmo.setRotation(270);
	LSAmmo.setTexture(Reimu);
	LSAmmo.setTextureRect(sf::IntRect(4 * width, 3 * height + 48, 2 * width, 24));
	LSAmmo.setRotation(270);
}*/
