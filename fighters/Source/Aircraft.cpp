#include "Include/Aircraft.hpp"
#include "Include/ResourceHolder.hpp"
#include "Include\Datatables.hpp"
#include"Include\utility.hpp"


#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RenderStates.hpp>

namespace
{
	const std::vector<AircraftData> Table = initializeAircraftData();
}

Aircraft::Aircraft(sf::RenderWindow& window, Type type, const TextureHolder& textures, const FontHolder& fonts, SoundHolder& mSounds
	, bool isPlayer
	, Player* player)
	: Entity(Table[type].hitpoints)
	, mType(type)
	, mSprite(textures.get(Table[type].texture))
	, mSounds(mSounds)
	, mFireCommand()
	, mMissileCommand()
	, mFireCountdown(sf::Time::Zero)
	, mIsFiring(false)
	, mIsLaunchingMissile(false)
	, mIsMarkedForRemoval(false)
	, mFireRateLevel(1)
	, mSpreadLevel(1)
	, mMissileAmmo(2)
	, mDropPickupCommand()
	, mTravelledDistance(0.f)
	, mDirectionIndex(0)
	, mPoints(0)
	, mMenu(window)
	, FireRateCost(10)
	, FireSpreadCost(20)
	, MissileSlotCost(15)
	, mMissileSlot(2)
	, mWindow(window)
	, isPlayerAircraft(isPlayer)
	, mOrigin(textures.get(Table[type].texture))
	, mPurchaseCountDown(sf::seconds(1.5))
{
	centerOrigin(mSprite);

	mFireCommand.category = Category::SceneAirLayer;
	mFireCommand.action = [this, &textures](SceneNode& node, sf::Time)
	{
		createBullets(node, textures);
	};

	mMissileCommand.category = Category::SceneAirLayer;
	mMissileCommand.action = [this, &textures](SceneNode& node, sf::Time)
	{
		createProjectile(node, Projectile::Missile, 0.f, 0.5f, textures);
	};

	if (isPlayer)
	{
		mPlayerClock.restart();
		mDamaged.loadFromFile("Media/Textures/EagleDamaged.png");
		mPlayer = player;

		mCountDownNode = new SceneNode;
		mCountDownTexture = new sf::Texture;
		mCountDownTexture->loadFromFile("Media/Flash/Loop.png");

	}

}

void Aircraft::drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const
{


	if (isPlayerAircraft)
	{
		mMenu.showMenu();
	}
	target.draw(mSprite, states);
}

void Aircraft::updateCurrent(sf::Time dt, CommandQueue& commands)
{


	if (isPlayerAircraft)
	{
		mMenu.updateMenu(getPosition(), getHitpoints(), mPoints, mMissileAmmo, FireRateCost, FireSpreadCost,MissileSlotCost);
		update(dt);			//����Aircraft����Flash�ڵ�

		if (getHitpoints() <= 0)
		{
			mPlayer->setPlayerDead();

			mMenu.closeMenus();
			mSprite.setTexture(mDamaged);
		}
		if(callingReborn)
		callingReborn = false;
	}


	// Entity has been destroyed: Possibly drop pickup, mark for removal
	if (isDestroyed())
	{
//		checkPickupDrop(commands);	
		if(!isPlayerAircraft)
			mIsMarkedForRemoval = true;
		return;
	}

	// Check if bullets or missiles are fired
	checkProjectileLaunch(dt, commands);

	// Update enemy movement pattern; apply velocity
	updateMovementPattern(dt);
	Entity::updateCurrent(dt, commands);

	// Update texts
//	updateTexts();


}

unsigned int Aircraft::getCategory() const
{
	if (isAllied())
		return Category::PlayerAircraft;
	else
		return Category::EnemyAircraft;
}

Aircraft::Type Aircraft::getType() const
{
	switch (mType)
	{
	case Type::Raptor:
		return Type::Raptor;
	case Type::RaptorA1:
		return Type::RaptorA1;
	case Type::RaptorA2:
		return Type::RaptorA2;
	case Type::RaptorB1:
		return Type::RaptorB1;
	case Type::RaptorB2:
		return Type::RaptorB2;
	case Type::RaptorC1:
		return Type::RaptorC1;
	case Type::RaptorC2:
		return Type::RaptorC2;
	case Type::RaptorD1:
		return Type::RaptorD1;
	case Type::RaptorD2:
		return Type::RaptorD2;

	case Type::Avenger:
		return Type::Avenger;
	case Type::AvengerA1:
		return Type::AvengerA1;
	case Type::AvengerA2:
		return Type::AvengerA2;
	case Type::AvengerB1:
		return Type::AvengerB1;
	case Type::AvengerB2:
		return Type::AvengerB2;
	case Type::AvengerC1:
		return Type::AvengerC1;
	case Type::AvengerC2:
		return Type::AvengerC2;
	case Type::AvengerD1:
		return Type::AvengerD1;
	case Type::AvengerD2:
		return Type::AvengerD2;

	case Type::Eagle:
		return Type::Eagle;
	case Type::EagleA1:
		return Type::EagleA1;
	case Type::EagleA2:
		return Type::EagleA2;
	case Type::EagleB1:
		return Type::EagleB1;
	case Type::EagleB2:
		return Type::EagleB2;
	}
}

