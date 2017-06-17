#pragma once
#include "Object_manage.h"
class Fly_BUlllet
{
public:
	Fly_BUlllet();
	~Fly_BUlllet();
	protected:
		string Fly_BUlllet_filename;//文件名
		Texture Fly_BUlllett_image;//用来读取图片
		Sprite Fly_BUlllet_sprite;//用来存图片
	    float  Fly_BUlllet_height;
		float Fly_BUlllet_width;
		int left_or_right;
		int angle;//角度
		double  Fly_BUlllet_x;
		double Fly_BUlllet_y_plus;//增量
		double  Fly_BUllet_y;
		int Fly_just_now;
		static int is_first;
		const sf::Time eraser_helpPack = sf::seconds(3.0f);
		Time del_helppack;
		sf::Clock delete_helpbag;
		friend class Object_manage;

};

