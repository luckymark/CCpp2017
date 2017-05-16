#ifndef _GAME_SCENE_H_
#define _GAME_SCENE_H_

#include "cocos2d.h"
#include <map>

class GameScene : public cocos2d::Layer
{
public:
	static cocos2d::Scene* createScene();

	virtual bool init();

	virtual void update(float delta);

	CREATE_FUNC(GameScene);


private:
	cocos2d::Sprite* plane;

	std::map<cocos2d::EventKeyboard::KeyCode, bool> keys;

	void onKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event);

	void onKeyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event);

	bool isKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode);

	void keyPressedDuration(cocos2d::EventKeyboard::KeyCode keyCode);
};

#endif
