#include "Item.h"
#include <cmath>

Player::Player(int kind, string name, string character_setting):Character(kind,name,character_setting){}
Player::Player(int kind, string name, string character_setting, sf::Vector2f pos) :Character(kind,name,character_setting,pos){}
Player::Player(int kind, string name, string character_setting, sf::Vector2f pos, int dir) :Character(kind,name,character_setting,pos,dir){}

void Player::Action(sf::Time dt){
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
		set_toward(0);
		use_skill(0);
	}
	else if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
		set_toward(1);
		use_skill(1);
	}
	else if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
		set_toward(2);
		use_skill(2);
	}
	else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
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

