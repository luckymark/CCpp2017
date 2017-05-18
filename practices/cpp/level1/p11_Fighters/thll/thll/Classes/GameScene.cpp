#include "GameScene.h"

#define OFFSET 5

USING_NS_CC;

Scene* GameScene::createScene()
{
	auto scene = Scene::create();

	auto layer = GameScene::create();

	scene->addChild(layer);

	return scene;
}

bool GameScene::init()
{

	if (!Layer::init())
	{
		return false;
	}

	auto visibleSize = Director::getInstance()->getVisibleSize();
	auto visibleOrigin = Director::getInstance()->getVisibleOrigin();

	auto plane = Sprite::create("hero1.png");
	plane->setTag(PLANE_TAG);
	plane->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
	plane->setAnchorPoint(Vec2(0.5, 0.5));

	this->addChild(plane);

	auto dispatcher = Director::getInstance()->getEventDispatcher();
	auto listener = EventListenerKeyboard::create();

	listener->onKeyPressed = CC_CALLBACK_2(GameScene::onKeyPressed, this);
	listener->onKeyReleased = CC_CALLBACK_2(GameScene::onKeyReleased, this);
	
	dispatcher->addEventListenerWithSceneGraphPriority(listener, this);

	this->scheduleUpdate();
	this->schedule(schedule_selector(GameScene::bulletCreate), 0.1);
	this->schedule(schedule_selector(GameScene::bulletMove), 0.05);

	return true;
}

void GameScene::update(float  delta)
{
	Node::update(delta);

	auto left = EventKeyboard::KeyCode::KEY_LEFT_ARROW;
	auto right = EventKeyboard::KeyCode::KEY_RIGHT_ARROW;
	auto up = EventKeyboard::KeyCode::KEY_UP_ARROW;
	auto down = EventKeyboard::KeyCode::KEY_DOWN_ARROW;

	if (isKeyPressed(left))
	{
		keyPressedDuration(left);
	}
	if (isKeyPressed(right))
	{
		keyPressedDuration(right);
	}
	if (isKeyPressed(up))
	{
		keyPressedDuration(up);
	}
	if (isKeyPressed(down))
	{
		keyPressedDuration(down);
	}
}

void GameScene::keyPressedDuration(EventKeyboard::KeyCode keyCode)
{
	auto visibleSize = Director::getInstance()->getVisibleSize();
	auto visibleOrigin = Director::getInstance()->getVisibleOrigin();
	auto winSize = Director::getInstance()->getWinSize();

	auto plane = this->getChildByTag(PLANE_TAG);

	int offsetX = 0, offsetY = 0;
	switch (keyCode)
	{
	case EventKeyboard::KeyCode::KEY_LEFT_ARROW:
		offsetX = - OFFSET;
		break;
	case EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
		offsetX = OFFSET;
		break;
	case EventKeyboard::KeyCode::KEY_UP_ARROW:
		offsetY = OFFSET;
		break;
	case EventKeyboard::KeyCode::KEY_DOWN_ARROW:
		offsetY = - OFFSET;
		break;
	default:
		offsetX = 0;
		offsetY = 0;
		break;
	}

	float totX = plane->getPositionX() + offsetX, totY = plane->getPositionY() + offsetY;

	float sizeX = plane->getContentSize().width, sizeY = plane->getContentSize().height / 2.0;

	if (totX >  winSize.width - sizeX)
	{
		totX = winSize.width - sizeX;
	}
	else if (totX < sizeX)
	{
		totX = sizeX;
	}
	if (totY > winSize.height - sizeY)
	{
		totY = winSize.height - sizeY;
	}
	else if (totY < sizeY)
	{
		totY = sizeY;
	}
	plane->setPosition(Vec2(totX, totY));
}

void GameScene::onKeyPressed(EventKeyboard::KeyCode keyCode, Event* event)
{
	// up 28
	// left 26
	// right 27
	// down 29
	// z 149
	// x 147
	// space 59
	// enter 164 & 35
	keys[keyCode] = true;
}

void GameScene::onKeyReleased(EventKeyboard::KeyCode keyCode, Event* event)
{
	keys[keyCode] = false;
}

bool GameScene::isKeyPressed(EventKeyboard::KeyCode keyCode)
{
	return keys[keyCode];
}

void GameScene::bulletCreate(float f)
{

	auto key_z = EventKeyboard::KeyCode::KEY_Z;
	auto plane = this->getChildByTag(PLANE_TAG);

	if (isKeyPressed(key_z))
	{
		auto bullet = Sprite::create("bullet.png");

		bullet->setPosition(plane->getPositionX(), plane->getPositionY() + 30);
		bullet->setTag(BULLET_TAG);

		this->addChild(bullet);
		this->bulletList.pushBack(bullet);
	}

}

void GameScene::bulletMove(float f)
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