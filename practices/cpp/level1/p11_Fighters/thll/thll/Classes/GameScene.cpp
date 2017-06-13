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

	// layer instance
	planeLayer = SelfPlaneLayer::create();
	this->addChild(planeLayer);

	enemyLayer = EnemyPlaneLayer::create();
	this->addChild(enemyLayer);

	bulletLayer = BulletLayer::create();
	this->addChild(bulletLayer);

	bossLayer = BossLayer::create();
	this->addChild(bossLayer);

	dropLayer = DropItemLayer::create();
	this->addChild(dropLayer);

	// plane instance
	plane = SelfPlane::sharedPlane;

	//life count
	String* strLife = String::createWithFormat("X%d", SelfPlane::sharedPlane->getLife());
	lifeLabel = LabelBMFont::create(strLife->getCString(), "font/font.fnt");
	lifeLabel->setColor(Color3B::BLACK);
	lifeLabel->setAnchorPoint(Vec2(1, 1));
	lifeLabel->setPosition(Vec2(visibleSize.width - 5, visibleSize.height - lifeLabel->getContentSize().height));
	this->addChild(lifeLabel);

	Sprite* s_plane = Sprite::create("ui/shoot/life.png");
	s_plane->setAnchorPoint(Vec2(1, 1));
	s_plane->setPosition(Vec2(visibleSize.width - lifeLabel->getContentSize().width, visibleSize.height));
	this->addChild(s_plane);

	// pause button
	auto menu = Menu::create();
	auto button_pause = MenuItemImage::create("ui/shoot/game_pause_nor.png", "ui/shoot/game_pause_pressed.png", CC_CALLBACK_0(GameScene::buttonPauseCallBack,this));
	menu->addChild(button_pause);
	menu->setPosition(Vec2(button_pause->getContentSize().width / 2, visibleSize.height - button_pause->getContentSize().height / 2));
	this->addChild(menu);

	//score label
	scoreLabel = LabelBMFont::create("0", "font/font.fnt");
	scoreLabel->setColor(Color3B::BLACK);
	scoreLabel->setAnchorPoint(Vec2(0, 1));
	scoreLabel->setPosition(Vec2(button_pause->getContentSize().width + 5, visibleSize.height - scoreLabel->getContentSize().height / 2));
	this->addChild(scoreLabel);

	// bomb label
	Sprite* s_bomb = Sprite::create("ui/shoot/bomb.png");

	auto menu_ = Menu::create();
	auto menu_bomb = MenuItemImage::create("ui/shoot/bomb.png", "ui/shoot/bomb.png", CC_CALLBACK_0(GameScene::buttonBombCallBack, this));
	menu_->addChild(menu_bomb);
	menu_->setAnchorPoint(Vec2(0, 0));
	menu_->setPosition(Vec2(s_bomb->getContentSize().width / 2, s_bomb->getContentSize().height / 2));
	this->addChild(menu_);

	
	/*s_bomb->setAnchorPoint(Vec2(0, 0));
	s_bomb->setPosition(Vec2(0, 0));
	this->addChild(s_bomb);*/

	String* strBomb = String::createWithFormat("X%d", SelfPlane::sharedPlane->getBomb());
	bombLabel = LabelBMFont::create(strLife->getCString(), "font/font.fnt");
	bombLabel->setColor(Color3B::BLACK);
	bombLabel->setAnchorPoint(Vec2(0, 0));
	bombLabel->setPosition(Vec2(s_bomb->getContentSize().width + 3, s_bomb->getContentSize().height / 4));
	this->addChild(bombLabel);

	// controller
	auto listener = EventListenerKeyboard::create();

	listener->onKeyPressed = CC_CALLBACK_2(GameScene::onKeyPressed, this);
	listener->onKeyReleased = CC_CALLBACK_2(GameScene::onKeyReleased, this);

	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);

	// Music
	Audio::getInstance()->playBGM();

	// LinkStart!
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

		// get the window picture
		auto renderTexture = RenderTexture::create(visibleSize.width, visibleSize.height);
		renderTexture->begin();
		this->getParent()->visit();
		renderTexture->end();

		is_first_enter = false;
		Director::sharedDirector()->pushScene(TextLayer::createScene(renderTexture));

	}

	TimeManager::getInstance()->timeIncreased();
	enemy_create_count++;
	enemy_move_count++;
	plane_auto_bullet_create_count++;
	auto_bullet_create++;

	//plane update
	auto left = EventKeyboard::KeyCode::KEY_LEFT_ARROW;
	auto right = EventKeyboard::KeyCode::KEY_RIGHT_ARROW;
	auto up = EventKeyboard::KeyCode::KEY_UP_ARROW;
	auto down = EventKeyboard::KeyCode::KEY_DOWN_ARROW;

	if (isKeyPressed(left))
	{
		planeLayer->planeUpdate(left);
	}
	if (isKeyPressed(right))
	{
		planeLayer->planeUpdate(right);
	}
	if (isKeyPressed(up))
	{
		planeLayer->planeUpdate(up);
	}
	if (isKeyPressed(down))
	{
		planeLayer->planeUpdate(down);
	}

	/*if (planeLayer->isKeyPressed(EventKeyboard::KeyCode::KEY_SPACE) && !SelfPlane::sharedPlane->getIsPlayBomb())
	{
		planeLayer->planeUpdate();
		if (SelfPlane::sharedPlane->getBomb() > 0)
		{
			planeLayer->setKeyReleased(EventKeyboard::KeyCode::KEY_SPACE);
			SelfPlane::sharedPlane->setIsPlayBomb(true);
			// get the window picture
			auto renderTexture = RenderTexture::create(visibleSize.width, visibleSize.height);
			renderTexture->begin();
			this->visit();
			renderTexture->end();

			Director::sharedDirector()->pushScene(BombSplashScreen::createScene(renderTexture));

			EnemyPlaneLayer::sharedEnemy->emptyAllEnemy();
			BulletLayer::sharedBulletLayer->emeptyAllEnemyBullet();
			SelfPlane::sharedPlane->bombDecresed();
		}
	}
	else
	{
		SelfPlane::sharedPlane->setIsPlayBomb(false);
		planeLayer->planeUpdate();
	}*/

	// shooting
	if (isKeyPressed(EventKeyboard::KeyCode::KEY_Z))
	{
		planeLayer->startShooting();
	}
	/*if (plane_auto_bullet_create_count % 360 == 0)
	{
		bulletLayer->autoBulletCreate();
		plane_auto_bullet_create_count = 0;
	}*/

	// Boss
	if (TimeManager::getInstance()->JudgeTime(55))
	{
		bossLayer->bossCreate();

		// set blood bar
		bloodbar = new ProgressView();
		bloodbar->setPosition(Vec2(visibleSize.width / 2, visibleSize.height - 50));
		bloodbar->setBackgroundTexture("ui/shoot_background/back_bar.png");
		bloodbar->setForegroundTexture("ui/shoot_background/back_bar_slider.png");
		bloodbar->setTotalProgress(1000.0f);
		bloodbar->setCurrentProgress(1000.0f);
		this->addChild(bloodbar);

		is_boss_create = true;
	}

	// Boss status 1
	if (JUD_T(56))
	{
		bossLayer->bossMove(1);
	}
	if (TimeManager::getInstance()->JudgeTimeArray(std::vector<long double>{56.2, 56.4, 56.6, 56.8, 57.0}))
	{
		bossLayer->bossAttack(1);
	}
	if (JUD_T(62))
	{
		bossLayer->bossMove(2);
	}
	if (TimeManager::getInstance()->JudgeTimeArray(std::vector<long double>{62.2, 62.4, 62.6, 62.8, 63.0}))
	{
		bossLayer->bossAttack(1);
	}
	// Boss status 2
	if (JUD_T(68))
	{
		bossLayer->bossMove(3);
	}
	if (TimeManager::getInstance()->JudgeTimeArray(std::vector<long double>{68.5, 69, 69.5, 70, 71.5,72.5,73,73.5,74,74.5,75,75.5,76,76.5,77,77.5,78,78.5,79,79.5,80}))
	{
		bossLayer->bossAttack(1);
	}



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
	if (auto_bullet_create % 60 == 0)
	{
		bulletLayer->autoBulletCreate();
		auto_bullet_create = 0;
	}

	if (enemy_move_count % 5 == 0)
	{
		//enemyLayer->enemyMove();
		enemy_move_count = 0;
	}

	// Bullet
	bulletLayer->bulletMove();

	// DropItem
	if (TimeManager::getInstance()->JudgeTimeArray(std::vector<long double> {1, 2, 3, 4, 5,9,11,13,17,28,36}))
	{
		dropLayer->createDrop();
	}
	dropLayer->dropMove();

	// Handle Game
	collisionJudge();

	// Handle Score
	scoreUpdate();

	// Handle life label
	lifeUpdate();

	// Handle bomb label
	bombUpdate();
}

