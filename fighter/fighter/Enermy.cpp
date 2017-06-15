#include "stdafx.h"
#include "Enermy.h"
extern int window_width;
extern int window_heigth;
//class Object_manage;

Enermy::Enermy()
{
	float time_temp;
	srand((unsigned)time(NULL));
	time_temp = rand() % 500+500;
	update_EnermyBullet_time = sf::seconds(time_temp/1000.0);//60毫秒
	explode_time0 = 0;
	shooted_time = 0;
	is_new = 1;
	is_on_screen = 0;
	srand((unsigned)time(NULL));
	int i = rand() % 3;
	switch (i)
	{
		case 0:Enermy_filename = "image/p0.png"; life = 3; explode[0]="image/cc_1.png"; explode[1] = "image/cc_2.png"; explode[2] = "image/cc_3.png"; break;
		case 1:Enermy_filename = "image/p1.png"; life = 1; explode[0] = "image/bb.png"; explode[1] = "image/bb.png"; explode[2] = "image/bb.png"; break;
		case 2:Enermy_filename = "image/p2.png"; life = 6; explode[0] = "image/aa_1.png"; explode[1] = "image/aa_2.png"; explode[2] = "image/aa_3.png"; break;
		default:
			break;
	}

	if (!Enermy_image.loadFromFile(Enermy_filename))//用来读取图片
	{
//cout << "Enermies load failed!";
}
Enermy_sprite.setTexture(Enermy_image);//用来存储图片
Enermy_width = Enermy_image.getSize().x;
Enermy_height = Enermy_image.getSize().y;
srand((unsigned)time(0));
Enermy_speed = rand()% Enermy::EnermyMax_Speed+1;//敌机快一点
Enermy_x =- (rand()%window_width)+1;//敌机的位置在屏幕内
//cout << Enermy_x << endl;
Enermy_y= Enermy_height/2;//从最上面下来
Enermy_sprite.setOrigin(Enermy_x, Enermy_y);
//用this指针试试
}
Enermy::~Enermy()
{
	//cout << "敌人析构";
}

float Enermy::get_x()
{
	return Enermy_x;
}

float Enermy::get_y()
{
	return Enermy_y;
}
string *Enermy::get_explode()
{
	return explode;
}