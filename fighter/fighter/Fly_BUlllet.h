#pragma once
#include "Object_manage.h"
class Fly_BUlllet
{
public:
	Fly_BUlllet();
	~Fly_BUlllet();
	protected:
		string Fly_BUlllet_filename;//�ļ���
		Texture Fly_BUlllett_image;//������ȡͼƬ
		Sprite Fly_BUlllet_sprite;//������ͼƬ
	    float  Fly_BUlllet_height;
		float Fly_BUlllet_width;
		int left_or_right;
		int angle;//�Ƕ�
		double  Fly_BUlllet_x;
		double Fly_BUlllet_y_plus;//����
		double  Fly_BUllet_y;
		int Fly_just_now;
		static int is_first;
		const sf::Time eraser_helpPack = sf::seconds(3.0f);
		Time del_helppack;
		sf::Clock delete_helpbag;
		friend class Object_manage;

};

