#include "Room.h"

Room::Room(int kind, string item_setting_name, sf::Vector2f pos):Item(kind, item_setting_name, pos){
	animation[cur_animation].set_sound_flag(0);
}

Room::Room(int kind, string item_setting_name, string  room_name, sf::Vector2f pos):Item(kind, item_setting_name, pos){
	animation[cur_animation].set_sound_flag(0);
}
