#pragma once
#include "Object_manage.h"
class My_plane;
class MyPlane_explode
{
public:
	MyPlane_explode(My_plane *my);
	~MyPlane_explode();
private:
	string _filename;//�ļ���
	Texture _image;//������ȡͼƬ
	Sprite _sprite;//������ͼƬ
	float _x;
	float _y;
	friend class Object_manage;
};

