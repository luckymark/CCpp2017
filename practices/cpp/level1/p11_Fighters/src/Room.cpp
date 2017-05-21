#include "Room.h"

Room::Room(int kind, string setting, sf::Vector2f pos, Director *world):Item(kind, setting, pos, world){
	animation[cur_animation].set_sound_flag(0);
	animation[cur_animation].set_position(pos);
}

void Room::Action(sf::Time dt, sf::Vector2f pos){
	next(dt);
	animation[cur_animation].set_play_flag(1);
}
