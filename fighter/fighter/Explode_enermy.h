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
	string _filename;//�ļ���
	Texture _image;//������ȡͼƬ
	Sprite _sprite;//������ͼƬ
	float _x;
	float _y;
	friend class Object_manage;
	friend class Enermy;
};

