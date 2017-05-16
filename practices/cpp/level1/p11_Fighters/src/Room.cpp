#include "Room.h"

Room::Room(int kind, string item_setting_name, sf::Vector2f pos):Item(kind, item_setting_name, pos){}

Room::Room(int kind, string item_setting_name, string  room_name, sf::Vector2f pos):Item(kind, item_setting_name, pos){}
