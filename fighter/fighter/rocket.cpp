#include "stdafx.h"
#include "rocket.h"

extern int window_width;
extern int window_heigth;
rocket::rocket()
{
	filename = "image/rocket.psd";//�ļ���
	if (!image.loadFromFile(filename))//������ȡͼƬ
	{
		cout << "�������ʧ�ܣ�";
	}
	height = image.getSize().y;
	sprite.setTexture(image);//������ͼƬ
	sprite.setOrigin(0,-window_heigth+5*(height/4));
	cout << -window_heigth + 2*height;
}


rocket::~rocket()
{
}
