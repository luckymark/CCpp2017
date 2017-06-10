#include "EnemyPlane.h"

USING_NS_CC;

EnemyPlane* EnemyPlane::create(const std::string& filename)
{
	EnemyPlane *sprite = new (std::nothrow) EnemyPlane();
	if (sprite && sprite->initWithFile(filename))
	{
		sprite->autorelease();
		return sprite;
	}
	CC_SAFE_DELETE(sprite);
	return nullptr;
}

void EnemyPlane::setDeleted(bool is)
{
	this->deleted = is;
}

bool EnemyPlane::isDeleted()
{
	return deleted;
}
