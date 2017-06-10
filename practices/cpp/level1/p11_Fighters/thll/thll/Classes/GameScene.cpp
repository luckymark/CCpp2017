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

	auto visibleOrigin = Director::getInstance()->getVisibleOrigin();
	auto visibleSize = Director::getInstance()->getVisibleSize();

	// create backgroud
	auto bg1 = Sprite::create("background.png");
	bg1->setPosition(Vec2(visibleOrigin.x + visibleSize.width / 2, 0));
	bg1->setAnchorPoint(Vec2(0.5, 0));
	bg1->setTag(BG_1_TAG); 
	this->addChild(bg1, 0);
	auto bg2 = Sprite::create("background.png");
	bg2->setPosition(Vec2(visibleOrigin.x + visibleSize.width / 2, bg1->getPositionY() + bg1->getContentSize().height));
	bg2->setAnchorPoint(Vec2(0.5, 0));
	bg2->setTag(BG_2_TAG);
	this->addChild(bg2, 0);

	// layer instance
	planeLayer = SelfPlaneLayer::create();
	this->addChild(planeLayer);

	enemyLayer = EnemyPlaneLayer::create();
	this->addChild(enemyLayer);

	bulletLayer = BulletLayer::create();
	this->addChild(bulletLayer);

	scoreLabel = LabelTTF::create();
	scoreLabel->setColor(ccc3(143, 146, 147));
	scoreLabel->setFontSize(30);
	scoreLabel->setPosition(Vec2(visibleSize.width - 100, visibleSize.height - 30));
	this->addChild(scoreLabel);

	this->schedule(schedule_selector(GameScene::gameUpdate), GAME_UPDATE_SEC);
	return true;
}

void GameScene::gameUpdate(float dt)
{
	auto visibleSize = Director::getInstance()->getVisibleSize();

	// background move
	auto bg1 = this->getChildByTag(BG_1_TAG);
	auto bg2 = this->getChildByTag(BG_2_TAG);
	if (bg2->getPositionY() + bg2->getContentSize().height <= Director::getInstance()->getVisibleSize().height)
	{
		bg1->setPositionY(-bg1->getContentSize().height + Director::getInstance()->getVisibleSize().height);
	}
	bg1->setPositionY(bg1->getPositionY() - 3);
	bg2->setPositionY(bg1->getPositionY() + bg1->getContentSize().height);

	if (is_first_enter)
	{
		is_first_enter = false;

		// get the window picture

		auto renderTexture = RenderTexture::create(visibleSize.width, visibleSize.height);

		renderTexture->begin();
		this->getParent()->visit();
		renderTexture->end();

		Director::sharedDirector()->pushScene(TextLayer::createScene(renderTexture));

	}

	TimeManager::getInstance()->timeIncreased();
	enemy_create_count++;
	enemy_move_count++;
	plane_auto_bullet_create_count++;
	enemy_bullet_create_count++;

	// Plane 
	planeLayer->planeUpdate(dt);

	planeLayer->startShooting();

	/*if (plane_auto_bullet_create_count % 360 == 0)
	{
		bulletLayer->autoBulletCreate();
		plane_auto_bullet_create_count = 0;
	}*/

	// Enemy
	if (TimeManager::getInstance()->JudgeTimeArray(std::vector<long double> {1,1.5,2,2.5,3,3.5,4,4.5,5,5.5,6,6.5,7,7.5,8,8.5,9,9.5,10}))
	{
		enemyLayer->enemyCreate(1);
	}

	if (TimeManager::getInstance()->JudgeTimeArray(std::vector<long double> {15, 20, 25}))
	{
		enemyLayer->enemyCreate(2);
	}

	if (TimeManager::getInstance()->JudgeTimeArray(std::vector<long double> {30,30.5,31,31.5,32,32.5,33,33.5,34,34.5,35,35.5,36,36.5,37,37.5,38,38.5,39,39.5,40}))
	{
		enemyLayer->enemyCreate(3);
	}

	if (TimeManager::getInstance()->JudgeTimeArray(std::vector<long double> {45, 50}))
	{
		enemyLayer->enemyCreate(4);
	}

	// enemy bullet
	if (enemy_bullet_create_count % 360 == 0)
	{
		enemyLayer->enemyShoting();
		enemy_bullet_create_count = 0;
	}

	if (enemy_move_count % 5 == 0)
	{
		//enemyLayer->enemyMove();
		enemy_move_count = 0;
	}

	// Bullet
	bulletLayer->bulletMove();

	// Handle Game
	collisionJudge();

	// Handle Score
	scoreUpdate();
}

