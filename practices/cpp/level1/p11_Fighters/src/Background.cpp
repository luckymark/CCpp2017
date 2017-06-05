#include "Background.h"

Background::Background(int kind, string item_setting_name, sf::Vector2f pos,Director *world_)
	:Item(kind, item_setting_name, pos, world_){ }

void Background::Action(sf::Time dt, sf::Vector2f pos){
	next(dt);
	animation[cur_animation].set_play_flag(1);
}
