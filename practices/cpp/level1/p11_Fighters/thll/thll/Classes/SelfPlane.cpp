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