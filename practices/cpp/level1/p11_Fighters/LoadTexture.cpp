#include "LoadTexture.h"

void LoadTexture::loadFromFile(string path){
	initLoad();
	sf::Image image;
	sf::Texture *texture;
	image.loadFromFile(path);
	for (int i = 0 ; i < imageVector.size() ; i ++){
		sf::IntRect r(imageVector.at(i)->position[0] , imageVector.at(i)->position[1] , imageVector.at(i)->position[2] , imageVector.at(i)->position[3]);
		texture = new sf::Texture();
		texture->loadFromImage(image , r);
		textureVector.push_back(texture);
	}
}
sf::Texture* LoadTexture::getTextureByName(string name){
	for (int i = 0 ; i < imageVector.size() ; i++){
		if (imageVector.at(i)->name == name){
			return textureVector.at(i);
		}
	}
	std::cout<<"no texture matched!\n";
}