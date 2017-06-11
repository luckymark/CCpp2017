#include "Enemy.h"
#include "Bullet.h"
#include "Director.h"
#include "PureAnimationItem.h"

Enemy::Enemy(int kind ,string item_setting, sf::Vector2f pos, Director *world)
	:Character(kind, item_setting, pos, world){
		relife_clock.restart();
		sub_enemy_clock.restart();
		sub_enemy_clock1.restart();
	}

void Enemy::Action(sf::Time dt, sf::Vector2f player_position){
	if(bullte_clock.getElapsedTime().asSeconds() > 1){
		fire(dt,player_position - physics.get_position());
		bullte_clock.restart();
	}
	if(life.w[0] <= 0){
		dead();
		return;
	}
	if(life.w[0] < life.w[2] && life_clock.getElapsedTime().asSeconds() > 0.1){
		life.w[0] += life.w[1];
		life_clock.restart();
	}

	physics.set_self_move_ratio(1);
	add_force_from_skill(0,player_position - physics.get_position(),dt,1);
	use_skill(0);
	animation[cur_animation].set_sound_flag(0);
	next(dt);
	animation[cur_animation].set_play_flag(1);
}

void Enemy::fire(sf::Time dt, sf::Vector2f dir){
	if(item_kind == type_Enemy_3 || item_kind == type_Enemy_4) return;
	if(item_kind == type_Enemy_1){
		if(relife_clock.getElapsedTime().asSeconds() > 30){
			Item *tmp = NULL;
			tmp = new Enemy(world -> sample_type[type_Enemy_1], world -> sample[type_Enemy_1], physics.get_position(), world);
			world -> stuff.push_back(tmp);
			relife_clock.restart();
			return;
		}
		if(sub_enemy_clock.getElapsedTime().asSeconds() > 19){
			Item *tmp = NULL;
			tmp = new Enemy(world -> sample_type[type_Enemy], world -> sample[type_Enemy], physics.get_position(), world);
			world -> stuff.push_back(tmp);
			sub_enemy_clock.restart();
			return;
		}
		if(sub_enemy_clock1.getElapsedTime().asSeconds() > 7){
			Item *tmp = NULL;
			tmp = new Enemy(world -> sample_type[type_Enemy_2], world -> sample[type_Enemy_2], physics.get_position(), world);
			world -> stuff.push_back(tmp);
			sub_enemy_clock1.restart();
			return;
		}
	}
	Item *tmp = NULL;
	//life.w[0] -= 10;
	dir = physics.make_one(dir);
	dir *= float(10000);
	tmp = new Bullet(world -> sample_type[type_Enemy_bullet], world -> sample[type_Enemy_bullet], physics.get_position(), world);
	if(tmp == NULL){
		cerr << "get memery fail" << endl;
		exit(0);
	}
	tmp -> physics.add_motivation(physics.get_speed() * (tmp -> physics.get_mass()));
	tmp -> physics.add_force(dir);
	physics.add_force(dir * float(-1));

	world -> stuff.push_back(tmp);
}

void Enemy::dead(){
	if(item_kind == type_Enemy_2){
		Item *tmp = NULL;
		tmp = new Enemy(world -> sample_type[type_Enemy_3], world -> sample[type_Enemy_3], physics.get_position(), world);
		world -> stuff.push_back(tmp);

		tmp = new Enemy(world -> sample_type[type_Enemy_4], world -> sample[type_Enemy_4], physics.get_position(), world);
		world -> stuff.push_back(tmp);
		//return;
	}
	Item *tmp = NULL;
	tmp = new PureAnimationItem( world -> sample_type[type_Enemy_dead], world -> sample[type_Enemy_dead], physics.get_position(), world, 1);
	if(tmp == NULL){
		cerr << "fail to get mem in Enemy.cpp" << endl;
		exit(0);
	}
	world -> stuff.push_back(tmp);
	world -> delete_stuff(this);
}
