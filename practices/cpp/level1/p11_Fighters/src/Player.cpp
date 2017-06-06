#include <cmath>
#include "Player.h"
#include "Bullet.h"
#include "Director.h"
#include <cstdlib>

void Player::set_skill(){
	skill[5].during_flag = 1;
	skill[5].cooling_time = 4;
}

Player::Player(int kind, string setting, sf::Vector2f pos, Director *world) 
	:Character(kind,setting,pos, world){
		shot_direction = sf::Vector2f(0,0);
		bullte = 0;
		bullte_clock.restart();
		life_bar.set_from_setting("../data/LifeBar/setting", sf::Vector2f(50,50));
		set_skill();
	}
void Player::Action(sf::Time dt, sf::Vector2f mouse_position){
	if(bullte_clock.getElapsedTime().asSeconds() > 0.3 && sf::Mouse::isButtonPressed(sf::Mouse::Left)){
		fire(dt,mouse_position - physics.get_position());
		bullte_clock.restart();
	}

	if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
		physics.set_self_move_ratio(0.4);
		add_force_from_skill(0,sf::Vector2f(0,1),dt);
		use_skill(0);
	} else if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
		physics.set_self_move_ratio(0.4);
		add_force_from_skill(1,sf::Vector2f(0,-1),dt);
		use_skill(1);
	} else if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
		physics.set_self_move_ratio(0.4);
		add_force_from_skill(1,sf::Vector2f(-1,0),dt);
		use_skill(2);
	} else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
		physics.set_self_move_ratio(0.4);
		add_force_from_skill(1,sf::Vector2f(1,0),dt);
		use_skill(3);
	} else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Q)){
		if(skill[5].is_ready()){
			sf::Vector2f dir = physics.make_one(mouse_position - physics.get_position());
			physics.set_self_move_ratio(0.4);
			physics.add_motivation(dir * float(6000));
			if(dir.x >= 0){
				animation[5].initlize();
				use_skill(5);
			}else {
				animation[6].initlize();
				use_skill(6);
			}
			skill[5].use();
		}
	}else if(sf::Keyboard::isKeyPressed(sf::Keyboard::E)){
		physics.set_self_move_ratio(1.0);
		use_skill(7);
	}
	else {
		physics.set_self_move_ratio(1);
		if(abs(physics.get_speed().x) < 10 && abs(physics.get_speed().y) < 10){
			use_skill(4);
		}
	}

	next(dt);
	if(cur_animation <= 4){
		animation[cur_animation].set_play_flag(1);
	}else if(cur_animation == 7){
		animation[cur_animation].set_play_flag(1);
	}else {
		if(cur_animation == 5 || cur_animation == 6){
			if(!animation[cur_animation].is_playing()){
				use_skill(4);
				animation[cur_animation].set_position(physics.get_position());
			}
		}
	}
	if(life.w[0] < life.w[2] && life_clock.getElapsedTime().asSeconds() > 0.1){
		life.w[0] += 1;
		life_clock.restart();
	}
	life_bar.set_life(life.w[0],life.w[2]);
}

void Player::fire(sf::Time dt,sf::Vector2f dir){
	Item *tmp = NULL;
	life.w[0] -= 10;
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

void Player::display(){
	animation[cur_animation].begin_cur_display(&(world -> window));
	life_bar.display(&(world -> window));
}

void Player::set_life_bar(string setting, sf::Vector2f pos){
	life_bar.set_from_setting(setting, pos);
}

/*void Player::be_impacted_from(Item *other){
  animation[cur_animation].set_position(physics.get_position());
  animation[cur_animation].be_affected(other -> get_cur_animation());
  if(other -> get_kind() == type_Enemy){
  if(animation[cur_animation].is_affect()){
  }
  }
  }*/