void GameScene::collisionJudge()
{
	Vector<Bullet* > bulletList = bulletLayer->getBulletList();
	Vector<EnemyPlane* > enemyList = enemyLayer->getEnemyList();
	auto plane = SelfPlane::sharedPlane;
	auto system = ParticleExplosion::create();

	if (plane->getStatus(getCurrentTime()) == STATUS_NO_ATTCK)
	{
		plane->setOpacity(150);
	}
	else
	{
		plane->setOpacity(255);
	}

	//check enemy and self
	for (int i = 0; i < enemyList.size(); i++)
	{
		auto enemy = enemyList.at(i);
		if (plane->getBoundingBox().intersectsRect(enemy->getBoundingBox()) && !enemy->isDeleted())
		{
			enemy->setDeleted(true);
			auto enemy_pos = enemy->getPosition();
			auto plane_pos = plane->getPosition();

			int enemy_tag = enemy->getTag();
			int plane_tag = plane->getTag();

			//enemy_pos.x += enemy->getBoundingBox().size.width / 2;
			//enemy_pos.y -= enemy->getBoundingBox().size.height / 2;
			//plane_pos.x += plane->getBoundingBox().size.width / 2;
			//plane_pos.y -= plane->getBoundingBox().size.height / 2;

			system->setPosition(enemy_pos);

			enemy->removeFromParent();
			this->planeBomb(enemy_pos, enemy_tag);
			enemyLayer->eraseEnemy(enemy);

			if (plane->getStatus(getCurrentTime()) == STATUS_SURVIVAL)
			{
				plane->setDead();
				//plane->runAction(Sequence::create(NULL, CallFunc::create(CC_CALLBACK_0(Sprite::removeFromParent, plane)), NULL));
				this->planeBomb(plane_pos, plane_tag);
			}
			break;
		}
	}
	//check bullet and enemy and plane
	for (int i = 0; i < bulletList.size(); i++)
	{
		auto bullet = bulletList.at(i);
		auto tag = bullet->getTag();
		// bullet and enemy bomb
		if (tag == PLANE_BULLET_TAG)
		{
			int flag = 0;
			for (int j = 0; j < enemyList.size(); j++)
			{
				auto enemy = enemyList.at(j);
				if (enemy->getBoundingBox().intersectsRect(bullet->getBoundingBox())&&!enemy->isDeleted())
				{
					enemy->setDeleted(true);
					auto pos = enemy->getPosition();
					int tag = enemy->getTag();
					//pos.x += enemy->getBoundingBox().size.width / 2;
					//pos.y -= enemy->getBoundingBox().size.height / 2;
					system->setPosition(pos);	
					enemy->removeFromParent();
					this->planeBomb(pos, tag);					
					enemyLayer->eraseEnemy(enemy);
					flag = 1;

					// update socre
					plane->addScore(1);
					break;
				}
			}
			if (flag)
			{
				bulletLayer->bulletRemove(bullet);
				break;
			}
		}
		// plane and bullet bomb
		else if (tag == ENEMY_BULLET_TAG)
		{
			if (plane->boundingBox().intersectsRect(bullet->getBoundingBox()))
			{
				auto plane_pos = plane->getPosition();

				int plane_tag = plane->getTag();

				if (plane->getStatus(getCurrentTime()) == STATUS_SURVIVAL)
				{
					plane->setDead();
					this->planeBomb(plane_pos, plane_tag);
				}
				break;
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
	sprite->removeFromParent();
	if (sprite->getTag() == PLANE_TAG)
	{
		// TODO : GAME OVER
		auto plane = SelfPlane::sharedPlane;
		if (plane->isLifeEmpty())
		{

		}
		else
		{
			plane->setReborn(getCurrentTime());
		}
	}
}

long GameScene::getCurrentTime()
{
	struct timeval tv;
	gettimeofday(&tv, NULL);
	return tv.tv_sec * 1000 + tv.tv_usec / 1000;
}

void GameScene::scoreUpdate()
{
	String* strScore = String::createWithFormat("SCORE: %d", SelfPlane::sharedPlane->getScore());
	scoreLabel->setString(strScore->_string.c_str());
}
