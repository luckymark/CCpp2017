#include "stdafx.h"
#include "rocket.h"

extern int window_width;
extern int window_heigth;
rocket::rocket()
{
	filename = "image/rocket.psd";//文件名
	if (!image.loadFromFile(filename))//用来读取图片
	{
		cout << "火箭加载失败！";
	}
	height = image.getSize().y;
	sprite.setTexture(image);//用来存图片
	sprite.setOrigin(0,-window_heigth+5*(height/4));
	cout << -window_heigth + 2*height;
}


rocket::~rocket()
{
}
