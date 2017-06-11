#include "SelfPlaneLayer.h"

USING_NS_CC;

SelfPlaneLayer* SelfPlaneLayer::sharedPlaneLayer = nullptr;

SelfPlaneLayer* SelfPlaneLayer::create()
{
	SelfPlaneLayer *pRet = new SelfPlaneLayer();
	if (pRet && pRet->init()) {
		pRet->autorelease();
		sharedPlaneLayer = pRet;
		return pRet;
	}
	else {
		CC_SAFE_DELETE(pRet);
		return NULL;
	}
}

Scene* SelfPlaneLayer::createScene()
{
	auto scene = Scene::create();
	auto layer = SelfPlaneLayer::create();

	scene->addChild(layer);
	
	return scene;
}

bool SelfPlaneLayer::init()
{
	if (!Layer::init())
	{
		return false;
	}

	auto visibleSize = Director::getInstance()->getVisibleSize();
	auto visibleOrigin = Director::getInstance()->getVisibleOrigin();
	auto winSize = Director::getInstance()->getWinSize();

	auto plane = SelfPlane::create("ui/shoot/hero1.png");
	plane->setTag(PLANE_TAG);
	plane->setInitialPosition();
	plane->setAnchorPoint(Vec2(0.5, 0.5));

	this->addChild(plane);

	planeRunAction();

	auto listener = EventListenerKeyboard::create();

	listener->onKeyPressed = CC_CALLBACK_2(SelfPlaneLayer::onKeyPressed, this);
	listener->onKeyReleased = CC_CALLBACK_2(SelfPlaneLayer::onKeyReleased, this);

	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, plane);

	//this->scheduleUpdate();
	//this->schedule(schedule_selector(SelfPlaneLayer::bulletCreate), 0.01);

	return true;
}

void SelfPlaneLayer::planeUpdate(float  delta)
{
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

void SelfPlaneLayer::keyPressedDuration(EventKeyboard::KeyCode keyCode)
{
	auto visibleSize = Director::getInstance()->getVisibleSize();
	auto visibleOrigin = Director::getInstance()->getVisibleOrigin();
	auto winSize = Director::getInstance()->getWinSize();

	auto plane = this->getChildByTag(PLANE_TAG);

	int offsetX = 0, offsetY = 0;
	switch (keyCode)
	{
	case EventKeyboard::KeyCode::KEY_LEFT_ARROW:
		offsetX = -OFFSET;
		break;
	case EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
		offsetX = OFFSET;
		break;
	case EventKeyboard::KeyCode::KEY_UP_ARROW:
		offsetY = OFFSET;
		break;
	case EventKeyboard::KeyCode::KEY_DOWN_ARROW:
		offsetY = -OFFSET;
		break;
	default:
		offsetX = 0;
		offsetY = 0;
		break;
	}

	float totX = plane->getPositionX() + offsetX, totY = plane->getPositionY() + offsetY;

	float sizeX = plane->getContentSize().width / 2.0, sizeY = plane->getContentSize().height / 2.0;

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

void SelfPlaneLayer::onKeyPressed(EventKeyboard::KeyCode keyCode, Event* event)
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

void SelfPlaneLayer::onKeyReleased(EventKeyboard::KeyCode keyCode, Event* event)
{
	keys[keyCode] = false;
}

bool SelfPlaneLayer::isKeyPressed(EventKeyboard::KeyCode keyCode)
{
	return keys[keyCode];
}

void SelfPlaneLayer::startShooting()
{
	auto key_z = EventKeyboard::KeyCode::KEY_Z;
	auto bulletLayer = BulletLayer::sharedBulletLayer;
	if (isKeyPressed(key_z))
	{
		bulletLayer->bulletCreate();
		/*if (EnemyPlaneLayer::sharedEnemy->getEnemyList().size() != 0)
		{
			bulletLayer->autoBulletCreate();
		}*/
		
	}
}
void SelfPlaneLayer::planeRunAction()
{
	Vector<SpriteFrame*> animationframe;
	for (int i = 1; i <= 2; i++)
	{
		auto string = cocos2d::__String::createWithFormat("ui/shoot/hero%d.png", i);
		SpriteFrame * sf = SpriteFrame::create(string->getCString(), Rect(0, 0, 102, 126));
		animationframe.pushBack(sf);
	}
	Animation * ani = Animation::createWithSpriteFrames(animationframe, 0.1);

	Action * act = RepeatForever::create(Animate::create(ani));
	SelfPlane::sharedPlane->runAction(act);
}

Node* SelfPlaneLayer::getPlane()
{
	return this->getChildByTag(PLANE_TAG);
}