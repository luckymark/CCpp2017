#pragma once
class Object_manage;
class background
{
public:
	background(string filename);
	~background();
	Sprite get_background();
	friend class  Object_manage;
private:
	string filename0;//�ļ���
	Texture image0;//������ȡͼƬ
	Sprite sprite0;//������ͼƬ
	static int background_order;

};

