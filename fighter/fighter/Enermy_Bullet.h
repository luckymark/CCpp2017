#pragma once
#include "Object_manage.h"
class Enermy;
class Object_manage;
class Enermy_Bullet
{
public:
	Enermy_Bullet(Enermy *en);
	~Enermy_Bullet();
protected:
	string Enermy_Bullet_filename;//文件名
	Texture Enermy_Bullet_image;//用来读取图片
	Sprite Enermy_Bullet_sprite;//用来存图片
	int Enermy_Bullet_height;
	int Enermy_Bullet_width;
	int Bullet_is_on_screen;
	int had_flew_out;
	int aggressivity;//攻击力
	float Enermy_Bullet_x;
	float Enermy_Bullet_y;
	int Enermy_Bullet_speed;
	int Enermy_Bullet_is_new;
	static int m;
	static int Enermy_BulletMax_speed;
	friend class Object_manage;
};

