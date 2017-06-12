#include "Entity.h"


Entity::Entity(int hitpoints)
{
	mHitpoints = hitpoints;
	mVelocity = { 0,0 };
}

bool Entity::isDestroyed() const
{
	return mHitpoints<=0;
}

void Entity::updateCurrent(sf::Time dt, CommandQueue& commands)
{	
	move(mVelocity * dt.asSeconds());
}