#include "Begin.h"
#include "Director.h"

Begin::Begin(int kind, string item_setting_name, sf::Vector2f pos, Director *world_)
	:CG(kind, item_setting_name, pos, world_){}

void Begin::dead(){
	world -> new_stuff(9,sf::Vector2f(0,200));
	world -> delete_stuff(this);
}
void Begin::Action(sf::Time dt){
	if(animation[cur_animation].is_playing() == 0 || sf::Mouse::isButtonPressed(sf::Mouse::Left)){
		dead();
		return;
	}
	next(dt);
}
