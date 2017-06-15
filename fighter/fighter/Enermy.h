#pragma once
#include "stdafx.h"
#include "Object_manage.h"
#include "Explode.h"
#include "Enermy_Bullet.h"
#include "Explode_enermy.h"
//class Object_manage;
class Enermy_Bullet;
class Explode_enermy;
class Enermy//每个敌人有自己爆炸的的图片
{
public:
	//Enermy(string fileName, string Bullet_filename);
	Enermy();
	~Enermy();
	float get_x();
	float get_y();
	string* get_explode();
private:
	deque<Explode_enermy*> exploed_plane;
	string Enermy_filename;//文件名
	Texture Enermy_image;//用来读取图片
	Sprite Enermy_sprite;//用来存图片
	int Enermy_height;
	int Enermy_width;
	float Enermy_x;
	float Enermy_y;
	int Enermy_speed;
	int is_new;
	int is_on_screen;
	int shooted_time;
	int life;
	int explode_time0;
	string explode[3];
	static int EnermyMax_Speed;
	static int Screen_max_enermy;
	static int update_time;
	friend class Object_manage;
	friend class Enermy_Bullet;
	sf::Time update_EnermyBullet_time;//60毫秒
	//sf::Time update_EnermyBullet_time = sf::milliseconds(10);//60毫秒
	Time time0;
	sf::Clock clock0;//构造的时候开始计时
	//map<int, Explode *> Explode_Image_list;
};

