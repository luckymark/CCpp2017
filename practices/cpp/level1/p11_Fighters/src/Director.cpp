#include "Director.h"
#include "Player.h"
#include "Bullet.h"
#include "Room.h"
#include "Enemy.h"
#include "Background.h"
#include "Dialog.h"
#include "CG.h"
#include "Begin.h"
#include <iostream>
#include <cmath>
using namespace std;

Director::Director(){
	map_change_flag = 0;
	stuff.clear();
	sample.clear();
	sample_type.clear();
	clock.restart();
	player_position = sf::Vector2f(-1,-1);
	player_key = -1;
}

void Director::delete_stuff(Item *tmp){
	for(vector<Item*>::iterator it = stuff.begin(); it != stuff.end(); it++){
		if((*it) == tmp){
			delete tmp;
			stuff.erase(it);
			return;
		}
	}
}

void Director::world_loop(){
	for(int i = 0; i < stuff.size(); i++)
		for(int j = i + 1; j < stuff.size(); j++){
			if(i < stuff.size() && j < stuff.size())
				stuff[j] -> be_impacted_from(stuff[i]); ///
			if(i < stuff.size() && j < stuff.size())
				stuff[i] -> be_impacted_from(stuff[j]); ///
		}
	for(int i = 0; i < stuff.size(); i++){
		float x = sf::Mouse::getPosition(window).x;
		float y = sf::Mouse::getPosition(window).y;
		if(stuff[i] -> get_kind() == type_Player){
			stuff[i] -> Action(clock.getElapsedTime(),sf::Vector2f(x,y));
			update_player_position();
		}else {
			stuff[i] -> Action(clock.getElapsedTime(),player_position);
		}
	}
}

void Director::deal_with_window_event(){
	while(window.pollEvent(event)){
		switch(event.type){
			case sf::Event::Closed:
				window.close();
				break;
			default: break;
		}
	}
}


void Director::basic_work(){
	bgm.next();
	window.clear(sf::Color(100,100,100));
	for(int i = 0; i < stuff.size(); i++) if(stuff[i] -> get_kind() == type_Background){
		stuff[i] -> display();
	}
	for(int i = 0; i < stuff.size(); i++) if(stuff[i] -> get_kind() != type_Background){
		stuff[i] -> display();
	}
	window.display();
}

void Director::map_change_process(){
	if(map_change_checker()){
		return;
	}
	for(int i = 0; i < stuff.size(); i++){
		if(stuff[i] -> get_kind() != type_Room){
			stuff[i] -> set_position(stuff[i] -> get_position() + map_change_dir);
		}
	}


}

int Director::map_change_checker(){
	sf::Vector2f tmp = new_map -> get_position();
	if(abs(tmp.x) < 10 && abs(tmp.y) < 10){
		for(int i = 0; i < stuff.size(); i++){
			if(stuff[i] -> get_kind() != type_Room){
				stuff[i] -> set_position(stuff[i] -> get_position() - new_map -> get_position());
			}
		}

		for(vector<Item*>:: iterator it = stuff.begin(); it != stuff.end();){
			sf::Vector2f po = (*it) -> get_position();
			if((po.x < 0 || po.x > 800 || po.y < 0 || po.y > 800) && (*it) != new_map && (*it) -> get_kind() != type_Player){
				delete (*it);
				it = stuff.erase(it);
			}else {
				it++;
			}
		}	

		map_change_flag = 0;
		map_change_dir = sf::Vector2f(0,0);
		new_map = NULL;

		return 1;
	}
	return 0;
}

void Director::main_loop(){
	window.create(sf::VideoMode(800,800), "My window");
	window.setVerticalSyncEnabled(true);
	window.setKeyRepeatEnabled(true);
	while(window.isOpen()){
		deal_with_window_event();
		if(map_change_flag == 0){
			world_loop();
		}else {
			map_change_process();
		}
		clock.restart();
		basic_work();
	}
}

void Director::update_player_position(){
	player_position = stuff[get_player_key()] -> get_position();
}

int Director::get_player_key(){
	if(player_key == -1){
		for(int i = 0; i < stuff.size(); i++){
			if(stuff[i] -> get_kind() == type_Player){ //0
				player_key = i;
				return i;
			}
		}
	}
	return player_key;
}

void Director::set_world(string setting){
	FILE *in = fopen(setting.c_str(),"r");
	char tmp[1005];
	int type;
	while(fscanf(in,"%d",&type) != EOF){
		fscanf(in,"%s",tmp);
		sample.push_back(string(tmp));
		sample_type.push_back(type);
	}
	fclose(in);
}

void Director::new_stuff(int x,sf::Vector2f request_place){
	if(x == -1) return;
	if(x >= sample.size()) return;

	Item *tmp = NULL;
	switch(sample_type[x]){
		case type_Player: tmp = new Player(sample_type[x], sample[x], request_place,this);
				  break;
		case type_Bullet: tmp = new Bullet(sample_type[x], sample[x], request_place,this);
				  break;
		case type_Room: tmp = new Room(sample_type[x], sample[x], request_place,this);
				break;
		case type_Enemy: tmp = new Enemy(sample_type[x], sample[x], request_place,this);
				 break;
		case type_Background: tmp = new Background(sample_type[x], sample[x], request_place, this, 0);
				      break;
		case type_Dialog: tmp = new Dialog(sample_type[x], sample[x], request_place, this);
				  break;
		case type_CG:	tmp = new CG(sample_type[x], sample[x], request_place, this);
				break;
		case type_Begin: tmp = new Begin(sample_type[x], sample[x], request_place, this);
				 break;
	}
	if(tmp != NULL) 
		stuff.push_back(tmp);
}

Director::~Director(){
	for(int i = 0; i < stuff.size(); i++){
		if(stuff[i] != NULL){
			delete stuff[i];
		}
	}
}
