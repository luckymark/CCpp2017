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
RenderWindow the_window(VideoMode(window_width, window_heigth), "here! let's fight the plane");
multimap<string, My_plane*>  My_plane_list;//放我的飞机
vector<MyBullet*>  MyBullet_list;//放我的子弹
vector<Fly_BUlllet*>  Fly_BUlllet_list;//放榴弹
vector<Quicker_killer*> quickBUllet_list;//你懂的的那个特别强大的功能
std::vector<Enermy_Bullet*> Enermy_Bullet_list;//用来存放所有的Bullet
vector<Enermy*> Enermy_list;//显示在屏幕上的飞机
std::vector<MyPlane_explode *> myplane_exploded_list;
Enermy *Object_manage::pointer[5] = { NULL };
int Enermy::EnermyMax_Speed = 1;
int Enermy::Screen_max_enermy = 10;
int Enermy_Bullet::Enermy_BulletMax_speed = 2;
int Enermy::update_time = 1;
int Object_manage::update_now = 1;
int My_plane::space_time = 0;
int Enermy_Bullet::m = 0;
int Fly_BUlllet::is_first = 1;
int Object_manage::now_add_Help_pack = 0;
int Object_manage::need_update_superBullet = 0;
int Object_manage::all_speed = 35000;
int background::background_order = 1;
int Object_manage::pass = 0;
rocket* Object_manage::ro = new rocket;
int main()
{
	Object_manage manager;
	manager.game_start();
	return 0;
}



//background.h
#pragma once
class Object_manage;
class background
{
public:
	background(string filename);
	~background();
	Sprite get_background();
	friend class  Object_manage;
private:
	string filename0;//文件名
	Texture image0;//用来读取图片
	Sprite sprite0;//用来存图片
	static int background_order;

};

//enermy.h
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

//enermy_Bullet.h
#pragma once
#include "Object_manage.h"
class Enermy;
class Object_manage;
class Enermy_Bullet
{
public:
	Enermy_Bullet(Enermy *en);
	~Enermy_Bullet();
protected:
	string Enermy_Bullet_filename;//文件名
	Texture Enermy_Bullet_image;//用来读取图片
	Sprite Enermy_Bullet_sprite;//用来存图片
	int Enermy_Bullet_height;
	int Enermy_Bullet_width;
	int Bullet_is_on_screen;
	int had_flew_out;
	int aggressivity;//攻击力
	float Enermy_Bullet_x;
	float Enermy_Bullet_y;
	int Enermy_Bullet_speed;
	int Enermy_Bullet_is_new;
	static int m;
	static int Enermy_BulletMax_speed;
	friend class Object_manage;
};

//explode.h
#pragma once
class Explode
{
public:
	Explode();
	~Explode();
private:
	string _filename;//文件名
	Texture _image;//用来读取图片
	Sprite _sprite;//用来存图片
	float _x;
	float _y;
	friend class Object_manage;
};

//explode_Enermy.h
#pragma once
#include "Object_manage.h"
#include "Enermy.h"
class Enermy;
class Explode_enermy
{
public:
	Explode_enermy(Enermy *mm, int m);
	~Explode_enermy();
private:
	string _filename;//文件名
	Texture _image;//用来读取图片
	Sprite _sprite;//用来存图片
	float _x;
	float _y;
	friend class Object_manage;
	friend class Enermy;
};

//Fly_Bullet.h
#pragma once
#include "Object_manage.h"
#include "Enermy.h"
class Enermy;
class Explode_enermy
{
public:
	Explode_enermy(Enermy *mm, int m);
	~Explode_enermy();
private:
	string _filename;//文件名
	Texture _image;//用来读取图片
	Sprite _sprite;//用来存图片
	float _x;
	float _y;
	friend class Object_manage;
	friend class Enermy;
};

//My_plane.h
#pragma once
#include "stdafx.h"
//#include "Object_manage.h"
#include "MyBullet.h"
#include "MyPlane_explode.h"
class Object_manage;
class My_plane
{
public:
	My_plane();
	~My_plane();
	Sprite get_myPlane_sprite();
	string get_myPlane_filename();
	int get_shooted_time();
	int get_Myplane_life();
	float get_My_x();
	float get_My_y();
	//string get_myPlane_filename();
	//Sprite set_myPlane_position();
	//void  set_myPlane_image();     
	//void show_myplane(RenderWindow &main_window);
	Texture getTexture();
	friend class Object_manage;
	friend class MyBullet;
private:
	string myPlane_filename;//文件名
	Texture myPlane_image;//用来读取图片
	Sprite myPlane_sprite;//用来存图片
	float my_Plane_height;
	float my_Plane_width;
	float My_x;
	float My_y;
	int My_plane_speed;
	int my_plane_life;
	int shooted_time;
	int the_Bullet_order;
	string myplane_explode[3];
	string Myplane_type;
	int show_Myplane;
	int super_plane;
	static int space_time;
	//static multimap<string,My_plane> My_plane_list;	
};


//My_Bullet.h
#pragma once
#include "stdafx.h"
//#include "Object_manage.h"
#include "MyBullet.h"
#include "MyPlane_explode.h"
class Object_manage;
class My_plane
{
public:
	My_plane();
	~My_plane();
	Sprite get_myPlane_sprite();
	string get_myPlane_filename();
	int get_shooted_time();
	int get_Myplane_life();
	float get_My_x();
	float get_My_y();
	//string get_myPlane_filename();
	//Sprite set_myPlane_position();
	//void  set_myPlane_image();     
	//void show_myplane(RenderWindow &main_window);
	Texture getTexture();
	friend class Object_manage;
	friend class MyBullet;
private:
	string myPlane_filename;//文件名
	Texture myPlane_image;//用来读取图片
	Sprite myPlane_sprite;//用来存图片
	float my_Plane_height;
	float my_Plane_width;
	float My_x;
	float My_y;
	int My_plane_speed;
	int my_plane_life;
	int shooted_time;
	int the_Bullet_order;
	string myplane_explode[3];
	string Myplane_type;
	int show_Myplane;
	int super_plane;
	static int space_time;
	//static multimap<string,My_plane> My_plane_list;	
};


//Object_manager.h

