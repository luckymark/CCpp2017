#ifndef _GAME_OVER_H_
#define _GAME_OVER_H_

#include "cocos2d.h"
#include "SelfPlane.h"

class GameOver : public cocos2d::Layer
{
public:
	static cocos2d::Scene* createScene();

	CREATE_FUNC(GameOver);

	virtual bool init();

};
#endif // !_GAME_OVER_H_

