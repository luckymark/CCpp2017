
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
			cout <<"ʹ�õ�����������ʧ��";
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
		life_number.setPosition(110,0);

		//life.setString
		score_name.setString("score:");
		score_name.setFont(font);
		score_name.setFillColor(Color::Blue);
		score_name.setCharacterSize(40);
		score_name.setPosition(0,40);

		
		//rocker_name
		rocketname.setString("Rocket:");
		rocketname.setFont(font);
		rocketname.setFillColor(Color::Red);
	    rocketname.setCharacterSize(40);
		rocketname.setPosition(100,580);

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
}

void Object_manage::game_loop()
{
	if (Game_state == begin_just_now)
	{
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
				cout << "aaaaaa";
				Game_state = game_over;
			}
		}
	}
	if (Game_state == game_over)
	{
		exit(0);
	}
	if (Game_state == pass_barrier)
	{
		cout << "������";
		Sleep(10000);
		exit(0);
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
				draw_life();
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

}


void  Object_manage::draw_life()
{
	the_window.draw(life);
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
	if (kill_enermy >= 10)
	{
		Game_state = pass_barrier;
	}
}

void Object_manage::update_All()
{
	/*Text ad;
	//a.setFont(font);
	ad.setString("jfejfjfojgoep");

	ad.setFillColor(Color::Blue);
	//a.setFont()
	ad.setOrigin(-100,-200);
	//a.setFont()
	the_window.draw(ad);
	//the_window.display();

	/*update_time = update_clock.getElapsedTime();
	if (operator>=(update_time,update_all_time))
	{
	update_time= update_clock.restart();
	}
	else
	{
	return;
	}*/
	for (int j = 0; j <= 30000; j++)
	{
		j++;
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
	//control_next();
}



//void draw _rocket();
//void draw_rocket_number();
void Object_manage::add_quicker_plane()
{
	//vector<Quicker_killer*>::iterator itm=quickBUllet_list.begin()
	
		Quicker_killer *h= new Quicker_killer(1);
		int t = window_width / (h->get_width()/2);
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
		if ((*itm)->get_y()>=0)
		{
			delete (*itm);
			Object_manage::need_update_superBullet--;
			itm = quickBUllet_list.erase(itm);
			continue;
		}
		//cout << "���½�����";
		(*itm)->__y += (*itm)->speed;
		(*itm)->sprite.setOrigin((*itm)->__x,(*itm)->__y);
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
	
	Game_state= begin_just_now;//״̬����
	for (int i = 0; i < 2; i++)
	{
		bac[i] = new background("image/background.png");//�ӱ���
	}
	start_window = new background("image/start.psd");//����������
	add_plane("image/shoot.png", new My_plane);//���ҵķɻ�
	p = new start_interface;//����������
	while (1)
	{
		game_loop();//������Ϸ
	}

}

Object_manage::~Object_manage()
{

}




void Object_manage::add_plane(string name,My_plane* my)
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
					it->second->My_y = it->second->My_y+it->second->My_plane_speed;
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
					cout << "ctrl����"<<endl;
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
	if (it->second->My_y>0 || it->second->My_y< -window_heigth+ it->second->my_Plane_height)
	{
		it->second->My_y = temp0;
	}
	if (it->second->My_x>it->second->my_Plane_width / 2 || it->second->My_x  < -window_width+ it->second->my_Plane_width / 2)
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
			if ((*ita)->MyBullet_y >=0)//����ɳ���Ļ�����ҵ��ӵ��б�ɾ��
			{
				delete (*ita);
				ita=MyBullet_list.erase(ita);
				continue;
			}
			(*ita)->MyBullet_sprite.setOrigin((*ita)->MyBullet_x,(*ita)->MyBullet_y);
			//ÿ�δ������˾ͻ���ȥ����
			the_window.draw((*ita)->MyBullet_sprite);
			ita++;
		}
	
}




void Object_manage::add_Enermy()//���µл�λ��
{
	time = clock.getElapsedTime();
	if (operator>=(time,update_Enermy_time))//�����ȡ��ʱ����ڸ��µ�ʱ��
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
			Enermy_Bullet_list.push_back( new Enermy_Bullet(*it));
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
			ith= Enermy_list.erase(ith);
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
			itm=Enermy_Bullet_list.erase(itm);
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
		(*itm)->Enermy_Bullet_sprite.setOrigin((*itm)->Enermy_Bullet_x,(*itm)->Enermy_Bullet_y);
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
			itm=Fly_BUlllet_list.erase(itm);
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
						score_all += 10;
					}
					if ((*it_Enermy)->Enermy_filename == "image/p1.png")
					{
						score_all += 5;
					}
					if ((*it_Enermy)->Enermy_filename == "image/p2.png")
					{
						score_all += 20;
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
			it_myPlane->second->my_plane_life --;
			//��������ӵ�
			delete *(it_Enermy_Bullet);
			it_Enermy_Bullet = Enermy_Bullet_list.erase(it_Enermy_Bullet);
			MyPlane_explode *p = new MyPlane_explode(it_myPlane->second);
			for (int t = 0; t <= 100; t++)
			{
				the_window.display();
			}
			delete p;//ɾ���ҵķɻ���ըͼ��
			if(it_myPlane->second->my_plane_life==0)
			//if (it_myPlane->second->shooted_time >= it_myPlane->second->my_plane_life)
			{
				Game_state = failed;
				draw_life();
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
						score_all += 10;
					}
					if ((*it_Enermy)->Enermy_filename == "image/p1.png")
					{
						score_all += 5;
					}
					if ((*it_Enermy)->Enermy_filename == "image/p2.png")
					{
						score_all += 20;
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
