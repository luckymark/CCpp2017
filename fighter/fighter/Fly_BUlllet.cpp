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

	if (!Fly_BUlllett_image.loadFromFile(Fly_BUlllet_filename))//������ȡͼƬ
	{
		cout << "Fly_BUlllett load failed!";
	}
	left_or_right = rand() % 2 + 1;//1����2,1������2������
	Fly_BUlllet_sprite.setTexture(Fly_BUlllett_image);//�����洢ͼƬ
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
		//cout << "��" << window_width<<endl;
		left_or_right = 2;
	}
	else
	{
		left_or_right =1;
	}*/
	//cout <<"���ң�"<<left_or_right << endl;
	Fly_BUllet_y = 0;
	Fly_BUlllet_y_plus =  1;//y�����ϵ�����
	angle = rand()%45;//���½Ƕ�̫С����������
	if (Fly_BUlllet_filename == "image/help.psd")
	{
		srand((unsigned)time(NULL));
		int t = window_width - 2 * Fly_BUlllet_width;
		Fly_BUlllet_x = -rand()%t;
		Fly_BUllet_y = -rand()%(window_heigth /2);//ֻ���ϰ�ƽ��
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
