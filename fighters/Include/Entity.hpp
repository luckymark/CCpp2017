#ifndef BOOK_ENTITY_HPP
#define BOOK_ENTITY_HPP

#include "SceneNode.hpp"


class Entity : public SceneNode
{
public:
	explicit			Entity(int hitpoints);

	void				setVelocity(sf::Vector2f velocity);
	void				setVelocity(float vx, float vy);
	void				accelerate(sf::Vector2f velocity);
	void				accelerate(float vx, float vy);
	sf::Vector2f		getVelocity() const;

	int					getHitpoints() const;
	void				increaseHP(int increase);
	void				repair(int points);
	void				damage(int points);
	void				destroy();
	virtual bool		isDestroyed() const;


protected:
	virtual void		updateCurrent(sf::Time dt, CommandQueue& commands);


private:
	sf::Vector2f		mVelocity;
	int					mHitpoints;
	int					mMaxHP;
};

#endif // BOOK_ENTITY_HPP
