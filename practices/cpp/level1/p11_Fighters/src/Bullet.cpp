#include "Bullet.h"
#include "Director.h"
#include "PureAnimationItem.h"
#include <cmath>

Bullet::Bullet(int kind, string setting,sf::Vector2f pos,Director *world):Item(kind, setting, pos,world){
	sound_flag = 0;
}

void Bullet::be_impacted_from(Item *other){
	animation[cur_animation].set_position(physics.get_position());
	animation[cur_animation].be_affected(other -> get_cur_animation());
	if(other -> get_kind() == type_Room){//Room
		if(!animation[cur_animation].is_affect()){
			//dead();
			int tp = animation[cur_animation].stand_at(other -> get_cur_animation());
			int tagx = tp%3, tagy = tp/3;
			if(tagy != 1){
				sf::Vector2f tmp_mo = physics.get_motivation();
				if(tagy == 0){
					if(tmp_mo.y < 0) tmp_mo.y *= float(-1);
				}else if(tagy == 2){
					if(tmp_mo.y > 0) tmp_mo.y *= float(-1);
				}
				physics.set_motivation(tmp_mo);
			}
			if(tagx != 1){
				sf::Vector2f tmp_mo = physics.get_motivation();
				if(tagx == 0){
					if(tmp_mo.x < 0) tmp_mo.x *= float(-1);
				}else if(tagx == 2){
					if(tmp_mo.x > 0) tmp_mo.x *= float(-1);
				}
				physics.set_motivation(tmp_mo);
			}
		}
	}else if(other -> get_kind() == type_Bullet){
		if(animation[cur_animation].is_affect() && (item_kind == type_Enemy_bullet || item_kind == type_Bullet)){
			//dead();
			//other -> dead();
			collision(physics, other -> physics);
		}
	}else if(other -> get_kind() == type_Enemy_bullet){
		if(animation[cur_animation].is_affect() && (item_kind == type_Bullet || item_kind == type_Enemy_bullet)){
			//dead();
			//other -> dead();
			collision(physics, other -> physics);
		}
	}
	/*else if(other -> get_kind() == type_Enemy){ // enemy
	  if(animation[cur_animation].is_affect()){
	  dead();
	  }
	  }*/
}

void Bullet::Action(sf::Time dt, sf::Vector2f pos){
	animation[cur_animation].set_position(physics.get_position());
	physics.set_self_move_ratio(1);
	next(dt);
	if(abs(physics.get_speed().x) < 100 && abs(physics.get_speed().y) < 100){
		dead();
	}
	if(cur_animation == 0){
		if(sound_flag){
			animation[cur_animation].set_sound_flag(0);
		}else {
			animation[cur_animation].set_play_flag(1);
		}
		animation[cur_animation].set_play_flag(1);
		sound_flag = 1;
	}
}

void Bullet::dead(){
	Item *tmp = NULL;
	if(item_kind == type_Bullet){
		tmp = new PureAnimationItem( world -> sample_type[type_Bullet_hit], world -> sample[type_Bullet_hit], physics.get_position(), world, 1);
	}else if(item_kind == type_Enemy_bullet){
		tmp = new PureAnimationItem( world -> sample_type[type_Enemy_bullet_hit], world -> sample[type_Enemy_bullet_hit], physics.get_position(), world, 1);
	}
	if(tmp == NULL){
		//cerr << "fail to get mem" << endl;
		//exit(0);
	}
	world -> stuff.push_back(tmp);
	world -> delete_stuff(this);
}
