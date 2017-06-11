#ifndef _BOSS_H_
#define _BOSS_H_

#define BOSS_TAG 233

#include "cocos2d.h"

class Boss :public cocos2d::Sprite
{
public:
	static Boss* create(const std::string& filename);

	static Boss* createWithSpriteFrameName(const std::string& filename);

	static Boss* create();

	static Boss* sharedBoss;

	virtual bool init();

	void setDeleted(bool is);

	bool isDeleted();

	void lifeDecreased(int attack);

	bool isLifeEmpty();

private:
	
	int life = 1000;

	bool deleted = false;
};
#endif // !_BOSS_H_

