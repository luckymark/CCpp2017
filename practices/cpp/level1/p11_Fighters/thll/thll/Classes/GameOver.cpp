#include "GameOver.h"

USING_NS_CC;

Scene* GameOver::createScene()
{
	auto scene = Scene::create();

	auto layer = GameOver::create();

	scene->addChild(layer);

	return scene;
}

bool GameOver::init()
{
	if (!Layer::init())
	{
		return false;
	}

	auto visibleSize = Director::getInstance()->getVisibleSize();

	Sprite* back = Sprite::create("ui/shoot_background/gameover.png");

	back->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));

	this->addChild(back, 0);

	String* str = String::createWithFormat("%d", SelfPlane::sharedPlane->getScore());
	auto score = LabelBMFont::create(str->getCString(), "font/font.fnt");
	score->setColor(Color3B::GRAY);
	score->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));

	this->addChild(score);

	return true;
}
