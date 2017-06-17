#pragma once
#include "Object_manage.h"
#include "Enermy.h"
class Enermy;
class Explode_enermy
{
public:
	Explode_enermy(Enermy *mm,int m);
	~Explode_enermy();
private:
	string _filename;//文件名
	Texture _image;//用来读取图片
	Sprite _sprite;//用来存图片
	float _x;
	float _y;
	friend class Object_manage;
	friend class Enermy;
};

