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
RenderWindow the_window(VideoMode(window_width, window_heigth), "here! let's fight the plane");
multimap<string, My_plane*>  My_plane_list;//���ҵķɻ�
vector<MyBullet*>  MyBullet_list;//���ҵ��ӵ�
vector<Fly_BUlllet*>  Fly_BUlllet_list;//����
vector<Quicker_killer*> quickBUllet_list;//�㶮�ĵ��Ǹ��ر�ǿ��Ĺ���
std::vector<Enermy_Bullet*> Enermy_Bullet_list;//����������е�Bullet
vector<Enermy*> Enermy_list;//��ʾ����Ļ�ϵķɻ�
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
	string filename0;//�ļ���
	Texture image0;//������ȡͼƬ
	Sprite sprite0;//������ͼƬ
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
class Enermy//ÿ���������Լ���ը�ĵ�ͼƬ
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
	string Enermy_filename;//�ļ���
	Texture Enermy_image;//������ȡͼƬ
	Sprite Enermy_sprite;//������ͼƬ
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
	sf::Time update_EnermyBullet_time;//60����
									  //sf::Time update_EnermyBullet_time = sf::milliseconds(10);//60����
	Time time0;
	sf::Clock clock0;//�����ʱ��ʼ��ʱ
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
	string Enermy_Bullet_filename;//�ļ���
	Texture Enermy_Bullet_image;//������ȡͼƬ
	Sprite Enermy_Bullet_sprite;//������ͼƬ
	int Enermy_Bullet_height;
	int Enermy_Bullet_width;
	int Bullet_is_on_screen;
	int had_flew_out;
	int aggressivity;//������
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
	string _filename;//�ļ���
	Texture _image;//������ȡͼƬ
	Sprite _sprite;//������ͼƬ
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
	string _filename;//�ļ���
	Texture _image;//������ȡͼƬ
	Sprite _sprite;//������ͼƬ
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
	string _filename;//�ļ���
	Texture _image;//������ȡͼƬ
	Sprite _sprite;//������ͼƬ
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
	string myPlane_filename;//�ļ���
	Texture myPlane_image;//������ȡͼƬ
	Sprite myPlane_sprite;//������ͼƬ
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
	string myPlane_filename;//�ļ���
	Texture myPlane_image;//������ȡͼƬ
	Sprite myPlane_sprite;//������ͼƬ
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
	void add_Enermy();//��ӵ��˵���Ҫ��ʾ������
	void add_Enermy_Bullet();
	void update_Myplane(RenderWindow &the_window);
	void update_MyBullet(RenderWindow &the_window);
	void update_Enermy(RenderWindow &the_window);
	void show_explode_myPlane(RenderWindow &the_window);
	void update_Enermy_Bullet(RenderWindow &the_window);
	void add_plane(string name, My_plane *my);//�����������
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
	enum game_status { begin_just_now, is_playing, is_exiting, game_over, pass_barrier, failed };//�տ�ʼ��������Ϸ���˳�����Ϸ����������
	string enermy_filename[5];
	string enermy_Bullet_filename[5];
	const sf::Time update_Fly_BUllet_time = sf::seconds(11.0f);//2��
	const sf::Time update_Enermy_time = sf::seconds(1.0f);//2��
	const sf::Time update_all_time = sf::seconds(0.001f);//0.1��
	const sf::Time UPdate_Enermy = sf::seconds(0.001f);//0.1��
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
	sf::Clock clock;//�����ʱ��ʼ��ʱ
	sf::Clock Flybullet_clock;
	sf::Clock Update_enermy;
	sf::Clock UPDATE_helpPack;
	int enermy_start;
	int flyBUllet_quantity;
	start_interface *p;//����������
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
	string filename;//�ļ���
	Texture image;//������ȡͼƬ
	Sprite sprite;//������ͼƬ
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
// stdafx.h : ��׼ϵͳ�����ļ��İ����ļ���
// ���Ǿ���ʹ�õ��������ĵ�
// �ض�����Ŀ�İ����ļ�
//

#pragma once

#include "targetver.h"

#include <stdio.h>
#include <tchar.h>



// TODO:  �ڴ˴����ó�����Ҫ������ͷ�ļ�


// stdafx.h : ��׼ϵͳ�����ļ��İ����ļ���
// ���Ǿ���ʹ�õ��������ĵ�
// �ض�����Ŀ�İ����ļ�
//

#pragma once

#include "targetver.h"

#include <stdio.h>
#include <tchar.h>

