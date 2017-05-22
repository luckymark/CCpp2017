#pragma once
#ifndef ENTITY_H_
#define ENTITY_H_
#include"YOUneedTHIS.h"
#include"SceneNode.h"
class Entity:public SceneNode
{
private:
	sf::Vector2f mVelocity;
private:
	virtual void updateCurrent(sf::Time dt);
public:
	void setVelocity(sf::Vector2f velocity);
	void setVelocity(float vx, float vy);
	sf::Vector2f getVelocity() const;
};
#endif // !ENTITY_H_H
