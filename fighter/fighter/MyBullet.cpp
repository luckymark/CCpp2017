#include "stdafx.h"
#include "My_plane.h"
#include "MyBullet.h"
extern  multimap<string, My_plane*>  My_plane_list;
extern  multimap<string, MyBullet*>  MyBullet_list;

MyBullet::MyBullet()
{
	multimap<string, My_plane*>::iterator  it;
	it = My_plane_list.begin();//�ҵ��ö���
	MyBullet_filename = "image/MyBullet.png";//�ļ���
	if (!MyBullet_image.loadFromFile(MyBullet_filename))//������ȡͼƬ
	{
		cout << "your Bullet load failed!";
	}
	MyBullet_sprite.setTexture(MyBullet_image);//�����洢ͼƬ
	MyBullet_width = MyBullet_image.getSize().x;
	MyBullet_height = MyBullet_image.getSize().y;
	MyBullet_speed = 10;
	//MyBullet_y = 0;
	if (it->second->Myplane_type == "common")
	{
		MyBullet_y = it->second->My_y+3;// + it->second->my_Plane_height;
		MyBullet_x = it->second->My_x - it->second->my_Plane_width / 2+14;
	}
	else
	{
		MyBullet_y = it->second->My_y - it->second->my_Plane_height / 2;
		if (it->second->the_Bullet_order == 1)
		{
			MyBullet_x = it->second->My_x - it->second->my_Plane_width / 8+10;
		}
		else
		{
			MyBullet_x = it->second->My_x - 3*(it->second->my_Plane_width / 4)+10;
		}	
	}
	MyBullet_sprite.setOrigin(MyBullet_x, MyBullet_y);
}


