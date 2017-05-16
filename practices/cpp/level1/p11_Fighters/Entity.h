#pragma once
#ifndef ENTITY_H_
#define ENTITY_H_
#include"YOUneedTHIS.h"
class Entity
{
private:
	sf::Vector2f mVelocity;
public:
	void setVelocity(sf::Vector2f velocity);
	void setVelocity(float vx, float vy);
	sf::Vector2f getVelocity() const;
};
#endif // !ENTITY_H_H
