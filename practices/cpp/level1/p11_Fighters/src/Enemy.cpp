#include "Enemy.h"
#include "Bullet.h"
#include "Director.h"
#include "PureAnimationItem.h"

Enemy::Enemy(int kind ,string item_setting, sf::Vector2f pos, Director *world)
	:Character(kind, item_setting, pos, world){}

void Enemy::Action(sf::Time dt, sf::Vector2f player_position){
	if(bullte_clock.getElapsedTime().asSeconds() > 1){
		fire(dt,player_position - physics.get_position());
		bullte_clock.restart();
	}
	if(life.w[0] <= 0){
		dead();
		return;
	}
	physics.set_self_move_ratio(1);
	add_force_from_skill(0,player_position - physics.get_position(),dt,1);
	use_skill(0);
	animation[cur_animation].set_sound_flag(0);
	next(dt);
	animation[cur_animation].set_play_flag(1);
}

void Enemy::fire(sf::Time dt, sf::Vector2f dir){
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
	Item *tmp = NULL;
	tmp = new PureAnimationItem( world -> sample_type[type_Enemy_dead], world -> sample[type_Enemy_dead], physics.get_position(), world, 1);
	if(tmp == NULL){
		cerr << "fail to get mem in Enemy.cpp" << endl;
		exit(0);
	}
	world -> stuff.push_back(tmp);
	world -> delete_stuff(this);
}
