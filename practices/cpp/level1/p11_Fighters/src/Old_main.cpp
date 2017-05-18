/*#include "Item.h"
#include "Animation.h"
int main(){
	sf::RenderWindow window(sf::VideoMode(800, 800), "My window");
	window.setVerticalSyncEnabled(true);

	Animation my("../data/character/walk/1/setting", "../data/character/walk/0/bird_flap.flac");
	my.set_core_position(sf::Vector2f(400.0,400.0));
	my.set_max_speed(10000.0);

	sf::Clock clock;
	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear(sf::Color(100,100,100));

		window.draw(*my.begin_cur_display());
		my.end_cur_display();
		my.set_acceleration(sf::Vector2f(-5,-5));
		my.next_frame(clock.getElapsedTime());
		clock.restart();

		window.display();
	}
	return 0;

}*/
/*#include "Item.h"
#include <iostream>
#include <cmath>
using namespace std;
int main(){
	sf::RenderWindow window(sf::VideoMode(800, 800), "My window");
	window.setVerticalSyncEnabled(true);
	window.setKeyRepeatEnabled(1);

	Character my(0,"../data/character/item_setting","../data/character/character_setting");
	my.set_position(sf::Vector2f(400.0,400.0));
	my.set_toward(0);

	sf::Clock clock;
	int key_flag;
	//sf::Clock key_clock;
	while (window.isOpen()) {
		sf::Event event;
		key_flag = 0;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();

			//if (event.type == sf::Event::KeyPressed) {
				//key_clock.restart();
				//cerr << "p" << endl;
			//}
		}

		window.clear(sf::Color(100,100,100));

		//if(key_clock.getElapsedTime().asSeconds() > 0.1){
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
			my.set_toward(0);
			my.use_skill(0);
			key_flag = 1;
		}
		else if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
			my.set_toward(1);
			my.use_skill(1);
			key_flag = 1;
		}
		else if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
			my.set_toward(2);
			my.use_skill(2);
			key_flag = 1;
		}
		else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
			my.set_toward(3);
			my.use_skill(3);
			key_flag = 1;
		}else {
			my.stop();
			if(abs(my.get_speed().x) < 10 && abs(my.get_speed().y) < 10){
				my.use_skill(4);
			///	my.set_stop_ratio(0);
			}
		}

		window.draw(*my.display());
		my.next(clock.getElapsedTime());
		clock.restart();
		window.display();
	}	
	return 0;
}*/
