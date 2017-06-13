#ifndef _BOMB_SPLASH_SCREEN_H_
#define _BOMB_SPLASH_SCREEN_H_

#include "cocos2d.h"
#include "SelfPlane.h"
#include "EnemyPlaneLayer.h"
#include "BulletLayer.h"

class BombSplashScreen :public cocos2d::Layer
{
public:
	static cocos2d::Scene* createScene(cocos2d::RenderTexture* sqr);

	static BombSplashScreen* create();

	void callBackFade();

	virtual bool init();
};
#endif // !_BOMB_SPLASH_SCREEN_H_

