#pragma once
class Object_manage;
class Quicker_killer
{
public:
	Quicker_killer(int order);
	~Quicker_killer();
	int get_width();
	int get_x();
	int get_y();
	int get_speed();
private:
	string filename;//�ļ���
	Texture image;//������ȡͼƬ
	Sprite sprite;//������ͼƬ
	int width;
	int speed;
	int height;
	int __x;
	int __y;
	friend class Object_manage;
};

