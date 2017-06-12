#include "EnemyPlaneLayer.h"

#include "cstdlib"

USING_NS_CC;
EnemyPlaneLayer* EnemyPlaneLayer::sharedEnemy = nullptr;

EnemyPlaneLayer* EnemyPlaneLayer::create()
{
	EnemyPlaneLayer *pRet = new EnemyPlaneLayer();
	if (pRet && pRet->init()) {
		pRet->autorelease();
		sharedEnemy = pRet;
		return pRet;
	}
	else {
		CC_SAFE_DELETE(pRet);
		return NULL;
	}
}

Scene* EnemyPlaneLayer::createScene()
{
	auto scene = Scene::create();

	auto layer = EnemyPlaneLayer::create();

	scene->addChild(layer);

	return scene;
}

bool EnemyPlaneLayer::init()
{
	if (!Layer::init())
	{
		return false;
	}

}

/*void EnemyPlaneLayer::enemyMove()
{
	auto winSize = Director::getInstance()->getWinSize();

	for (int i = 0; i < enemyList.size(); i++)
	{
		auto enemy = enemyList.at(i);
		if(!enemy->isDeleted())enemy->setPositionY(enemy->getPositionY() - 5);
		if (enemy->getPositionY() < 0)
		{
			enemy->removeFromParent();
			enemyList.eraseObject(enemy);	
			i--;
		}
	}
}*/

