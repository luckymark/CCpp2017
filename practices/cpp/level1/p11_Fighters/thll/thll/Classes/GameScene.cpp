#include "GameScene.h"

USING_NS_CC;

Scene* GameScene::createScene()
{
	auto scene = Scene::create();
	
	auto layer = GameScene::create();

	scene->addChild(layer);

	return scene;
}

bool GameScene::init()
{
	if (!Layer::init())
	{
		return false;
	}

	return true;
}

void GameScene::onEnterTransitionDidFinish()
{
	planeLayer = SelfPlaneLayer::create();
	this->addChild(planeLayer);

	enemyLayer = EnemyPlaneLayer::create();
	this->addChild(enemyLayer);

	this->schedule(schedule_selector(GameScene::collisionJudge), 0.001);
}

void GameScene::collisionJudge(float dt)
{
	Vector<Sprite* > bulletList = planeLayer->getBulletList();
	Vector<EnemyPlane* > enemyList = enemyLayer->getEnemyList();
	auto plane = planeLayer->getPlane();
	auto system = ParticleExplosion::create();

	//check bullet and enemy
	for (int i = 0; i < bulletList.size(); i++)
	{
		auto bullet = bulletList.at(i);
		for (int j = 0; j < enemyList.size(); j++)
		{
			auto enemy = enemyList.at(j);
			if (enemy->getBoundingBox().intersectsRect(bullet->getBoundingBox())&&!enemy->isDeleted())
			{
				enemy->setDeleted(true);
				auto pos = enemy->getPosition();
				int tag = enemy->getTag();
				pos.x += enemy->getBoundingBox().size.width / 2;
				pos.y -= enemy->getBoundingBox().size.height / 2;
				system->setPosition(pos);	
				enemy->removeFromParent();
				this->planeBomb(pos, tag);					
				enemyList.eraseObject(enemy);
				return;
			}
		}
	}
}
void GameScene::planeBomb(Vec2 vec, int tag)
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

	Action * act = Sequence::create(Animate::create(ani), CCCallFuncN::create(blanksprite, callfuncN_selector(GameScene::bombRemove)), NULL);
	this->addChild(blanksprite);
	blanksprite->setPosition(vec);
	blanksprite->runAction(act);
}

void GameScene::bombRemove(Node * sprite)
{
	log("ok\n");
	sprite->removeFromParent();
	if (sprite->getTag() == 103)
	{

	}
}