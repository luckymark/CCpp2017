#include "GameMenu.h"

USING_NS_CC;

Scene* GameMenu::createScene()
{
	auto scene = Scene::create();

	auto layer = GameMenu::create();

	scene->addChild(layer);

	return scene;
}

bool GameMenu::init()
{
	if (!Layer::init())
	{
		return false;
	}

	auto visibleOrigin = Director::getInstance()->getVisibleOrigin();
	auto visibleSize = Director::getInstance()->getVisibleSize();

	// music prepare
	Audio::getInstance()->prepare();

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

	// create logo
	auto logo = Sprite::create("ui/shoot_background/shoot_copyright.png");
	logo->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 4 * 3));
	this->addChild(logo);

	// create menu
	auto menu = Menu::create();

	auto menuStart = MenuItemImage::create("ui/shoot_background/game_start.png","ui/shoot_background/game_start2.png", CC_CALLBACK_1(GameMenu::menuStartCallBack, this));

	auto menuEnd = MenuItemImage::create("ui/shoot_background/game_exit.png", "ui/shoot_background/game_exit.png", CC_CALLBACK_1(GameMenu::menuEndCallBack, this));

	menu->addChild(menuStart);
	menu->addChild(menuEnd);
	menu->alignItemsVerticallyWithPadding(40);
	menu->setPosition(Director::getInstance()->getVisibleSize().width / 2, Director::getInstance()->getVisibleSize().height / 2);

	this->addChild(menu);

	this->schedule(schedule_selector(GameMenu::updateMenu), GAME_UPDATE_SEC);
	return true;
}

void GameMenu::menuStartCallBack(Ref* ref)
{
	auto game = GameLoading::createScene();
	
	Director::getInstance()->replaceScene(game);
}

void GameMenu::menuEndCallBack(Ref* ref)
{

}

void GameMenu::updateMenu(float dt)
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
