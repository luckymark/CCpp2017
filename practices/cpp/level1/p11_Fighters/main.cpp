#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <fstream>
#include"bullet.h"
#include"plane.h"
#include"Enemy.h"
/*to do list:
1.完成配置；
2.静态飞机的产生及边界控制；
3.子弹的产生极其后续处理；
4.敌机的产生
*/

void main()
{
	static int count = 0;

	sf::Music music;
	music.openFromFile("1.wav");
	music.play();
	music.setLoop(true);
	sf::Keyboard::Key;
	sf::RenderWindow window(sf::VideoMode(1800, 1080), "Fighting!");

	Plane plane(3, 900, 800, 0.5, 0.5);
	Bullets bullet;
	Enemy enemy1(4, 20, 1);
	srand((unsigned)time(NULL));

	while (window.isOpen())
	{
		sf::Event event;

		window.clear(sf::Color::Black);
		window.draw(plane.get());
		window.display();

		while (1) {
			if (count % 50 == 0) {
				enemy1.produce();
				count == 0;
			}
			int x = plane.getx(), y = plane.gety();
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
				if (x > 0)x -= 1;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
				if (x < 1700)x += 1;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
				if (y > 0)y -= 1;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
				if (y < 900)y += 1;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
				break;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
				if (count % 100 == 0) {
					bullet.append(x, y);
				}
			}

 			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					window.close();
			}
			window.clear();

 			plane.move(x, y);
			enemy1.move();
			bullet.move();
			for (int i = 0;i < 100;i++) {
				if (bullet.exist(i)) {
					window.draw(bullet.draw(i));
				}
			}
			for (int i = 0;i < 20;i++) {
				if (enemy1.exist(i)) {
					window.draw(enemy1.draw(i));
				}
			}
			window.draw(plane.get());
			window.display();
			count++;
		}
	}
}


