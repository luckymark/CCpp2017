#ifndef _ENEMY_PLANE_MEDIUM_H_
#define _ENEMY_PLANE_MEDIUM_H_

#include "EnemyPlane.h"

class EnemyPlaneMedium :public EnemyPlane
{
public:

	static EnemyPlaneMedium* create(const std::string& filename);

	int getLife();

	void lifeDecresed(int attack);

	bool isLifeEmpty();

private:
	int life = 50;
};
#endif