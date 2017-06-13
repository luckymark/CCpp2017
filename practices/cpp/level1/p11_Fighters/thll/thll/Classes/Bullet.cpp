#include "Bullet.h"

USING_NS_CC;

Bullet::Bullet() :value(0x123456789ABCDE0)
{

}

Bullet::~Bullet()
{
	value = 0;
}

Bullet* Bullet::create(const std::string& filename)
{
	Bullet *sprite = new (std::nothrow) Bullet();
	if (sprite && sprite->initWithFile(filename))
	{
		sprite->autorelease();
		return sprite;
	}
	CC_SAFE_DELETE(sprite);
	return nullptr;
}

Bullet* Bullet::createWithSpriteFrameName(const std::string& spriteFrameName)
{
	SpriteFrame *spriteFrame = SpriteFrameCache::getInstance()->getSpriteFrameByName(spriteFrameName);
	Bullet *sprite = new (std::nothrow) Bullet();
	if (sprite && spriteFrame && sprite->initWithSpriteFrame(spriteFrame))
	{
		sprite->autorelease();
		return sprite;
	}
	CC_SAFE_DELETE(sprite);
	return nullptr;
}

int Bullet::getType()
{
	return this->type;
}

void Bullet::setType(int type)
{
	this->type = type;
}

int Bullet::getDirection()
{
	return this->direction;
}

void Bullet::setDirection(int dir)
{
	this->direction = dir;
}

bool Bullet::isWilder()
{
	return value == 0x123456789ABCDE0;
}

bool Bullet::init()
{
	if (Bullet::init())
	{
		return false;
	}

	return true;
}