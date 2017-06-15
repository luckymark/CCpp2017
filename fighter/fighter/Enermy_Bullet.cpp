#include "stdafx.h"
#include "Enermy_Bullet.h"
#include "Enermy.h"




Enermy_Bullet::Enermy_Bullet(Enermy *en)
{

	//cout << m << endl;
	if ("image/p0.png" == en->Enermy_filename)
	{
		Enermy_Bullet_filename = "image/2_s.png";
	}
	if ("image/p1.png" == en->Enermy_filename)
	{
		Enermy_Bullet_filename = "image/MyBullet0.png";
	}
	if ("image/p2.png" == en->Enermy_filename)
	{
		srand((unsigned)time(NULL));
		int t = rand() % 3;
		//cout <<t<< endl;
		switch (t)
		{
		case 0:Enermy_Bullet_filename = "image/0_s.png"; m++; break;
		case 1:Enermy_Bullet_filename = "image/0_s.png"; m++; break;
		case 2:Enermy_Bullet_filename = "image/0_s.png"; m++; break;
		default:
			break;
		}
	}
	if ("image/MyBullet.png" == Enermy_Bullet_filename)//设置子弹的攻击力
	{
		aggressivity = 1;
	}
	else
	{
		aggressivity = 3;
	}
	Enermy_Bullet_is_new = 1;
	if (!Enermy_Bullet_image.loadFromFile(Enermy_Bullet_filename))//用来读取图片
	{
		//cout << "your Bullet load failed!";
	}
	Enermy_Bullet_sprite.setTexture(Enermy_Bullet_image);//用来存储图片
	Enermy_Bullet_width = Enermy_Bullet_image.getSize().x;
	Enermy_Bullet_height = Enermy_Bullet_image.getSize().y;
	Enermy_Bullet_speed = 6;
	if (Enermy_Bullet_filename == "image/3.1s.png" || Enermy_Bullet_filename == "image/3.2s.png" || Enermy_Bullet_filename == "image/3.3s.png")
	{
		Enermy_Bullet_speed = 10;
	}
	if (en->Enermy_width > Enermy_Bullet_width)
	{
		Enermy_Bullet_x = en->Enermy_x - (en->Enermy_width / 2 - Enermy_Bullet_width / 2);
	}
	else
	{
		Enermy_Bullet_x = en->Enermy_x + Enermy_Bullet_width / 2 - en->Enermy_width / 2;
	}
	/*if ("image/p1.png" == en->Enermy_filename)
	{
		Enermy_Bullet_x += 2;
	}*/
	Enermy_Bullet_y = en->Enermy_y - en->Enermy_height;//认为y是上表面距离窗口边缘的距离
	Enermy_Bullet_sprite.setOrigin(Enermy_Bullet_x, Enermy_Bullet_y);
}


Enermy_Bullet::~Enermy_Bullet()
{
	//cout << "shanchuZD";
}
