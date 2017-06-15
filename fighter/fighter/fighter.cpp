// fighter.cpp : 定义控制台应用程序的入口点。
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
multimap<string, My_plane*>  My_plane_list;//放我的飞机
vector<MyBullet*>  MyBullet_list;//放我的子弹
vector<Fly_BUlllet*>  Fly_BUlllet_list;//放榴弹
vector<Quicker_killer*> quickBUllet_list;//你懂的的那个特别强大的功能
std::vector<Enermy_Bullet*> Enermy_Bullet_list;//用来存放所有的Bullet
vector<Enermy*> Enermy_list;//显示在屏幕上的飞机
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
	string filename0;//文件名
	Texture image0;//用来读取图片
	Sprite sprite0;//用来存图片
	Text a;
	if (!font.loadFromFile("font/stheitisc.ttf"))
	{
		cout << "字体加载失败！";
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

