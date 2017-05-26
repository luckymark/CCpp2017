/*
 * bullet2.h
 *
 *  Created on: 2017年5月18日
 *      Author: mark
 */

#ifndef BULLET2_H_
#define BULLET2_H_
#include"bullet.h"
#include<iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
using namespace std ;

class ArrayBullet
{
public:
	void add_m(int x , int y){
		sf::Mutex mutex;
		mutex.lock();
		bullet a(1);
		a.sprite.setTexture(texture1);
		a.set(x+55,y);
		A.push_back(a);
		mutex.unlock();
	}
	void add_e(int x , int y){
		sf::Mutex mutex;
		mutex.lock();
		bullet a('a');
		a.sprite.setTexture(texture2);
		a.sprite.setRotation(180);
		a.set(x-55,y);
		A.push_back(a);
		mutex.unlock();
	}

void control_bullet(){
	sf::Mutex mutex;
	while(1){
		mutex.lock();
		if(A.size()!=0){
			for(int i = 0;i < A.size();i++){
				if(A[i].getb()==0){
					int j = A[i].fly1();
					if( j == 0){A.erase(A.begin() + i );}
				}
				if(A[i].getb()==1){
					int j = A[i].fly2();
					if( j == 0){A.erase(A.begin() + i );}
				}

		   }
			mutex.unlock();
			sf::sleep(sf::milliseconds(10));
		}
	}
}
	vector <bullet>A ;
	sf::Texture  texture1;
	sf::Texture  texture2;
};

#endif /* BULLET2_H_ */
