#pragma once
#include "stdafx.h"
#include "Plane.h"
class ObjectManager
{
private:
	int flag = 0;
public:
	void PlaneUpdate(Plane &plane);
	void ObjectManager::BulletUpdate(Bullet *bullet);
	bool FullOrEmpty(int i);
};

