
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
    void add_plane(string name,My_plane *my);//加入对象到容器
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
	void control_next();
	//void draw _rocket();
	//void draw_rocket_number();
	int  get_Update_help();
	double randa;
	static Enermy* pointer[5];
	static int update_now;

private:
	enum game_status{begin_just_now,is_playing,is_exiting,game_over,pass_barrier,failed};//刚开始，正在游戏，退出，游戏结束，过关
	string enermy_filename[5];
	string enermy_Bullet_filename[5];
	const sf::Time update_Fly_BUllet_time = sf::seconds(11.0f);//2秒
	const sf::Time update_Enermy_time= sf::seconds(1.0f);//2秒
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
	//int screen_NO_enermies;
};

