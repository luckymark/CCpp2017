#ifndef _GAME_LOADING_H_
#define _GAME_LOADING_H_

#include "cocos2d.h"
#include "GameScene.h"

class GameLoading :public cocos2d::Layer
{
public:
	static cocos2d::Scene* createScene();

	CREATE_FUNC(GameLoading);

	virtual bool init();

	void updateBackground(float dt);

	void loadingFinishedCallBack();
};
#endif // !_GAME_LOADING_H_

