#pragma once
#include "Object_manage.h"
//class Object_manage;
class MyBullet
{
public:
	MyBullet();
protected:
	string MyBullet_filename;//�ļ���
	Texture MyBullet_image;//������ȡͼƬ
	Sprite MyBullet_sprite;//������ͼƬ
	int MyBullet_height;
	int MyBullet_width;
	float MyBullet_x;
	float MyBullet_y;
	int MyBullet_speed;
	friend class Object_manage;
	//static multimap<string,My_plane> My_plane_list;

};