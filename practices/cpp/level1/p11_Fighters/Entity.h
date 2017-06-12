#ifndef ENTITY_H_
#define ENTITY_H_

#include "SceneNode.h"
#include "YOUneedTHIS.h"
#include "CommandQueue.h"

class Entity : public SceneNode
{
	
	public:
		explicit Entity(int hitpoints);
		Entity() {};
		void repair(int points)
		{
			mHitpoints += points;
		}
		void damage(int points)
		{
			mHitpoints -= points;
		}
		void destroy()
		{
			mHitpoints = 0;
		}

		int getHitpoints() const
		{
			return mHitpoints;
		}
		

		void setVelocity(sf::Vector2f velocity)
		{
			mVelocity = velocity;
		}
		void setVelocity(float vx, float vy)
		{
			mVelocity.x = vx;
			mVelocity.y = vy;
		}
		void accelerate(sf::Vector2f velocity)
		{
			mVelocity += velocity;
		}
		void accelerate(float vx, float vy)
		{
			mVelocity.x += vx;
			mVelocity.y += vy;
		}
		sf::Vector2f getVelocity() const
		{
			return mVelocity;
		}


	protected:
		virtual void updateCurrent(sf::Time dt, CommandQueue& commands);
public:

		bool isDestroyed() const;

	private:
		int mHitpoints;
		sf::Vector2f mVelocity;
};

#endif // !ENTITY_H_
