#include "GamePauseLayer.h"

USING_NS_CC;

Scene* GamePauseLayer::createScene(RenderTexture* sqr)
{
	auto scene = Scene::create();

	auto layer = GamePauseLayer::create();

	scene->addChild(layer, 2);

	Size visibleSize = Director::sharedDirector()->getVisibleSize();

	Sprite *back_spr = Sprite::createWithTexture(sqr->getSprite()->getTexture());

	back_spr->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));

	back_spr->setFlipY(true);

	back_spr->setColor(Color3B::GRAY);

	scene->addChild(back_spr, 0);

	return scene;
}

GamePauseLayer* GamePauseLayer::create()
{
	GamePauseLayer* pRet = new GamePauseLayer();
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

bool GamePauseLayer::init()
{
	if (!Layer::init())
	{
		return false;
	}

	auto visibleSize = Director::getInstance()->getVisibleSize();

	auto menu = Menu::create();
	auto btn_resume = MenuItemImage::create("ui/shoot_background/btn_finish.png", "ui/shoot_background/btn_finish.png", CC_CALLBACK_0(GamePauseLayer::buttonResumeCallBack, this));
	menu->addChild(btn_resume);

	auto btn_return = MenuItemImage::create("ui/shoot/game_resume_nor.png", "ui/shoot/game_resume_pressed.png", CC_CALLBACK_0(GamePauseLayer::buttonReturnCallBack, this));
	btn_return->setRotation(180);
	menu->addChild(btn_return);

	menu->alignItemsVerticallyWithPadding(40);
	menu->setPosition(visibleSize / 2);

	this->addChild(menu,3);

	return true;
}

void GamePauseLayer::buttonResumeCallBack()
{
	Director::getInstance()->popScene();
}

void GamePauseLayer::buttonReturnCallBack()
{
	//Director::getInstance()->replaceScene(GameMenu::createScene());
}