// TODO:  �ڴ˴����ó�����Ҫ������ͷ�ļ�


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
	filename0 = filename;//�ļ���
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
	if (!image0.loadFromFile(filename0))//������ȡͼƬ
	{
		//cout << "��������ʧ�ܣ�";
	}
	sprite0.setTexture(image0);//������ͼƬ
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
	update_EnermyBullet_time = sf::seconds(time_temp / 1000.0);//60����
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

	if (!Enermy_image.loadFromFile(Enermy_filename))//������ȡͼƬ
	{
		//cout << "Enermies load failed!";
	}
	Enermy_sprite.setTexture(Enermy_image);//�����洢ͼƬ
	Enermy_width = Enermy_image.getSize().x;
	Enermy_height = Enermy_image.getSize().y;
	srand((unsigned)time(0));
	Enermy_speed = rand() % Enermy::EnermyMax_Speed + 1;//�л���һ��
	Enermy_x = -(rand() % window_width) + 1;//�л���λ������Ļ��
											//cout << Enermy_x << endl;
	Enermy_y = Enermy_height / 2;//������������
	Enermy_sprite.setOrigin(Enermy_x, Enermy_y);
	//��thisָ������
}
Enermy::~Enermy()
{
	//cout << "��������";
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
	if ("image/MyBullet.png" == Enermy_Bullet_filename)//�����ӵ��Ĺ�����
	{
		aggressivity = 1;
	}
	else
	{
		aggressivity = 3;
	}
	Enermy_Bullet_is_new = 1;
	if (!Enermy_Bullet_image.loadFromFile(Enermy_Bullet_filename))//������ȡͼƬ
	{
		//cout << "your Bullet load failed!";
	}
	Enermy_Bullet_sprite.setTexture(Enermy_Bullet_image);//�����洢ͼƬ
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
	Enermy_Bullet_y = en->Enermy_y - en->Enermy_height;//��Ϊy���ϱ�����봰�ڱ�Ե�ľ���
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
		cout << "��ըͼƬ����ʧ�ܣ�";
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
RenderWindow the_window(VideoMode(window_width, window_heigth), "here! let's fight the plane");
multimap<string, My_plane*>  My_plane_list;//���ҵķɻ�
vector<MyBullet*>  MyBullet_list;//���ҵ��ӵ�
vector<Fly_BUlllet*>  Fly_BUlllet_list;//����
vector<Quicker_killer*> quickBUllet_list;//�㶮�ĵ��Ǹ��ر�ǿ��Ĺ���
std::vector<Enermy_Bullet*> Enermy_Bullet_list;//����������е�Bullet
vector<Enermy*> Enermy_list;//��ʾ����Ļ�ϵķɻ�
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

	if (!Fly_BUlllett_image.loadFromFile(Fly_BUlllet_filename))//������ȡͼƬ
	{
		cout << "Fly_BUlllett load failed!";
	}
	left_or_right = rand() % 2 + 1;//1����2,1������2������
	Fly_BUlllet_sprite.setTexture(Fly_BUlllett_image);//�����洢ͼƬ
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
	//cout << "��" << window_width<<endl;
	left_or_right = 2;
	}
	else
	{
	left_or_right =1;
	}*/
	//cout <<"���ң�"<<left_or_right << endl;
	Fly_BUllet_y = 0;
	Fly_BUlllet_y_plus = 1;//y�����ϵ�����
	angle = rand() % 45;//���½Ƕ�̫С����������
	if (Fly_BUlllet_filename == "image/help.psd")
	{
		srand((unsigned)time(NULL));
		int t = window_width - 2 * Fly_BUlllet_width;
		Fly_BUlllet_x = -rand() % t;
		Fly_BUllet_y = -rand() % (window_heigth / 2);//ֻ���ϰ�ƽ��
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
	my_plane_life = 5;//��ͨ�ӵ���Ҫ�����
	show_Myplane = 1;
	shooted_time = 0;
	myplane_explode[0] = "image/plane1.png";
	myplane_explode[1] = "image/plane2.png";
	myplane_explode[2] = "image/plane3.png";
	myPlane_filename = "image/shoot.png";//�ļ���
	if (!myPlane_image.loadFromFile(myPlane_filename)) //������ȡͼƬ
	{
		cout << "your plane load failed!";
	}
	myPlane_sprite.setTexture(myPlane_image);//�����洢ͼƬ
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
		//cout << "��ը������";
	}
	else if (my->get_shooted_time()  >  2 * (my->get_Myplane_life() / 3))
	{
		_filename = "image/plane2.png";
		//cout << "2��ը����";
	}
	else
	{
		_filename = "image/plane3.png";
	}
	if (!_image.loadFromFile(_filename)) //������ȡͼƬ
	{
		//cout << "your plane_exploding load failed!"<<_filename;
	}
	_sprite.setTexture(_image);//������ͼƬ
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
extern std::vector<Enermy_Bullet*> Enermy_Bullet_list;//����������е�Bullet
extern vector<Enermy*> Enermy_list;//��ʾ����Ļ�ϵķɻ�
extern std::vector<MyPlane_explode *> myplane_exploded_list;
extern int window_width;
extern int window_heigth;
extern vector<Fly_BUlllet*>  Fly_BUlllet_list;//����
extern vector<Quicker_killer*> quickBUllet_list;//�㶮�ĵ��Ǹ��ر�ǿ��Ĺ���
Object_manage::Object_manage()
{
	srand((unsigned)std::time(NULL));
	//Fly_BUlllet_x = -rand() % (window_width - 90);
	randa = -rand() % (window_heigth / 2);//ֻ���ϰ�ƽ��
	enermy_filename[0] = "image/0.png";//1.3���ӵ�
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
	score_all = 0;//�ܷ���0
	flyBUllet_quantity = 0;
	kill_enermy = 0;//ɱ��0ge
					//now_add_Help_pack = 0;
					//sf::Music shoot_sound;
	if (!shoot_sound.openFromFile("sound/bullet.ogg"))
	{
		cout << "������������ʧ��";
	}
	//enermy_exploed
	if (!enermy_exploed.openFromFile("sound/enemy1_down.ogg"))
	{
		cout << "��ը��������ʧ��";
	}
	if (!get.openFromFile("sound/achievement.ogg"))
	{
		cout << "�õ�������������ʧ��";
	}
	if (!use_bomb.openFromFile("sound/use_bomb.ogg"))
	{
		cout << "ʹ�õ�����������ʧ��";
	}
	if (!font.loadFromFile("font/stheitisc.ttf"))
	{
		cout << "�������ʧ�ܣ�";
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
		p = new start_interface;//����������
								//Game_state= begin_just_now;//״̬����
		for (int i = 0; i < 2; i++)
		{
			bac[i] = new background("image/background.png");//�ӱ���
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
		MyBullet_list.clear();//���ҵ��ӵ�
		Fly_BUlllet_list.clear();//����
		quickBUllet_list.clear();//�㶮�ĵ��Ǹ��ر�ǿ��Ĺ���
		Enermy_Bullet_list.clear();//
		add_plane("image/shoot.png", new My_plane);//���ҵķɻ�
		multimap<string, My_plane*>::iterator ita;
		ita = My_plane_list.begin();

		if (!pass)//û����
		{
			score_all = 0;
		}
		else
		{
			pass = 0;
			ita->second->my_plane_life = temp;
		}
		kill_enermy = 0;
		start_window = new background("image/start.psd");//����������

														 //p = new start_interface;//����������
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
			while (the_window.pollEvent(ev))//����Ϣ����ȡ����Ϣ
			{
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))//��ؼ���
				{
					//cout << "q";
					exit(0);
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::N))//��ؼ���
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
				update_All();//����λ��
				display_All(the_window);//��ʾ�ڴ�����
			}
		}
		else
		{
			the_window.display();
		}
		/*the_window.clear();
		update_All();//����λ��
		display_All(the_window);//��ʾ�ڴ�����*/
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
	it = My_plane_list.begin();//��һ��
	_itoa_s(it->second->super_plane, temp, 10);
	rocket_quantity.setString(temp);
	the_window.draw(rocket_quantity);
}
void Object_manage::draw_lifeNumber()
{
	multimap<string, My_plane*>::iterator  it;
	it = My_plane_list.begin();//��һ��
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
	update_Myplane(the_window);//չʾ
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
	//Object_manage::need_update_superBullet = t;//��Ҫ���µ�����
	for (int i = 0; i <= t; i++)
	{
		cout << "������";
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
		//cout << "���½�����";
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
		//cout << "��һ";
	}
	else
	{
		the_window.draw(bac[1]->sprite0);
		background::background_order = 1;
		//cout << "�Ƕ�";
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
		cout << "��ʼ��������ʧ��";
	}
	a.setLoop(1);
	a.play();
	Game_state = begin_just_now;
	/*;//״̬����
	for (int i = 0; i < 2; i++)
	{
	bac[i] = new background("image/background.png");//�ӱ���
	}
	start_window = new background("image/start.psd");//����������
	add_plane("image/shoot.png", new My_plane);//���ҵķɻ�
	p = new start_interface;//����������*/
	while (1)
	{
		game_loop();//������Ϸ
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
	it = My_plane_list.begin();//��һ��
	float temp = it->second->My_x;
	float temp0 = it->second->My_y;
	/*if (0 == it->show_Myplane)
	{
	show
	}*/
	Event ev;


	while (the_window.pollEvent(ev))//����Ϣ����ȡ����Ϣ
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))//��ؼ���
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
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))//���ӵ�
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
				else//˫�ӵ�
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
			cout << "ctrl����" << endl;
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
	it->second->myPlane_sprite.setOrigin(it->second->My_x, it->second->My_y);//����λ��
	the_window.draw(it->second->myPlane_sprite);//��������
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
		if ((*ita)->MyBullet_y >= 0)//����ɳ���Ļ�����ҵ��ӵ��б�ɾ��
		{
			delete (*ita);
			ita = MyBullet_list.erase(ita);
			continue;
		}
		(*ita)->MyBullet_sprite.setOrigin((*ita)->MyBullet_x, (*ita)->MyBullet_y);
		//ÿ�δ������˾ͻ���ȥ����
		the_window.draw((*ita)->MyBullet_sprite);
		ita++;
	}

}




