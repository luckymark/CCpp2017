#include "Enemy.h"

Enemy::Enemy(int kind ,string item_setting, sf::Vector2f pos, Director *world)
	:Character(kind, item_setting, pos, world){}

void Enemy::Action(sf::Time dt, sf::Vector2f mouse_position){
	use_skill(0);
	next(dt);
}
