#include "Director.h"
#include "Player.h"
#include "Bullet.h"
#include "Room.h"
#include "Enemy.h"
#include "Background.h"
#include <iostream>
using namespace std;

Director::Director(){
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
			stuff[j] -> be_impacted_from(stuff[i]); ///
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

void Director::main_loop(){
	window.create(sf::VideoMode(800,800), "My window");
	window.setVerticalSyncEnabled(true);
	window.setKeyRepeatEnabled(true);
	while(window.isOpen()){
		while(window.pollEvent(event)){
			switch(event.type){
				case sf::Event::Closed:
					window.close();
					break;
				default: break;
			}
		}
		window.clear(sf::Color(100,100,100));
		world_loop();
		clock.restart();
		for(int i = 0; i < stuff.size(); i++){
			stuff[i] -> display();
		}
		window.display();
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
		case type_Background: tmp = new Background(sample_type[x], sample[x], request_place, this);
			break;
		case 6: //tmp = new Object(sample_type[x], sample[x], request_place);
			break;
		case 7: //tmp = new Boss(sample_type[x], sample[x], request_place);
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
