#include "Director.h"

void Director::clean_stuff(){
	for(int i = 0; i < stuff.size(); i++){
		if(stuff[i] -> is_dead()){
			dead_request.push_back(stuff[i] -> dead());
		}
	}
	for(vector<Item*>::iterator it = stuff.begin(); it != stuff.end();){
		if((*it) -> is_dead()){
			delete *it;
			it = stuff.erase(it);
		}else {
			it++;
		}
	}
}

void Director::world_loop(){
	for(int i = 0; i < stuff.size(); i++)
		for(int j = i + 1; j < stuff.size(); i++){
			Animation *tmp = stuff[j] -> get_current_animation();
			stuff[j] -> get_impact_from(stuff[i] -> get_current_animation());
			stuff[i] -> get_impact_from(tmp);
		}
	clean_stuff();
	for(int i = 0; i < stuff.size(); i++){
		stuff[i] -> Action(clock.getElapsedTime());
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
					return;
				/*.........*/
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

void Director::new_stuff(int x,sf::Vector2f dead_place){
	if(x == -1) return;
	if(x >= sample.size()) return;

	char tt[2][1005];
	FILE *in = fopen(sample[x].c_str(), "r");
	fscanf(in,"%s",tt[0]);
	fscanf(in,"%s",tt[1]);
	fclose(in);
	Item *tmp = NULL;
	switch(sample_type[x]){
		case 0: tmp = new Player(sample_type[x], string(tt[0]), string(tt[1]), dead_place);
			break;
		case 1: //tmp = new Boss(sample_type[x], sample[x], dead_place);
			break;
		case 2: //tmp = new Normal(sample_type[x], sample[x], dead_place);
			break;
		case 3: //tmp = new Subject(sample_type[x], sample[x], dead_place);
			break;
	}
	if(tmp != NULL) stuff.push_back(tmp);
}

void Director::fill_request(){
	for(int i = 0; i < dead_request.size(); i++){
		new_stuff(dead_request[i],dead_position[i]);
	}
	dead_request.clear();
	dead_position.clear();
}

Director::~Director(){
	for(int i = 0; i < stuff.size(); i++){
		delete stuff[i];
	}
}
