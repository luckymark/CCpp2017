#ifndef AIRCRAFT_H_
#define AIRCRAFT_H_

#include "Entity.h"
#include "YOUneedTHIS.h"
#include "TextNode.h"
#include "Projectile.h"
#include "DateTables.h"
#include "Animation.h"
#include "CommandQueue.h"
#include "Pickup.h"
#include "SoundNode.h"


class Aircraft : public Entity
{
public:
	enum Type
	{
		Eagle,
		Raptor,
		Avenger,
		TypeCount
	};


public:
	Aircraft(Type type, const TextureHolder& textures, const FontHolder& fonts);

	virtual unsigned int getCategory() const;
	virtual sf::FloatRect getBoundingRect() const;
	virtual bool isMarkedForRemoval() const;
	bool isAllied() const;
	float getMaxSpeed() const;

	void increaseFireRate();
	void increaseSpread();
	void collectMissiles(unsigned int count);

	void fire();
	void launchMissile();
	void playLocalSound(CommandQueue& commands, SoundEffect::ID effect);

private:
	virtual void drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;
	virtual void updateCurrent(sf::Time dt, CommandQueue& commands);
	void updateMovementPattern(sf::Time dt);
	void checkPickupDrop(CommandQueue& commands);
	void checkProjectileLaunch(sf::Time dt, CommandQueue& commands);

	void createBullets(SceneNode& node, const TextureHolder& textures) const;
	void createProjectile(SceneNode& node, Projectile::Type type, float xOffset, float yOffset, const TextureHolder& textures) const;
	void createPickup(SceneNode& node, const TextureHolder& textures) const;
	void updateRollAnimation();
	void updateTexts();

	

private:
	Type mType;
	sf::Sprite mSprite;
	Command mFireCommand;
	Command mMissileCommand;
	sf::Time mFireCountdown;
	bool mIsFiring;
	bool mIsLaunchingMissile;
	bool mIsMarkedForRemoval;

	int mFireRateLevel;
	int	mSpreadLevel;
	int	mMissileAmmo;

	Command	mDropPickupCommand;
	bool mSpawnedPickup;
	float mTravelledDistance;
	std::size_t mDirectionIndex;
	TextNode* mHealthDisplay;
	TextNode* mMissileDisplay;
	Animation mExplosion;
	bool mShowExplosion;
	bool mPlayedExplosionSound;
};
#endif // !AIRCRAFT_H_
