#include "Include/Entity.hpp"

Entity::Entity(int hitpoints)
	: mVelocity()
	, mHitpoints(hitpoints)
	, mMaxHP(hitpoints)
{
}

void Entity::setVelocity(sf::Vector2f velocity)
{
	mVelocity = velocity;
}

void Entity::setVelocity(float vx, float vy)
{
	mVelocity.x = vx;
	mVelocity.y = vy;
}

sf::Vector2f Entity::getVelocity() const
{
	return mVelocity;
}

void Entity::setHP(int HP)
{
	mHitpoints = HP;
}

void Entity::accelerate(sf::Vector2f velocity)
{
	mVelocity += velocity;
}

void Entity::accelerate(float vx, float vy)
{

	mVelocity.x += vx;
	mVelocity.y += vy;

}

int Entity::getHitpoints() const
{
	return mHitpoints;
}

void Entity::increaseHP(int increase)
{
	mHitpoints += increase;
}


void Entity::repair(int points)
{
	//	assert(points > 0);
	mHitpoints += points;

	if (mHitpoints > mMaxHP) mHitpoints = mMaxHP;

}

void Entity::damage(int points)
{
	//	assert(points > 0);

 	mHitpoints -= points;
}

void Entity::destroy()
{
	mHitpoints = 0;
}

bool Entity::isDestroyed() const
{
	return mHitpoints <= 0;
}

void Entity::updateCurrent(sf::Time dt, CommandQueue&)
{
	move(mVelocity * dt.asSeconds());
}