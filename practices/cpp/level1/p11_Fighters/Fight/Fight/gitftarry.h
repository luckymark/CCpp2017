/*
 * gitftarry.h
 *
 *  Created on: 2017年6月8日
 *      Author: mark
 */

#ifndef GITFTARRY_H_
#define GITFTARRY_H_
#include<vector>
#include<iostream>
#include"gift.h"
using namespace std ;
class Gift
{
public:
	Gift(sf::Texture &tex){
		texture1 = tex;
		texture2 = tex ;
	}



	vector<gift> arry;

	void create(){
		if(rand()%20==1){
			gift a;
			a.setsprite(texture1);
			a.setPosition(rand()%500+100,0);
			arry.push_back(a);
		}
	}

	void fly(){
		for(int i = 0 ; i < arry.size();i++){
			if(arry[i].gety()<1000){
				arry[i].fly();
			}
			else{
				arry.erase(arry.begin()+i);
			}
		}
	}


	sf::Texture texture1  ;
	sf::Texture texture2  ;
};




#endif /* GITFTARRY_H_ */