void GameScene::collisionJudge()
{
	Vector<Bullet* > bulletList = bulletLayer->getBulletList();
	Vector<EnemyPlane* > enemyList = enemyLayer->getEnemyList();
	Vector<Sprite* > dropList = dropLayer->getDropList();
	auto plane = SelfPlane::sharedPlane;
	auto system = ParticleExplosion::create();
	auto boss = Boss::sharedBoss;

	if (plane->getStatus(getCurrentTime()) == STATUS_NO_ATTCK)
	{
		plane->setOpacity(150);
	}
	else
	{
		plane->setOpacity(255);
	}

	// check plane and dropitem
	for (int i = 0; i < dropList.size(); i++)
	{
		auto drop = dropList.at(i);
		if (plane->getBoundingBox().intersectsRect(drop->getBoundingBox()))
		{
			if (drop->getTag() == DROP_TYPE_2_TAG)
			{
				plane->bombIncresed();
			}
			else if(drop->getTag() == DROP_TYPE_1_TAG)
			{
				plane->addScore(100);
			}
			dropLayer->removeDrop(drop);
			drop->removeFromParent();
		}
	}

	//check enemy and plane
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

			if (enemy->getTag() == ENEMY_TYPE_1_TAG)
			{
				Audio::getInstance()->playEnemy1();
			}
			else
			{
				Audio::getInstance()->playEnemy2();
			}
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
	//check bullet and enemy and plane and boss
	for (int i = 0; i < bulletList.size(); i++)
	{
		auto bullet = bulletList.at(i);
		auto tag = bullet->getTag();
		// bullet and enemy bomb
		if (tag == PLANE_BULLET_TAG)
		{

			if (is_boss_create)
			{
				if (boss->getBoundingBox().intersectsRect(bullet->getBoundingBox()) && !boss->isDeleted() )
				{
					bulletLayer->bulletRemove(bullet);
					if (!boss->isLifeEmpty())
					{
						boss->lifeDecreased(1);
						bloodbar->setCurrentProgress(bloodbar->getCurrentProgress() - 1);
						Vector<SpriteFrame*> animationframe;
						SpriteFrame * sf = SpriteFrame::create("ui/shoot/enemy3_hit.png", Rect(0, 0, 169, 258));
						animationframe.pushBack(sf);
						Animation * ani = Animation::createWithSpriteFrames(animationframe, 0.1);
						Action* act = Sequence::create(Animate::create(ani), NULL, NULL);
						boss->runAction(act);
					}
					else
					{
						Audio::getInstance()->playEnemy3();

						bloodbar->removeFromParent();

						is_boss_create = false;

						boss->setDeleted(true);

						auto boss_pos = boss->getPosition();

						int boss_tag = boss->getTag();

						boss->removeFromParent();

						plane->addScore(10000);

						this->planeBomb(boss_pos, boss_tag);
					}

				}
			}

			int flag = 0;
			for (int j = 0; j < enemyList.size(); j++)
			{
				auto enemy = enemyList.at(j);
				if (enemy->getBoundingBox().intersectsRect(bullet->getBoundingBox())&&!enemy->isDeleted())
				{
					bulletLayer->bulletRemove(bullet);
					if (enemy->getTag() == ENEMY_TYPE_1_TAG)
					{
						enemy->setDeleted(true);
						auto pos = enemy->getPosition();
						int tag = enemy->getTag();
						
						Audio::getInstance()->playEnemy1();
						system->setPosition(pos);	
						enemy->removeFromParent();
						this->planeBomb(pos, tag);					
						enemyLayer->eraseEnemy(enemy);
						flag = 1;

						// enemy bullet
						if (isEnemyShoot())
						{
							bulletLayer->enemyBulletCreate(enemy->getPosition());
						}

						// update socre
						plane->addScore(1000);
					}
					else if (enemy->getTag() == ENEMY_TYPE_2_TAG)
					{
						EnemyPlaneMedium* enemyM = (EnemyPlaneMedium *)enemy;
						if (!enemyM->isLifeEmpty())
						{
							enemyM->lifeDecresed(1);
							Vector<SpriteFrame*> animationframe;
							SpriteFrame * sf = SpriteFrame::create("ui/shoot/enemy2_hit.png", Rect(0, 0, 69, 99));
							SpriteFrame * sf2 = SpriteFrame::create("ui/shoot/enemy2.png", Rect(0, 0, 69, 99));
							animationframe.pushBack(sf);
							animationframe.pushBack(sf2);
							Animation * ani = Animation::createWithSpriteFrames(animationframe, 0.1);
							Action* act = Sequence::create(Animate::create(ani), NULL, NULL);
							enemy->runAction(act);
						}
						else
						{
							enemy->setDeleted(true);
							auto pos = enemy->getPosition();
							int tag = enemy->getTag();
							//pos.x += enemy->getBoundingBox().size.width / 2;
							//pos.y -= enemy->getBoundingBox().size.height / 2;

							Audio::getInstance()->playEnemy2();

							system->setPosition(pos);
							enemy->removeFromParent();
							this->planeBomb(pos, tag);
							enemyLayer->eraseEnemy(enemy);
							flag = 1;

							// enemy bullet
							if (isEnemyShoot())
							{
								bulletLayer->enemyBulletCreate(enemy->getPosition());
							}

							// update socre
							plane->addScore(2000);
						}
					}
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
			auto string = cocos2d::__String::createWithFormat("ui/shoot/enemy1_down%d.png", i);
			SpriteFrame * sf = SpriteFrame::create(string->getCString(), Rect(0, 0, 57, 43));
			animationframe.pushBack(sf);
		}
	}
	else if (tag == ENEMY_TYPE_2_TAG)
	{
		for (int i = 1; i<5; i++)
		{
			auto string = cocos2d::__String::createWithFormat("ui/shoot/enemy2_down%d.png", i);
			SpriteFrame * sf = SpriteFrame::create(string->getCString(), Rect(0, 0, 69, 95));
			animationframe.pushBack(sf);
		}
	}
	else if (tag == BOSS_TAG)
	{
		for (int i = 1; i<= 6; i++)
		{
			auto string = cocos2d::__String::createWithFormat("ui/shoot/enemy3_down%d.png", i);
			SpriteFrame * sf = SpriteFrame::create(string->getCString(), Rect(0, 0, 165, 261));
			animationframe.pushBack(sf);
		}
	}
	else
	{
		dt = 0.5;
		for (int i = 1; i<5; i++)
		{
			auto string = cocos2d::__String::createWithFormat("ui/shoot/hero_blowup_n%d.png", i);
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
			Director::getInstance()->replaceScene(GameOver::createScene());
		}
		else
		{
			plane->setReborn(getCurrentTime());
		}
	}
	else if (sprite->getTag() == BOSS_TAG)
	{
		Director::getInstance()->replaceScene(GameOver::createScene());
	}
}

void GameScene::buttonPauseCallBack()
{
	auto visibleSize = Director::getInstance()->getVisibleSize();
	auto renderTexture = RenderTexture::create(visibleSize.width, visibleSize.height);
	renderTexture->begin();
	this->getParent()->visit();
	renderTexture->end();
	Director::getInstance()->pushScene(GamePauseLayer::createScene(renderTexture));
}

long GameScene::getCurrentTime()
{
	struct timeval tv;
	gettimeofday(&tv, NULL);
	return tv.tv_sec * 1000 + tv.tv_usec / 1000;
}

bool GameScene::isEnemyShoot()
{
	srand(time(0));
	int n = rand() % 2;
	return n == 1;
}

void GameScene::onKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event * event)
{
	if (keyCode == EventKeyboard::KeyCode::KEY_SPACE)
	{
		if (plane->getBomb() > 0)
		{
			auto visibleSize = Director::getInstance()->getVisibleSize();

			auto renderTexture = RenderTexture::create(visibleSize.width, visibleSize.height);
			renderTexture->begin();
			this->getParent()->visit();
			renderTexture->end();

			Director::sharedDirector()->pushScene(BombSplashScreen::createScene(renderTexture));

			//EnemyPlaneLayer::sharedEnemy->emptyAllEnemy();
			//BulletLayer::sharedBulletLayer->emeptyAllEnemyBullet();
			//SelfPlane::sharedPlane->bombDecresed();

			onKeyReleased(EventKeyboard::KeyCode::KEY_SPACE, event);
		}

	}
	else
	{
		this->keys[keyCode] = true;
	}
	
}

void GameScene::onKeyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event * event)
{
	this->keys[keyCode] = false;
}

