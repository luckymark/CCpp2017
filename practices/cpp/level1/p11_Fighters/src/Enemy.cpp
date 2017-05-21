#include "Enemy.h"

Enemy::Enemy(int kind ,string item_setting, sf::Vector2f pos, Director *world)
	:Character(kind, item_setting, pos, world){}

void Enemy::Action(sf::Time dt, sf::Vector2f mouse_position){
	physics.set_self_move_ratio(1);
	add_force_from_skill(0,mouse_position - physics.get_position(),dt);
	use_skill(0);
	next(dt);
	animation[cur_animation].set_play_flag(1);
}
