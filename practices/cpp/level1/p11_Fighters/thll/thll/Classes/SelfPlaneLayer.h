#ifndef _SELF_PLANE_LAYER_H_
#define _SELF_PLANE_LAYER_H_

#define OFFSET 5
#define PLANE_TAG 103

#include "cocos2d.h"
#include "SelfPlane.h"
#include "BulletLayer.h"
#include "BombSplashScreen.h"
#include "Audio.h"

class SelfPlaneLayer :public cocos2d::Layer
{
public:
	static cocos2d::Scene* createScene();

	virtual bool init();

	static SelfPlaneLayer* create();

	cocos2d::Node* getPlane();

	void planeUpdate(cocos2d::EventKeyboard::KeyCode keyCode);

	void planeUpdate();

	void startShooting();

	void planeRunAction();

	void setKeyReleased(cocos2d::EventKeyboard::KeyCode keyCode);

	bool isKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode);

	static SelfPlaneLayer* sharedPlaneLayer;

private:

	cocos2d::RenderTexture *renderTexture;

	std::map<cocos2d::EventKeyboard::KeyCode, bool> keys;

	void onKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event);

	void onKeyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event);

	void keyPressedDuration(cocos2d::EventKeyboard::KeyCode keyCode);
};
#endif