#include "BulletLayer.h"

USING_NS_CC;

BulletLayer* BulletLayer::sharedBullet = nullptr;

BulletLayer* BulletLayer::create()
{
	BulletLayer *pRet = new BulletLayer();
	if (pRet && pRet->init()) {
		pRet->autorelease();
		sharedBullet = pRet;
		return pRet;
	}
	else {
		CC_SAFE_DELETE(pRet);
		return NULL;
	}
}

Scene* BulletLayer::createScene()
{
	auto scene = Scene::create();

	auto layer = BulletLayer::create();

	scene->addChild(layer);

	return scene;
}

bool BulletLayer::init()
{
	if (!Layer::init())
	{
		return false;
	}
	return true;
}

void BulletLayer::bulletMove()
{
	auto winSize = Director::getInstance()->getWinSize();
	for (int i = 0; i < bulletList.size(); i++)
	{
		auto bullet = bulletList.at(i);
		auto tag = bullet->getTag();

		if (tag == PLANE_BULLET_TAG)
		{
			bullet->setPositionY(bullet->getPositionY() + 3);
			if (bullet->getPositionY() > winSize.height)
			{
				bulletList.eraseObject(bullet);
				bullet->removeFromParent();
				i--;
			}
		}
		else if (tag == ENEMY_BULLET_TAG)
		{
			bullet->setPositionY(bullet->getPositionY() - 3);
			if (bullet->getPositionY() < 0)
			{
				bulletList.eraseObject(bullet);
				bullet->removeFromParent();
				i--;
			}
		}

	}
}

void BulletLayer::bulletCreate()
{

	auto key_z = EventKeyboard::KeyCode::KEY_Z;
	auto plane = SelfPlaneLayer::sharedPlaneLayer->getChildByTag(PLANE_TAG);

	auto bullet = Sprite::create("bullet.png");

	bullet->setPosition(plane->getPositionX(), plane->getPositionY() + 30);
	bullet->setTag(PLANE_BULLET_TAG);

	this->addChild(bullet);
	bulletList.pushBack(bullet);
}

void BulletLayer::enemyBulletCreate()
{
	auto enemyList = EnemyPlaneLayer::sharedEnemy->getEnemyList();

	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("enemy_bullet.plist");

	for (int i = 0; i < enemyList.size(); i++)
	{
		auto bullet = Sprite::createWithSpriteFrameName("W2.png");

		auto enemy = enemyList.at(i);

		bullet->setPosition(enemy->getPositionX(), enemy->getPositionY() - 30);
		bullet->setTag(ENEMY_BULLET_TAG);

		this->addChild(bullet);
		bulletList.pushBack(bullet);
	}
}

Vector<Sprite* > BulletLayer::getBulletList()
{
	return this->bulletList;
}

void BulletLayer::bulletRemove(Sprite* sprite)
{
	sprite->removeFromParent();
	this->bulletList.eraseObject(sprite);
}