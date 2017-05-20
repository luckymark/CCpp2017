#ifndef _SELF_PLANE_LAYER_H_
#define _SELF_PLANE_LAYER_H_

#define OFFSET 5
#define PLANE_TAG 103
#define BULLET_TAG 107

#include "cocos2d.h"
#include "SelfPlane.h"

class SelfPlaneLayer :public cocos2d::Layer
{
public:
	//static cocos2d::Scene* createScene();

	virtual bool init();

	virtual void update(float dt);

	CREATE_FUNC(SelfPlaneLayer);

private:
	std::map<cocos2d::EventKeyboard::KeyCode, bool> keys;

	cocos2d::Vector<cocos2d::Sprite* > bulletList;

	void bulletCreate(float f);

	void bulletMove(float f);

	void onKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event);

	void onKeyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event);

	bool isKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode);

	void keyPressedDuration(cocos2d::EventKeyboard::KeyCode keyCode);
};

#endif