sf::FloatRect Aircraft::getBoundingRect() const
{
	return getWorldTransform().transformRect(mSprite.getGlobalBounds());
}

bool Aircraft::isMarkedForRemoval() const
{
	return mIsMarkedForRemoval;
}

bool Aircraft::isAllied() const
{
	return mType == Eagle;
}

float Aircraft::getMaxSpeed() const
{
	return Table[mType].speed;
}

bool Aircraft::increaseFireRate()
{
	if (mFireRateLevel < 7)
	{
		mFireRateLevel+=0.5;
		return true;
	}
	return false;

}

bool Aircraft::increaseSpread()
{
	if (mSpreadLevel < 4)
	{
		++mSpreadLevel;;
		return true;
	}
	return false;


}

bool Aircraft::increaseMissileSlot()
{
	if (mMissileSlot < 4)
	{
		mMissileSlot++;
		return true;
	}
	return false;
}


void Aircraft::collectMissiles(unsigned int count)
{
	mMissileAmmo += count;
}

void Aircraft::fire()
{
	// Only ships with fire interval != 0 are able to fire
	if (Table[mType].fireInterval != sf::Time::Zero)
		mIsFiring = true;

	if (isPlayerAircraft)
	{
		mMenu.closeMenus();
	}
}

void Aircraft::launchMissile()
{
	if (mMissileAmmo > 0)
	{
		mIsLaunchingMissile = true;
		--mMissileAmmo;

		if (isPlayerAircraft)
		{
			mMenu.closeMenus();
		}
	}
}

void Aircraft::updateMovementPattern(sf::Time dt)
{
	// Enemy airplane: Movement pattern
	const std::vector<Direction>& directions = Table[mType].directions;
	if (!directions.empty())
	{
		// Moved long enough in current direction: Change direction
		if (mTravelledDistance > directions[mDirectionIndex].distance)
		{
			mDirectionIndex = (mDirectionIndex + 1) % directions.size();
			mTravelledDistance = 0.f;
		}

		// Compute velocity from direction
		float radians = toRadian(directions[mDirectionIndex].angle + 90.f);
		float vx = getMaxSpeed() * std::cos(radians);
		float vy = getMaxSpeed() * std::sin(radians);

		setVelocity(vx, vy);

		//����addTroopE()�Ķ�������
		if (getType() == Aircraft::RaptorD1 || getType() == Aircraft::RaptorD2|| getType() == Aircraft::AvengerD1 ||getType() == Aircraft::AvengerD2)
		{
			accelerate(0, -50);

			if (radians == 0)
			{
				setVelocity(getMaxSpeed(), 0);
			}
		}
		mTravelledDistance += getMaxSpeed() * dt.asSeconds();
	}
}
/*
void Aircraft::checkPickupDrop(CommandQueue& commands)
{
if (!isAllied() && randomInt(3) == 0)
commands.push(mDropPickupCommand);
}
*/
void Aircraft::checkProjectileLaunch(sf::Time dt, CommandQueue& commands)
{
	// Enemies try to fire all the time
	if (!isAllied())
	{
		fire();
	}
		

	// Check for automatic gunfire, allow only in intervals
	if (mIsFiring && mFireCountdown <= sf::Time::Zero)
	{
		// Interval expired: We can fire a new bullet
		commands.push(mFireCommand);
		mFireCountdown += Table[mType].fireInterval / (mFireRateLevel + 0.8f);
		mIsFiring = false;
		if (!isAllied())
		{
			mSounds.play(SoundEffect::EnemyGunfire);
		}
		else
		{
			mSounds.play(SoundEffect::AlliedGunfire);
		}
		
	}
	else if (mFireCountdown > sf::Time::Zero)
	{
		// Interval not expired: Decrease it further
		mFireCountdown -= dt;
		mIsFiring = false;
	}

	// Check for missile launch
	if (mIsLaunchingMissile)
	{
		commands.push(mMissileCommand);
		mIsLaunchingMissile = false;
		mSounds.play(SoundEffect::LaunchMissile);

	}
}

void Aircraft::createBullets(SceneNode& node, const TextureHolder& textures) const
{
	Projectile::Type type = isAllied() ? Projectile::AlliedBullet : Projectile::EnemyBullet;

	switch (mSpreadLevel)
	{
	case 1:
		createProjectile(node, type, 0.0f, 0.5f, textures);
		break;

	case 2:
		createProjectile(node, type, -0.33f, 0.33f, textures);
		createProjectile(node, type, +0.33f, 0.33f, textures);
		break;

	case 3:
		createProjectile(node, type, -0.5f, 0.33f, textures);
		createProjectile(node, type, 0.0f, 0.5f, textures);
		createProjectile(node, type, +0.5f, 0.33f, textures);
		break;
	case 4:
		createProjectile(node, type, -0.55f, 0.33f, textures);
		createProjectile(node, type, -0.17f, 0.55f, textures);
		createProjectile(node, type, +0.17f, 0.55f, textures);
		createProjectile(node, type, +0.55f, 0.33f, textures);


	}
}

