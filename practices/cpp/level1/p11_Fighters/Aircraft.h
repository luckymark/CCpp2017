#pragma once
#ifndef AIRCRAFT_H_
#define AIRCRAFT_H_
#include"YOUneedTHIS.h"
#include"Entity.h"
#include"ResourseHolder.h"
class Aircraft :public Entity
{
public:
	enum Type{Eagle,Raptor};
private:
	Type mType;
	sf::Sprite mSprite;
private:
	Textures::ID toResourceId(Aircraft::Type type);
public:
	explicit Aircraft(Type type,const TextureHolder& textures);
	Aircraft() {};
	virtual void drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;
};
#endif // !AIRCRAFT_H_
