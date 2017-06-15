#pragma once
#include "Object_manage.h"
class My_plane;
class MyPlane_explode
{
public:
	MyPlane_explode(My_plane *my);
	~MyPlane_explode();
private:
	string _filename;//文件名
	Texture _image;//用来读取图片
	Sprite _sprite;//用来存图片
	float _x;
	float _y;
	friend class Object_manage;
};

