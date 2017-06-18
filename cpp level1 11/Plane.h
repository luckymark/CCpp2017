#pragma once
#include "stdafx.h"
#define weaponnumber 2
class Plane
{
public:
	 static float pointX;
	 static float pointY;
	 static float width;
	 static float height;
	 static int weaponStatus;
	 static int efflag;
	 static int mefflag;
	 sf::Texture image;
	

	Plane(int width, int height);
	void MoveLeft(float timeDelta);
	void MoveRight(float timeDelta);
	void MoveUp(float timeDelta);
	void MoveDown(float timeDelta);
	void WeaponChange();
	void draw();
	friend class NormalBullet;
};