void Object_manage::add_Enermy()//���µл�λ��
{
	time = clock.getElapsedTime();
	if (operator>=(time, update_Enermy_time))//�����ȡ��ʱ����ڸ��µ�ʱ��
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
			//Enermy_Bullet_list[temp] = new Enermy_Bullet(it);//�β���ָ��
			(*it)->time0 = (*it)->clock0.restart();
		}
	}

}




void Object_manage::update_Enermy(RenderWindow &the_window)//ȡ������
{
	update_enermy = Update_enermy.getElapsedTime();
	//update_enermy = Update_enermy.getElapsedTime();
	if (operator<(update_enermy, UPdate_Enermy))//�����ȡ��ʱ��С�ڸ��µ�ʱ��
	{

		return;

	}
	update_enermy = Update_enermy.restart();

	vector<Enermy*>::iterator  ith;
	for (ith = Enermy_list.begin(); ith != Enermy_list.end();)
	{
		if ((*ith)->Enermy_y <= -window_heigth)//ɾ������
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
			delete *itm;//*(*itm)��һ��ָ��
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
	/*	multimap<string, My_plane*>::iterator it_MyPlane;//�Һ͵��˵ķɻ�
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
	if (operator>=(FlyBUllet_time, update_Fly_BUllet_time))//�����ȡ��ʱ����ڸ��µ�ʱ��
	{
		Fly_BUlllet_list.push_back(new Fly_BUlllet);//����
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
		if ((*itm)->Fly_BUllet_y <= -window_heigth)//���±߳�ȥ
		{
			delete (*itm);
			itm = Fly_BUlllet_list.erase(itm);
			continue;
		}
		if ((*itm)->Fly_BUlllet_filename == "image/help.psd")
		{
			(*itm)->del_helppack = (*itm)->delete_helpbag.getElapsedTime();
			//���ʱ�䵽�˾�ɾ����
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
		if ((*itm)->Fly_BUlllet_x >= 0)//��߳�ȥ
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

	//�ҵ��ӵ��͵���
	vector<MyBullet*>::iterator it_myBullet;
	vector<Enermy*>::iterator it_Enermy;
	sf::Rect<float> temp;//������������
	for (it_Enermy = Enermy_list.begin(); it_Enermy != Enermy_list.end();)
	{
		int t = 0;
		temp = (*it_Enermy)->Enermy_sprite.getGlobalBounds();//����
		for (it_myBullet = MyBullet_list.begin(); it_myBullet != MyBullet_list.end();)
		{
			if (temp.intersects((*it_myBullet)->MyBullet_sprite.getGlobalBounds()))//if crash
			{
				//�ӷ�


				((*it_Enermy)->shooted_time)++;
				//resolve my Bullet
				delete (*it_myBullet);
				it_myBullet = MyBullet_list.erase(it_myBullet);
				//cout << "������" << (*it_Enermy)->shooted_time;
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

						delete p;//�ͷſռ�
						(*it_Enermy)->exploed_plane.pop_front();
					}
					//	cout << "����ը��" << endl;
					//	cout << "ը���ˣ�������" << (*it_Enermy)->shooted_time;
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




	//�����ӵ�����

	multimap<string, My_plane*>::iterator it_myPlane;

	it_myPlane = My_plane_list.begin();
	//cout << "�������" << it_myPlane->second->super_plane << endl;
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
			//��������ӵ�
			delete *(it_Enermy_Bullet);
			it_Enermy_Bullet = Enermy_Bullet_list.erase(it_Enermy_Bullet);
			MyPlane_explode *p = new MyPlane_explode(it_myPlane->second);
			for (int t = 0; t <= 100; t++)
			{
				the_window.display();
			}
			delete p;//ɾ���ҵķɻ���ըͼ��
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
	//�Һ�flybullet
	// vector<Fly_BUlllet*>  Fly_BUlllet_list;//����
	vector<Fly_BUlllet*>::iterator it_Fly;
	for (it_Fly = Fly_BUlllet_list.begin(); it_Fly != Fly_BUlllet_list.end();)
	{
		if (temp0.intersects((*it_Fly)->Fly_BUlllet_sprite.getGlobalBounds()))
		{
			get.play();
			//�ж���ɶ
			if ((*it_Fly)->Fly_BUlllet_filename == "image/3.1s.png")//˫�ӵ�
			{
				it_myPlane->second->Myplane_type = "double_BUllet";//���ӵ�ʱ��ע��
				delete (*it_Fly);
				it_Fly = Fly_BUlllet_list.erase(it_Fly);
				continue;

			}
			if ((*it_Fly)->Fly_BUlllet_filename == "image/help.psd")//���Ȱ�
			{
				it_myPlane->second->my_plane_life += 2;//����+2
				delete (*it_Fly);
				it_Fly = Fly_BUlllet_list.erase(it_Fly);
				continue;
			}
			if ((*it_Fly)->Fly_BUlllet_filename == "image/3.3s.png")//����
			{
				it_myPlane->second->super_plane++;//���ҵķɻ���һ�������ڵ�������
				delete (*it_Fly);
				it_Fly = Fly_BUlllet_list.erase(it_Fly);
				continue;
			}

		}
		it_Fly++;
	}

	vector<Quicker_killer*>::iterator itl;//��ķɻ����ӵ�
	for (itl = quickBUllet_list.begin(); itl != quickBUllet_list.end(); itl++)
	{
		temp = (*itl)->sprite.getGlobalBounds();
		for (it_Enermy_Bullet = Enermy_Bullet_list.begin(); it_Enermy_Bullet != Enermy_Bullet_list.end();)//�����ӵ�
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


	for (itl = quickBUllet_list.begin(); itl != quickBUllet_list.end(); itl++)//��ķɻ��͵���
	{
		temp = (*itl)->sprite.getGlobalBounds();
		for (it_Enermy = Enermy_list.begin(); it_Enermy != Enermy_list.end();)
		{


			//temp = (*itl)->sprite.getGlobalBounds();
			if (temp.intersects((*it_Enermy)->Enermy_sprite.getGlobalBounds()))
			{
				//�ӷ�
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
				//cout << "�㽶��";
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
	speed = rand() % 20 + 10;//��С�ٶ���30
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
	filename = "image/rocket.psd";//�ļ���
	if (!image.loadFromFile(filename))//������ȡͼƬ
	{
		cout << "�������ʧ�ܣ�";
	}
	height = image.getSize().y;
	sprite.setTexture(image);//������ͼƬ
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
	/*��ʼ���棺
	��߾�657px
	�����521px   226��75
	�����625px   220, 75*/
	//play�ĵ����Χ
	MenuItem playButton;
	playButton.rect.top = 490;
	playButton.rect.left = 657;
	playButton.rect.width = 226;
	playButton.rect.height = 70;
	playButton.action = Play;

	//Exit�ĵ����Χ
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

//�ж������λ���Ƿ��ھ�����������Ӷ�����״̬����
start_interface::MenuResult start_interface::HandleClick(int x, int y)
{
	//����������list���������ŵĵ�������Թ��ж�
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

//������궯����������Ӧ����Ӧ
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
// stdafx.cpp : ֻ������׼�����ļ���Դ�ļ�
// fighter.pch ����ΪԤ����ͷ
// stdafx.obj ������Ԥ����������Ϣ

#include "stdafx.h"

// TODO: �� STDAFX.H �������κ�����ĸ���ͷ�ļ���
//�������ڴ��ļ�������


