#include "Boss.h"

USING_NS_CC;

Boss* Boss::sharedBoss = nullptr;

Boss* Boss::create(const std::string& filename)
{
	Boss* pRet = new (std::nothrow) Boss();

	if (pRet && pRet->initWithFile(filename) )
	{
		pRet->autorelease();
		sharedBoss = pRet;
		return pRet;
	}
	else
	{
		CC_SAFE_DELETE(pRet);
		return NULL;
	}
}

Boss * Boss::createWithSpriteFrameName(const std::string & spriteFrameName)
{
	SpriteFrame *spriteFrame = SpriteFrameCache::getInstance()->getSpriteFrameByName(spriteFrameName);
	Boss *sprite = new (std::nothrow) Boss();
	if (sprite && spriteFrame && sprite->initWithSpriteFrame(spriteFrame))
	{
		sprite->autorelease();
		return sprite;
	}
	CC_SAFE_DELETE(sprite);
	return nullptr;
}

Boss* Boss::create()
{
	Boss* pRet = new (std::nothrow) Boss();

	if (pRet && pRet->init())
	{
		pRet->autorelease();
		sharedBoss = pRet;
		return pRet;
	}
	else
	{
		CC_SAFE_DELETE(pRet);
		return NULL;
	}
}

bool Boss::init()
{
	if (!Sprite::init())
	{
		return false;
	}

	return true;
}

void Boss::setDeleted(bool is)
{
	this->deleted = is;
}

bool Boss::isDeleted()
{
	return this->deleted;
}

void Boss::lifeDecreased(int attack)
{
	this->life--;
}

bool Boss::isLifeEmpty()
{
	return this->life == 0;
}
