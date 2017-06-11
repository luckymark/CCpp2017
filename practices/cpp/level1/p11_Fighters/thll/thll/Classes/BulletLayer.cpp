#include "BulletLayer.h"

USING_NS_CC;

BulletLayer* BulletLayer::sharedBulletLayer = nullptr;

BulletLayer* BulletLayer::create()
{
	BulletLayer *pRet = new BulletLayer();
	if (pRet && pRet->init()) {
		pRet->autorelease();
		sharedBulletLayer = pRet;
		return pRet;
	}
	else {
		CC_SAFE_DELETE(pRet);
		return NULL;
	}
}

Scene* BulletLayer::createScene()
{
	auto scene = Scene::create();

	auto layer = BulletLayer::create();

	scene->addChild(layer);

	return scene;
}

bool BulletLayer::init()
{
	if (!Layer::init())
	{
		return false;
	}
	return true;
}

void BulletLayer::bulletMove()
{
	auto winSize = Director::getInstance()->getWinSize();
	auto plane = SelfPlane::sharedPlane;
	auto enemyList = EnemyPlaneLayer::sharedEnemy->getEnemyList();

	for (int i = 0; i < bulletList.size(); i++)
	{
		auto bullet = bulletList.at(i);
		auto tag = bullet->getTag();

		if (tag == PLANE_BULLET_TAG)
		{
			if (bullet->getType() == 3)
			{
				if (bullet->getDirection() == 0)
				{
					bullet->setPositionX(bullet->getPositionX() - sqrt(PLANE_BULLET_SPEED));
					bullet->setPositionY(bullet->getPositionY() + PLANE_BULLET_SPEED);
				}
				else if (bullet->getDirection() == 1)
				{
					bullet->setPositionY(bullet->getPositionY() + PLANE_BULLET_SPEED);
				}
				else if (bullet->getDirection() == 2)
				{
					bullet->setPositionX(bullet->getPositionX() + sqrt(PLANE_BULLET_SPEED));
					bullet->setPositionY(bullet->getPositionY() + PLANE_BULLET_SPEED);
				}	
			}
			else if (bullet->getType() == 4)
			{
				/*float minY = 100000.0, minAbsX = 1000000.0; 
				Vec2 minVec;
				for (int i = 0; i < enemyList.size(); i++)
				{
					auto enemy = enemyList.at(i);
					if (enemy->getPositionY() < minY && enemy->getPositionY() > plane->getPositionY() && minAbsX > fabs(plane->getPositionX() - enemy->getPositionX()))
					{
						minY = enemy->getPositionY();
						minAbsX = fabs(plane->getPositionX() - enemy->getPositionX());
						minVec = enemy->getPosition();
					}
				}

				bullet->setPositionY(bullet->getPositionY() + 5);
				Vec2 newVec = minVec - bullet->getPosition();
				float theta = atan(newVec.y / newVec.x);

				//bullet->setRotation(bullet->getRotation() + theta);

				bullet->setPosition(bullet->getPosition() + Vec2(cos(theta) * 5, sin(theta) * 5));*/

			}
			else
			{
				bullet->setPositionY(bullet->getPositionY() + PLANE_BULLET_SPEED);
			}		
			
			if (bullet->getPositionY() > winSize.height)
			{
				bulletList.eraseObject(bullet);
				bullet->removeFromParent();
				i--;
			}
		}
		else if (tag == ENEMY_BULLET_TAG)
		{
			bullet->setPositionY(bullet->getPositionY() - 3);
			if (bullet->getPositionY() < 0)
			{
				bulletList.eraseObject(bullet);
				bullet->removeFromParent();
				i--;
			}
		}

	}
}

