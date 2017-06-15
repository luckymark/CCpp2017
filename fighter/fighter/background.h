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
	string filename0;//文件名
	Texture image0;//用来读取图片
	Sprite sprite0;//用来存图片
	static int background_order;

};

