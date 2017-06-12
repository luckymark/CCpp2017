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
	boss->setPosition(Vec2(visibleSize.width / 2, visibleSize.height - boss->getContentSize().height / 4 * 3));
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

void BossLayer::bossMove(int progress)
{
	auto visibleSize = Director::getInstance()->getVisibleSize();

	if (progress == 1)
	{
		ActionInterval* forward = MoveBy::create(2, Vec2(- visibleSize.width / 2, - visibleSize.height / 4));
		ActionInterval* back = forward->reverse();
		Action* action = Sequence::create(forward, back, NULL);
		boss->runAction(action);
	}
	else if(progress == 2)
	{
		ActionInterval* forward = MoveBy::create(2, Vec2(visibleSize.width / 2, -visibleSize.height / 4));
		ActionInterval* back = forward->reverse();
		Action* action = Sequence::create(forward, back, NULL);
		boss->runAction(action);
	}
	else if (progress == 3)
	{
		ccBezierConfig tr0;
		tr0.endPosition = Vec2(visibleSize.width, visibleSize.height / 2);
		tr0.controlPoint_1 = Vec2(visibleSize.width / 2, visibleSize.height / 2);
		tr0.controlPoint_2 = Vec2(visibleSize.width / 3, visibleSize.height / 3);

		ActionInterval* bezierForward = BezierTo::create(3.f, tr0);
		ActionInterval *forwardBy = RotateBy::create(3.f, -180);

		ccBezierConfig tr1;
		tr1.endPosition = boss->getPosition();
		tr1.controlPoint_1 = Vec2(visibleSize.width / 2, visibleSize.height / 2);
		tr1.controlPoint_2 = Vec2(visibleSize.width / 3, visibleSize.height / 3);

		ActionInterval* bezierForward2 = BezierTo::create(3.f, tr1);
		ActionInterval *forwardBy2 = RotateBy::create(3.f, -180);

		ccBezierConfig tr2;
		tr2.endPosition = Vec2(0, visibleSize.height / 2);
		tr2.controlPoint_1 = Vec2(visibleSize.width / 2, visibleSize.height / 2);
		tr2.controlPoint_2 = Vec2(visibleSize.width / 3, visibleSize.height / 3);

		ActionInterval* bezierForward3 = BezierTo::create(3.f, tr2);
		ActionInterval *forwardBy3 = RotateBy::create(3.f, -180);

		ccBezierConfig tr3;
		tr3.endPosition = boss->getPosition();
		tr3.controlPoint_1 = Vec2(visibleSize.width / 2, visibleSize.height / 2);
		tr3.controlPoint_2 = Vec2(visibleSize.width / 3, visibleSize.height / 3);

		ActionInterval* bezierForward4 = BezierTo::create(3.f, tr3);
		ActionInterval *forwardBy4 = RotateBy::create(3.f, -180);

		Spawn* spawn1 = Spawn::create(bezierForward, forwardBy,  NULL);

		Spawn* spawn2 = Spawn::create(bezierForward2, forwardBy2, NULL);

		Spawn* spawn3 = Spawn::create(bezierForward3, forwardBy3, NULL);

		Spawn* spawn4 = Spawn::create(bezierForward4, forwardBy4, NULL);

		Action* action = Sequence::create(spawn1, spawn2, spawn3, spawn4, NULL);

		boss->runAction(action);
	}
}

void BossLayer::bossAttack(int progress)
{
	BulletLayer::sharedBulletLayer->bossBulletCreate(progress);
}

void BossLayer::bossMoveAndAttack(int progress)
{
}

