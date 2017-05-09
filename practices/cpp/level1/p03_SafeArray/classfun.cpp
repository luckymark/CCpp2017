/*
 * classfun.cpp
 *
 *  Created on: 2017年3月30日
 *      Author: mark
 */
#include<iostream>
#include"SafeArry.h"
using namespace std ;

void SafeArry::put(int number , int value)
{
	if(number >= k || number < 0  ){
		cout<<"sorry over "<<endl;
	}
	else{
		arry[number] = value ;
	}
}

int SafeArry::get(int number)
{
	if(number >= k || number < 0  ){
		cout<<"ilegal visit"<<endl;
		return 0;
	}
	else{
		return arry[number];
	}
}



