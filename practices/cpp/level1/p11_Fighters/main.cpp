#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include<string.h>
#include"bullet.h"
#include"plane.h"
#include"Enemy.h"
#include"BoomArray.h"
#include "Text.h"
#include"background.h"
#include"start_text.h"

void main()
{
	static int count = 0;
	int enemy_number = 20, enemy_bullet_number = 20, my_bullet_num = 30;
	int death_flag = 0, death_positionx, death_positiony, death_time = 0;
	int marks = 0,life_left = 3, revive_flag = 0, revive_time = 0,produce_cause=200;
	int time_left = 300;
	bool over_flag = 0;

	std::string Str;

	sf::SoundBuffer buffer1,buffer2,buffer3;
	buffer1.loadFromFile("collision2.flac");
	buffer2.loadFromFile("collision3.flac");
	buffer3.loadFromFile("background_music.flac");
	sf::Sound bingo1,bingo2;
	sf::Sound music;
	bingo1.setBuffer(buffer1);
	bingo2.setBuffer(buffer2);
	music.setBuffer(buffer3);
	music.play();
	music.setLoop(true);
	sf::Keyboard::Key;
	sf::RenderWindow window(sf::VideoMode(1200, 1080), "Fighting!");
	sf::FloatRect EnemyBoundryBox;


	Plane hero(3, 900, 800, 1, 1);
	Bullets bullet(50);
	bullet.setspeed(4);
	Enemy enemy1(2, enemy_number, enemy_bullet_number, 1);
	Enemy enemyboss2(6, enemy_number, enemy_bullet_number, 1);
	Enemy enemyboss1(5, 2, enemy_bullet_number, 1);
	BoomArray boom(enemy_number);
	Picture start_background;
	Background gamemap(1);
	StartText start_text;
	Text score;
	Text life;
	Text times;
	Text start;
	Text over1,over2;

	srand((unsigned)time(NULL));
	enemy1.setspeed(1, -3);
	enemyboss1.setspeed(1, -3);
	start_background.produce(5, 0, 0);
	window.setFramerateLimit(200);


	while (window.isOpen())
	{
		sf::Event event;
		window.clear(sf::Color::Black);
		
		static int k = 0;
		while (0 == k || k == 2||k==3) {
			window.draw(start_background.get());
			while (window.pollEvent(event));
			if (k == 0) {
				window.draw(start_text.draw(0));
				window.draw(start_text.draw(1));
				window.draw(start_text.draw(2));
				window.display();
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
					k = 1;
				}
			}
			if (k == 2) {
				using namespace std;
				string Str;
				Str = to_string(marks);
				over1.setmark(7, Str);
				window.draw(over1.draw());
				death_flag = 0, death_time = 0;
				life_left = 3, revive_flag = 0, revive_time = 0, produce_cause = 200;
				time_left = 300, over_flag = 0;
				window.display();
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::R)) {
					marks = 0;
					goto restart;
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
					window.close();
				}
			}
			if (k == 3) {
				over1.setmark(7, Str);
				window.draw(over1.draw());
				window.display();
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::R)) {
					k = 2;
					marks = 0;
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
					window.close();
				}
			}
		}
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		while (over_flag==0) {
		restart:
			if (count %  produce_cause == 0) {
				enemy1.produce();
				produce_cause -= 5;
				if (produce_cause == 50)produce_cause = 200;
				count = 0;
			}
			if (time_left / 100 < 15) {
 				enemyboss1.produce();
			}
			int x = hero.getx(), y = hero.gety();
			if (death_flag == 0) {
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
					if (x > 0)x -= 5;
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
					if (x < 1100)x += 5;
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
					if (y > 0)y -= 5;
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
					if (y < 900)y += 5;
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
					if (count % 15 == 0) {
						bullet.append(x + 40, y + 10);
					}
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
					window.close();
				}
			}

			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					window.close();
			}
			window.clear();

			window.draw(gamemap.draw());
			if(count%2)gamemap.move();
			hero.move(x, y);
			enemyboss1.move(count, hero.getx());
			if (count % 1 == 0) {
				enemy1.move(count);
				bullet.move();
			}

			for (int i = 0; i < enemy_bullet_number; i++) {
				if (bullet.exist(i)) {
					EnemyBoundryBox = bullet.draw(i).getGlobalBounds();
					if (enemy1.bingo(EnemyBoundryBox,1)) {
						boom.produce(4, bullet.getx(i) - 20, bullet.gety(i) - 50);
						bingo1.play();
						bullet.destroy(i);
						marks += 1;
						time_left += 200;
					}
					if (enemyboss1.bingo(EnemyBoundryBox,10)) {
						bullet.destroy(i);
						bingo1.play();
						marks += 1;
						time_left += 200;
					}
				}

				if (revive_flag == 0) {
					if (enemy1.exist_bullet(i)) {
						EnemyBoundryBox = enemy1.draw_bullet(i).getGlobalBounds();
						if (hero.get().getGlobalBounds().intersects(EnemyBoundryBox)) {
							death_positionx = hero.getx();
							death_positiony = hero.gety();
							boom.produce(1, death_positionx + 20, death_positiony + 40);
							hero.move(0, 0);
							death_flag += 1;
						}
					}
					if (i<10&&enemy1.exist(i)) {
						EnemyBoundryBox = enemy1.draw_enemy(i).getGlobalBounds();
						if (hero.get().getGlobalBounds().intersects(EnemyBoundryBox)) {
							death_positionx = hero.getx();
							death_positiony = hero.gety();
							boom.produce(1, death_positionx + 20, death_positiony + 40);
							hero.move(0, 0);
							death_flag += 1;
						}
					}
					if (enemyboss1.exist_bullet(i)) {
						if (enemyboss1.exist_bullet(i)) {
							EnemyBoundryBox = enemyboss1.draw_bullet(i).getGlobalBounds();
							if (hero.get().getGlobalBounds().intersects(EnemyBoundryBox)) {
								death_positionx = hero.getx();
								death_positiony = hero.gety();
								bingo2.play();
								boom.produce(1, death_positionx + 20, death_positiony + 40);
								death_flag += 1;
							}
						}
					}
				}
				if (i<my_bullet_num&&bullet.exist(i)) {
					window.draw(bullet.draw(i));
				}
				if (enemy1.exist_bullet(i)) {
					window.draw(enemy1.draw_bullet(i));
				}
				if (enemyboss1.exist_bullet(i)) {
					window.draw(enemyboss1.draw_bullet(i));
				}
			}
			for (int i = 0; i < enemy_number; i++) {
				if (enemy1.exist(i)) {
					window.draw(enemy1.draw_enemy(i));
				}
				if (boom.exist(i)) {
					window.draw(boom.get(i));
					boom.initialize(i, count);
				}
				if (i < 2 && enemyboss1.exist(i)) {
					window.draw(enemyboss1.draw_enemy(i));
				}
			}

			if (death_flag == 0) {
				window.draw(hero.get());
			}
			else {
				death_time += 1;
				boom.produce(4, death_positionx, death_positiony + 40);
				if (death_time == 20) {
					death_flag = 0;
					death_time = 0;
					hero.move(death_positionx, death_positiony);
					revive_flag = 1;
					life_left -= 1;
				}
			}

			if (revive_flag == 1) {
				revive_time += 1;
				if (revive_time >= 500) {
					revive_flag = 0;
					revive_time = 0;
				}
			}
			 
			using namespace std;
			Str = to_string(marks);
			score.setmark(1, Str);
			Str = to_string(life_left);
			life.setmark(2, Str);
			Str = to_string(time_left/100);
			times.setmark(3, Str);

			window.draw(times.draw());
			window.draw(score.draw());
			window.draw(life.draw());
			window.display();
			count++,k=2;
			time_left--;
			if ( life_left == 0 ) {
				over_flag = 1;
			}
			if (marks >= 200) goto quit;
		}

	quit:k = 3;
	}
}