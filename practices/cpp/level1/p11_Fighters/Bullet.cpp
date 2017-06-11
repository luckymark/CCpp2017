#include "Bullet.h"
Bullet::Bullet(int type){
	this->type = type;
}
int Bullet::getType(){
	return type;
}
Bullet::Bullet(const Bullet& bullet){
	this->type = bullet.type;
	this->setTexture(*bullet.getTexture());
}