#pragma once
#include "stdafx.h"
#include "Object_manage.h"
#include "My_plane.h"
#include "Enermy.h"
#include "MyBullet.h"
#include "MyPlane_explode.h"
#include "background.h"
#include "Resolve_interface.h"
#include "start_interface.h"
#include "Fly_BUlllet.h"
#include "Quicker_killer.h"
#include "rocket.h"
class My_plane;
class MyBullet;
class Enermy;
class Fly_Bulllet;
class Quicker_killer;
class rocket;
class Object_manage
{
public:
	Object_manage();
	~Object_manage();
	void update_All();
	void display_All(RenderWindow &the_window);
	void add_MyBullet(MyBullet* Bullet);
	void add_Enermy();//添加敌人到我要显示的容器
	void add_Enermy_Bullet();
	void update_Myplane(RenderWindow &the_window);
	void update_MyBullet(RenderWindow &the_window);
	void update_Enermy(RenderWindow &the_window);
	void show_explode_myPlane(RenderWindow &the_window);
	void update_Enermy_Bullet(RenderWindow &the_window);
	void add_plane(string name, My_plane *my);//加入对象到容器
	void crash_detector();
	void add_Fly_bullet();
	void update_Fly_bullet();
	void update_manage();
	void update_background();
	void game_loop();
	void game_start();
	void add_quicker_plane();
	void update_quicker_plane();
	void add_rocket();
	void draw_life();
	void draw_lifeNumber();
	void draw_score();
	void draw_score_name();
	void draw_rocketname();
	void draw_rocketQuantity();
	void draw_end_score_();
	void draw_endScoreName();
	void draw_pass();
	void control_next();
	//void draw _rocket();
	//void draw_rocket_number();
	int  get_Update_help();
	double randa;
	static Enermy* pointer[5];
	static int update_now;

private:
	enum game_status { begin_just_now, is_playing, is_exiting, game_over, pass_barrier, failed };//刚开始，正在游戏，退出，游戏结束，过关
	string enermy_filename[5];
	string enermy_Bullet_filename[5];
	const sf::Time update_Fly_BUllet_time = sf::seconds(11.0f);//2秒
	const sf::Time update_Enermy_time = sf::seconds(1.0f);//2秒
	const sf::Time update_all_time = sf::seconds(0.001f);//0.1秒
	const sf::Time UPdate_Enermy = sf::seconds(0.001f);//0.1秒
	const sf::Time UPDate_HelpPack = sf::seconds(10.0f);
	int score_all;
	int kill_enermy;
	Time time;
	Time FlyBUllet_time;
	Time update_time;
	Time update_enermy;
	Time update_helpPack;
	game_status Game_state;
	background *bac[3];
	background *start_window;
	sf::Clock update_clock;
	sf::Clock clock;//构造的时候开始计时
	sf::Clock Flybullet_clock;
	sf::Clock Update_enermy;
	sf::Clock UPDATE_helpPack;
	int enermy_start;
	int flyBUllet_quantity;
	start_interface *p;//点击区域设计
	sf::Music shoot_sound;
	sf::Music enermy_exploed;
	sf::Music get;
	sf::Music use_bomb;
	static 	int now_add_Help_pack;
	static int need_update_superBullet;
	static rocket *ro;
	static int all_speed;
	static int pass;
	char temp[100];
	char temp0[100];
	char temp1[100];
	sf::Text life;
	sf::Text life_number;
	sf::Text score;
	sf::Text score_name;
	sf::Font font;
	sf::Text rocketname;
	sf::Text rocket_quantity;
	sf::Text _end_score;
	sf::Text _end_scorename;
	sf::Text _pass;
	sf::Text _pass1;
	//int screen_NO_enermies;
};

//Quicker_killer.h
#pragma once
class Object_manage;
class Quicker_killer
{
public:
	Quicker_killer(int order);
	~Quicker_killer();
	int get_width();
	int get_x();
	int get_y();
	int get_speed();
private:
	string filename;//文件名
	Texture image;//用来读取图片
	Sprite sprite;//用来存图片
	int width;
	int speed;
	int height;
	int __x;
	int __y;
	friend class Object_manage;
};

//resolve_intreface
#pragma once
#include "stdafx.h"
class Resolve_interface
{
public:
	Resolve_interface();
	~Resolve_interface();
};

//rocket.h
#pragma once
class Object_manage;
class rocket
{
public:
	rocket();
	friend class Object_manage;
	~rocket();
private:
	string filename;
	Texture image;
	Sprite sprite;
	int height;
};
//start_interface.h
#pragma once
#include "Resolve_interface.h"
//#include "Object_manage.h"
class Object_manage;
class start_interface
{
public:
	enum MenuResult { Nothing, Exit, Play };
	struct MenuItem
	{
	public:
		sf::Rect<int> rect;
		MenuResult action;
	};
	MenuResult GetMenuResponse(sf::RenderWindow& window);
	MenuResult HandleClick(int x, int y);
	start_interface();
	~start_interface();

	void design_click_area();
private:
	friend class Object_manage;
	list<MenuItem> _menuItems;
};

//stdafx.h
// stdafx.h : 标准系统包含文件的包含文件，
// 或是经常使用但不常更改的
// 特定于项目的包含文件
//

#pragma once

#include "targetver.h"

#include <stdio.h>
#include <tchar.h>



// TODO:  在此处引用程序需要的其他头文件


// stdafx.h : 标准系统包含文件的包含文件，
// 或是经常使用但不常更改的
// 特定于项目的包含文件
//

#pragma once

#include "targetver.h"

#include <stdio.h>
#include <tchar.h>

// TODO:  在此处引用程序需要的其他头文件


#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <map>
#include <deque>
#include <list>
#include <cmath>
//#include <essert.h>
#include "windows.h"
#include "iostream"
using namespace sf;
using namespace std;

//background.cpp
#include "stdafx.h"
#include "background.h"


background::background(string filename)
{
	filename0 = filename;//文件名
	if (filename0 != "image/start.psd")
	{
		if (background_order == 1)
		{
			filename0 = "image/background1.png";
			background_order = 2;
		}
		else
		{
			filename0 = "image/background2.png";
			background_order = 1;
		}
	}
	if (!image0.loadFromFile(filename0))//用来读取图片
	{
		//cout << "背景加载失败！";
	}
	sprite0.setTexture(image0);//用来存图片
	sprite0.setOrigin(0, 0);
}
Sprite background::get_background()
{
	return  sprite0;
}

background::~background()
{
}


//Enermy.cpp
#include "stdafx.h"
#include "Enermy.h"
extern int window_width;
extern int window_heigth;
//class Object_manage;

