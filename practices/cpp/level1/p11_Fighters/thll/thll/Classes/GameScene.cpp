#include "GameScene.h"

USING_NS_CC;

Scene* GameScene::gameScene = nullptr;
SelfPlaneLayer* GameScene::planeLayer = nullptr;
EnemyPlaneLayer* GameScene::enemyLayer = nullptr;

Scene* GameScene::create()
{
	gameScene = Scene::createWithPhysics();

	planeLayer = SelfPlaneLayer::create();

	enemyLayer = EnemyPlaneLayer::create();

	gameScene->addChild(planeLayer);

	gameScene->addChild(enemyLayer);

	return gameScene;
}

SelfPlaneLayer* GameScene::getSelfPlaneLayer()
{
	return this->planeLayer;
}