bool GameScene::isKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode)
{
	return keys[keyCode];
}

void GameScene::buttonBombCallBack()
{
	if (plane->getBomb() > 0)
	{
		auto visibleSize = Director::getInstance()->getVisibleSize();

		auto renderTexture = RenderTexture::create(visibleSize.width, visibleSize.height);
		renderTexture->begin();
		this->getParent()->visit();
		renderTexture->end();

		Director::sharedDirector()->pushScene(BombSplashScreen::createScene(renderTexture));

		//EnemyPlaneLayer::sharedEnemy->emptyAllEnemy();
		//BulletLayer::sharedBulletLayer->emeptyAllEnemyBullet();
		//SelfPlane::sharedPlane->bombDecresed();

	}
}

void GameScene::scoreUpdate()
{
	String* strScore = String::createWithFormat("%d", SelfPlane::sharedPlane->getScore());
	scoreLabel->setString(strScore->_string.c_str());
}

void GameScene::lifeUpdate()
{
	String* strLife = String::createWithFormat("X%d", SelfPlane::sharedPlane->getLife());
	lifeLabel->setString(strLife->_string.c_str());
}

void GameScene::bombUpdate()
{
	String* strBomb = String::createWithFormat("X%d", SelfPlane::sharedPlane->getBomb());
	bombLabel->setString(strBomb->_string.c_str());
}