void EnemyPlaneLayer::enemyCreate(int progress)
{
	Size visibleSize = Director::getInstance()->getVisibleSize();

	if (progress == 1)
	{
		auto enemy = EnemyPlane::create("enemy1.png");
		enemy->setRotation(90);
		enemy->setPosition(Vec2(0, visibleSize.height));
		enemy->setTag(ENEMY_TYPE_1_TAG);
		this->enemyList.pushBack(enemy);
		this->addChild(enemy);
 
		ccBezierConfig tr0;
		tr0.endPosition = Vec2(0, visibleSize.height / 2); 
		tr0.controlPoint_1 = Vec2(visibleSize.width / 2, visibleSize.height / 2);
		tr0.controlPoint_2 = Vec2(visibleSize.width / 3, visibleSize.height / 3);


		ActionInterval* bezierForward = BezierTo::create(3.f, tr0);
		ActionInterval *forwardBy = RotateBy::create(3.f, 180);       
		Spawn* spawn = Spawn::create(bezierForward, forwardBy, NULL); 

		auto actionDone = CallFuncN::create(CC_CALLBACK_1(EnemyPlaneLayer::enemyRemove, this));
 
		Sequence* sequence = Sequence::create(spawn, actionDone, NULL);
		enemy->runAction(sequence);
	}
	else if(progress == 2)
	{ 
		auto enemy1 = EnemyPlaneMedium::create("enemy2.png");
		auto enemy2 = EnemyPlaneMedium::create("enemy2.png");
		auto enemy3 = EnemyPlaneMedium::create("enemy2.png");

		float height = enemy1->getContentSize().height;
		float width = enemy1->getContentSize().width;

		// setPosition
		enemy1->setPosition(Vec2(width, visibleSize.height + height));
		enemy2->setPosition(Vec2(visibleSize.width / 2, visibleSize.height - height));
		enemy3->setPosition(Vec2(visibleSize.width - width, visibleSize.height + height));

		enemy1->setTag(ENEMY_TYPE_2_TAG);
		enemy2->setTag(ENEMY_TYPE_2_TAG);
		enemy3->setTag(ENEMY_TYPE_2_TAG);
		this->enemyList.pushBack(enemy1);
		this->enemyList.pushBack(enemy2);
		this->enemyList.pushBack(enemy3);

		this->addChild(enemy1);
		this->addChild(enemy2);
		this->addChild(enemy3);

		//calculate velocity
		float flyVelocity = 100;
		float flyLen = visibleSize.height;
		float realFlyDuration = flyLen / flyVelocity;
 
		auto actionMove1 = MoveBy::create(realFlyDuration, Point(0, -visibleSize.height - height));
		auto actionMove2 = MoveBy::create(realFlyDuration, Point(0, -visibleSize.height - height));
		auto actionMove3 = MoveBy::create(realFlyDuration, Point(0, -visibleSize.height - height));

		auto actionDone = CallFuncN::create(CC_CALLBACK_1(EnemyPlaneLayer::enemyRemove, this));

		Sequence* sequence1 = Sequence::create(actionMove1, actionDone, NULL);
		Sequence* sequence2 = Sequence::create(actionMove2, actionDone, NULL);
		Sequence* sequence3 = Sequence::create(actionMove3, actionDone, NULL);

		//enemy move
		enemy1->runAction(sequence1);
		enemy2->runAction(sequence2);
		enemy3->runAction(sequence3);
	}
	else if (progress == 3)
	{
		auto enemy = EnemyPlane::create("enemy1.png");
		enemy->setRotation(90);
		enemy->setPosition(Vec2(visibleSize.width, visibleSize.height));
		enemy->setTag(ENEMY_TYPE_1_TAG);
		this->enemyList.pushBack(enemy);
		this->addChild(enemy);

		ccBezierConfig tr0;
		tr0.endPosition = Vec2(visibleSize.width, visibleSize.height / 2);
		tr0.controlPoint_1 = Vec2(visibleSize.width / 2, visibleSize.height / 2);
		tr0.controlPoint_2 = Vec2(visibleSize.width / 3, visibleSize.height / 3);


		ActionInterval* bezierForward = BezierTo::create(3.f, tr0);
		ActionInterval *forwardBy = RotateBy::create(3.f, -180);
		Spawn* spawn = Spawn::create(bezierForward, forwardBy, NULL);

		auto actionDone = CallFuncN::create(CC_CALLBACK_1(EnemyPlaneLayer::enemyRemove, this));

		Sequence* sequence = Sequence::create(spawn, actionDone, NULL);
		enemy->runAction(sequence);
	}
	else if (progress == 4)
	{
		//left enemy 
		auto enemy1 = EnemyPlaneMedium::create("enemy2.png");
		auto enemy2 = EnemyPlaneMedium::create("enemy2.png");
		auto enemy3 = EnemyPlaneMedium::create("enemy2.png");
		//right enemy 
		auto enemy4 = EnemyPlaneMedium::create("enemy2.png");
		auto enemy5 = EnemyPlaneMedium::create("enemy2.png");
		auto enemy6 = EnemyPlaneMedium::create("enemy2.png");

		float height = enemy1->getContentSize().height;
		float width = enemy1->getContentSize().width;

		enemy1->setPosition(Vec2(-width / 2, visibleSize.height - height / 2 - 10));
		enemy2->setPosition(Vec2(-width / 2, enemy1->getPosition().y - 2 * height - 10));
		enemy3->setPosition(Vec2(-width / 2, enemy2->getPosition().y - 2 * height - 10));

		enemy4->setPosition(Vec2(visibleSize.width + width / 2, enemy1->getPosition().y - height - 10));
		enemy5->setPosition(Vec2(visibleSize.width + width / 2, enemy4->getPosition().y - 2 * height - 10));
		enemy6->setPosition(Vec2(visibleSize.width + width / 2, enemy5->getPosition().y - 2 * height - 10));
 
		enemy1->setTag(ENEMY_TYPE_2_TAG);
		enemy2->setTag(ENEMY_TYPE_2_TAG);
		enemy3->setTag(ENEMY_TYPE_2_TAG);
		enemy4->setTag(ENEMY_TYPE_2_TAG);
		enemy5->setTag(ENEMY_TYPE_2_TAG);

		this->enemyList.pushBack(enemy1);
		this->enemyList.pushBack(enemy2);
		this->enemyList.pushBack(enemy3);
		this->enemyList.pushBack(enemy4);
		this->enemyList.pushBack(enemy5);

		this->addChild(enemy1);
		this->addChild(enemy2);
		this->addChild(enemy3);
		this->addChild(enemy4);
		this->addChild(enemy5);


		//calculate fly time 
		float flyVelocity = 200;
		float flyLen = visibleSize.width + width;
		float realFlyDuration = flyLen / flyVelocity;


		auto actionMove1 = MoveBy::create(realFlyDuration, Point(flyLen, 0));
		auto actionMove2 = MoveBy::create(realFlyDuration, Point(-flyLen, 0));

		auto actionDone = CallFuncN::create(CC_CALLBACK_1(EnemyPlaneLayer::enemyRemove, this));

		Sequence* sequence1 = Sequence::create(actionMove1, actionDone, NULL);
		Sequence* sequence2 = Sequence::create(actionMove1->clone(), actionDone, NULL);
		Sequence* sequence3 = Sequence::create(actionMove1->clone(), actionDone, NULL);
		Sequence* sequence4 = Sequence::create(actionMove2, actionDone, NULL);
		Sequence* sequence5 = Sequence::create(actionMove2->clone(), actionDone, NULL);

		enemy1->runAction(sequence1);
		enemy2->runAction(sequence2);
		enemy3->runAction(sequence3);
		enemy4->runAction(sequence4);
		enemy5->runAction(sequence5);
	}




	/*int rnd = rand() % 2 + 1;

	auto strings = cocos2d::__String::createWithFormat("enemy%d.png", rnd);
	auto enemy = EnemyPlane::create(strings->getCString());

	if (rnd == 1)
	{
		enemy->setTag(ENEMY_TYPE_1_TAG);
	}
	else
	{
		enemy->setTag(ENEMY_TYPE_2_TAG);
	}

	enemy->setPosition(Vec2(rand() % (int)(Director::getInstance()->getVisibleSize().width), Director::getInstance()->getVisibleSize().height));

	this->addChild(enemy);
	this->enemyList.pushBack(enemy);*/
}

