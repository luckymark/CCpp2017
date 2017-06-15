#include <SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include<iostream>
#include<windows.h>
#include"move_aircraft.h"
#include"missile.h"
#include"aircraft.h"
#include"my_aircraft.h"
#include"my_missile.h"
#include"enemy_aircraft.h"
#include"enemy_aircraft_2.h"
#include"enemy_missile.h"
#include"boss_1.h"
#include"boss_2.h"
#include"energy.h"
#include"blood_plus.h"
#define move_speed_my_missle 0.6
#define move_speed_enemy_aircraft 0.25
#define move_speed_enemy_missile 0.3
#define move_speed_energy 0.5
#define max_enemy_num 50
#define max_enemy_missile_num 200
#define max_my_missile_num 80
#define window_lenth 1920
#define window_width 1080
#define PI 3.14
int main()
{

	srand(time(0));
	//播放背景音乐
	sf::Music backgound_music;
	sf::Music enemy_boom;
	sf::Music i_boom;
	sf::Music boss_boom;
	sf::Music fire;
	if (!backgound_music.openFromFile("Sight.wav")) {
		std::cout << "wrong0" << std::endl;
	}
	if (!enemy_boom.openFromFile("enemy_boom.wav")) {
		std::cout << "wrong1" << std::endl;
	}
	if (!i_boom.openFromFile("i_boom.wav")) {
		std::cout << "wrong2" << std::endl;;
	}
	if (!boss_boom.openFromFile("boss_boom.wav")) {
		std::cout << "wrong0" << std::endl;
	}
	if (!fire.openFromFile("fire.wav")) {
		std::cout << "wrong0" << std::endl;
	}
	backgound_music.setVolume(40);
	enemy_boom.setVolume(50);
	boss_boom.setVolume(60);
	i_boom.setVolume(100);
	fire.setVolume(40);
	backgound_music.play();
	backgound_music.setLoop(true);
	//设置背景图片
	sf::Texture tex_background;
	sf::Sprite background;
	if (!tex_background.loadFromFile("background.jpg")) {
		std::cout << "wrong3" << std::endl;
	}
	background.setTexture(tex_background);
	background.setOrigin(266.5, 150);
	background.setScale(3.8f, 3.6f);
	background.setPosition(window_lenth / 2, window_width / 2);
	//爆炸特效
	sf::Texture tex_enemy_boom;
	sf::Sprite enemy_boom_pic;
	if (!tex_enemy_boom.loadFromFile("enemy_boom.png")) {
		std::cout << "wrong" << std::endl;
	}
	enemy_boom_pic.setTexture(tex_enemy_boom);
	enemy_boom_pic.setOrigin(61, 55);
	//死亡时触发图片
	sf::Texture tex_death;
	sf::Sprite death_picture;
	if (!tex_death.loadFromFile("death.jpg")) {
		std::cout << "wrong4" << std::endl;
	}
	death_picture.setTexture(tex_death);
	death_picture.setOrigin(232.5, 150);
	death_picture.setScale(4.5f, 3.5f);
	death_picture.setPosition(window_lenth / 2, window_width / 2);
	//游戏结束时触发图片
	sf::Texture tex_gameover;
	sf::Sprite game_over;
	if (!tex_gameover.loadFromFile("gameover.jpg")) {
		std::cout << "wrong5" << std::endl;
	}
	game_over.setTexture(tex_gameover);
	game_over.setOrigin(254.5,150);
	game_over.setScale(3.8f, 3.5f);
	game_over.setPosition(window_lenth / 2, window_width / 2);
	//可以使用技能时，进行提醒
	sf::Font font;
	if (!font.loadFromFile("BertramLP.ttf")){
		std::cout << "wrong6" << std::endl;
	}
	sf::Text text1;
	text1.setFont(font);
	text1.setString("You Can Use Skill_1: Z");
	text1.setCharacterSize(36);
	text1.setFillColor(sf::Color::Blue);
	text1.setPosition(10, 100);
	sf::Text text2;
	text2.setFont(font);
	text2.setString("You Can Use Skill_2: X");
	text2.setCharacterSize(36);
	text2.setFillColor(sf::Color::Red);
	text2.setPosition(10, 150);
	MY_MISSILE my_missile[max_my_missile_num];
	ENEMY_AIRCRAFT enemy_aircraft[max_enemy_num];
	ENEMY_AIRCRAFT_2 enemy_aircraft_2[max_enemy_num];
	ENEMY_MISSILE enemy_missile[max_enemy_missile_num];
	ENEMY_MISSILE enemy_missile_2[max_enemy_missile_num];
	ENERGY energy[max_enemy_num];
	ENERGY energy_2[max_enemy_num];
	BOSS_1 boss_1;
	BOSS_2 boss_2;
	ENEMY_MISSILE boss_1_missile[max_enemy_missile_num];
	ENEMY_MISSILE boss_2_missile[max_enemy_missile_num];
	BLOOD_PLUS blood[2];
	sf::Clock clock;
	sf::Clock clock1;
	sf::Clock clock2;
	sf::Clock clock3;
	sf::Clock clock4;
	sf::Clock clock5;
	sf::Clock clock6;
	sf::Clock clock7;
	sf::Clock clock8;
	int if_my_aircraft_exist;
	float renew_aircraft_time = 2, speed_multiple = 1;
	int  renew_boss_1_time = 18, renew_boss_2_time = 15;
	int your_blood_number, your_energy_number, your_protected_blood, if_protect_exist, your_score=200, your_life = 3;
	sf::RenderWindow window(sf::VideoMode(window_lenth, window_width), "SFML works!");
	while (your_life > 0) {
		your_blood_number = 300;
		your_energy_number = 300;
		MY_AIRCRAFT *my_aircraft = new (MY_AIRCRAFT);
		if_my_aircraft_exist = 1;
		while (window.isOpen()) {
			sf::Event event;
			while (window.pollEvent(event)) {
				if (event.type == sf::Event::Closed)
					window.close();
			}
			//累积能量
			sf::Time elapsed1 = clock1.getElapsedTime();
			if (elapsed1.asSeconds()>1) {
				your_energy_number += 5;
				clock1.restart();
				if (your_energy_number > 300) {
					your_energy_number = 300;
				}
			}
			//显示分数，生命
			sf::Text text3;
			text3.setFont(font);
			char s1[100];
			sprintf_s(s1, "YOUR SCORE:%d\n", your_score);
			text3.setString(s1);
			text3.setCharacterSize(36);
			text3.setFillColor(sf::Color::Blue);
			text3.setPosition(window_lenth-400, 100);
			sf::Text text4;
			text4.setFont(font);
			char s2[100];
			sprintf_s(s2, "YOUR LIFE:%d\n", your_life);
			text4.setString(s2);
			text4.setCharacterSize(36);
			text4.setFillColor(sf::Color::White);
			text4.setPosition(window_lenth-400,50);
			sf::Time elapsed2 = clock2.getElapsedTime();
			if(elapsed2.asSeconds()>renew_aircraft_time){
				for (int j = 0; j < max_enemy_num; j++) {
					if ((0 == enemy_aircraft[j].if_exist) && (0 == enemy_missile[j].if_exist)) {
						enemy_aircraft[j].if_exist = 1;
						enemy_aircraft[j].aircraft.setPosition(rand() % window_lenth, 0);
						break;
					}
				}
				clock2.restart();
			}
			sf::Time elapsed8 = clock8.getElapsedTime();
			if (elapsed8.asSeconds() > 3*renew_aircraft_time) {
				for (int j = 0; j < max_enemy_num; j++) {
					if ((0 == enemy_aircraft_2[j].if_exist) && (0 == enemy_missile_2[j].if_exist)) {
						enemy_aircraft_2[j].if_exist = 1;
						enemy_aircraft_2[j].aircraft.setPosition(rand() % window_lenth, 0);
						break;
					}
				}
				clock8.restart();
			}
			//刷新向下移动的敌机
			for (int j = 0; j<max_enemy_num; j++) {
				if (1 == enemy_aircraft[j].if_exist) {
					enemy_aircraft[j].aircraft.move(0, move_speed_enemy_aircraft);
					if (enemy_aircraft[j].aircraft.getPosition().y > window_width) {
						enemy_aircraft[j].if_exist = 0;
					}
				}
			}
			//刷新左右来回移动的敌机
			for (int j = 0; j<max_enemy_num; j++) {
				while(1 == enemy_aircraft_2[j].if_exist) {
					if (1 == enemy_aircraft_2[j].fly_way) {
						enemy_aircraft_2[j].aircraft.move(3*move_speed_enemy_aircraft, move_speed_enemy_aircraft);
					}
					if (2 == enemy_aircraft_2[j].fly_way) {
						enemy_aircraft_2[j].aircraft.move(-3*move_speed_enemy_aircraft,move_speed_enemy_aircraft);
					}
					if (enemy_aircraft_2[j].aircraft.getPosition().x <= 0) {
						enemy_aircraft_2[j].fly_way = 1;
					}
					if (enemy_aircraft_2[j].aircraft.getPosition().x >= window_lenth) {
						enemy_aircraft_2[j].fly_way = 2;
					}
					if (enemy_aircraft_2[j].aircraft.getPosition().y > window_width) {
						enemy_aircraft_2[j].if_exist = 0;
					}
					break;
				}
			}
			//刷新向下移动的boss_1
			sf::Time elapsed3 = clock3.getElapsedTime();
			if ((elapsed3.asSeconds()>renew_boss_1_time)&&(your_score>150)) {
				boss_1.if_exist = 1;
				boss_1.life = 3;
				boss_1.aircraft.setPosition(rand() % window_lenth, 0);
				clock3.restart();
			}
			if (1==boss_1.if_exist) {
				boss_1.aircraft.move(0,move_speed_enemy_aircraft/2);
			}
			if(boss_1.aircraft.getPosition().y>window_width){
				boss_1.if_exist = 0;
			}
			//刷新向下移动的boss_2
			sf::Time elapsed4 = clock4.getElapsedTime();
			if ((elapsed4.asSeconds() > renew_boss_2_time)&&(your_score>300)) {
			boss_2.if_exist = 1;
				boss_2.life = 5;
				boss_2.aircraft.setPosition(rand() % window_lenth, 0);
				clock4.restart();
			}
			if (1 == boss_2.if_exist) {
				boss_2.aircraft.move(0, move_speed_enemy_aircraft/2);
			}
			if (boss_2.aircraft.getPosition().y>window_width) {
				boss_2.if_exist = 0;
			}
			//产生敌机的子弹
			sf::Time elapsed5 = clock5.getElapsedTime();
			if (elapsed5.asSeconds() > 2.5) {
				for (int j = 0; j < max_enemy_num; j++) {
					if (1 == enemy_aircraft[j].if_exist) {
						for (int i = 0; i < max_enemy_missile_num; i++) {
							if (enemy_missile[i].if_exist == 0) {
								enemy_missile[i].if_exist = 1;
								enemy_missile[i].missile.setPosition(enemy_aircraft[j].aircraft.getPosition());
								break;
							}
						}
					}
					if (1 == enemy_aircraft_2[j].if_exist) {
						for (int i = 0; i < max_enemy_missile_num; i++) {
							if (enemy_missile_2[i].if_exist == 0) {
								enemy_missile_2[i].if_exist = 1;
								enemy_missile_2[i].missile.setPosition(enemy_aircraft_2[j].aircraft.getPosition());
								break;
							}
						}
					}
				}
				if (1 == boss_1.if_exist) {
					for (int i = 0; i < 10; i++) {
						for (int j = 0; j < max_enemy_missile_num; j++) {
							if (boss_1_missile[j].if_exist == 0) {
								boss_1_missile[j].if_exist = 1;
								boss_1_missile[j].missile.setPosition(boss_1.aircraft.getPosition());
								break;
							}
						}
					}
				}
				clock5.restart();
			}
			sf::Time elapsed6 = clock6.getElapsedTime();
			if (elapsed6.asSeconds() > 0.2) {
				if (1 == boss_2.if_exist) {
					for (int j = 0; j < max_enemy_missile_num; j++) {
						if (boss_2_missile[j].if_exist == 0) {
							boss_2_missile[j].if_exist = 1;
							boss_2_missile[j].missile.setPosition(boss_2.aircraft.getPosition());
							clock6.restart();
							break;
						}
					}
				}
			}
			//boss子弹轨迹方程
			for (int i = 0; i < max_enemy_missile_num; i++) {
				float vx = 0.8*cos(PI*(i % 10) / 9.0);
				float vy = 0.8*sin(PI*(i % 10) / 9.0);
				if (boss_1_missile[i].if_exist == 1) {
					boss_1_missile[i].missile.move(vx, vy);
				}
			}
			for (int i = 0; i < max_enemy_missile_num; i++) {
				float vx = speed_multiple*0.5*cos(PI*(i % 18) / 9.0);
				float vy = speed_multiple*0.5*sin(PI*(i % 18) / 9.0);
				if (boss_2_missile[i].if_exist == 1) {
					boss_2_missile[i].missile.move(vx, vy);
				}
			}
			//敌机子弹出边界处理
			for (int i = 0; i < max_enemy_missile_num; i++) {
				if (enemy_missile[i].if_exist == 1) {
					enemy_missile[i].missile.move(0, 1.5*move_speed_enemy_missile);
				}
				if (enemy_missile_2[i].if_exist == 1) {
					enemy_missile_2[i].missile.move(0, move_speed_enemy_missile);
				}
				if (enemy_missile[i].missile.getPosition().y>window_width) {
					enemy_missile[i].if_exist = 0;
				}
				if (enemy_missile_2[i].missile.getPosition().y>window_width) {
					enemy_missile_2[i].if_exist = 0;
				}
			}
			//boss飞出边界对子弹和敌机的处理
			if (boss_1.aircraft.getPosition().y>window_width) {
				boss_1.if_exist = 0;
			}
			if (boss_2.aircraft.getPosition().y>window_width) {
				boss_2.if_exist = 0;
			}
			if (boss_1.if_exist == 0) {
					for (int i = 0; i < max_enemy_missile_num; i++) {
						sf::Vector2f boss_1_position=boss_1_missile[i].missile.getPosition();
						if ((boss_1_position.x<0)||(boss_1_position.x>window_lenth)||(boss_1_position.y>window_lenth)) {
							boss_1_missile[i].if_exist = 0;
						}
					}
			}
			if (boss_2.if_exist == 0) {
				for (int i = 0; i < max_enemy_missile_num; i++) {
					sf::Vector2f boss_2_position = boss_2_missile[i].missile.getPosition();
					if ((boss_2_position.x<0) || (boss_2_position.x>window_lenth) || (boss_2_position.y>window_lenth)) {
						boss_2_missile[i].if_exist = 0;
					}
				}
			}
			//移动我方战机
			move_aircraft(my_aircraft->aircraft);
			//发射我方向上移动的子弹
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
				sf::Time elapsed = clock.getElapsedTime();
				if (elapsed.asSeconds() > 0.08) {
					fire.play();
					for (int i = 0; i < max_my_missile_num; i++) {
						if (0 == my_missile[i].if_exist) {
							my_missile[i].if_exist = 1;
							my_missile[i].missile.setPosition(my_aircraft->aircraft.getPosition());
							clock.restart();
							break;
						}
					}
				}
			}
			//我方子弹飞出边界处理
			for (int i = 0; i < max_my_missile_num; i++) {
				if (1 == my_missile[i].if_exist) {
					my_missile[i].missile.move(0, -move_speed_my_missle);
				}
				if (my_missile[i].missile.getPosition().y < 0) {
					my_missile[i].if_exist = 0;
				}
			}
			//击毁敌机，产生能量
			for (int j = 0; j < max_enemy_num; j++) {
				if (1 == energy[j].if_exist) {
					energy[j].missile.move(0, move_speed_energy);
				}
				if (1 == energy_2[j].if_exist) {
					energy_2[j].missile.move(0, move_speed_energy);
				}
				if (energy[j].missile.getPosition().y >= window_width) {
					energy[j].if_exist = 0;
				}
				if (energy_2[j].missile.getPosition().y >= window_width) {
					energy_2[j].if_exist = 0;
				}
			}
			//boss死亡，产生生命补给包
			for (int i = 0; i < 2; i++) {
				if (1 == blood[i].if_exist) {
					blood[i].missile.move(0, move_speed_energy);
				}
				if (blood[i].missile.getPosition().y >= window_width) {
					blood[i].if_exist = 0;
				}
			}
			sf::FloatRect boundingBox = my_aircraft->aircraft.getGlobalBounds();
			for (int i = 0; i < max_my_missile_num; i++) {
				//子弹射中敌机
				for (int j = 0; j < max_enemy_num; j++) {
					if ((1 == my_missile[i].if_exist) && (1 == enemy_aircraft[j].if_exist)) {
						sf::FloatRect boundingBox1= enemy_aircraft[j].aircraft.getGlobalBounds();
						sf::FloatRect boundingBox2 = my_missile[i].missile.getGlobalBounds();
						if (boundingBox1.intersects(boundingBox2)) {
							enemy_boom.play();
							energy[j].if_exist = 1;
							energy[j].missile.setPosition(enemy_aircraft[j].aircraft.getPosition());
							my_missile[i].if_exist = 0;
							enemy_aircraft[j].if_exist = 0;
							your_score += 5;
						}
					}
					if ((1 == my_missile[i].if_exist) && (1 == enemy_aircraft_2[j].if_exist)) {
						sf::FloatRect boundingBox1 = enemy_aircraft_2[j].aircraft.getGlobalBounds();
						sf::FloatRect boundingBox2 = my_missile[i].missile.getGlobalBounds();
						if (boundingBox1.intersects(boundingBox2)) {
							enemy_boom.play();
							energy_2[j].if_exist = 1;
							energy_2[j].missile.setPosition(enemy_aircraft_2[j].aircraft.getPosition());
							my_missile[i].if_exist = 0;
							enemy_aircraft_2[j].if_exist = 0;
							your_score += 5;
						}
					}
				}
				//子弹射中boss_1
				if ((1 == my_missile[i].if_exist) && (1 == boss_1.if_exist)) {
					sf::FloatRect boundingBox1 = boss_1.aircraft.getGlobalBounds();
					sf::FloatRect boundingBox2 = my_missile[i].missile.getGlobalBounds();
					if (boundingBox1.intersects(boundingBox2)) {
						my_missile[i].if_exist = 0;
						boss_1.life--;
						if (boss_1.life == 0) {
							boss_boom.play();
							for (int j = 0; j < 2; j++) {
								if (blood[j].if_exist == 0) {
									blood[j].if_exist = 1;
									blood[j].missile.setPosition(boss_1.aircraft.getPosition());
									break;
								}
							}
							your_score += 30;
							boss_1.if_exist = 0;
						}
					}
				}
				//子弹射中boss_2
				if ((1 == my_missile[i].if_exist) && (1 == boss_2.if_exist)) {
					sf::FloatRect boundingBox1 = boss_2.aircraft.getGlobalBounds();
					sf::FloatRect boundingBox2 = my_missile[i].missile.getGlobalBounds();
					if (boundingBox1.intersects(boundingBox2)) {
						boss_boom.play();
						my_missile[i].if_exist = 0;
						boss_2.life--;
						if (boss_2.life == 0) {
							boss_boom.play();
							for (int j = 0; j < 2; j++) {
								if (blood[j].if_exist == 0) {
									blood[j].if_exist = 1;
									blood[j].missile.setPosition(boss_2.aircraft.getPosition());
									break;
								}
							}
							your_score += 30;
							boss_2.if_exist = 0;
						}
					}
				}
			}
			//获得能量
			for (int j = 0; j < max_enemy_num; j++) {
				if (1 == energy[j].if_exist) {
					sf::FloatRect boundingBox1= energy[j].missile.getGlobalBounds();
					if (boundingBox.intersects(boundingBox1)) {
						energy[j].if_exist = 0;
						your_energy_number += 5;
						if (your_energy_number > 300) {
							your_energy_number = 300;
						}
					}
				}
				if (1 == energy_2[j].if_exist) {
					sf::FloatRect boundingBox1 = energy_2[j].missile.getGlobalBounds();
					if (boundingBox.intersects(boundingBox1)) {
						energy_2[j].if_exist = 0;
						your_energy_number += 5;
						if (your_energy_number > 300) {
							your_energy_number = 300;
						}
					}
				}
			}
			//获得血包
			for (int j = 0; j < 2; j++) {
				if (1 == blood[j].if_exist) {
					sf::FloatRect boundingBox1 = blood[j].missile.getGlobalBounds();
					if (boundingBox.intersects(boundingBox1)) {
						blood[j].if_exist = 0;
						your_blood_number +=20;
						if (your_blood_number > 300) {
							your_blood_number = 300;
						}
					}
				}
			}
			//与敌机碰撞
			for (int j = 0; j < max_enemy_num; j++) {
				if (1 == enemy_aircraft[j].if_exist) {
					sf::FloatRect boundingBox1 = enemy_aircraft[j].aircraft.getGlobalBounds();
					if (boundingBox.intersects(boundingBox1)) {
						enemy_boom.play();
						enemy_aircraft[j].if_exist = 0;
						if (1 == if_protect_exist) {
							your_protected_blood -= 20;
						}
						else {
							your_blood_number -= 20;
						}
						break;
					}
				}
				if (1 == enemy_aircraft_2[j].if_exist) {
					sf::FloatRect boundingBox1 = enemy_aircraft_2[j].aircraft.getGlobalBounds();
					if (boundingBox.intersects(boundingBox1)) {
						enemy_boom.play();
						enemy_aircraft_2[j].if_exist = 0;
						if (1 == if_protect_exist) {
							your_protected_blood -= 20;
						}
						else {
							your_blood_number -= 20;
						}
						break;
					}
				}
			}
			//与boss_1碰撞
			if (1 == boss_1.if_exist) {
				sf::FloatRect boundingBox1 = boss_1.aircraft.getGlobalBounds();
				if (boundingBox.intersects(boundingBox1)) {
					enemy_boom.play();
					boss_1.if_exist = 0;
					if (1 == if_protect_exist) {
						your_protected_blood -= 80;
					}
					else {
						your_blood_number -= 80;
					}
				}
			}
			//与boss_2碰撞
			if (1 == boss_2.if_exist) {
				sf::FloatRect boundingBox1 = boss_2.aircraft.getGlobalBounds();
				if (boundingBox.intersects(boundingBox1)) {
					enemy_boom.play();
					boss_2.if_exist = 0;
					if (1 == if_protect_exist) {
						your_protected_blood -= 50;
					}
					else {
						your_blood_number -= 50;
					}
				}
			}
			//被敌机子弹射中
			for (int j = 0; j < max_enemy_missile_num; j++) {
				if (1 == enemy_missile[j].if_exist) {
					sf::FloatRect boundingBox1 = enemy_missile[j].missile.getGlobalBounds();
					if (boundingBox.intersects(boundingBox1)) {
						enemy_missile[j].if_exist = 0;
						if (1 == if_protect_exist) {
							your_protected_blood -= 10;
						}
						else {
							your_blood_number -= 10;
						}
						break;
					}
				}
				if (1 == enemy_missile_2[j].if_exist) {
					sf::FloatRect boundingBox1 = enemy_missile_2[j].missile.getGlobalBounds();
					if (boundingBox.intersects(boundingBox1)) {
						enemy_missile_2[j].if_exist = 0;
						if (1 == if_protect_exist) {
							your_protected_blood -= 10;
						}
						else {
							your_blood_number -= 10;
						}
						break;
					}
				}
			}
			//被boss_1子弹射中
			for (int j = 0; j < max_enemy_missile_num; j++) {
				if (1 == boss_1_missile[j].if_exist) {
					sf::FloatRect boundingBox1= boss_1_missile[j].missile.getGlobalBounds();
					if (boundingBox.intersects(boundingBox1)) {
						boss_1_missile[j].if_exist = 0;
						if (1 == if_protect_exist) {
							your_protected_blood -= 20;
						}
						else {
							your_blood_number -= 20;
						}
						break;
					}
				}
			}
			//被boss_2子弹射中
			for (int j = 0; j < max_enemy_missile_num; j++) {
				if (1 == boss_2_missile[j].if_exist) {
					sf::FloatRect boundingBox1 = boss_2_missile[j].missile.getGlobalBounds();
					if (boundingBox.intersects(boundingBox1)) {
						boss_2_missile[j].if_exist = 0;
						if (1 == if_protect_exist) {
							your_protected_blood -= 30;
						}
						else {
							your_blood_number -= 30;
						}
						break;
					}
				}
			}
			//血量
			sf::VertexArray quad1(sf::Quads, 4);
			quad1[0].position = sf::Vector2f(10, 10);
			quad1[1].position = sf::Vector2f(10 + your_blood_number, 10);
			quad1[2].position = sf::Vector2f(10 + your_blood_number, 30);
			quad1[3].position = sf::Vector2f(10, 30);
			quad1[0].color = sf::Color::Red;
			quad1[1].color = sf::Color::Red;
			quad1[2].color = sf::Color::Red;
			quad1[3].color = sf::Color::Red;
			//能量
			sf::VertexArray quad2(sf::Quads, 4);
			quad2[0].position = sf::Vector2f(10, 50);
			quad2[1].position = sf::Vector2f(10, 70);
			quad2[2].position = sf::Vector2f(10+your_energy_number, 70);
			quad2[3].position = sf::Vector2f(10+ your_energy_number, 50);
			quad2[0].color = sf::Color::Green;
			quad2[1].color = sf::Color::Green;
			quad2[2].color = sf::Color::Green;
			quad2[3].color = sf::Color::Green;
			window.clear();
			window.draw(background);
			window.draw(quad1);
			window.draw(quad2);
			window.draw(my_aircraft->aircraft);
			window.draw(text3);
			window.draw(text4);
			//死亡，生命-1
			if (your_blood_number <= 0) {
				if_my_aircraft_exist = 0;
				your_life--;
			}
			//使用1技能
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z) && (your_energy_number >= 100)) {
				sf::Time elapsed7 = clock7.getElapsedTime();
				if (elapsed7.asSeconds() > 0.5) {
					if_protect_exist = 1;
					your_protected_blood = 100;
					your_energy_number -= 100;
					clock7.restart();
				}
			}
			if (1 == if_protect_exist) {
				if (your_blood_number + your_protected_blood <= 300) {
					sf::VertexArray quad3(sf::Quads, 4);
					quad3[0].position = sf::Vector2f(10 + your_blood_number, 10);
					quad3[1].position = sf::Vector2f(10 + your_blood_number, 30);
					quad3[2].position = sf::Vector2f(10 + your_blood_number + your_protected_blood, 30);
					quad3[3].position = sf::Vector2f(10 + your_blood_number + your_protected_blood, 10);
					quad3[0].color = sf::Color::White;
					quad3[1].color = sf::Color::White;
					quad3[2].color = sf::Color::White;
					quad3[3].color = sf::Color::White;
					window.draw(quad3);
				}
				if ((your_blood_number + your_protected_blood > 300) && (your_blood_number != 300)) {
					sf::VertexArray quad4(sf::Quads, 4);
					quad4[0].position = sf::Vector2f(10 + your_blood_number, 30);
					quad4[1].position = sf::Vector2f(10 + your_blood_number, 10);
					quad4[2].position = sf::Vector2f(310, 10);
					quad4[3].position = sf::Vector2f(310, 30);
					quad4[0].color = sf::Color::White;
					quad4[1].color = sf::Color::White;
					quad4[2].color = sf::Color::White;
					quad4[3].color = sf::Color::White;
					window.draw(quad4);
				}
				if ((your_blood_number + your_protected_blood > 300) && (your_blood_number == 300)) {
					sf::VertexArray quad5(sf::Quads, 4);
					quad5[0].position = sf::Vector2f(310, 30);
					quad5[1].position = sf::Vector2f(310, 10);
					quad5[2].position = sf::Vector2f(310 - your_protected_blood, 10);
					quad5[3].position = sf::Vector2f(310 - your_protected_blood, 30);
					quad5[0].color = sf::Color::White;
					quad5[1].color = sf::Color::White;
					quad5[2].color = sf::Color::White;
					quad5[3].color = sf::Color::White;
					window.draw(quad5);
				}
			}
			if (your_protected_blood <= 0){
				if_protect_exist = 0;
				}
			if (1 == if_protect_exist) {
				sf::CircleShape shape(75);
				shape.setFillColor(sf::Color::Transparent);
				shape.setOrigin(75, 75);
				shape.setPosition(my_aircraft->aircraft.getPosition());
				shape.setOutlineThickness(10);
				shape.setOutlineColor(sf::Color(250, 150, 100));
				window.draw(shape);
			}
			//使用2技能
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::X) && (your_energy_number >= 200)) {
				int index_x = 0;
				int index_y = window_width;
				for (int i = max_my_missile_num - 30; i < max_my_missile_num; i++) {
					my_missile[i].if_exist = 1;
				}
				index_y = window_width - 50;
				for (int i = max_my_missile_num - 30; i < max_my_missile_num - 20; i++) {
					index_x += window_lenth / 10;
					my_missile[i].missile.setPosition(index_x, index_y);
				}
				index_y -= 50;
				index_x = 0;
				for (int i = max_my_missile_num - 20; i < max_my_missile_num - 10; i++) {
					index_x += window_lenth / 10;
					my_missile[i].missile.setPosition(index_x, index_y);
				}
				index_y -= 50; index_x = 0;
				for (int i = max_my_missile_num - 10; i < max_my_missile_num; i++) {
					index_x += window_lenth / 10;
					my_missile[i].missile.setPosition(index_x, index_y);
				}
				your_energy_number -= 200;
			}
			if (your_energy_number >= 100) {
				window.draw(text1);
			}
			if (your_energy_number >= 200) {
				window.draw(text2);
			}
			//绘制我方子弹
			for (int i = 0; i < max_my_missile_num; i++) {
				if (1 == my_missile[i].if_exist) {
					window.draw(my_missile[i].missile);
				}
			}
			//绘制敌机
			for (int j = 0; j < max_enemy_num; j++) {
				if (1 == enemy_aircraft[j].if_exist) {
					window.draw(enemy_aircraft[j].aircraft);
				}
				if (1 == enemy_aircraft_2[j].if_exist) {
					window.draw(enemy_aircraft_2[j].aircraft);
				}
			}
			//绘制敌机子弹
			for (int j = 0; j < max_enemy_missile_num; j++) {
				if (1 == enemy_missile[j].if_exist) {
					window.draw(enemy_missile[j].missile);
				}
				if (1 == enemy_missile_2[j].if_exist) {
					window.draw(enemy_missile_2[j].missile);
				}
				if (1 == boss_1_missile[j].if_exist) {
					window.draw(boss_1_missile[j].missile);
				}
				if (1 == boss_2_missile[j].if_exist) {
					window.draw(boss_2_missile[j].missile);
				}
			}
			//绘制boss
			if (1 == boss_1.if_exist) {
				window.draw(boss_1.aircraft);
			}
			if (1 == boss_2.if_exist) {
				window.draw(boss_2.aircraft);
			}
			//绘制能量
			for (int j = 0; j < max_enemy_num; j++) {
				if (1 == energy[j].if_exist) {
					window.draw(energy[j].missile);
				}
				if (1 == energy_2[j].if_exist) {
					window.draw(energy_2[j].missile);
				}
			}
			for (int j = 0; j < 2; j++) {
				if (1 == blood[j].if_exist) {
					window.draw(blood[j].missile);
				}
			}
			//改变敌机刷新时间
			if ((your_score % 100 == 0) && (your_score<=500)){
				renew_aircraft_time -= 0.2;
				your_score += 5;
			}
			//改变boss_1刷新时间
			if ((your_score%150==0) && (your_score<=1050)) {
				renew_boss_1_time -= 1;
				your_score += 5;
			}
			//改变boss_2刷新时间
			if ((your_score % 200 == 0) && (your_score <= 1200)) {
				renew_boss_2_time -= 1;
				speed_multiple += 0.2;
				your_score += 5;
			}
			if ((0 == if_my_aircraft_exist) &&(your_life!=0)){
				blood[0].if_exist = 0;
				blood[1].if_exist = 0;
				for (int j = 0; j < max_enemy_num; j++) {
					enemy_aircraft[j].if_exist = 0;
					energy[j] .if_exist= 0;
				}
				for (int j = 0; j < max_my_missile_num; j++) {
					my_missile[j].if_exist = 0;
				}
				for (int j = 0; j < max_enemy_missile_num; j++) {
					enemy_missile[j].if_exist = 0;
					boss_1_missile[j].if_exist= 0;
					boss_2_missile[j].if_exist= 0;
					boss_1.if_exist = 0;
					boss_2.if_exist = 0;
				}
				i_boom.play();
				window.draw(death_picture);
				window.display();
				Sleep(3000);
				break;
			}
			if ((0 == if_my_aircraft_exist) && (your_life == 0)) {
				if (your_life == 0) {
					sf::Text text5;
					text5.setFont(font);
					char s3[100];
					sprintf_s(s3, "YOUR FINAL SCORE:%d\n", your_score);
					text5.setString(s3);
					text5.setCharacterSize(54);
					text5.setFillColor(sf::Color::Red);
					text5.setPosition(window_lenth/2-300 , 200);
					window.draw(game_over);
					window.draw(text5);
					window.display();
					Sleep(5000);
					break;
				}
			}
			window.display();
		}
	}
	return 0;
}
