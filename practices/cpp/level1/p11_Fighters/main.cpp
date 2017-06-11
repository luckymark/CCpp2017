#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Sky.h"
#include "LoadTexture.h"
#include "Plane.h"
#include "Controller.h"
#include "Bullet.h"
#include "Firer.h"
int main(void){
	// the score
	// the clock to control the enemy
	sf::Clock enemyClock;
	enemyClock.restart();
	// the window
	sf::RenderWindow window(sf::VideoMode(480 , 800) , "fighters");
	window.setFramerateLimit(60);
	// background music
	sf::Music backgroundMusic;
	backgroundMusic.openFromFile("resource/sounds/background.ogg");
	backgroundMusic.setLoop(true);
	//backgroundMusic.setVolume(20);
	backgroundMusic.play();
	// background
	sf::Sprite backgroundSprite;
	sf::Texture backgroundTexture;
	backgroundTexture.loadFromFile("resource/background.png");
	backgroundSprite.setTexture(backgroundTexture);
	// sky
	Sky sky;
	sky.add(backgroundSprite);
	// loadtexture
	LoadTexture loadtexture;
	loadtexture.initLoad();
	loadtexture.loadFromFile("resource/shoot.png");
	// firer
	Firer firer(sky , loadtexture);
	// hero
	Plane hero(HERO);
	hero.setTexture(*loadtexture.getTextureByName("hero2"));
	// set hero position
	hero.setOrigin(hero.getTexture()->getSize().x / 2 , hero.getTexture()->getSize().y / 2);
	hero.setPosition(window.getSize().x / 2, window.getSize().y - hero.getTexture()->getSize().y / 2);
	hero.setFirer(firer);
	sky.add(hero);
	// the controller
	Controller controller;
	// the enemy_1 pointer
	Plane *enemy;
	// the enemy_1 vector
	std::vector<sf::Texture*> enemy_1TextureVector;
	enemy_1TextureVector.push_back(loadtexture.getTextureByName("enemy1_down1"));
	enemy_1TextureVector.push_back(loadtexture.getTextureByName("enemy1_down2"));
	enemy_1TextureVector.push_back(loadtexture.getTextureByName("enemy1_down3"));
	enemy_1TextureVector.push_back(loadtexture.getTextureByName("enemy1_down4"));
	// the loop
	while (window.isOpen()){
		sf::Event event;
		while (window.pollEvent(event)){
			if (event.type == sf::Event::Closed){
				window.close();
			}
		}
		// random add enemy
		if((enemyClock.getElapsedTime().asSeconds() > sf::seconds(1.0f).asSeconds()))
		{
			enemy = new Plane(ENEMY_1);
			enemy->setTexture(*loadtexture.getTextureByName("enemy1"));
			enemy->setOrigin(enemy->getTexture()->getSize().x / 2, enemy->getTexture()->getSize().y / 2);
			enemy->setFirer(firer);
			enemy->setTimePerTexture(0.05f);
			int a = 480- int(hero.getTexture()->getSize().x / 2), b = int(hero.getTexture()->getSize().x / 2);
			enemy->setPosition((rand()%(b-a+1)+b), 0);
			enemy->setTextureVector(&enemy_1TextureVector);
			sky.add(*enemy);
			enemy->fire();
			enemyClock.restart();
		}
		window.clear();
		window.draw(backgroundSprite);
		controller.control(hero);
		sky.draw(window);
		window.display();
	}
}