Vector<EnemyPlane* > EnemyPlaneLayer::getEnemyList()
{
	return this->enemyList;
}

void EnemyPlaneLayer::enemyShoting()
{
	//BulletLayer::sharedBulletLayer->enemyBulletCreate();
}

void EnemyPlaneLayer::eraseEnemy(EnemyPlane* enemy)
{
	this->enemyList.eraseObject(enemy);
}

void EnemyPlaneLayer::emptyAllEnemy()
{
	for (int i = enemyList.size() - 1; i >= 0; i--)
	{
		auto enemy = enemyList.at(i);
		auto pos = enemy->getPosition();
		int tag = enemy->getTag();

		enemy->removeFromParent();
		this->enemyList.eraseObject(enemy);

		float dt = 0.1;
		Vector<SpriteFrame*> animationframe;
		if (tag == ENEMY_TYPE_1_TAG)
		{
			for (int i = 1; i<5; i++)
			{
				auto string = cocos2d::__String::createWithFormat("ui/shoot/enemy1_down%d.png", i);
				SpriteFrame * sf = SpriteFrame::create(string->getCString(), Rect(0, 0, 57, 43));
				animationframe.pushBack(sf);
			}
			SelfPlane::sharedPlane->addScore(1000);
		}
		else if (tag == ENEMY_TYPE_2_TAG)
		{
			for (int i = 1; i<5; i++)
			{
				auto string = cocos2d::__String::createWithFormat("ui/shoot/enemy2_down%d.png", i);
				SpriteFrame * sf = SpriteFrame::create(string->getCString(), Rect(0, 0, 69, 95));
				animationframe.pushBack(sf);
			}
			SelfPlane::sharedPlane->addScore(2000);
		}

		Animation * ani = Animation::createWithSpriteFrames(animationframe, dt);
		auto blanksprite = Sprite::create();
		blanksprite->setTag(tag);

		Action * act = Sequence::create(Animate::create(ani), CCCallFuncN::create(blanksprite, callfuncN_selector(EnemyPlaneLayer::aniRemove)), NULL);
		this->addChild(blanksprite);
		blanksprite->setPosition(pos);
		blanksprite->runAction(act);
	}
}

void EnemyPlaneLayer::aniRemove(Node * sprite)
{
	sprite->removeFromParent();
}

void EnemyPlaneLayer::enemyRemove(Node * pNode)
{
	if (NULL == pNode) {
		return;
	}
	EnemyPlane* plane = (EnemyPlane*)pNode;
	this->eraseEnemy(plane);
	this->removeChild(plane, true);
}