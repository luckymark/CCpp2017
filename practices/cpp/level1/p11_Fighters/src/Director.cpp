#include "Director.h"
#include "Player.h"
#include "Bullet.h"
#include <iostream>
using namespace std;

Director::Director(){
	stuff.clear();
	request.clear();
	request_position.clear();
	request_dir.clear();
	sample.clear();
	sample_type.clear();
	clock.restart();
}

void Director::clean_stuff(){
	for(vector<Item*>::iterator it = stuff.begin(); it != stuff.end();){
		if((*it) -> is_dead()){
			if(*it != NULL){
				delete *it;
			}
			it = stuff.erase(it);
		}else {
			it++;
		}
	}
}

void Director::get_request(){
	for(int i = 0; i < stuff.size(); i++){
		if(stuff[i] -> has_request()){
			request.push_back(stuff[i] -> get_request());
			request_position.push_back(stuff[i] -> get_position());
			request_dir.push_back(stuff[i] -> get_request_direction());
		}
	}
}

void Director::clear_request(){
	request_position.clear();
	request.clear();
	request_dir.clear();
}

void Director::world_loop(){
	fill_request();
	clear_request();
	for(int i = 0; i < stuff.size(); i++)
		for(int j = i + 1; j < stuff.size(); j++){
			//stuff[j] -> be_impacted_from(stuff[i]);
			//stuff[i] -> be_impacted_from(stuff[j]);
		}
	clean_stuff();
	for(int i = 0; i < stuff.size(); i++){
		float x = sf::Mouse::getPosition(window).x;
		float y = sf::Mouse::getPosition(window).y;
		stuff[i] -> Action(clock.getElapsedTime(),sf::Vector2f(x,y));
	}
	get_request();
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
			}
		}
		window.clear(sf::Color(100,100,100));
		world_loop();
		clock.restart();
		for(int i = 0; i < stuff.size(); i++){
			window.draw(*(stuff[i] -> display()));
		}
		window.display();
	}
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

void Director::new_stuff(int x,sf::Vector2f request_place, sf::Vector2f dir){
	if(x == -1) return;
	if(x >= sample.size()) return;

	char tt[2][1005];
	FILE *in = fopen(sample[x].c_str(), "r");
	fscanf(in,"%s",tt[0]);
	fscanf(in,"%s",tt[1]);
	fclose(in);
	Item *tmp = NULL;
	switch(sample_type[x]){
		case 0: tmp = new Player(sample_type[x], string(tt[0]), string(tt[1]), request_place);
			tmp -> set_direction(dir);
			break;
		case 4: //tmp = new Boss(sample_type[x], sample[x], request_place);
			break;
		case 2: //tmp = new Normal(sample_type[x], sample[x], request_place);
			break;
		case 3: //tmp = new Subject(sample_type[x], sample[x], request_place);
			break;
		case 1: tmp = new Bullet(sample_type[x], string(tt[0]), string(tt[1]), request_place);
			tmp -> set_direction(dir);
	}
	if(tmp != NULL) 
		stuff.push_back(tmp);
}

void Director::fill_request(){
	for(int i = 0; i < request.size(); i++){
		new_stuff(request[i],request_position[i],request_dir[i]);
	}
}

Director::~Director(){
	for(int i = 0; i < stuff.size(); i++){
		if(stuff[i] != NULL){
			delete stuff[i];
			cerr << "stuff" << i << "deleted" << endl;
		}
	}
}
