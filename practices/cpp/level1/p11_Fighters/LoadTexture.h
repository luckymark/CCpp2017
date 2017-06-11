#ifndef LOADTEXTURE_H
#define LOADTEXTURE_H
#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include <iostream>
using namespace std;
struct Position{
	string name;
	int position[4];
};
typedef struct Position ImagePosition;

class LoadTexture{
	public:
		void loadFromFile(string path);
		sf::Texture* getTextureByName(string name);
		void initLoad(){
imagePosition = new ImagePosition;
imagePosition -> name = "enemy3_down6";
imagePosition -> position[0] = 0;
imagePosition -> position[1] = 747;
imagePosition -> position[2] = 166;
imagePosition -> position[3] = 261;
imageVector.push_back(imagePosition);
imagePosition = new ImagePosition;
imagePosition -> name = "enemy3_hit";
imagePosition -> position[0] = 166;
imagePosition -> position[1] = 750;
imagePosition -> position[2] = 169;
imagePosition -> position[3] = 258;
if (imagePosition != NULL){
	imageVector.push_back(imagePosition);
}
imagePosition = new ImagePosition;
imagePosition -> name = "enemy3_n1";
imagePosition -> position[0] = 335;
imagePosition -> position[1] = 750;
imagePosition -> position[2] = 169;
imagePosition -> position[3] = 258;
if (imagePosition != NULL){
	imageVector.push_back(imagePosition);
}
imagePosition = new ImagePosition;
imagePosition -> name = "enemy3_n2";
imagePosition -> position[0] = 504;
imagePosition -> position[1] = 750;
imagePosition -> position[2] = 169;
imagePosition -> position[3] = 258;
if (imagePosition != NULL){
	imageVector.push_back(imagePosition);
}
imagePosition = new ImagePosition;
imagePosition -> name = "enemy3_down1";
imagePosition -> position[0] = 0;
imagePosition -> position[1] = 486;
imagePosition -> position[2] = 165;
imagePosition -> position[3] = 261;
if (imagePosition != NULL){
	imageVector.push_back(imagePosition);
}
imagePosition = new ImagePosition;
imagePosition -> name = "enemy3_down2";
imagePosition -> position[0] = 0;
imagePosition -> position[1] = 225;
imagePosition -> position[2] = 165;
imagePosition -> position[3] = 261;
if (imagePosition != NULL){
	imageVector.push_back(imagePosition);
}
imagePosition = new ImagePosition;
imagePosition -> name = "enemy3_down5";
imagePosition -> position[0] = 673;
imagePosition -> position[1] = 748;
imagePosition -> position[2] = 166;
imagePosition -> position[3] = 260;
if (imagePosition != NULL){
	imageVector.push_back(imagePosition);
}
imagePosition = new ImagePosition;
imagePosition -> name = "enemy3_down3";
imagePosition -> position[0] = 839;
imagePosition -> position[1] = 748;
imagePosition -> position[2] = 165;
imagePosition -> position[3] = 260;
if (imagePosition != NULL){
	imageVector.push_back(imagePosition);
}
imagePosition = new ImagePosition;
imagePosition -> name = "enemy3_down4";
imagePosition -> position[0] = 165;
imagePosition -> position[1] = 486;
imagePosition -> position[2] = 165;
imagePosition -> position[3] = 261;
if (imagePosition != NULL){
	imageVector.push_back(imagePosition);
}
imagePosition = new ImagePosition;
imagePosition -> name = "hero1";
imagePosition -> position[0] = 0;
imagePosition -> position[1] = 99;
imagePosition -> position[2] = 102;
imagePosition -> position[3] = 126;
if (imagePosition != NULL){
	imageVector.push_back(imagePosition);
}
imagePosition = new ImagePosition;
imagePosition -> name = "hero2";
imagePosition -> position[0] = 165;
imagePosition -> position[1] = 360;
imagePosition -> position[2] = 102;
imagePosition -> position[3] = 126;
if (imagePosition != NULL){
	imageVector.push_back(imagePosition);
}
imagePosition = new ImagePosition;
imagePosition -> name = "hero_blowup_n1";
imagePosition -> position[0] = 165;
imagePosition -> position[1] = 234;
imagePosition -> position[2] = 102;
imagePosition -> position[3] = 126;
if (imagePosition != NULL){
	imageVector.push_back(imagePosition);
}
imagePosition = new ImagePosition;
imagePosition -> name = "hero_blowup_n2";
imagePosition -> position[0] = 330;
imagePosition -> position[1] = 624;
imagePosition -> position[2] = 102;
imagePosition -> position[3] = 126;
if (imagePosition != NULL){
	imageVector.push_back(imagePosition);
}
imagePosition = new ImagePosition;
imagePosition -> name = "hero_blowup_n3";
imagePosition -> position[0] = 330;
imagePosition -> position[1] = 498;
imagePosition -> position[2] = 102;
imagePosition -> position[3] = 126;
if (imagePosition != NULL){
	imageVector.push_back(imagePosition);
}
imagePosition = new ImagePosition;
imagePosition -> name = "hero_blowup_n4";
imagePosition -> position[0] = 432;
imagePosition -> position[1] = 624;
imagePosition -> position[2] = 102;
imagePosition -> position[3] = 126;
if (imagePosition != NULL){
	imageVector.push_back(imagePosition);
}
imagePosition = new ImagePosition;
imagePosition -> name = "enemy2";
imagePosition -> position[0] = 0;
imagePosition -> position[1] = 0;
imagePosition -> position[2] = 69;
imagePosition -> position[3] = 99;
if (imagePosition != NULL){
	imageVector.push_back(imagePosition);
}
imagePosition = new ImagePosition;
imagePosition -> name = "enemy2_hit";
imagePosition -> position[0] = 432;
imagePosition -> position[1] = 525;
imagePosition -> position[2] = 69;
imagePosition -> position[3] = 99;
if (imagePosition != NULL){
	imageVector.push_back(imagePosition);
}
imagePosition = new ImagePosition;
imagePosition -> name = "ufo2";
imagePosition -> position[0] = 102;
imagePosition -> position[1] = 118;
imagePosition -> position[2] = 60;
imagePosition -> position[3] = 107;
if (imagePosition != NULL){
	imageVector.push_back(imagePosition);
}
imagePosition = new ImagePosition;
imagePosition -> name = "enemy2_down1";
imagePosition -> position[0] = 534;
imagePosition -> position[1] = 655;
imagePosition -> position[2] = 69;
imagePosition -> position[3] = 95;
if (imagePosition != NULL){
	imageVector.push_back(imagePosition);
}
imagePosition = new ImagePosition;
imagePosition -> name = "enemy2_down2";
imagePosition -> position[0] = 603;
imagePosition -> position[1] = 655;
imagePosition -> position[2] = 69;
imagePosition -> position[3] = 95;
if (imagePosition != NULL){
	imageVector.push_back(imagePosition);
}
imagePosition = new ImagePosition;
imagePosition -> name = "enemy2_down3";
imagePosition -> position[0] = 672;
imagePosition -> position[1] = 653;
imagePosition -> position[2] = 69;
imagePosition -> position[3] = 95;
if (imagePosition != NULL){
	imageVector.push_back(imagePosition);
}
imagePosition = new ImagePosition;
imagePosition -> name = "enemy2_down4";
imagePosition -> position[0] = 741;
imagePosition -> position[1] = 653;
imagePosition -> position[2] = 69;
imagePosition -> position[3] = 95;
if (imagePosition != NULL){
	imageVector.push_back(imagePosition);
}
imagePosition = new ImagePosition;
imagePosition -> name = "ufo1";
imagePosition -> position[0] = 267;
imagePosition -> position[1] = 398;
imagePosition -> position[2] = 58;
imagePosition -> position[3] = 88;
if (imagePosition != NULL){
	imageVector.push_back(imagePosition);
}
imagePosition = new ImagePosition;
imagePosition -> name = "bomb";
imagePosition -> position[0] = 810;
imagePosition -> position[1] = 691;
imagePosition -> position[2] = 63;
imagePosition -> position[3] = 57;
if (imagePosition != NULL){
	imageVector.push_back(imagePosition);
}
imagePosition = new ImagePosition;
imagePosition -> name = "enemy1_down1";
imagePosition -> position[0] = 267;
imagePosition -> position[1] = 347;
imagePosition -> position[2] = 57;
imagePosition -> position[3] = 51;
if (imagePosition != NULL){
	imageVector.push_back(imagePosition);
}
imagePosition = new ImagePosition;
imagePosition -> name = "enemy1_down2";
imagePosition -> position[0] = 873;
imagePosition -> position[1] = 697;
imagePosition -> position[2] = 57;
imagePosition -> position[3] = 51;
if (imagePosition != NULL){
	imageVector.push_back(imagePosition);
}
imagePosition = new ImagePosition;
imagePosition -> name = "enemy1_down3";
imagePosition -> position[0] = 267;
imagePosition -> position[1] = 296;
imagePosition -> position[2] = 57;
imagePosition -> position[3] = 51;
if (imagePosition != NULL){
	imageVector.push_back(imagePosition);
}
imagePosition = new ImagePosition;
imagePosition -> name = "enemy1_down4";
imagePosition -> position[0] = 930;
imagePosition -> position[1] = 697;
imagePosition -> position[2] = 57;
imagePosition -> position[3] = 51;
if (imagePosition != NULL){
	imageVector.push_back(imagePosition);
}
imagePosition = new ImagePosition;
imagePosition -> name = "game_pause_nor";
imagePosition -> position[0] = 267;
imagePosition -> position[1] = 251;
imagePosition -> position[2] = 60;
imagePosition -> position[3] = 45;
if (imagePosition != NULL){
	imageVector.push_back(imagePosition);
}
imagePosition = new ImagePosition;
imagePosition -> name = "game_pause_pressed";
imagePosition -> position[0] = 810;
imagePosition -> position[1] = 646;
imagePosition -> position[2] = 60;
imagePosition -> position[3] = 45;
if (imagePosition != NULL){
	imageVector.push_back(imagePosition);
}
imagePosition = new ImagePosition;
imagePosition -> name = "enemy1";
imagePosition -> position[0] = 534;
imagePosition -> position[1] = 612;
imagePosition -> position[2] = 57;
imagePosition -> position[3] = 43;
if (imagePosition != NULL){
	imageVector.push_back(imagePosition);
}
imagePosition = new ImagePosition;
imagePosition -> name = "bullet1";
imagePosition -> position[0] = 1004;
imagePosition -> position[1] = 987;
imagePosition -> position[2] = 9;
imagePosition -> position[3] = 21;
if (imagePosition != NULL){
	imageVector.push_back(imagePosition);
}
imagePosition = new ImagePosition;
imagePosition -> name = "bullet2";
imagePosition -> position[0] = 69;
imagePosition -> position[1] = 78;
imagePosition -> position[2] = 9;
imagePosition -> position[3] = 21;
if (imagePosition != NULL){
	imageVector.push_back(imagePosition);
}
}
	private:
		vector<sf::Texture *> textureVector;
		vector<ImagePosition*> imageVector;
		ImagePosition* imagePosition;
};
#endif