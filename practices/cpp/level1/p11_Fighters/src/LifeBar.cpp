#include "LifeBar.h"
#include "Director.h"
#include "Item.h"

void LifeBar::set_from_setting(string setting, sf::Vector2f pos){
	FILE *in = fopen(setting.c_str(), "r");
	if(in == NULL){
		cerr << "fail to open file in LifeBar.cpp -> LifeBar" << endl;
		exit(0);
	}

	char tmp[1005];
	for(int i = 0; i < 2; i++){
		fscanf(in, "%s", tmp);
		frame[i].set_image(string(tmp));
		fscanf(in, "%s", tmp);
		frame[i].set_image_info(string(tmp));
	}
}

void LifeBar::set_life(float life, float max_life){
	frame[1].set_scale(sf::Vector2f(life/max_life, 1.0f));
}

void LifeBar::display(sf::RenderWindow *win){
	for(int i = 0; i < 2; i++){
		frame[i].display(win);
	}
}

