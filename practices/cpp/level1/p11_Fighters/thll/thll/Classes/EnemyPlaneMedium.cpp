#include "EnemyPlaneMedium.h"

USING_NS_CC;

EnemyPlaneMedium* EnemyPlaneMedium::create(const std::string& filename)
{
	EnemyPlaneMedium *sprite = new (std::nothrow) EnemyPlaneMedium();
	if (sprite && sprite->initWithFile(filename))
	{
		sprite->autorelease();
		return sprite;
	}
	CC_SAFE_DELETE(sprite);
	return nullptr;
}

int EnemyPlaneMedium::getLife()
{
	return this->life;
}

void EnemyPlaneMedium::lifeDecresed(int attack)
{
	this->life--;
}

bool EnemyPlaneMedium::isLifeEmpty()
{
	return this->life == 0;
}
