#include "Game.h"
#define HERO_INIT_X 340
#define HERO_INIT_Y 750
std::default_random_engine Game::random(time(NULL));
Game::Game(World* world)
{
	//ctor
	this->world = world;
	//Score.setColor(sf::Color::Red);
	//GameOver.setColor(sf::Color::White);
	Score.setFont(RTexture::FONT);
	GameOver.setFont(RTexture::FONT);
	GameOver.setScale(1.5, 1.5);
	float x(4.0), y(3.0);
	GameOver.setPosition(this->world->getGlobalBounds().height / x, this->world->getGlobalBounds().height / y);
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
	gameover_mark = 0;
	restart = 0;
	world->hero->setPosition(340,750);
	world->ClearAll(true);
	world->window->clear();
	world->hero->init();
}

void Game::MainLoop()
{
	this->play_music();
	while (world->window->isOpen())
	{
		sf::Event event;
		if (this->world->loading) {
		
			
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return)) {
				this->world->loading = false;
				this->init();
				//this->LOAD_BGM.stop();


			}

			

		}
		if (gameover_mark == 1) {
			

				if (sf::Keyboard::isKeyPressed(sf::Keyboard::R)) {
					init();
					continue;
				}
			
		}
		else if (this->world->loading == false) {
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
				if (this->world->hero->getPosition().x > 0) {
					
					world->hero->move(sf::Vector2f(-1.0, 0.0));
				}
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
				if (this->world->hero->getPosition().x < this->world->getTextureRect().width - 430) {
					
					world->hero->move(sf::Vector2f(1.0, 0.0));
				}
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
				if (this->world->hero->getPosition().y > 0) {
					world->hero->move(sf::Vector2f(0.0, -1.0));
				}
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
				if (this->world->hero->getPosition().y < 800) {
					
					world->hero->move(sf::Vector2f(0.0, 1.0));
				}
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {

				this->world->hero->shoot(this->world->hero->get_bulletmuch());
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)&&this->world->hero->MP==100) {

				this->world->Skill();
				this->world->hero->MP = 0;
			}
		}
		

		while (world->window->pollEvent(event)) {

			if (event.type == sf::Event::Closed) {
				world->window->close();

				return;
			}
		}
		if (gameover_mark == 1&&restart==0)
		{
			
			
			GameOvers(win);
			restart = 1;
			continue;
		}
		else if ((this->world->hero->GetScore()) >= 1000) {
			win = true; 
			GameOvers(win); 
			restart = 1;	
			gameover_mark = 1;	
			world->ClearAll(true); 
			world->window->clear(); 
			continue;
		
		}
		else if (gameover_mark == 0) {
			if (world->killed())
			{
				if ((world->hero->blood) < 0) {

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
			}
			
			world->addEnemy();
			world->EnemyShoot();
			world->BonusFunction();
			world->moveBullet();
			world->cleanBullet();
			world->Refresh();
			if (this->world->loading) {
				sf::Sprite load;
				load.setTexture(RTexture::LOAD);
				this->world->window->draw(load);


			}
			if (!this->world->loading) { ShowInfo(); }
			world->window->display();
		}
	}
}

void Game::GameOvers(bool win)
{
	char str[120];
	if (win) {
		sprintf_s(str, "Congratulations!\nYou Win!\nYour Score: %d \nPress R To Retart!", this->world->hero->GetScore());

	}
	else {
		sprintf_s(str, "Regrettable!\nYou Failed!\nYOUR Score: %d \nPress R To Retart!", this->world->hero->GetScore());
	}

	GameOver.setString(str);
	world->window->draw(GameOver);
	world->window->display();
}

void Game::ShowInfo()
{
	sf::RectangleShape rectangle(sf::Vector2f((this->world->hero->GetBlood()) * 2.0, 40));
	rectangle.setPosition(0, 50);
	rectangle.setFillColor(sf::Color::Red);
	this->world->window->draw(rectangle);

	sf::RectangleShape rectangleS(sf::Vector2f((this->world->hero->get_mp()) * 2.0, 40));
	rectangleS.setPosition(0, 90);
	rectangleS.setFillColor(sf::Color::Green);
	this->world->window->draw(rectangleS);

	this->life_now = world->hero->GetLife();
	char INFO[120];
	sprintf_s(INFO, "Score: %d                                                 Life: %d", this->world->hero->GetScore(), this->life_now);
	Score.setString(INFO);
	Score.setCharacterSize(40);
	Score.setPosition(0, 0);
	this->world->window->draw(Score);
}
