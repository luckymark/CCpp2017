#ifndef _SELF_PLANE_H_
#define _SELF_PLANE_H_

#define STATUS_SURVIVAL 0
#define STATUS_DEAD 1
#define STATUS_NO_ATTCK 2

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

	void setDead();

	void setReborn(long time);

	bool getIsDead();

	int getStatus(long time);

private:
	int status = 0;

	int life = 3;

	int score = 0;

	bool is_dead = false;

	long reborn_time = 0;
};
#endif