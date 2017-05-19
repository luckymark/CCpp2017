#include "Enemy.h"

Enemy::Enemy(int kind, string item_setting, string enemy_setting)
	:Character(kind, item_setting, enemy_setting){}
Enemy::Enemy(int kind ,string item_setting, string enemy_setting, sf::Vector2f pos)
	:Character(kind, item_setting, enemy_setting,pos){}
Enemy::Enemy(int kind, string item_setting, string enemy_setting, sf::Vector2f pos, int dir)
	:Character(kind , item_setting ,enemy_setting,pos,dir){}

void Enemy::Action(sf::Time dt, sf::Vector2f mouse_position){
	use_skill(0);
	set_direction(mouse_position - position);
	next(dt);
}