Enermy::Enermy()
{
	float time_temp;
	srand((unsigned)time(NULL));
	time_temp = rand() % 500 + 500;
	update_EnermyBullet_time = sf::seconds(time_temp / 1000.0);//60毫秒
	explode_time0 = 0;
	shooted_time = 0;
	is_new = 1;
	is_on_screen = 0;
	srand((unsigned)time(NULL));
	int i = rand() % 3;
	switch (i)
	{
	case 0:Enermy_filename = "image/p0.png"; life = 3; explode[0] = "image/cc_1.png"; explode[1] = "image/cc_2.png"; explode[2] = "image/cc_3.png"; break;
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
	Enermy_speed = rand() % Enermy::EnermyMax_Speed + 1;//敌机快一点
	Enermy_x = -(rand() % window_width) + 1;//敌机的位置在屏幕内
											//cout << Enermy_x << endl;
	Enermy_y = Enermy_height / 2;//从最上面下来
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


//Enermy_Bullet.cpp
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

//Explode.cpp
#include "stdafx.h"
#include "Explode.h"


Explode::Explode()
{
}


Explode::~Explode()
{
}

//Explode_enermy.cpp
#include "stdafx.h"
#include "Explode_enermy.h"
extern RenderWindow the_window;

Explode_enermy::Explode_enermy(Enermy *mm, int m)
{
	if (0 == m)
	{
		_filename = mm->get_explode()[0];
	}
	if (1 == m)
	{
		_filename = mm->get_explode()[1];
	}
	if (2 == m)
	{
		_filename = mm->get_explode()[2];
	}

	if (!_image.loadFromFile(_filename))
	{
		cout << "爆炸图片加载失败！";
	}
	_sprite.setTexture(_image);
	_x = mm->get_x();
	_y = mm->get_y();
	_sprite.setOrigin(_x, _y);
	the_window.draw(_sprite);
}


Explode_enermy::~Explode_enermy()
{
}

//fight.cpp
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
RenderWindow the_window(VideoMode(window_width, window_heigth), "here! let's fight the plane");
multimap<string, My_plane*>  My_plane_list;//放我的飞机
vector<MyBullet*>  MyBullet_list;//放我的子弹
vector<Fly_BUlllet*>  Fly_BUlllet_list;//放榴弹
vector<Quicker_killer*> quickBUllet_list;//你懂的的那个特别强大的功能
std::vector<Enermy_Bullet*> Enermy_Bullet_list;//用来存放所有的Bullet
vector<Enermy*> Enermy_list;//显示在屏幕上的飞机
std::vector<MyPlane_explode *> myplane_exploded_list;
Enermy *Object_manage::pointer[5] = { NULL };
int Enermy::EnermyMax_Speed = 1;
int Enermy::Screen_max_enermy = 10;
int Enermy_Bullet::Enermy_BulletMax_speed = 2;
int Enermy::update_time = 1;
int Object_manage::update_now = 1;
int My_plane::space_time = 0;
int Enermy_Bullet::m = 0;
int Fly_BUlllet::is_first = 1;
int Object_manage::now_add_Help_pack = 0;
int Object_manage::need_update_superBullet = 0;
int Object_manage::all_speed = 35000;
int background::background_order = 1;
int Object_manage::pass = 0;
rocket* Object_manage::ro = new rocket;
int main()
{
	Object_manage manager;
	manager.game_start();
	return 0;
}


//Fly_Bullet.cpp
#include "stdafx.h"
#include "Fly_BUlllet.h"
extern int window_width;
extern int window_heigth;

Fly_BUlllet::Fly_BUlllet()
{
	Object_manage *a = new Object_manage;
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
	Fly_BUlllet_width = (float)Fly_BUlllett_image.getSize().x;
	Fly_BUlllet_height = (float)Fly_BUlllett_image.getSize().y;
	//cout << Fly_BUlllet_width<<endl;
	srand((unsigned)time(NULL));
	Fly_just_now = 1;
	Fly_BUlllet_x = -rand() % ((int)(window_width - Fly_BUlllet_width)) + 1;
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
	Fly_BUlllet_y_plus = 1;//y方向上的增量
	angle = rand() % 45;//害怕角度太小飞下来很慢
	if (Fly_BUlllet_filename == "image/help.psd")
	{
		srand((unsigned)time(NULL));
		int t = window_width - 2 * Fly_BUlllet_width;
		Fly_BUlllet_x = -rand() % t;
		Fly_BUllet_y = -rand() % (window_heigth / 2);//只在上半平面
		if (Fly_BUlllet_x > -Fly_BUlllet_width)
		{
			Fly_BUlllet_x = -3 * Fly_BUlllet_width;
		}
		if (abs(Fly_BUllet_y)<2 * Fly_BUlllet_height)
		{
			Fly_BUllet_y = -10 * Fly_BUlllet_height;
		}
	}
	delete a;
}


Fly_BUlllet::~Fly_BUlllet()
{
}

//My_plane.cpp
#include "stdafx.h"
#include "My_plane.h"


My_plane::My_plane()
{
	my_plane_life = 5;//普通子弹需要打五次
	show_Myplane = 1;
	shooted_time = 0;
	myplane_explode[0] = "image/plane1.png";
	myplane_explode[1] = "image/plane2.png";
	myplane_explode[2] = "image/plane3.png";
	myPlane_filename = "image/shoot.png";//文件名
	if (!myPlane_image.loadFromFile(myPlane_filename)) //用来读取图片
	{
		cout << "your plane load failed!";
	}
	myPlane_sprite.setTexture(myPlane_image);//用来存储图片
	my_Plane_width = (float)myPlane_image.getSize().x;
	my_Plane_height = (float)myPlane_image.getSize().y;
	My_plane_speed = 40;
	My_x = -500 + my_Plane_width / 2;
	My_y = -700 + my_Plane_height;
	myPlane_sprite.setOrigin(My_x, My_y);
	super_plane = 0;
	Myplane_type = "common";
}


My_plane::~My_plane()
{
}

Sprite My_plane::get_myPlane_sprite()
{
	return myPlane_sprite;
}
string  My_plane::get_myPlane_filename()
{
	return myPlane_filename;
}
Texture  My_plane::getTexture()
{
	return myPlane_image;
}


int My_plane::get_shooted_time()
{
	return shooted_time;
}

int My_plane::get_Myplane_life()
{
	return my_plane_life;
}

float My_plane::get_My_x()
{
	return My_x;
}
float My_plane::get_My_y()
{
	return My_y;
}

//My_bullet.cpp
#include "stdafx.h"
#include "My_plane.h"
#include "MyBullet.h"
extern  multimap<string, My_plane*>  My_plane_list;
extern  multimap<string, MyBullet*>  MyBullet_list;

MyBullet::MyBullet()
{
	multimap<string, My_plane*>::iterator  it;
	it = My_plane_list.begin();//找到该对象
	MyBullet_filename = "image/MyBullet.png";//文件名
	if (!MyBullet_image.loadFromFile(MyBullet_filename))//用来读取图片
	{
		cout << "your Bullet load failed!";
	}
	MyBullet_sprite.setTexture(MyBullet_image);//用来存储图片
	MyBullet_width = MyBullet_image.getSize().x;
	MyBullet_height = MyBullet_image.getSize().y;
	MyBullet_speed = 10;
	//MyBullet_y = 0;
	if (it->second->Myplane_type == "common")
	{
		MyBullet_y = it->second->My_y + 3;// + it->second->my_Plane_height;
		MyBullet_x = it->second->My_x - it->second->my_Plane_width / 2 + 14;
	}
	else
	{
		MyBullet_y = it->second->My_y - it->second->my_Plane_height / 2;
		if (it->second->the_Bullet_order == 1)
		{
			MyBullet_x = it->second->My_x - it->second->my_Plane_width / 8 + 10;
		}
		else
		{
			MyBullet_x = it->second->My_x - 3 * (it->second->my_Plane_width / 4) + 10;
		}
	}
	MyBullet_sprite.setOrigin(MyBullet_x, MyBullet_y);
}



//Myplane_explode.cpp
#include "stdafx.h"
#include "MyPlane_explode.h"
extern RenderWindow the_window;
MyPlane_explode::MyPlane_explode(My_plane *my)
{

	if (my->get_shooted_time() < my->get_Myplane_life() / 3)
	{
		_filename = "image/plane1.png";
		//cout << "爆炸加载了";
	}
	else if (my->get_shooted_time()  >  2 * (my->get_Myplane_life() / 3))
	{
		_filename = "image/plane2.png";
		//cout << "2爆炸加载";
	}
	else
	{
		_filename = "image/plane3.png";
	}
	if (!_image.loadFromFile(_filename)) //用来读取图片
	{
		//cout << "your plane_exploding load failed!"<<_filename;
	}
	_sprite.setTexture(_image);//用来存图片
	_x = my->getTexture().getSize().x;
	_y = my->getTexture().getSize().y;
	_sprite.setOrigin(my->get_My_x(), my->get_My_y());
	the_window.draw(_sprite);
}


MyPlane_explode::~MyPlane_explode()
{
}

//Object_manage.cpp

#include "stdafx.h"
#include "Object_manage.h"
class Enermy;
extern RenderWindow the_window;
extern  multimap<string, My_plane*>  My_plane_list;
extern  vector<MyBullet*>  MyBullet_list;
extern std::vector<Enermy_Bullet*> Enermy_Bullet_list;//用来存放所有的Bullet
extern vector<Enermy*> Enermy_list;//显示在屏幕上的飞机
extern std::vector<MyPlane_explode *> myplane_exploded_list;
extern int window_width;
extern int window_heigth;
extern vector<Fly_BUlllet*>  Fly_BUlllet_list;//放榴弹
extern vector<Quicker_killer*> quickBUllet_list;//你懂的的那个特别强大的功能
Object_manage::Object_manage()
{
	srand((unsigned)std::time(NULL));
	//Fly_BUlllet_x = -rand() % (window_width - 90);
	randa = -rand() % (window_heigth / 2);//只在上半平面
	enermy_filename[0] = "image/0.png";//1.3是子弹
	enermy_filename[1] = "image/1.png";
	enermy_filename[2] = "image/2.png";
	enermy_filename[3] = "image/3.png";
	enermy_filename[4] = "image/4.png";
	enermy_Bullet_filename[0] = "image/0_s.png";
	enermy_Bullet_filename[1] = "image/1_s.png";
	enermy_Bullet_filename[2] = "image/2_s.png";
	enermy_Bullet_filename[3] = "image/3_s.png";
	enermy_Bullet_filename[4] = "image/4_s.png";
	enermy_start = 0;
	score_all = 0;//总分是0
	flyBUllet_quantity = 0;
	kill_enermy = 0;//杀了0ge
					//now_add_Help_pack = 0;
					//sf::Music shoot_sound;
	if (!shoot_sound.openFromFile("sound/bullet.ogg"))
	{
		cout << "发射声音播放失败";
	}
	//enermy_exploed
	if (!enermy_exploed.openFromFile("sound/enemy1_down.ogg"))
	{
		cout << "爆炸声音播放失败";
	}
	if (!get.openFromFile("sound/achievement.ogg"))
	{
		cout << "得到道具声音播放失败";
	}
	if (!use_bomb.openFromFile("sound/use_bomb.ogg"))
	{
		cout << "使用道具声音播放失败";
	}
	if (!font.loadFromFile("font/stheitisc.ttf"))
	{
		cout << "字体加载失败！";
	}
	//life
	life.setFont(font);
	life.setString("life:");
	sf::Color  color = Color::Red;
	life.setFillColor(color);
	life.setCharacterSize(40);
	life.setPosition(0, 0);
	//life_number
	life_number.setFont(font);
	life_number.setFillColor(sf::Color::Black);
	life_number.setCharacterSize(40);
	life_number.setPosition(110, 0);

	//life.setString
	score_name.setString("score:");
	score_name.setFont(font);
	score_name.setFillColor(Color::Blue);
	score_name.setCharacterSize(40);
	score_name.setPosition(0, 40);


	//rocker_name
	rocketname.setString("Rocket:");
	rocketname.setFont(font);
	rocketname.setFillColor(Color::Red);
	rocketname.setCharacterSize(40);
	rocketname.setPosition(100, 580);

	//rocket_quantity

	rocket_quantity.setFont(font);
	rocket_quantity.setFillColor(Color::Black);
	rocket_quantity.setCharacterSize(40);
	rocket_quantity.setPosition(280, 580);


	score.setFont(font);
	score.setFillColor(sf::Color::Black);
	score.setCharacterSize(40);
	score.setPosition(150, 40);
	//score.setPosition(0,40);

	//end score_name
	_end_scorename.setFont(font);
	_end_scorename.setString("your score:");
	_end_scorename.setFillColor(color);
	_end_scorename.setCharacterSize(50);
	_end_scorename.setPosition(250, 250);

	//end_score
	_end_score.setFont(font);
	//_end_score.setString("your score:");
	_end_score.setFillColor(sf::Color::Yellow);
	_end_score.setCharacterSize(50);
	_end_score.setPosition(630, 250);

	//pass 
	_pass.setFont(font);
	_pass.setString("exit,please enter Q");
	_pass.setFillColor(sf::Color::Red);
	_pass.setCharacterSize(50);
	_pass.setPosition(200, 325);

	//pass_1
	_pass1.setFont(font);
	_pass1.setString("continue,please enter N");
	_pass1.setFillColor(sf::Color::Red);
	_pass1.setCharacterSize(50);
	_pass1.setPosition(180, 400);

}

void Object_manage::draw_pass()
{
	the_window.draw(_pass);
	the_window.draw(_pass1);
}
void Object_manage::game_loop()
{
	if (Game_state == begin_just_now)
	{
		p = new start_interface;//点击区域设计
								//Game_state= begin_just_now;//状态描述
		for (int i = 0; i < 2; i++)
		{
			bac[i] = new background("image/background.png");//加背景
		}
		int temp;
		if (My_plane_list.empty())
		{

		}
		else
		{
			multimap<string, My_plane*>::iterator it;
			it = My_plane_list.begin();
			temp = it->second->my_plane_life;
		}

		My_plane_list.clear();
		MyBullet_list.clear();//放我的子弹
		Fly_BUlllet_list.clear();//放榴弹
		quickBUllet_list.clear();//你懂的的那个特别强大的功能
		Enermy_Bullet_list.clear();//
		add_plane("image/shoot.png", new My_plane);//加我的飞机
		multimap<string, My_plane*>::iterator ita;
		ita = My_plane_list.begin();

		if (!pass)//没过关
		{
			score_all = 0;
		}
		else
		{
			pass = 0;
			ita->second->my_plane_life = temp;
		}
		kill_enermy = 0;
		start_window = new background("image/start.psd");//加启动界面

														 //p = new start_interface;//点击区域设计
		start_interface::MenuResult mk;
		the_window.clear();
		the_window.draw(start_window->get_background());
		the_window.display();
		//p->GetMenuResponse(the_window);
		while (1)
		{
			mk = p->GetMenuResponse(the_window);
			if (mk == p->Nothing)
			{
				continue;
			}
			if (mk == p->Play)
			{
				//{begin_just_now, is_playing, is_exiting, game_over, pass_barrier, failed};
				Game_state = is_playing;
				break;
			}
			if (mk == p->Exit)
			{
				//cout << "aaaaaa";
				Game_state = game_over;
				break;
			}
		}
	}
	if (Game_state == game_over)
	{

		the_window.clear();
		draw_life();
		life_number.setFillColor(sf::Color::Yellow);
		draw_lifeNumber();
		draw_end_score_();
		draw_endScoreName();
		the_window.display();
		Sleep(2000);
		Game_state = begin_just_now;

	}
	if (Game_state == pass_barrier)
	{
		pass = 1;
		all_speed -= 5;
		the_window.clear();
		draw_life();
		life_number.setFillColor(sf::Color::Yellow);
		draw_lifeNumber();
		draw_end_score_();
		draw_endScoreName();
		draw_pass();
		the_window.display();

		//Sleep(2000);
		//Game_state = begin_just_now;
		Event ev;
		int t = 0;
		while (1)
		{
			while (the_window.pollEvent(ev))//从消息队列取出消息
			{
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))//监控键盘
				{
					//cout << "q";
					exit(0);
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::N))//监控键盘
				{
					//cout << "N";
					Game_state = begin_just_now;
					t = 1;
					break;

				}
			}
			if (1 == t)
			{
				break;
			}
		}
	}
	if (Game_state == is_playing)
	{
		update_time = update_clock.getElapsedTime();
		if (operator>=(update_time, update_all_time))
		{
			update_time = update_clock.restart();
			multimap<string, My_plane*>::iterator it_myPlane;
			it_myPlane = My_plane_list.begin();
			if (it_myPlane->second->my_plane_life <= 0)
			{
				it_myPlane->second->my_plane_life = 0;
				Game_state = failed;
				//draw_life();
				//return;
			}
			else
			{
				the_window.clear();
				update_All();//更新位置
				display_All(the_window);//显示在窗口上
			}
		}
		else
		{
			the_window.display();
		}
		/*the_window.clear();
		update_All();//更新位置
		display_All(the_window);//显示在窗口上*/
	}
	//is_exiting

}


