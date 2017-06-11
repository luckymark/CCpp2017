#include "BossLayer.h"

USING_NS_CC;

BossLayer* BossLayer::sharedBossLayer = nullptr;

BossLayer* BossLayer::create()
{
	BossLayer* pRet = new BossLayer();
	if (pRet && pRet->init())
	{
		pRet->autorelease();
		sharedBossLayer = pRet;
		return pRet;
	}
	else
	{
		CC_SAFE_DELETE(pRet);
		return NULL;
	}
}

bool BossLayer::init()
{
	if (!Layer::init())
	{
		return false;
	}

	return true;
}

void BossLayer::bossCreate()
{
	auto visibleSize = Director::getInstance()->getVisibleSize();

	boss = Boss::create("ui/shoot/enemy3_n1.png");
	boss->setPosition(Vec2(visibleSize.width / 2, visibleSize.height - boss->getContentSize().height / 2));
	boss->setTag(BOSS_TAG);
	this->addChild(boss);
	bossRunAction();
}

void BossLayer::bossRunAction()
{
	Vector<SpriteFrame*> animationframe;
	for (int i = 1; i <= 2; i++)
	{
		auto string = cocos2d::__String::createWithFormat("ui/shoot/enemy3_n%d.png", i);
		SpriteFrame * sf = SpriteFrame::create(string->getCString(), Rect(0, 0, 169, 258));
		animationframe.pushBack(sf);
	}
	Animation * ani = Animation::createWithSpriteFrames(animationframe, 0.1);

	Action * act = RepeatForever::create(Animate::create(ani));
	boss->runAction(act);
}

