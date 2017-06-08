#ifndef _SELF_PLANE_H_
#define _SELF_PLANE_H_

#include "cocos2d.h"

class SelfPlane :public cocos2d::Sprite
{
public:
	static SelfPlane* create(const std::string& filename);

	static SelfPlane* sharedPlane;

	virtual bool init();

	void lifeDecreased();

	bool isLifeEmpty();

	void setInitialPosition();

	void addScore(int score);

	int getScore();

	void setNullPosition();

private:
	int life = 3;

	int score = 0;
};
#endif