void  Object_manage::draw_life()
{
	the_window.draw(life);
}

void Object_manage::draw_end_score_()
{
	_itoa_s(score_all, temp0, 10);
	_end_score.setString(temp0);
	the_window.draw(_end_score);
}
void Object_manage::draw_endScoreName()
{
	the_window.draw(_end_scorename);
}
void Object_manage::draw_rocketname()
{
	the_window.draw(rocketname);
}
void Object_manage::draw_rocketQuantity()
{
	multimap<string, My_plane*>::iterator  it;
	it = My_plane_list.begin();//第一个
	_itoa_s(it->second->super_plane, temp, 10);
	rocket_quantity.setString(temp);
	the_window.draw(rocket_quantity);
}
void Object_manage::draw_lifeNumber()
{
	multimap<string, My_plane*>::iterator  it;
	it = My_plane_list.begin();//第一个
	_itoa_s(it->second->get_Myplane_life(), temp, 10);
	life_number.setString(temp);
	the_window.draw(life_number);
}
void Object_manage::draw_score()
{
	_itoa_s(score_all, temp0, 10);
	score.setString(temp0);
	the_window.draw(score);

}
void Object_manage::draw_score_name()
{
	the_window.draw(score_name);
}
void Object_manage::control_next()
{
	if (kill_enermy >= 50)
	{
		Game_state = pass_barrier;
	}
}

