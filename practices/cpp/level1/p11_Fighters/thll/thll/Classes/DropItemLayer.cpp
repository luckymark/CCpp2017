#include "DropItemLayer.h"

USING_NS_CC;

DropItemLayer* DropItemLayer::sharedDropItemLayer = nullptr;

DropItemLayer* DropItemLayer::create()
{
	DropItemLayer* pRet = new (std::nothrow) DropItemLayer();
	if (pRet && pRet->init())
	{
		pRet->autorelease();
		sharedDropItemLayer = pRet;
		return pRet;
	}
	else
	{
		CC_SAFE_DELETE(pRet);
		return NULL;
	}
}

bool DropItemLayer::init()
{
	if (!Layer::init())
	{
		return false;
	}

	return true;
}

void DropItemLayer::createDrop()
{
	auto visibleSize = Director::getInstance()->getVisibleSize();

	int n = rand() % 2 + 1;
	String* str = String::createWithFormat("ui/shoot/ufo%d.png", n);
	auto drop = Sprite::create(str->getCString());
	int x = rand() % 370 + 30;
	drop->setPosition(Vec2(x, visibleSize.height));
	if (n == 1) 
	{
		drop->setTag(DROP_TYPE_1_TAG);
	}
	else
	{
		drop->setTag(DROP_TYPE_2_TAG);
	}
	this->addDrop(drop);
	this->addChild(drop);
}

void DropItemLayer::addDrop(Sprite * sprite)
{
	this->dropList.pushBack(sprite);
}

void DropItemLayer::dropMove()
{
	for (int i = 0; i < this->dropList.size(); i++)
	{
		auto drop = dropList.at(i);
		drop->setPositionY(drop->getPositionY() - 3);
	}
}

cocos2d::Vector<Sprite*> DropItemLayer::getDropList()
{
	return this->dropList;
}

void DropItemLayer::removeDrop(Sprite * sprite)
{
	this->dropList.eraseObject(sprite);
}
