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
		bullet->setPositionY(bullet->getPositionY() + 3);
		if (bullet->getPositionY() > winSize.height)
		{
			bulletList.eraseObject(bullet);
			bullet->removeFromParent();
			i--;
		}
	}
}

void BulletLayer::bulletCreate()
{

	auto key_z = EventKeyboard::KeyCode::KEY_Z;
	auto plane = SelfPlaneLayer::sharedPlane->getChildByTag(PLANE_TAG);

	auto bullet = Sprite::create("bullet.png");

	bullet->setPosition(plane->getPositionX(), plane->getPositionY() + 30);
	bullet->setTag(BULLET_TAG);

	this->addChild(bullet);
	bulletList.pushBack(bullet);
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