void Object_manage::update_All()
{

	for (int j = 0; j <= all_speed; j++)
	{
	}
	update_background();
	add_rocket();
	draw_life();
	draw_lifeNumber();
	draw_score_name();
	draw_rocketname();
	draw_score();
	draw_rocketQuantity();
	update_quicker_plane();
	crash_detector();
	update_Myplane(the_window);//展示
	update_MyBullet(the_window);
	add_Enermy();
	update_Enermy(the_window);
	add_Enermy_Bullet();
	update_Enermy_Bullet(the_window);
	add_Fly_bullet();
	update_Fly_bullet();
	control_next();
}



//void draw _rocket();
//void draw_rocket_number();
void Object_manage::add_quicker_plane()
{
	//vector<Quicker_killer*>::iterator itm=quickBUllet_list.begin()

	Quicker_killer *h = new Quicker_killer(1);
	int t = window_width / (h->get_width() / 2);
	//Object_manage::need_update_superBullet = t;//需要更新的数量
	for (int i = 0; i <= t; i++)
	{
		cout << "建立了";
		quickBUllet_list.push_back(new Quicker_killer(i));
	}
	delete h;

}


void Object_manage::add_rocket()
{
	the_window.draw(ro->sprite);
}
void Object_manage::update_quicker_plane()
{
	//extern vector<Quicker_killer*> quickBUllet_list
	/*	if (Object_manage::need_update_superBullet<=0)
	{
	return;
	}*/
	vector<Quicker_killer*>::iterator itm;
	for (itm = quickBUllet_list.begin(); itm != quickBUllet_list.end();)
	{
		if ((*itm)->get_y() >= 0)
		{
			delete (*itm);
			Object_manage::need_update_superBullet--;
			itm = quickBUllet_list.erase(itm);
			continue;
		}
		//cout << "更新进来了";
		(*itm)->__y += (*itm)->speed;
		(*itm)->sprite.setOrigin((*itm)->__x, (*itm)->__y);
		the_window.draw((*itm)->sprite);
		itm++;
	}
}
int  Object_manage::get_Update_help()
{
	return now_add_Help_pack;
}



void Object_manage::update_background()
{
	if (background::background_order == 1)
	{
		the_window.draw(bac[0]->sprite0);
		background::background_order = 2;
		//cout << "是一";
	}
	else
	{
		the_window.draw(bac[1]->sprite0);
		background::background_order = 1;
		//cout << "是二";
	}
	/*for (int i = 0; i <= 1; i++)
	{
	cout << bac[i]->filename0 << endl;
	}*/
}

void Object_manage::game_start()
{
	sf::Music a;
	if (!a.openFromFile("sound/game_music.ogg"))
	{
		cout << "开始声音播放失败";
	}
	a.setLoop(1);
	a.play();
	Game_state = begin_just_now;
	/*;//状态描述
	for (int i = 0; i < 2; i++)
	{
	bac[i] = new background("image/background.png");//加背景
	}
	start_window = new background("image/start.psd");//加启动界面
	add_plane("image/shoot.png", new My_plane);//加我的飞机
	p = new start_interface;//点击区域设计*/
	while (1)
	{
		game_loop();//进入游戏
	}


}

Object_manage::~Object_manage()
{

}




void Object_manage::add_plane(string name, My_plane* my)
{
	My_plane_list.insert(multimap<std::string, My_plane*>::value_type(name, my));
}



