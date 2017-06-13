#include "BombSplashScreen.h"

USING_NS_CC;

Scene* BombSplashScreen::createScene(RenderTexture* sqr)
{
	auto scene = Scene::create();

	auto layer = BombSplashScreen::create();

	scene->addChild(layer, 2);

	Size visibleSize = Director::sharedDirector()->getVisibleSize();

	Sprite *back_spr = Sprite::createWithTexture(sqr->getSprite()->getTexture());

	back_spr->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));

	back_spr->setFlipY(true);

	back_spr->setColor(Color3B::GRAY);

	scene->addChild(back_spr, 0);

	return scene;
}

BombSplashScreen* BombSplashScreen::create()
{
	BombSplashScreen* pRet = new BombSplashScreen();
	if (pRet && pRet->init())
	{
		pRet->autorelease();
		return pRet;
	}
	else
	{
		CC_SAFE_DELETE(pRet);
		return NULL;
	}
}

bool BombSplashScreen::init()
{
	if (!Layer::init())
	{
		return false;
	}

	auto visibleSize = Director::getInstance()->getVisibleSize();

	auto listener = EventListenerKeyboard::create();

	auto splash = Sprite::create("ui/shoot/LL.png");
	splash->setPosition(Vec2(visibleSize.width / 2 + 10,visibleSize.height / 2));
	splash->setOpacity(0);

	ActionInterval *forwardIn = FadeIn::create(1);
	ActionInterval *backIn = forwardIn->reverse();
	Action *actionIn = Sequence::create(forwardIn, backIn, CCCallFunc::create(this, callfunc_selector(BombSplashScreen::callBackFade)), NULL);

	splash->runAction(actionIn);

	this->addChild(splash);

	return true;
}

void BombSplashScreen::callBackFade()
{
	EnemyPlaneLayer::sharedEnemy->emptyAllEnemy();
	BulletLayer::sharedBulletLayer->emeptyAllEnemyBullet();
	SelfPlane::sharedPlane->bombDecresed();
	Director::getInstance()->popScene();
}