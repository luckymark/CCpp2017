// fighter.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "My_plane.h"
#include "Object_manage.h"
#include "Enermy.h"
#include "Fly_BUlllet.h"
#include "Quicker_killer.h"
#include "rocket.h"
int window_width = 1000;
int window_heigth = 700;
RenderWindow the_window(VideoMode(window_width,window_heigth), "here! let's fight the plane");
multimap<string, My_plane*>  My_plane_list;//���ҵķɻ�
vector<MyBullet*>  MyBullet_list;//���ҵ��ӵ�
vector<Fly_BUlllet*>  Fly_BUlllet_list;//����
vector<Quicker_killer*> quickBUllet_list;//�㶮�ĵ��Ǹ��ر�ǿ��Ĺ���
std::vector<Enermy_Bullet*> Enermy_Bullet_list;//����������е�Bullet
vector<Enermy*> Enermy_list;//��ʾ����Ļ�ϵķɻ�
std::vector<MyPlane_explode *> myplane_exploded_list;
Enermy *Object_manage::pointer[5] = { NULL};
int Enermy::EnermyMax_Speed = 1;
int Enermy::Screen_max_enermy = 10;
int Enermy_Bullet::Enermy_BulletMax_speed = 2;
int Enermy::update_time =1;
int Object_manage::update_now=1;
int My_plane::space_time = 0;
int Enermy_Bullet::m = 0;
int Fly_BUlllet::is_first = 1;
int Object_manage::now_add_Help_pack = 0;
int Object_manage::need_update_superBullet = 0;
int background::background_order=1;
rocket* Object_manage::ro= new rocket;
int main()
{
	/*char ahh[50];
	int m = 1000;
	_itoa_s(m, ahh, 10);
    sf::Font font;
	string filename0;//�ļ���
	Texture image0;//������ȡͼƬ
	Sprite sprite0;//������ͼƬ
	Text a;
	if (!font.loadFromFile("font/stheitisc.ttf"))
	{
		cout << "�������ʧ�ܣ�";
	}
	string  i = "100";
	a.setFont(font);
	a.setString(ahh);
	sf::Color  color = Color::Red;
	a.setFillColor(color);
	a.setCharacterSize(30);
	a.setPosition(500,350);
	the_window.draw(a);
	the_window.display();
	Sleep(60000000);
	*/
    Object_manage manager;
	
    manager.game_start();
    return 0;
}

