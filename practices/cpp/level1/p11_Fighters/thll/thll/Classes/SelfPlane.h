#ifndef _SELF_PLANE_H_
#define _SELF_PLANE_H_

#define STATUS_SURVIVAL 0
#define STATUS_DEAD 1
#define STATUS_NO_ATTCK 2
#define PLANE_LEVEL_1_SCORE 0
#define PLANE_LEVEL_2_SCORE 9
#define PLANE_LEVEL_3_SCORE 15

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

	int getLevel();

	void levelUp();

	void setLevel(int level);

private:

	int level = 1;

	int status = 0;

	int life = 3;

	int score = 0;

	bool is_dead = false;

	long reborn_time = 0;
};
#endif