void Object_manage::update_Myplane(RenderWindow &the_window)
{

	/*if (0==My_plane_list.size())
	{
	cout << "game over!";
	Sleep(5000);
	exit(0);
	}*/
	multimap<string, My_plane*>::iterator  it;
	if (My_plane_list.empty())
	{
		return;
	}
	it = My_plane_list.begin();//第一个
	float temp = it->second->My_x;
	float temp0 = it->second->My_y;
	/*if (0 == it->show_Myplane)
	{
	show
	}*/
	Event ev;


	while (the_window.pollEvent(ev))//从消息队列取出消息
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))//监控键盘
		{
			it->second->My_x = it->second->My_x + it->second->My_plane_speed;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			it->second->My_x = it->second->My_x - it->second->My_plane_speed;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			it->second->My_y = it->second->My_y + it->second->My_plane_speed;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			it->second->My_y = it->second->My_y - it->second->My_plane_speed;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))//加子弹
		{
			My_plane::space_time++;
			if (My_plane::space_time >= 2)
			{
				if (it->second->Myplane_type == "common")
				{
					MyBullet *Bullet = new MyBullet;
					shoot_sound.play();
					add_MyBullet(Bullet);
				}
				else//双子弹
				{
					for (int i = 0; i < 2; i++)
					{
						MyBullet *Bullet = new MyBullet;
						shoot_sound.play();
						add_MyBullet(Bullet);
						it->second->the_Bullet_order = i + 1;
					}
					it->second->the_Bullet_order = 0;
				}
				My_plane::space_time = 0;
			}
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::LControl))//
		{
			cout << "ctrl按了" << endl;
			cout << it->second->super_plane << endl;
			if (it->second->super_plane >= 1)
			{
				add_quicker_plane();
				use_bomb.play();
				it->second->super_plane--;
			}

		}
		if (ev.type == Event::EventType::Closed)
		{
			exit(0);
		}
	}
	if (it->second->My_y>0 || it->second->My_y< -window_heigth + it->second->my_Plane_height)
	{
		it->second->My_y = temp0;
	}
	if (it->second->My_x>it->second->my_Plane_width / 2 || it->second->My_x  < -window_width + it->second->my_Plane_width / 2)
	{
		it->second->My_x = temp;
	}
	it->second->myPlane_sprite.setOrigin(it->second->My_x, it->second->My_y);//设置位置
	the_window.draw(it->second->myPlane_sprite);//画进窗口
}




void Object_manage::update_manage()
{
	if (Object_manage::update_now)
	{
		return;
	}
	else
	{
		//sf::Music a;
		//a.
		//	cout << "you had died!";
		//Sleep(5000);
		exit(0);
	}
}

void Object_manage::add_MyBullet(MyBullet* Bullet)
{
	MyBullet_list.push_back(Bullet);
	//MyBullet_list.insert(multimap<std::string, MyBullet *>::value_type(name, Bullet));
}

void Object_manage::display_All(RenderWindow &the_window)
{
	the_window.display();
}


void Object_manage::update_MyBullet(RenderWindow &the_window)
{


	vector<MyBullet*>::iterator ita;
	for (ita = MyBullet_list.begin(); ita != MyBullet_list.end();)
	{
		(*ita)->MyBullet_y += (*ita)->MyBullet_speed;
		if ((*ita)->MyBullet_y >= 0)//如果飞出屏幕，从我的子弹列表删除
		{
			delete (*ita);
			ita = MyBullet_list.erase(ita);
			continue;
		}
		(*ita)->MyBullet_sprite.setOrigin((*ita)->MyBullet_x, (*ita)->MyBullet_y);
		//每次处理完了就画进去窗口
		the_window.draw((*ita)->MyBullet_sprite);
		ita++;
	}

}




void Object_manage::add_Enermy()//更新敌机位置
{
	time = clock.getElapsedTime();
	if (operator>=(time, update_Enermy_time))//如果获取的时间大于更新的时间
	{
		Enermy_list.push_back(new Enermy);
		time = clock.restart();
	}

}


void Object_manage::add_Enermy_Bullet()
{
	vector<Enermy*>::iterator  it;
	for (it = Enermy_list.begin(); it != Enermy_list.end(); it++)
	{
		(*it)->time0 = (*it)->clock0.getElapsedTime();
		if (operator>=((*it)->time0, (*it)->update_EnermyBullet_time))
		{
			//int temp = Enermy_Bullet_list.size();
			//map<int, Enermy_Bullet*> Enermy_Bullet_list;
			Enermy_Bullet_list.push_back(new Enermy_Bullet(*it));
			//Enermy_Bullet_list[temp] = new Enermy_Bullet(it);//形参是指针
			(*it)->time0 = (*it)->clock0.restart();
		}
	}

}




void Object_manage::update_Enermy(RenderWindow &the_window)//取出部分
{
	update_enermy = Update_enermy.getElapsedTime();
	//update_enermy = Update_enermy.getElapsedTime();
	if (operator<(update_enermy, UPdate_Enermy))//如果获取的时间小于更新的时间
	{

		return;

	}
	update_enermy = Update_enermy.restart();

	vector<Enermy*>::iterator  ith;
	for (ith = Enermy_list.begin(); ith != Enermy_list.end();)
	{
		if ((*ith)->Enermy_y <= -window_heigth)//删除敌人
		{
			delete (*ith);
			ith = Enermy_list.erase(ith);
			continue;
		}
		if ((*ith)->is_new)
		{
			(*ith)->is_new = 0;
			return;
		}
		(*ith)->Enermy_y -= (*ith)->Enermy_speed;
		(*ith)->Enermy_sprite.setOrigin((*ith)->Enermy_x, (*ith)->Enermy_y);
		the_window.draw((*ith)->Enermy_sprite);
		ith++;
	}
}




void Object_manage::update_Enermy_Bullet(RenderWindow &the_window)
{
	//std::vector<My_plane*>::iterator  ita=;
	std::vector<Enermy_Bullet*>::iterator itm;
	for (itm = Enermy_Bullet_list.begin(); itm != Enermy_Bullet_list.end(); )
	{
		if ((*itm)->Enermy_Bullet_y <= -window_heigth)
		{
			delete *itm;//*(*itm)是一个指针
			itm = Enermy_Bullet_list.erase(itm);
			continue;
		}
		if ((*itm)->Enermy_Bullet_is_new)
		{
			(*itm)->Enermy_Bullet_is_new = 0;
			return;
		}
		else
		{
			(*itm)->Enermy_Bullet_y -= (*itm)->Enermy_Bullet_speed;
		}
		(*itm)->Enermy_Bullet_sprite.setOrigin((*itm)->Enermy_Bullet_x, (*itm)->Enermy_Bullet_y);
		the_window.draw((*itm)->Enermy_Bullet_sprite);
		itm++;

	}

	/*	for (itm = Enermy_Bullet_list.begin(); itm != Enermy_Bullet_list.end(); itm++)
	{
	if (itm->Enermy_Bullet_is_new)
	{
	itm->Enermy_Bullet_is_new = 0;
	return;
	}
	else

	{
	itm->Enermy_Bullet_y -= itm->Enermy_Bullet_speed;
	}
	itm->Enermy_Bullet_sprite.setOrigin(itm->Enermy_Bullet_x, itm->Enermy_Bullet_y);
	the_window.draw(itm->Enermy_Bullet_sprite);
	}*/

}




void Object_manage::show_explode_myPlane(RenderWindow &the_window)
{
	/*	multimap<string, My_plane*>::iterator it_MyPlane;//我和敌人的飞机
	it_MyPlane = My_plane_list.begin();
	std::vector<MyPlane_explode *>::iterator itm= myplane_exploded_list.begin();
	if (0 == it_MyPlane->exploded_time)
	{
	the_window.display()
	}
	*/
}

