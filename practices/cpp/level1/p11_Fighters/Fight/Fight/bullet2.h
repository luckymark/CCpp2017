/*
 * bullet2.h
 *
 *  Created on: 2017年5月28日
 *      Author: chen
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
		bullet a(1);
		a.sprite.setTexture(texture1);
		a.set(x+55,y);
		A.push_back(a);
	}
	void add_e(int x , int y){
		bullet a('a');
		a.sprite.setTexture(texture2);
		a.sprite.setRotation(180);
		a.set(x-55,y);
		A.push_back(a);
	}

void control_bullet(){
	if(A.size()!=0){
//		std::cout<<"in the control_bullet"<<std::endl;
		for(int i = 0;i < A.size();i++){
			if(A[i].getb()==0){
				int j = A[i].fly1();
				if( j == 0){A.erase(A.begin() + i );
		//		std::cout<<"in erase"<<std::endl;
				}
			}
			if(A[i].getb()==1){
				int j = A[i].fly2();
				if( j == 0){A.erase(A.begin() + i );
		//		std::cout<<"in erase"<<std::endl;
				}

			}
		}
	}
}

void destry()
{
	int k = 0;
	while(k<A.size()){
		if(A[k].status==0){
			A.erase(A.begin()+k);
			std::cout<<"destory the bullet"<<std::endl;
			k=0;
			continue;
		}
		k++;
	}
}
	vector <bullet>A ;
	sf::Texture  texture1;
	sf::Texture  texture2;
};




#endif /* BULLET2_H_ */
