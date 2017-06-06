#include "EnemyPlaneLayer.h"

#include "cstdlib"

USING_NS_CC;
EnemyPlaneLayer* EnemyPlaneLayer::sharedEnemy = nullptr;

EnemyPlaneLayer* EnemyPlaneLayer::create()
{
	EnemyPlaneLayer *pRet = new EnemyPlaneLayer();
	if (pRet && pRet->init()) {
		pRet->autorelease();
		sharedEnemy = pRet;
		return pRet;
	}
	else {
		CC_SAFE_DELETE(pRet);
		return NULL;
	}
}

Scene* EnemyPlaneLayer::createScene()
{
	auto scene = Scene::create();

	auto layer = EnemyPlaneLayer::create();

	scene->addChild(layer);

	return scene;
}

bool EnemyPlaneLayer::init()
{
	if (!Layer::init())
	{
		return false;
	}

}

void EnemyPlaneLayer::enemyMove()
{
	auto winSize = Director::getInstance()->getWinSize();

	for (int i = 0; i < enemyList.size(); i++)
	{
		auto enemy = enemyList.at(i);
		if(!enemy->isDeleted())enemy->setPositionY(enemy->getPositionY() - 5);
		if (enemy->getPositionY() < 0)
		{
			enemy->removeFromParent();
			enemyList.eraseObject(enemy);	
			i--;
		}
	}
}

void EnemyPlaneLayer::enemyCreate()
{
	int rnd = rand() % 2 + 1;

	auto strings = cocos2d::__String::createWithFormat("enemy%d.png", rnd);
	auto enemy = EnemyPlane::create(strings->getCString());

	if (rnd == 1)
	{
		enemy->setTag(ENEMY_TYPE_1_TAG);
	}
	else
	{
		enemy->setTag(ENEMY_TYPE_2_TAG);
	}

	enemy->setPosition(Vec2(rand() % (int)(Director::getInstance()->getVisibleSize().width), Director::getInstance()->getVisibleSize().height));

	this->addChild(enemy);
	this->enemyList.pushBack(enemy);
}

Vector<EnemyPlane* > EnemyPlaneLayer::getEnemyList()
{
	return this->enemyList;
}

void EnemyPlaneLayer::enemyShoting()
{
	BulletLayer::sharedBullet->enemyBulletCreate();
}