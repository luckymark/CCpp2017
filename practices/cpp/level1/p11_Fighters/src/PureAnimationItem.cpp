#include "PureAnimationItem.h"
#include "Director.h"

PureAnimationItem::PureAnimationItem(int kind, string setting, sf::Vector2f pos, Director *world, int times)
	:Item(kind,setting,pos,world){
		cnt = times;
	}

void PureAnimationItem::Action(sf::Time dt, sf::Vector2f pos){
	if(cnt == -1) {
		dead();
		return;
	}
	if(!animation[0].is_playing()){
		animation[0].set_play_flag(1);
		animation[0].set_sound_flag(1);
		animation[0].set_position(physics.get_position());
		cnt--;
		if(cnt == -1){
			dead();
			return;
		}
	} else if(animation[0].is_playing()){
		next(dt);
		animation[0].set_sound_flag(0);
	}
}