void  Object_manage::add_Fly_bullet()
{
	update_helpPack = UPDATE_helpPack.getElapsedTime();
	if (operator>=(update_helpPack, UPDate_HelpPack))
	{
		now_add_Help_pack = 1;
		update_helpPack = UPDATE_helpPack.restart();
		Fly_BUlllet_list.push_back(new Fly_BUlllet);
		now_add_Help_pack = 0;
	}


	FlyBUllet_time = Flybullet_clock.getElapsedTime();
	if (operator>=(FlyBUllet_time, update_Fly_BUllet_time))//如果获取的时间大于更新的时间
	{
		Fly_BUlllet_list.push_back(new Fly_BUlllet);//放榴弹
		FlyBUllet_time = Flybullet_clock.restart();
	}
}


void Object_manage::update_Fly_bullet()
{
	double temp;
	if (Fly_BUlllet_list.empty())
	{
		return;
	}
	vector<Fly_BUlllet*>::iterator itm;
	for (itm = Fly_BUlllet_list.begin(); itm != Fly_BUlllet_list.end();)
	{
		if ((*itm)->Fly_BUllet_y <= -window_heigth)//从下边出去
		{
			delete (*itm);
			itm = Fly_BUlllet_list.erase(itm);
			continue;
		}
		if ((*itm)->Fly_BUlllet_filename == "image/help.psd")
		{
			(*itm)->del_helppack = (*itm)->delete_helpbag.getElapsedTime();
			//如果时间到了就删除了
			if (operator>=((*itm)->del_helppack, (*itm)->eraser_helpPack))
			{
				delete (*itm);
				itm = Fly_BUlllet_list.erase(itm);
				continue;
			}
			else
			{
				(*itm)->Fly_BUlllet_sprite.setOrigin((*itm)->Fly_BUlllet_x, (*itm)->Fly_BUllet_y);
				the_window.draw((*itm)->Fly_BUlllet_sprite);
				itm++;
				continue;
			}
		}
		temp = abs(std::tan((*itm)->angle))*(*itm)->Fly_BUlllet_y_plus;
		if ((*itm)->Fly_BUlllet_x >= 0)//左边出去
		{
			(*itm)->left_or_right = 2;
		}

		if ((*itm)->Fly_BUlllet_x <= -window_width + (*itm)->Fly_BUlllet_width)
		{

			(*itm)->left_or_right = 1;

		}
		if ((*itm)->left_or_right == 1)
		{
			(*itm)->Fly_BUlllet_x += temp;
		}
		if ((*itm)->left_or_right == 2)
		{
			(*itm)->Fly_BUlllet_x -= temp;
		}
		(*itm)->Fly_BUllet_y -= (*itm)->Fly_BUlllet_y_plus;
		(*itm)->Fly_BUlllet_sprite.setOrigin((*itm)->Fly_BUlllet_x, (*itm)->Fly_BUllet_y);
		the_window.draw((*itm)->Fly_BUlllet_sprite);
		itm++;
	}
}






void Object_manage::crash_detector()
{
	if (My_plane_list.empty())
	{
		Game_state == begin_just_now;
		return;
	}

	//我的子弹和敌人
	vector<MyBullet*>::iterator it_myBullet;
	vector<Enermy*>::iterator it_Enermy;
	sf::Rect<float> temp;//创建矩形区域
	for (it_Enermy = Enermy_list.begin(); it_Enermy != Enermy_list.end();)
	{
		int t = 0;
		temp = (*it_Enermy)->Enermy_sprite.getGlobalBounds();//敌人
		for (it_myBullet = MyBullet_list.begin(); it_myBullet != MyBullet_list.end();)
		{
			if (temp.intersects((*it_myBullet)->MyBullet_sprite.getGlobalBounds()))//if crash
			{
				//加分


				((*it_Enermy)->shooted_time)++;
				//resolve my Bullet
				delete (*it_myBullet);
				it_myBullet = MyBullet_list.erase(it_myBullet);
				//cout << "次数：" << (*it_Enermy)->shooted_time;
				if ((*it_Enermy)->shooted_time >= (*it_Enermy)->life)
				{
					kill_enermy++;
					if ((*it_Enermy)->Enermy_filename == "image/p0.png")
					{
						score_all += 100;
					}
					if ((*it_Enermy)->Enermy_filename == "image/p1.png")
					{
						score_all += 50;
					}
					if ((*it_Enermy)->Enermy_filename == "image/p2.png")
					{
						score_all += 200;
					}
					enermy_exploed.play();
					for (int i = 0; i < 3; i++)
					{
						Explode_enermy *p = new Explode_enermy((*it_Enermy), (*it_Enermy)->explode_time0);
						(*it_Enermy)->exploed_plane.push_back(p);
						(*it_Enermy)->explode_time0++;
						for (int t = 0; t <= 5; t++)
						{
							the_window.display();
						}

						delete p;//释放空间
						(*it_Enermy)->exploed_plane.pop_front();
					}
					//	cout << "敌人炸毁" << endl;
					//	cout << "炸毁了！次数：" << (*it_Enermy)->shooted_time;
					delete (*it_Enermy);
					it_Enermy = Enermy_list.erase(it_Enermy);
					t = 1;
					break;
				}
				continue;
			}
			it_myBullet++;
		}
		if (1 == t)
		{
			continue;
		}
		it_Enermy++;
	}




	//敌人子弹和我

	multimap<string, My_plane*>::iterator it_myPlane;

	it_myPlane = My_plane_list.begin();
	//cout << "检测里面" << it_myPlane->second->super_plane << endl;
	sf::Rect<float> temp0 = it_myPlane->second->myPlane_sprite.getGlobalBounds();
	//vector<Enermy_Bullet*> Enermy_Bullet_list
	vector<Enermy_Bullet*>::iterator it_Enermy_Bullet;
	for (it_Enermy_Bullet = Enermy_Bullet_list.begin(); it_Enermy_Bullet != Enermy_Bullet_list.end();)
	{
		if (temp0.intersects((*it_Enermy_Bullet)->Enermy_Bullet_sprite.getGlobalBounds()))
		{

			it_myPlane->second->Myplane_type = "common";
			it_myPlane->second->shooted_time += (*it_Enermy_Bullet)->aggressivity;
			it_myPlane->second->my_plane_life--;
			//处理敌人子弹
			delete *(it_Enermy_Bullet);
			it_Enermy_Bullet = Enermy_Bullet_list.erase(it_Enermy_Bullet);
			MyPlane_explode *p = new MyPlane_explode(it_myPlane->second);
			for (int t = 0; t <= 100; t++)
			{
				the_window.display();
			}
			delete p;//删除我的飞机爆炸图。
			if (it_myPlane->second->my_plane_life <= 0)
				//if (it_myPlane->second->shooted_time >= it_myPlane->second->my_plane_life)
			{
				Game_state = game_over;
				//draw_lifeNumber();
				//the_window.display();
				game_loop();
				//delete it_myPlane->second;
				//My_plane_list.erase(it_myPlane);
				return;
			}
			continue;
		}
		it_Enermy_Bullet++;
	}
	//我和flybullet
	// vector<Fly_BUlllet*>  Fly_BUlllet_list;//放榴弹
	vector<Fly_BUlllet*>::iterator it_Fly;
	for (it_Fly = Fly_BUlllet_list.begin(); it_Fly != Fly_BUlllet_list.end();)
	{
		if (temp0.intersects((*it_Fly)->Fly_BUlllet_sprite.getGlobalBounds()))
		{
			get.play();
			//判断是啥
			if ((*it_Fly)->Fly_BUlllet_filename == "image/3.1s.png")//双子弹
			{
				it_myPlane->second->Myplane_type = "double_BUllet";//加子弹时候注意
				delete (*it_Fly);
				it_Fly = Fly_BUlllet_list.erase(it_Fly);
				continue;

			}
			if ((*it_Fly)->Fly_BUlllet_filename == "image/help.psd")//急救包
			{
				it_myPlane->second->my_plane_life += 2;//寿命+2
				delete (*it_Fly);
				it_Fly = Fly_BUlllet_list.erase(it_Fly);
				continue;
			}
			if ((*it_Fly)->Fly_BUlllet_filename == "image/3.3s.png")//导弹
			{
				it_myPlane->second->super_plane++;//给我的飞机加一个超级炮弹的属性
				delete (*it_Fly);
				it_Fly = Fly_BUlllet_list.erase(it_Fly);
				continue;
			}

		}
		it_Fly++;
	}

	vector<Quicker_killer*>::iterator itl;//快的飞机和子弹
	for (itl = quickBUllet_list.begin(); itl != quickBUllet_list.end(); itl++)
	{
		temp = (*itl)->sprite.getGlobalBounds();
		for (it_Enermy_Bullet = Enermy_Bullet_list.begin(); it_Enermy_Bullet != Enermy_Bullet_list.end();)//敌人子弹
		{
			if (temp.intersects((*it_Enermy_Bullet)->Enermy_Bullet_sprite.getGlobalBounds()))
			{
				delete (*it_Enermy_Bullet);
				it_Enermy_Bullet = Enermy_Bullet_list.erase(it_Enermy_Bullet);
				continue;
			}
			it_Enermy_Bullet++;
		}
	}


	for (itl = quickBUllet_list.begin(); itl != quickBUllet_list.end(); itl++)//快的飞机和敌人
	{
		temp = (*itl)->sprite.getGlobalBounds();
		for (it_Enermy = Enermy_list.begin(); it_Enermy != Enermy_list.end();)
		{


			//temp = (*itl)->sprite.getGlobalBounds();
			if (temp.intersects((*it_Enermy)->Enermy_sprite.getGlobalBounds()))
			{
				//加分
				if ((*it_Enermy)->Enermy_filename == "image/p0.png")
				{
					score_all += 100;
				}
				if ((*it_Enermy)->Enermy_filename == "image/p1.png")
				{
					score_all += 50;
				}
				if ((*it_Enermy)->Enermy_filename == "image/p2.png")
				{
					score_all += 200;
				}
				//cout << "香蕉了";
				delete (*it_Enermy);
				it_Enermy = Enermy_list.erase(it_Enermy);
				continue;
			}


			it_Enermy++;
		}
	}


}

