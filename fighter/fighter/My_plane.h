#pragma once
#include "stdafx.h"
//#include "Object_manage.h"
#include "MyBullet.h"
#include "MyPlane_explode.h"
class Object_manage;
class My_plane
{
public:
	My_plane();
	~My_plane();
	Sprite get_myPlane_sprite();
	string get_myPlane_filename();
	int get_shooted_time();
	int get_Myplane_life();
	float get_My_x();
	float get_My_y();
	//string get_myPlane_filename();
	//Sprite set_myPlane_position();
	//void  set_myPlane_image();     
	//void show_myplane(RenderWindow &main_window);
	Texture getTexture();
	friend class Object_manage;
	friend class MyBullet;
private:
	string myPlane_filename;//文件名
	Texture myPlane_image;//用来读取图片
	Sprite myPlane_sprite;//用来存图片
	float my_Plane_height;
	float my_Plane_width;
	float My_x;
	float My_y;
	int My_plane_speed;
	int my_plane_life;
	int shooted_time;
	int the_Bullet_order;
	string myplane_explode[3];
	string Myplane_type;
	int show_Myplane;
	int super_plane;
	static int space_time;
	//static multimap<string,My_plane> My_plane_list;	
};


