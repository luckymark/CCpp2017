#include <cmath>
#include "Player.h"
#include "Bullet.h"
#include "Director.h"
#include <cstdlib>

Player::Player(int kind, string setting, sf::Vector2f pos, Director *world) 
	:Character(kind,setting,pos, world){
		shot_direction = sf::Vector2f(0,0);
		bullte = 0;
		bullte_clock.restart();
	}
void Player::Action(sf::Time dt, sf::Vector2f mouse_position){
	animation[cur_animation].set_play_flag(1);
	if(bullte_clock.getElapsedTime().asSeconds() > 0.3 && sf::Mouse::isButtonPressed(sf::Mouse::Left)){
		fire(dt,mouse_position - physics.get_position());
		bullte_clock.restart();
	}

	if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
		physics.set_self_move_ratio(0.4);
		add_force_from_skill(0,sf::Vector2f(0,1),dt);
		use_skill(0);
	}
	else if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
		physics.set_self_move_ratio(0.4);
		add_force_from_skill(1,sf::Vector2f(0,-1),dt);
		use_skill(1);
	}
	else if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
		physics.set_self_move_ratio(0.4);
		add_force_from_skill(1,sf::Vector2f(-1,0),dt);
		use_skill(2);
	}
	else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
		physics.set_self_move_ratio(0.4);
		add_force_from_skill(1,sf::Vector2f(1,0),dt);
		use_skill(3);
	}else {
		physics.set_self_move_ratio(1);
		if(abs(physics.get_speed().x) < 10 && abs(physics.get_speed().y) < 10){
			use_skill(4);
		}
	}
	next(dt);
	animation[cur_animation].set_play_flag(1);
}

void Player::fire(sf::Time dt,sf::Vector2f dir){
	Item *tmp = NULL;
	dir = physics.make_one(dir);
	dir *= float(15000);
	tmp = new Bullet(world -> sample_type[type_Bullet], world -> sample[type_Bullet], physics.get_position(), world);
	if(tmp == NULL){
		cerr << "get memery fail" << endl;
		exit(0);
	}
	tmp -> physics.add_motivation(physics.get_speed() * (tmp -> physics.get_mass()));
	tmp -> physics.add_force(dir);
	physics.add_force(dir * float(-1));

	world -> stuff.push_back(tmp);
}
