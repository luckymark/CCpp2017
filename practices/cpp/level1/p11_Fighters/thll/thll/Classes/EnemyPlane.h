#ifndef _ENEMY_PLANE_H_
#define _ENEMY_PLANE_H_

#include "cocos2d.h"

class EnemyPlane :public cocos2d::Sprite
{
public:
	static EnemyPlane* create(const std::string& filename);

	void setDeleted(bool is);

	bool isDeleted();

private:
	bool deleted;
};
#endif