void BulletLayer::bulletCreate()
{
	Size visibleSize = Director::getInstance()->getVisibleSize();
	auto key_z = EventKeyboard::KeyCode::KEY_Z;
	auto plane = (SelfPlane* )SelfPlaneLayer::sharedPlaneLayer->getChildByTag(PLANE_TAG);

	int level = plane->getLevel();
	switch (level)
	{
	case 1:
	{
		auto bullet1 = Bullet::create("bullet.png");

		bullet1->setPosition(plane->getPositionX(), plane->getPositionY() + 30);
		bullet1->setTag(PLANE_BULLET_TAG);
		bullet1->setType(1);

		this->addChild(bullet1);
		bulletList.pushBack(bullet1);
		break;
	}
	case 2:
	{
		auto bullet1 = Bullet::create("bullet.png");
		auto bullet2 = Bullet::create("bullet.png");

		bullet1->setPosition(plane->getPositionX() - 5, plane->getPositionY() + 30);
		bullet1->setTag(PLANE_BULLET_TAG);
		bullet1->setType(2);

		bullet2->setPosition(plane->getPositionX() + 5, plane->getPositionY() + 30);
		bullet2->setTag(PLANE_BULLET_TAG);
		bullet2->setType(2);

		this->addChild(bullet1);
		bulletList.pushBack(bullet1);
		this->addChild(bullet2);
		bulletList.pushBack(bullet2);
		break;
	}
	case 3:
	{
		auto bullet1 = Bullet::create("bullet.png");
		auto bullet2 = Bullet::create("bullet.png");
		auto bullet3 = Bullet::create("bullet.png");

		bullet1->setPosition(plane->getPositionX() - 10, plane->getPositionY() + 30);
		bullet1->setTag(PLANE_BULLET_TAG);
		bullet1->setRotation(-30);
		bullet1->setType(3);
		bullet1->setDirection(0);

		bullet2->setPosition(plane->getPositionX() + 10, plane->getPositionY() + 30);
		bullet2->setTag(PLANE_BULLET_TAG);
		bullet2->setRotation(30);
		bullet2->setType(3);
		bullet2->setDirection(2);

		bullet3->setPosition(plane->getPositionX(), plane->getPositionY() + 30);
		bullet3->setTag(PLANE_BULLET_TAG);
		bullet3->setType(3);
		bullet3->setDirection(1);

		this->addChild(bullet1);
		bulletList.pushBack(bullet1);

		this->addChild(bullet2);
		bulletList.pushBack(bullet2);

		this->addChild(bullet3);
		bulletList.pushBack(bullet3);

		//float height = bullet1->getContentSize().height;
		//float width = bullet1->getContentSize().width;

		//calculate fly time 
		/*float flyVelocity = PLANE_BULLET_SPEED;
		float flyLen = visibleSize.width + width;
		float realFlyDuration = flyLen / flyVelocity;

		auto actionMove1 = MoveBy::create(realFlyDuration, Point(0, visibleSize.height + height));
		auto actionMove2 = MoveBy::create(realFlyDuration, Point(0, visibleSize.height + height));
		auto actionMove3 = MoveBy::create(realFlyDuration, Point(0, visibleSize.height + height));

		auto actionDone = CallFuncN::create(CC_CALLBACK_1(BulletLayer::bulletRemoveFromActin, this));

		Sequence* sequence1 = Sequence::create(actionMove1, actionDone, NULL);
		Sequence* sequence2 = Sequence::create(actionMove2, actionDone, NULL);
		Sequence* sequence3 = Sequence::create(actionMove3, actionDone, NULL);

		bullet1->runAction(sequence1);
		bullet2->runAction(sequence2);
		bullet3->runAction(sequence3);*/

		break;
	}
	default:
		break;
	}

}

void BulletLayer::autoBulletCreate()
{
	auto plane = SelfPlane::sharedPlane;

	if (plane->getLevel() >= 3)
	{
		auto bullet = Bullet::create("bullet.png");
		bullet->setPosition(plane->getPosition());
		bullet->setType(4);
		bullet->setTag(PLANE_BULLET_TAG);

		this->addChild(bullet);
		this->bulletList.pushBack(bullet);
	}
}

void BulletLayer::enemyBulletCreate()
{
	auto enemyList = EnemyPlaneLayer::sharedEnemy->getEnemyList();

	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("enemy_bullet.plist");

	for (int i = 0; i < enemyList.size(); i++)
	{
		auto bullet = Bullet::createWithSpriteFrameName("W2.png");

		auto enemy = enemyList.at(i);

		bullet->setPosition(enemy->getPositionX(), enemy->getPositionY() - 30);
		bullet->setTag(ENEMY_BULLET_TAG);

		this->addChild(bullet);
		bulletList.pushBack(bullet);
	}
}

Vector<Bullet* > BulletLayer::getBulletList()
{
	return this->bulletList;
}

void BulletLayer::bulletRemove(Bullet* sprite)
{
	sprite->removeFromParent();
	this->bulletList.eraseObject(sprite);
}

void BulletLayer::bulletRemoveFromActin(Node * pNode)
{
	if (NULL == pNode) {
		return;
	}
	Bullet* plane = (Bullet*)pNode;
	this->bulletRemove(plane);
	this->removeChild(plane, true);
}