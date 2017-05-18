#include <cmath>
#include "Player.h"

Player::Player(int kind, string name, string character_setting):Character(kind,name,character_setting){
	shot_direction = sf::Vector2f(0,0);
	bullte = 0;
	bullte_clock.restart();
}
Player::Player(int kind, string name, string character_setting, sf::Vector2f pos) :Character(kind,name,character_setting,pos){
	shot_direction = sf::Vector2f(0,0);
	bullte = 0;
	bullte_clock.restart();
}
Player::Player(int kind, string name, string character_setting, sf::Vector2f pos, int dir) :Character(kind,name,character_setting,pos,dir){
	shot_direction = sf::Vector2f(0,0);
	bullte = 0;
	bullte_clock.restart();
}

void Player::Action(sf::Time dt, sf::Vector2f mouse_position){
	set_shot_direction(mouse_position);
	if(bullte_clock.getElapsedTime().asSeconds() > 0.3 && sf::Mouse::isButtonPressed(sf::Mouse::Left)){
		fire(1);
		//cerr << mouse_position.x << " " << mouse_position.y << endl;
		bullte_clock.restart();
	}else {
		fire(0);
	}
//	fire(0);

	if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
		set_direction(sf::Vector2f(0,1));
		set_toward(0);
		use_skill(0);
	}
	else if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
		set_direction(sf::Vector2f(0,-1));
		set_toward(1);
		use_skill(1);
	}
	else if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
		set_direction(sf::Vector2f(-1,0));
		set_toward(2);
		use_skill(2);
	}
	else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
		set_direction(sf::Vector2f(1,0));
		set_toward(3);
		use_skill(3);
	}else {
		stop();
		if(abs(get_speed().x) < 10 && abs(get_speed().y) < 10){
			use_skill(4);
		}
	}
	next(dt);
}

void Player::fire(int x){
	request_flag = x;
	request = 1;//子弹目前的编号
	request_direction = shot_direction;
}
