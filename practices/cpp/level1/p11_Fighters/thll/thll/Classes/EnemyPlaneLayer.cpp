#include "EnemyPlaneLayer.h"

#include "cstdlib"

USING_NS_CC;

bool EnemyPlaneLayer::init()
{
	if (!Layer::init())
	{
		return false;
	}

	this->schedule(schedule_selector(EnemyPlaneLayer::enemyCreate), 1);
	this->schedule(schedule_selector(EnemyPlaneLayer::enemyMove), 0.05);
}

void EnemyPlaneLayer::enemyMove(float dt)
{
	auto winSize = Director::getInstance()->getWinSize();

	for (int i = 0; i < enemyList.size(); i++)
	{
		auto enemy = enemyList.at(i);
		enemy->setPositionY(enemy->getPositionY() - 5);
		if (enemy->getPositionY() < 0)
		{
			enemyList.eraseObject(enemy);
			enemy->removeFromParent();
			i--;
		}
	}
}

void EnemyPlaneLayer::enemyCreate(float dt)
{
	int rnd = rand() % 2 + 1;

	auto strings = cocos2d::__String::createWithFormat("enemy%d.png", rnd);
	auto enemy = Sprite::create(strings->getCString());

	if (rnd == 1)
	{
		enemy->setTag(ENEMY_TYPE_1_TAG);
	}
	else
	{
		enemy->setTag(ENEMY_TYPE_2_TAG);
	}

	enemy->setPosition(Vec2(rand() % (int)(Director::getInstance()->getVisibleSize().width), Director::getInstance()->getVisibleSize().height));

	auto enemyBody = PhysicsBody::createBox(enemy->getContentSize());        
	enemyBody->setContactTestBitmask(0x0003);
	enemyBody->setCategoryBitmask(0x0002);
	enemyBody->setCollisionBitmask(0x0001);
	enemyBody->setGravityEnable(false);
	enemy->setPhysicsBody(enemyBody);

	this->addChild(enemy);
	this->enemyList.pushBack(enemy);
}