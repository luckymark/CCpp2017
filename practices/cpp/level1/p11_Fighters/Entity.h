#pragma once

#include "SceneNode.h"

class Entity :public SceneNode
{
public:
	explicit			Entity(int hitpoints);
	virtual void		remove();
	void				repair(int points);
	void				damage(int points);
	void				destroy();

	void				setVelocity(sf::Vector2f velocity);
	void				setVelocity(float vx, float vy);
	void				accelerate(sf::Vector2f velocity);
	void				accelerate(float vx, float vy);
	sf::Vector2f		getVelocity() const;

	int					getHitpoints() const;
	virtual bool		isDestroyed() const;

private:
	sf::Vector2f		mVelocity;

	int					mHitpoints;

protected:
	virtual void		updateCurrent(sf::Time dt, CommandQueue& commands);
};