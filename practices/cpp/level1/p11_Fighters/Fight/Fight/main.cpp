/*
 * main.cpp
 *
 *  Created on: 2017年5月28日
 *      Author: chen
 */

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include<iostream>
#include"advanced.h"
#include"flight.h"
#include"EnemyFlight.h"
#include"map.h"
#include"bullet2.h"
#include"bullet.h"
#include"explosion.h"
#include"gitftarry.h"
#include"gift.h"
#define WIDE 1000
#define HIGH 1000

int main()
{
	int live = 1;
	srand(time(0));

	sf::Texture textureofgift;
	textureofgift.loadFromFile("gift.png");

	Gift arryofgift(textureofgift);

	sf::Clock clock ;
	sf::Clock clock_draw;
	sf::Clock clock_gift;
	sf::Clock clock_gift1;
	sf::Mutex mutex;

    sf::RenderWindow window(sf::VideoMode(WIDE,HIGH), "Fly to Dream");

    std::vector<Explosion*> explosion ;
    sf::Texture Exlosion_Texture;
    Exlosion_Texture.loadFromFile("explosion.png");

    Flight MyFlight;
    sf::Texture MyFlight_Texture;
    MyFlight_Texture.loadFromFile("Flight.png");
    MyFlight.SetTexture(MyFlight_Texture);

    sf::Texture EnemeyFlight_Texture;
    EnemeyFlight_Texture.loadFromFile("2.png");
    EnemyFlight Enemey(EnemeyFlight_Texture);

    Map map("back.jpg");

    ArrayBullet Bullet;
    Bullet.texture1.loadFromFile("bullet1.png");
    Bullet.texture2.loadFromFile("bullet1.png");

 //   sf::Thread BulletControl(&ArrayBullet::control_bullet,&Bullet);

//    BulletControl.launch();

    sf::Clock clock1;
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event)){
            if (event.type == sf::Event::Closed)
            	window.close();
        }
        int b=MyFlight.control();

        if(clock_gift.getElapsedTime()>sf::seconds(1)){
        	arryofgift.create();
        	clock_gift.restart();
        }
        if(clock_gift1.getElapsedTime()>sf::milliseconds(100)){
        	arryofgift.fly();
        	clock_gift1.restart();
        }
        if(!arryofgift.arry.empty()){
        	sf::FloatRect fly = MyFlight.GetSprite().getGlobalBounds();
        	for(int i = 0 ; i <arryofgift.arry.size(); i++  ){
        		sf::FloatRect gift = arryofgift.arry[i].getsprite().getGlobalBounds();
        		if(fly.intersects(gift)){
        			if(arryofgift.arry[i].getm()==1){
        				MyFlight.setlife(1);
        			}
        			arryofgift.arry.erase(arryofgift.arry.begin()+i);
        		}
        	}
        }


        if(b)Bullet.add_m(MyFlight.getx(),MyFlight.gety());

        if(clock1.getElapsedTime()>sf::microseconds(90000)){
        	int m = Enemey.control();
        		while(m/10){
        			Bullet.add_e(Enemey.E[m%10]->getx()+10,Enemey.E[m%10]->gety()+10);
        			m = m / 10 ;
        		}
        		clock1.restart();
        }
        if(clock.getElapsedTime()>sf::milliseconds(10)){
        	Bullet.control_bullet();
        	clock.restart();
        }

        for(int i = 0 ;i < Bullet.A.size();i++){
        	for(int j = 0 ;j < Enemey.E.size();j++)
        	{
        		sf::FloatRect fly = Enemey.E[j]->GetSprite().getGlobalBounds();
        		sf::FloatRect bul = Bullet.A[i].getsprite().getGlobalBounds();
        		if(!Bullet.A[i].getb()&&fly.intersects(bul)){
        			Bullet.A[i].status=0;
        			Enemey.E[j]->setlive();
        			Bullet.A.erase(Bullet.A.erase(Bullet.A.begin()+j));
        			explosion.push_back(new Explosion(Exlosion_Texture));
        			explosion[explosion.size()-1]->setposition(Enemey.E[j]->getx(),Enemey.E[j]->gety());
        		}
        	}
        }
        for(int i = 0 ;i < Bullet.A.size();i++){
        	sf::FloatRect fly = MyFlight.GetSprite().getGlobalBounds();
        	sf::FloatRect bul = Bullet.A[i].getsprite().getGlobalBounds();
        	if(Bullet.A[i].getb()&&fly.intersects(bul)){
        		Bullet.A[i].status=0;

        		MyFlight.setlife(-1);
        		explosion.push_back(new Explosion(Exlosion_Texture));
        		explosion[explosion.size()-1]->setposition(MyFlight.getx()+70,MyFlight.gety()+70);
        		std::cout<<"life --"<<std::endl;
        		if(MyFlight.ifdeath()){
        			live = 0;
        			break;
        		}
        	}
        }
        Bullet.destry();

        if(live == 0){
        	for(int k = 0; k<explosion.size();k++){
        		if(explosion[k]!=NULL){
        			std::cout<<"explosin draw"<<std::endl;
        			window.draw(explosion[k]->sprite);
        			std::cout<<"explosin draw"<<std::endl;
        			window.display();
        		}
        	}
        	break;
        }

        if(Enemey.destory()){
        	std::cout<<"finish destory"<<std::endl;
        }

        window.clear(sf::Color::Black);
        window.draw(map.Getsprite());
        window.draw(MyFlight.GetSprite());
        for(int i= 0 ; i < Bullet.A.size();i++){
        	window.draw(Bullet.A[i].getsprite());
        }

        for(int j = 0 ;j<Enemey.getnumber();j++){
        	window.draw(Enemey.E[j]->GetSprite());
        }

        for(int k = 0; k<explosion.size();k++){
        	if(explosion[k]!=NULL){
        		window.draw(explosion[k]->sprite);
        	//	std::cout<<"draw the explosion \n"<<explosion[k]->x<<" "<<explosion[k]->y<<endl;
        	}
        }

        for(int k = 0; k<explosion.size();k++){
        	if(explosion[k]->clock.getElapsedTime()>sf::milliseconds(500)){
        		delete explosion[k] ;
        		explosion[k] = NULL;
        		std::cout<<"in delete"<<endl;
        	}
        }

        int j = 0;
        while(j!=explosion.size()){
        	if(explosion[j]==NULL){
        		explosion.erase(explosion.begin()+j);
        		j=0;
        		continue;
        	}
        	j++;
        }

        for(int k = 0 ;k<arryofgift.arry.size();k++){
        	window.draw(arryofgift.arry[k].getsprite());
        }

  //      window.draw(test);
        window.display();

    }
    return 0 ;
}






