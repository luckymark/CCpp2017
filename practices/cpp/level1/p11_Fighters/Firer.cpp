#include "Sky.h"

Firer::Firer(Sky &sky , LoadTexture &loadtexture){
	this->sky = &sky;
	this->loadtexture = &loadtexture;
}
void Firer::fire(sf::Vector2f position , int type){
	bullet = new Bullet(type);
	bullet->setTexture(*loadtexture->getTextureByName("bullet2"));
	bullet->setOrigin(bullet->getTexture()->getSize().x / 2 ,bullet->getTexture()->getSize().y / 2);
	bullet->setPosition(position);
	sky->add(bullet);
}