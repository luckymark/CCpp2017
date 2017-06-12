#include "GameLoading.h"

USING_NS_CC;

Scene* GameLoading::createScene()
{
	auto scene = Scene::create();
	auto layer = GameLoading::create();
	scene->addChild(layer);
	return scene;
}

bool GameLoading::init()
{
	if (!Layer::init())
	{
		return false;
	}

	auto visibleOrigin = Director::getInstance()->getVisibleOrigin();
	auto visibleSize = Director::getInstance()->getVisibleSize();

	// create backgroud
	auto bg1 = Sprite::create("ui/shoot_background/background.png");
	bg1->setPosition(Vec2(visibleOrigin.x + visibleSize.width / 2, 0));
	bg1->setAnchorPoint(Vec2(0.5, 0));
	bg1->setTag(BG_1_TAG);
	this->addChild(bg1, 0);
	auto bg2 = Sprite::create("ui/shoot_background/background.png");
	bg2->setPosition(Vec2(visibleOrigin.x + visibleSize.width / 2, bg1->getPositionY() + bg1->getContentSize().height));
	bg2->setAnchorPoint(Vec2(0.5, 0));
	bg2->setTag(BG_2_TAG);
	this->addChild(bg2, 0);

	float dt = 1;
	Vector<SpriteFrame*> animationframe;
	for (int i = 1; i <= 4; i++)
	{
		auto string = cocos2d::__String::createWithFormat("ui/shoot_background/game_loading%d.png", i);
		SpriteFrame * sf = SpriteFrame::create(string->getCString(), Rect(0, 0, 186, 38));
		animationframe.pushBack(sf);
	}
	this->schedule(schedule_selector(GameLoading::updateBackground), GAME_UPDATE_SEC);
	Animation * ani = Animation::createWithSpriteFrames(animationframe, dt);
	auto blanksprite = Sprite::create();

	Action * act = Sequence::create(Animate::create(ani), CCCallFunc::create(this, callfunc_selector(GameLoading::loadingFinishedCallBack)), NULL);
	this->addChild(blanksprite);
	blanksprite->setPosition(visibleSize / 2);
	blanksprite->runAction(act);

	return true;
}

void GameLoading::updateBackground(float dt)
{
	// background move
	auto bg1 = this->getChildByTag(BG_1_TAG);
	auto bg2 = this->getChildByTag(BG_2_TAG);
	if (bg2->getPositionY() + bg2->getContentSize().height <= Director::getInstance()->getVisibleSize().height)
	{
		bg1->setPositionY(-bg1->getContentSize().height + Director::getInstance()->getVisibleSize().height);
	}
	bg1->setPositionY(bg1->getPositionY() - 3);
	bg2->setPositionY(bg1->getPositionY() + bg1->getContentSize().height);
}

void GameLoading::loadingFinishedCallBack()
{
	Director::getInstance()->replaceScene(GameScene::createScene());
}
