#ifndef BOOK_AIRCRAFT_HPP
#define BOOK_AIRCRAFT_HPP

#include "ResourceIdentifiers.hpp"
#include "Entity.hpp"
#include "ResourceIdentifiers.hpp"
#include"Projectile.hpp"
#include"SoundHolder.hpp"
#include "Command.hpp"
#include"CommandQueue.hpp"
#include "PlayerStatusMenu.h"
#include"Player.hpp"

#include<SFML/Graphics.hpp>

class Player;

class Aircraft : public Entity
{
public:
	enum Type
	{
		Eagle,
		Raptor,
		Avenger,

		RaptorA1,
		RaptorA2,
		RaptorB1,
		RaptorB2,
		RaptorC1,
		RaptorC2,
		RaptorD1,
		RaptorD2,


		AvengerA1,
		AvengerA2,
		AvengerB1,
		AvengerB2,
		AvengerC1,
		AvengerC2,
		AvengerD1,
		AvengerD2,



		EagleA1,
		EagleA2,
		EagleB1,
		EagleB2,

		TypeCount,
	};


public:
	Aircraft(sf::RenderWindow& window, Type type, const TextureHolder& textures, const FontHolder& fonts, SoundHolder& mSounds
			,bool isPlayer=false,Player* player=NULL);
	virtual unsigned int	getCategory() const;
	Aircraft::Type			getType() const;
	virtual sf::FloatRect	getBoundingRect() const;
	virtual bool 			isMarkedForRemoval() const;
	bool					isAllied() const;
	float					getMaxSpeed() const;

	bool					increaseFireRate();
	bool					increaseSpread();
	void					GetMissileORUpgradeFire();
	void					GetHpOrFirePile();
	void					collectMissiles(unsigned int count);

	void 					fire();
	void					launchMissile();

	void					openEMenu();
	void					openQMenu();

	void					closeMenu();
	void					addPoints(int points);
	void					updateScore(int scores);
	bool					reborn();
	void					restart();
	int						getScore();

private:
	virtual void			drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;
	virtual void 			updateCurrent(sf::Time dt, CommandQueue& commands);
	void					updateMovementPattern(sf::Time dt);
	void					checkProjectileLaunch(sf::Time dt, CommandQueue& commands);

	void					createBullets(SceneNode& node, const TextureHolder& textures) const;
	void					createProjectile(SceneNode& node, Projectile::Type type, float xOffset, float yOffset, const TextureHolder& textures) const;
	void					setAllyVelocity(float x, float y);


private:
	Type					mType;
	sf::Sprite				mSprite;
	sf::Texture				mDamaged;
	sf::Texture				mOrigin;
	Command 				mFireCommand;
	Command					mMissileCommand;
	SoundHolder&			mSounds;
	sf::RenderWindow&       mWindow;

	sf::Time				mFireCountdown;
	bool 					mIsFiring;
	bool					mIsLaunchingMissile;
	bool 					mIsMarkedForRemoval;
	bool					isPlayerAircraft;

	int						mFireRateLevel;
	int						mSpreadLevel;
	int						mMissileAmmo;
	int						mPoints;
	int						mScore;

	int						FireRateCost;
	int						FireSpreadCost;

	Command 				mDropPickupCommand;
	float					mTravelledDistance;
	std::size_t				mDirectionIndex;


	PlayerStatusMenu		mMenu;
	Player*					mPlayer;

};

#endif // BOOK_AIRCRAFT_HPP
