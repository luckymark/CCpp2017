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
using namespace std ;
class ArrayBullet
{
public:
	void add_m(int x , int y){
		bullet a(1);
		a.set(x,y);
		A.push_back(a);
		size = A.size();
	}
	void add_e(int x , int y){
		bullet a('a');
		a.set(x,y);
		A.push_back(a);
		size = A.size();
	}

	void control_bullet(){
		if(A.size()!=0){
			for(int i = 0;i <= size;i++){
				if(A[i].getb()==1){
					int j = A[i].fly1();
					if( j == 0){
						std::vector<bullet>::iterator it = A.begin()+j ;
						A.erase(it);
					}
				}
				if(A[i].getb()==0){
					int j = A[i].fly1();
					if( j == 0){
						std::vector<bullet>::iterator it = A.begin()+j ;
						A.erase(it);
					}
				}


			}
		}
	}
	vector <bullet>A ;
	int size = 0;
};




#endif /* BULLET2_H_ */
