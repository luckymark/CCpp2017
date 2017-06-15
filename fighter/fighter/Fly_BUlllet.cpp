#include "stdafx.h"
#include "Fly_BUlllet.h"
extern int window_width;
extern int window_heigth;

Fly_BUlllet::Fly_BUlllet()
{
	Object_manage *a=new Object_manage;
	if (a->get_Update_help())
	{
		Fly_BUlllet_filename = "image/help.psd";
	}
    else 
	{
		if (is_first == 1)
		{
			Fly_BUlllet_filename = "image/3.1s.png";
			is_first = 0;
		}
		else
		{
			Fly_BUlllet_filename = "image/3.3s.png";
			is_first = 1;
		}
	}

	if (!Fly_BUlllett_image.loadFromFile(Fly_BUlllet_filename))//用来读取图片
	{
		cout << "Fly_BUlllett load failed!";
	}
	left_or_right = rand() % 2 + 1;//1或者2,1代表左，2代表右
	Fly_BUlllet_sprite.setTexture(Fly_BUlllett_image);//用来存储图片
	//int Fly_BUlllet_height;
	Fly_BUlllet_width= (float)Fly_BUlllett_image.getSize().x;
	Fly_BUlllet_height = (float)Fly_BUlllett_image.getSize().y;
	//cout << Fly_BUlllet_width<<endl;
	srand((unsigned)time(NULL));
	Fly_just_now = 1;
	Fly_BUlllet_x = -rand()%((int)(window_width-Fly_BUlllet_width))+1;
	//system("cls");

	/*if (Fly_BUlllet_x >= -window_width/2)
	{
		//cout << "宽：" << window_width<<endl;
		left_or_right = 2;
	}
	else
	{
		left_or_right =1;
	}*/
	//cout <<"左右："<<left_or_right << endl;
	Fly_BUllet_y = 0;
	Fly_BUlllet_y_plus =  1;//y方向上的增量
	angle = rand()%45;//害怕角度太小飞下来很慢
	if (Fly_BUlllet_filename == "image/help.psd")
	{
		srand((unsigned)time(NULL));
		int t = window_width - 2 * Fly_BUlllet_width;
		Fly_BUlllet_x = -rand()%t;
		Fly_BUllet_y = -rand()%(window_heigth /2);//只在上半平面
		if (Fly_BUlllet_x > -Fly_BUlllet_width)
		{
			Fly_BUlllet_x = -3*Fly_BUlllet_width;
		}
		if (abs(Fly_BUllet_y)<2*Fly_BUlllet_height)
		{
			Fly_BUllet_y = -10*Fly_BUlllet_height;
		}
	}
	delete a;
}


Fly_BUlllet::~Fly_BUlllet()
{
}
