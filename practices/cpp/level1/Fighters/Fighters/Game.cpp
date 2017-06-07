#include "Game.h"
#define HERO_INIT_X 340
#define HERO_INIT_Y 750
std::default_random_engine Game::random(time(0));
Game::Game(World* world)
{
	//ctor
	this->world = world;
	//Score.setColor(sf::Color::Red);
	//GameOver.setColor(sf::Color::White);
	Score.setFont(RTexture::FONT);
	GameOver.setFont(RTexture::FONT);
	GameOver.setScale(2, 2);
	GameOver.setPosition(this->world->getGlobalBounds().height / 4, this->world->getGlobalBounds().height / 3.0);
}

Game::~Game()
{
	//dtor
}

void Game::play_music()
{
	BGM.play();
	BGM.setLoop(true);
}

void Game::pause_music()
{
	BGM.stop();
}

void Game::init()
{
	world->hero->setPosition(400, 400);
	world->window->clear();
	world->hero->init();
}

void Game::MainLoop()
{
	this->play_music();
	while (world->window->isOpen())
	{
		sf::Event event;
		if (this->world->loading == true) {

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
				if (this->world->hero->getPosition().x>0) {
					world->hero->move(sf::Vector2f(-1.0, 0.0));
				}
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
				if (this->world->hero->getPosition().x<this->world->getTextureRect().width - 430) {
					world->hero->move(sf::Vector2f(1.0, 0.0));
				}
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
				if (this->world->hero->getPosition().y>0) {
					world->hero->move(sf::Vector2f(0.0, -1.0));
				}
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
				if (this->world->hero->getPosition().y<800) {
					world->hero->move(sf::Vector2f(0.0, 1.0));
				}
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
				this->world->hero->shoot();
			}
		}

		while (world->window->pollEvent(event)) {

			if (event.type == sf::Event::Closed) {
				world->window->close();

				return;
			}
		}
		if (gameover_mark == 1)
		{
			GameOvers(win);
			continue;
		}
		else if (gameover_mark == 0) {
			if (world->killed())
			{


				if (world->hero->dead())
				{
					gameover_mark = 1;
					world->hero->setPosition(HERO_INIT_X, HERO_INIT_Y);
					world->ClearAll(true);
					world->window->clear();
					continue;
				}
				this->world->hero->unbeatable = 301;
				world->hero->setPosition(HERO_INIT_X, HERO_INIT_Y);
				world->ClearAll(false);
			}

			world->addEnemy();
			world->EnemyShoot();
			world->moveBullet();
			world->cleanBullet();
			world->Refresh();
			ShowInfo();
			world->window->display();
		}
	}
}

void Game::GameOvers(bool win)
{
	char str[120];
	if (win) {
		sprintf_s(str, "Congratulations!!!\nYou Win!!!\nYour Score: %d ", this->world->hero->GetScore());

	}
	else {
		sprintf_s(str, "Regrettable!!!\nYou Failed!!!\nYOUR Score: %d ", this->world->hero->GetScore());
	}

	GameOver.setString(str);
	world->window->draw(GameOver);
	world->window->display();
}

void Game::ShowInfo()
{
	this->life_now = world->hero->GetLife();
	char INFO[120];
	sprintf_s(INFO, "Score: %d                                                 Life: %d", this->world->hero->GetScore(), this->life_now);
	Score.setString(INFO);
	Score.setCharacterSize(40);
	Score.setPosition(0, 0);
	this->world->window->draw(Score);
}
