#include "GameMenu.h"
#include "GameScene.h"

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

	// create menu
	auto menu = Menu::create();

	auto menuStart = MenuItemFont::create("Start Game", CC_CALLBACK_1(GameMenu::menuStartCallBack, this));
	menuStart->setFontSizeObj(15);

	auto menuEnd = MenuItemFont::create("End Game", CC_CALLBACK_1(GameMenu::menuEndCallBack, this));
	menuEnd->setFontSizeObj(15);

	menu->addChild(menuStart);
	menu->addChild(menuEnd);
	menu->alignItemsVerticallyWithPadding(40);
	menu->setPosition(Director::getInstance()->getVisibleSize().width * 7 / 8, Director::getInstance()->getVisibleSize().height / 2);

	this->addChild(menu);

	return true;
}

void GameMenu::menuStartCallBack(Ref* ref)
{
	auto game = GameScene::createScene();
	
	Director::getInstance()->replaceScene(game);
}

void GameMenu::menuEndCallBack(Ref* ref)
{

}