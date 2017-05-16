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

	plane = Sprite::create("plane1.png");
	plane->setPosition(Vec2(Director::getInstance()->getVisibleSize().width / 2, Director::getInstance()->getVisibleSize().height / 2));

	this->addChild(plane);

	auto dispatcher = Director::getInstance()->getEventDispatcher();
	auto listener = EventListenerKeyboard::create();

	listener->onKeyPressed = CC_CALLBACK_2(GameScene::onKeyPressed, this);
	listener->onKeyReleased = CC_CALLBACK_2(GameScene::onKeyReleased, this);
	
	dispatcher->addEventListenerWithSceneGraphPriority(listener, this);

	this->scheduleUpdate();

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

	auto moveTo = MoveTo::create(0.1 /* times*/, Vec2(plane->getPositionX() + offsetX, plane->getPositionY() + offsetY));
	plane->runAction(moveTo);

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