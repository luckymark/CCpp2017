#pragma once
class Explode
{
public:
	Explode();
	~Explode();
private:
	string _filename;//�ļ���
	Texture _image;//������ȡͼƬ
	Sprite _sprite;//������ͼƬ
	float _x;
	float _y;
	friend class Object_manage;
};

