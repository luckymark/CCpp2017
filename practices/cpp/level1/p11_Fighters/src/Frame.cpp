#include "Animation.h"
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
using namespace std;

Frame::Frame(){
	memset(x,0,sizeof(x));
	memset(y,0,sizeof(y));
	core_position.x = core_position.y = 0;
	del_position.x = del_position.y = 0;
	impact_flag = hurt_flag = 0;
}

Frame::Frame( string image_file_name, string image_info_file_name ){
	memset(x,0,sizeof(x));
	memset(y,0,sizeof(y));
	core_position.x = core_position.y = 0;
	del_position.x = del_position.y = 0;
	impact_flag = hurt_flag = 0;
	set_image(image_file_name);
	set_image_info(image_info_file_name);
}

void Frame::update_draw_position(){
	x[0] = core_position.x - del_position.x;
	x[1] = x[0] + image.getSize().x;
	y[0] = core_position.y - del_position.y;
	y[1] = y[0] + image.getSize().y;
	sprite.setPosition(core_position - del_position);
}

sf::Sprite* Frame::display(){
	return &sprite;
}

void Frame::set_image(string image_file_name){
	if(!image.loadFromFile(image_file_name)){
		cerr << "fail to open the image in: " << image_file_name << endl;
		exit(0);
	}
	if(!texture.loadFromImage(image)){
		cerr << "fail to open the image obj" << endl;
		exit(0);
	}
	sprite.setTexture(texture);
	sprite.setTextureRect(sf::IntRect(0,0,image.getSize().x, image.getSize().y));
}

void Frame::set_image_info(string image_info_file_name){
	char tmp[1005];
	FILE *in = fopen(image_info_file_name.c_str(), "r");
	if(in == NULL){
		cerr << "fail to open in Frame.cpp 48" << endl;
		exit(0);
	}
	fscanf(in," %f%f", &del_position.x,&del_position.y);
	//del_position.y = image.getSize().y;
	fclose(in);
}

void Frame::set_core_position(sf::Vector2f position){
	//cerr << position.x << " " << position.y << endl;
	core_position = position;
	update_draw_position();
}

int Frame::is_in(const sf::Vector2f &point){
	return (x[0] <= point.x && x[1] >= point.x) && 
		(y[0] <= point.y && y[1] >= point.y);
}

int Frame::is_in(Frame *other){
	return (core_position.x <= (other -> x[1]) && core_position.x >= (other -> x[0]))
		&&(core_position.y <= (other -> y[1]) && core_position.y >= (other -> y[0]));
}
