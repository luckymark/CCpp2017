#include "stdafx.h"
#include "My_plane.h"


My_plane::My_plane()
{
	my_plane_life = 50;//��ͨ�ӵ���Ҫ�����
	show_Myplane=1;
	shooted_time = 0;
	myplane_explode[0] = "image/plane1.png";
	myplane_explode[1] = "image/plane2.png";
	myplane_explode[2] = "image/plane3.png";
	myPlane_filename="image/shoot.png";//�ļ���
	if(!myPlane_image.loadFromFile(myPlane_filename)) //������ȡͼƬ
	{
		cout << "your plane load failed!";
	}
	myPlane_sprite.setTexture(myPlane_image);//�����洢ͼƬ
	my_Plane_width = (float)myPlane_image.getSize().x;                                      
	my_Plane_height = (float)myPlane_image.getSize().y;
	My_plane_speed = 40;
	My_x = -500 + my_Plane_width / 2;
	My_y = -700 + my_Plane_height;
	myPlane_sprite.setOrigin(My_x,My_y);
	super_plane = 0;
	Myplane_type = "common";
}


My_plane::~My_plane()
{
}

Sprite My_plane::get_myPlane_sprite()
{
	return myPlane_sprite;
}
string  My_plane::get_myPlane_filename()
{
	return myPlane_filename;
}
Texture  My_plane::getTexture()
{
	return myPlane_image;
}


int My_plane::get_shooted_time()
{
	return shooted_time;
}

int My_plane::get_Myplane_life()
{
	return my_plane_life;
}

float My_plane::get_My_x()
{
	return My_x;
}
float My_plane::get_My_y()
{
	return My_y;
}