//Quicker_killer.cpp
#include "stdafx.h"
#include "Quicker_killer.h"

extern int window_width;
extern int window_heigth;
Quicker_killer::Quicker_killer(int order)
{
	filename = "image/rocket.psd";
	if (!image.loadFromFile(filename))
	{
		cout << "quicker plane read failed!";
	}
	sprite.setTexture(image);
	width = image.getSize().x;
	height = image.getSize().y;
	//srand((unsigned)time(NULL));
	speed = rand() % 20 + 10;//最小速度是30
	__x = -order*(width / 2);
	__y = -window_heigth;

};


int Quicker_killer::get_width()
{
	return width;
}

int Quicker_killer::get_x()
{
	return __x;
}
int Quicker_killer::get_y()
{
	return __y;
}

int Quicker_killer::get_speed()
{
	return speed;
}


Quicker_killer::~Quicker_killer()
{
}

//Resolve_interface.cpp
#include "stdafx.h"
#include "Resolve_interface.h"


Resolve_interface::Resolve_interface()
{
}


Resolve_interface::~Resolve_interface()
{
}

//rocket.cpp
#include "stdafx.h"
#include "rocket.h"

extern int window_width;
extern int window_heigth;
rocket::rocket()
{
	filename = "image/rocket.psd";//文件名
	if (!image.loadFromFile(filename))//用来读取图片
	{
		cout << "火箭加载失败！";
	}
	height = image.getSize().y;
	sprite.setTexture(image);//用来存图片
	sprite.setOrigin(0, -window_heigth + 5 * (height / 4));
	cout << -window_heigth + 2 * height;
}


rocket::~rocket()
{
}

//start_interface.cpp
#include "stdafx.h"
#include "start_interface.h"


start_interface::start_interface()
{
	/*开始界面：
	左边距657px
	上面的521px   226、75
	下面的625px   220, 75*/
	//play的点击范围
	MenuItem playButton;
	playButton.rect.top = 490;
	playButton.rect.left = 657;
	playButton.rect.width = 226;
	playButton.rect.height = 70;
	playButton.action = Play;

	//Exit的点击范围
	MenuItem exitButton;
	exitButton.rect.top = 590;
	exitButton.rect.left = 657;
	exitButton.rect.height = 75;
	exitButton.rect.width = 220;
	exitButton.action = Exit;
	_menuItems.push_back(playButton);
	_menuItems.push_back(exitButton);
}


start_interface::~start_interface()
{
}
void start_interface::design_click_area()
{


}

//判断鼠标点击位置是否在矩形区域里面从而返回状态参数
start_interface::MenuResult start_interface::HandleClick(int x, int y)
{
	//迭代器遍历list容器里面存放的点击区域以供判断
	std::list<MenuItem>::iterator it;
	for (it = _menuItems.begin(); it != _menuItems.end(); it++)
	{
		sf::Rect<int> menuItemRect = (*it).rect;
		if (menuItemRect.height + menuItemRect.top > y && menuItemRect.top < y
			&& menuItemRect.left < x
			&& menuItemRect.width + menuItemRect.left > x)
		{
			return (*it).action;
		}
	}
	return Nothing;
}

//根据鼠标动作来做出相应的响应
start_interface::MenuResult  start_interface::GetMenuResponse(sf::RenderWindow& window)
{
	sf::Event menuEvent;
	while (1)
	{
		while (window.pollEvent(menuEvent))
		{
			//sf::Event::
			if (menuEvent.type == sf::Event::MouseButtonReleased)//:MouseButtonPressed)
			{
				return HandleClick(menuEvent.mouseButton.x, menuEvent.mouseButton.y);
			}
			if (menuEvent.type == sf::Event::Closed)
			{
				return Exit;
			}
		}
	}
}

//stdafx.cpp
// stdafx.cpp : 只包括标准包含文件的源文件
// fighter.pch 将作为预编译头
// stdafx.obj 将包含预编译类型信息

#include "stdafx.h"

// TODO: 在 STDAFX.H 中引用任何所需的附加头文件，
//而不是在此文件中引用