void Aircraft::createProjectile(SceneNode& node, Projectile::Type type, float xOffset, float yOffset, const TextureHolder& textures) const
{
	std::unique_ptr<Projectile> projectile(new Projectile(type, textures));

	sf::Vector2f offset(xOffset * mSprite.getGlobalBounds().width, yOffset * mSprite.getGlobalBounds().height);
	sf::Vector2f velocity(0, projectile->getMaxSpeed());

	float sign = isAllied() ? -1.f : +1.f;
	projectile->setPosition(getWorldPosition() + offset * sign);
	projectile->setVelocity(velocity * sign);
	node.attachChild(std::move(projectile));
}

void Aircraft::setAllyVelocity(float x,float y)
{
//	this->mch
}

void Aircraft::addCountDowm()
{
//	mCountDownNode->removeWrecks();

	std::unique_ptr<Flash> mflash(new Flash(*mCountDownTexture, Textures::Loop));		//���֮ǰ��circle�������µ�
//	mflash->setPosition(getPosition().x, getPosition().y-500);
	mCountDown = mflash.get();
//	mCountDownNode->attachChild(std::move(mflash));

	this->attachChild(std::move(mflash));
}

int Aircraft::getScore()
{
	return mScore;
}

void Aircraft::GetMissileORUpgradeFire()
{
	mTimeSincePurchase += mPlayerClock.restart();

	if (mTimeSincePurchase > mPurchaseCountDown)
	{
		if (mMenu.isEOpened())
		{
			if (mPoints - 2 >= 0 && mMissileAmmo < mMissileSlot)
			{
				mPoints -= 2;
				mMissileAmmo++;
				mSounds.play(SoundEffect::Purchase);
				mTimeSincePurchase = sf::seconds(0);
				addCountDowm();
			}
		}
		else if (mMenu.isQOpened() && mTimeSincePurchase>mPurchaseCountDown)
		{
			if (mPoints - FireRateCost >= 0)
			{

				if (increaseFireRate())
				{
					mPoints -= FireRateCost;
					mSounds.play(SoundEffect::Upgrade);
					FireRateCost = FireRateCost / 3 + 5 + FireRateCost;		//���������������
					mTimeSincePurchase = sf::seconds(0);
					addCountDowm();
				}

			}
		}
	}

}

void Aircraft::GetHpOrFirePile()
{
	mTimeSincePurchase += mPlayerClock.restart();
		if (mMenu.isEOpened())
		{
			if (mPoints - 5 >= 0 && getHitpoints()<100&& mTimeSincePurchase>mPurchaseCountDown)
			{
				repair(20);
				mPoints -= 5;
				mSounds.play(SoundEffect::Purchase);
				mTimeSincePurchase = sf::seconds(0);
				addCountDowm();
			}
		}
		else if (mMenu.isQOpened())
		{
			if (mPoints - FireSpreadCost >= 0 && mTimeSincePurchase>mPurchaseCountDown)
			{

				if (increaseSpread())
				{
					mPoints -= FireSpreadCost;
					mSounds.play(SoundEffect::Upgrade);
					FireSpreadCost = FireSpreadCost / 2 + 5 + FireSpreadCost;
					mTimeSincePurchase = sf::seconds(0);
					addCountDowm();
				}

			}
		}


}

void Aircraft::openEMenu()
{
	if (!mMenu.isEOpened())
	{
		mMenu.closeMenus();
		mMenu.openMenu(PlayerStatusMenu::Menus::EMenu);
	}
	else
	{
		mMenu.closeMenus();
	}
}

void Aircraft::openQMenu()
{
	if (!mMenu.isQOpened())
	{
		mMenu.closeMenus();
		mMenu.openMenu(PlayerStatusMenu::Menus::QMenu);
	}
	else
	{
		mMenu.closeMenus();
	}

}

void Aircraft::closeMenuOrUpgradeMissileSlot()
{
	mTimeSincePurchase += mPlayerClock.restart();
	if (mMenu.isEOpened())
	{
		mMenu.closeMenus();
	}
	else if (mMenu.isQOpened())
	{
		if ( mTimeSincePurchase>mPurchaseCountDown && mPoints - MissileSlotCost >= 0)
		{
			if (increaseMissileSlot())
			{
				mPoints -= MissileSlotCost;
				mSounds.play(SoundEffect::Upgrade);
				MissileSlotCost = 2*MissileSlotCost ;
				mTimeSincePurchase = sf::seconds(0);
				addCountDowm();
			}

		}
		
	}


}

void Aircraft::addPoints(int points)
{
	mPoints += points;
}

void Aircraft::updateScore(int scores)
{
	mScore = scores;
}

bool Aircraft::reborn()
{
	if (mScore >=500&& getHitpoints() <= 0)
	{
		setHP(60);
		mPlayer->setPlayerAlive();
		mScore -= 500;
		mSprite.setTexture(mOrigin);
		return true;
	}
	return false;
}

void Aircraft::restart()
{


}

