#include "CollisionLayer.h"
#include "GameScene.h"

USING_NS_CC;

bool CollisionLayer::init()
{
	if (!Layer::init())
	{
		return false;
	}
	
	this->schedule(schedule_selector(CollisionLayer::collisionJudge), 0.01);
}

/*void CollisionLayer::collisionJudge(float dt)
{

	// check plane and enemy
	Vector<Sprite* > bulletList = GameScene::getSelfPlaneLayer()->getBulletList();
	Vector<Sprite* > enemyList = GameScene::getEnemyPlaneLayer()->getEnemyList();
	auto plane = GameScene::getSelfPlaneLayer()->getPlane();

	for (int i = 0; i < enemyList.size(); i++)
	{
		if (enemyList.at(i)->getBoundingBox().intersectsRect(plane->getBoundingBox()))
		{
			log("#1:%d %d\n#2:%d %d\n", enemyList.at(i)->getBoundingBox().size.width, enemyList.at(i)->getBoundingBox().size.height, plane->getBoundingBox().size.width, plane->getBoundingBox().size.height);
			enemyList.eraseObject(enemyList.at(i));
			enemyList.at(i)->removeFromParent();
			i--;
		}
	}
}*/

/*void CollisionLayer::onEnter()
{
	auto listener = EventListenerPhysicsContact::create();

	listener->onContactBegin = CC_CALLBACK_1(CollisionLayer::onContactBegin, this);

	auto eventDispather = Director::getInstance()->getEventDispatcher();
	eventDispather->addEventListenerWithFixedPriority(listener, 1);
}

bool CollisionLayer::onContactBegin(PhysicsContact &contact)
{
	auto spriteA = (Sprite*)contact.getShapeA()->getBody()->getNode();
	auto spriteB = (Sprite*)contact.getShapeB()->getBody()->getNode();

	int tagA = spriteA->getTag(), tagB = spriteB->getTag();
	Vec2 vecA = spriteA->getPosition(), vecB = spriteB->getPosition();

	if (tagA + tagB == BULLET_TAG + ENEMY_TYPE_1_TAG || tagA + tagB == BULLET_TAG + ENEMY_TYPE_2_TAG)
	{
		auto system = ParticleExplosion::create();

		if (tagA == ENEMY_TYPE_1_TAG || tagA == ENEMY_TYPE_2_TAG)
		{
			GameScene::getSelfPlaneLayer()->getBulletList().eraseObject(spriteB);
			GameScene::getEnemyPlaneLayer()->getEnemyList().eraseObject(spriteA);
			//spriteA->removeFromParent(); spriteB->removeFromParent();
			system->setPosition(vecA);
			this->planBomb(vecA, tagA);
		}
		else
		{
			GameScene::getSelfPlaneLayer()->getBulletList().eraseObject(spriteA);
			GameScene::getEnemyPlaneLayer()->getEnemyList().eraseObject(spriteB);
			//spriteA->removeFromParent(); spriteB->removeFromParent();
			system->setPosition(vecB);
			this->planBomb(vecB, tagB);
		}

		this->addChild(system);
	}
	else if (tagA + tagB == PLANE_TAG + ENEMY_TYPE_1_TAG || tagA + tagB == PLANE_TAG + ENEMY_TYPE_2_TAG)
	{

	}

	return true;
}

void CollisionLayer::planBomb(Vec2 vec, int tag)
{
	float dt = 0.1;
	Vector<SpriteFrame*> animationframe;
	if (tag == ENEMY_TYPE_1_TAG) 
	{
		for (int i = 1; i<5; i++)
		{
			auto string = cocos2d::__String::createWithFormat("enemy1_down%d.png", i);
			SpriteFrame * sf = SpriteFrame::create(string->getCString(), Rect(0, 0, 57, 43));
			animationframe.pushBack(sf);
		}
	}
	else if (tag == ENEMY_TYPE_2_TAG)        
	{
		for (int i = 1; i<5; i++)
		{
			auto string = cocos2d::__String::createWithFormat("enemy2_down%d.png", i);
			SpriteFrame * sf = SpriteFrame::create(string->getCString(), Rect(0, 0, 69, 95));
			animationframe.pushBack(sf);
		}
	}
	else            
	{
		dt = 0.5;
		for (int i = 1; i<5; i++)
		{
			auto string = cocos2d::__String::createWithFormat("hero_blowup_n%d.png", i);
			SpriteFrame * sf = SpriteFrame::create(string->getCString(), Rect(0, 0, 102, 126));
			animationframe.pushBack(sf);
		}
	}
	Animation * ani = Animation::createWithSpriteFrames(animationframe, dt);
	auto blanksprite = Sprite::create();
	blanksprite->setTag(tag);

	Action * act = Sequence::create(Animate::create(ani), CCCallFuncN::create(blanksprite, callfuncN_selector(CollisionLayer::bombRemove)), NULL);
	this->addChild(blanksprite);
	blanksprite->setPosition(vec);
	blanksprite->runAction(act);
}

void CollisionLayer::bombRemove(Node * sprite)
{
	log("ok\n");
	sprite->removeFromParent();
	if (sprite->getTag() == 103)            
	{
		
	}
}*/