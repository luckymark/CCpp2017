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
	update_enemy_exist_flag();
	winner_checker();
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
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::M)){
		map_flag = 1;
	}else {
		map_flag = 0;
	}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::R)){
		if(lose_flag == 1 || win_flag == 1){
			restart();
		}
	}
}


void Director::basic_work(){
	bgm.next();
	window.clear(sf::Color(100,100,100));
	for(int i = 0; i < stuff.size(); i++) if(stuff[i] -> get_kind() == type_Background || stuff[i] -> get_kind() == type_Background1 || stuff[i] -> get_kind() == type_Background2){
		stuff[i] -> display();
	}
	for(int i = 0; i < stuff.size(); i++) if(stuff[i] -> get_kind() != type_Background && stuff[i] -> get_kind() != type_Background1 && stuff[i] -> get_kind() != type_Background2){
		stuff[i] -> display();
	}
	if(map_flag){
		small_map.display(&window);
	}
	if(win_flag){
		win_image.display(&window);
	}
	if(lose_flag){
		lose_image.display(&window);
	}
	window.display();
}


void Director::winner_checker(){
	int ff = 0;
	int ls = 0;
	for(int i = 0; i < stuff.size(); i++){
		if(stuff[i] -> get_kind() == type_Dialog){
			ff++; ls++;
		}
		if(stuff[i] -> get_kind() == type_CG){
			ff++; ls++;
		}
		if(stuff[i] -> get_kind() == type_Begin){
			ff++; ls++;
		}
		if(stuff[i] -> get_kind() == type_Door){
			ff++;
		}
		if(stuff[i] -> get_kind() == type_Enemy || stuff[i] -> get_kind() == type_Enemy_1 
			|| stuff[i] -> get_kind() == type_Enemy_2 || stuff[i] -> get_kind() == type_Enemy_3 || stuff[i] -> get_kind() == type_Enemy_4){
			ff++;
		}
		if(stuff[i] -> get_kind() == type_Player){
			ls++;
		}
	}
	if(ff == 0){
		win_flag = 1;
	}else {
		win_flag = 0;
	}
	if(ls == 0){
		lose_flag = 1;
	}else {
		lose_flag = 0;
	}
}

void Director::end_game(){
	for(vector<Item*>::iterator it = stuff.begin(); it != stuff.end();){
		delete (*it);
		it = stuff.erase(it);
	}
}

void Director::start(){
	load_image();
	new_stuff(10,sf::Vector2f(0,0));
}

void Director::restart(){
	end_game();
	new_stuff(5,sf::Vector2f(0,0));
	new_stuff(2,sf::Vector2f(50,50));
	new_stuff(0,sf::Vector2f(400.0,400.0));
}

void Director::load_image(){
	small_map.set_image("../data/sys_pic/2.jpg");
	win_image.set_image("../data/sys_pic/0.png");
	lose_image.set_image("../data/sys_pic/1.png");
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
	//if(player_key == -1){
	for(int i = 0; i < stuff.size(); i++){
		if(stuff[i] -> get_kind() == type_Player){ //0
			player_key = i;
			return i;
		}
	}
	//}
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

void Director::update_enemy_exist_flag(){
	enemy_exist_flag = 0;
	for(int i = 0 ; i < stuff.size(); i++){
		enemy_exist_flag |= (stuff[i] -> get_kind() == type_Enemy | stuff[i] ->get_kind() == type_Enemy_1 | stuff[i] -> get_kind() == type_Enemy_2
				| stuff[i] -> get_kind() == type_Enemy_3 | stuff[i] -> get_kind() == type_Enemy_4);
	}
}

Director::~Director(){
	for(int i = 0; i < stuff.size(); i++){
		if(stuff[i] != NULL){
			delete stuff[i];
		}
	}
}
