#include "SelfPlane.h"

USING_NS_CC;

SelfPlane* SelfPlane::sharedPlane = nullptr;

SelfPlane* SelfPlane::create(const std::string& filename)
{
	SelfPlane *sprite = new (std::nothrow) SelfPlane();
	if (sprite && sprite->initWithFile(filename))
	{
		sprite->autorelease();
		sharedPlane = sprite;
		return sprite;
	}
	CC_SAFE_DELETE(sprite);
	return nullptr;
}

bool SelfPlane::init()
{
	if (Sprite::init())
	{
		return false;
	}

	return true;
}

void SelfPlane::lifeDecreased()
{
	if (this->life - 1 < 0)
	{
		this->life = 0;
	}
	else
	{
		this->life -= 1;
	}
}

bool SelfPlane::isLifeEmpty()
{
	return this->life == 0;
}

void SelfPlane::setInitialPosition()
{
	auto visibleSize = Director::getInstance()->getVisibleSize();

	this->setPosition(Vec2(visibleSize.width / 2.0, this->getContentSize().height / 2.0));
}

void SelfPlane::addScore(int score)
{
	this->score += score;
	if (this->score >= PLANE_LEVEL_1_SCORE && this->score <= PLANE_LEVEL_2_SCORE)
	{
		setLevel(1);
	}
	else if (this->score >= PLANE_LEVEL_2_SCORE && this->score <= PLANE_LEVEL_3_SCORE)
	{
		setLevel(2);
	}
	else if (this->score >= PLANE_LEVEL_3_SCORE)
	{
		setLevel(3);
	}
}

int SelfPlane::getScore()
{
	return this->score;
}

void SelfPlane::setNullPosition()
{
	this->setPosition(Vec2(-10, -10));
}

void SelfPlane::setDead()
{
	this->setNullPosition();
	this->setVisible(false);
	this->status = STATUS_DEAD;
}

void SelfPlane::setReborn(long time)
{
	this->setVisible(true);
	this->setInitialPosition();
	this->lifeDecreased();
	this->reborn_time = time;
	this->status = STATUS_SURVIVAL;
}

bool SelfPlane::getIsDead()
{
	return this->is_dead;
}

int SelfPlane::getStatus(long time)
{
	if (reborn_time + 5000 > time)
	{
		return STATUS_NO_ATTCK;
	}
	else
	{
		return status;
	}
	
}

int SelfPlane::getLevel()
{
	return this->level;
}

void SelfPlane::levelUp()
{
	this->level++;
}

void SelfPlane::setLevel(int level)
{
	this->level = level;
}

int SelfPlane::getLife()
{
	return this->life;
}

