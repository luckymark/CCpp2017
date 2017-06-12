#ifndef _GAME_PAUSE_LAYER_H_
#define _GAME_PAUSE_LAYER_H_

#include "cocos2d.h"

class GamePauseLayer:public cocos2d::Layer
{
public:
	static cocos2d::Scene* createScene(cocos2d::RenderTexture* sqr);

	static GamePauseLayer* create();

	virtual bool init();

	void buttonResumeCallBack();

	void buttonReturnCallBack();
};
#endif // !_GAME_PAUSE_LAYER_H_

