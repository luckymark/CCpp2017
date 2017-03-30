/*
 * main.cpp
 *
 *  Created on: 2017年3月30日
 *      Author: mark
 */

#include<iostream>
#include"SafeArry.h"
#include<time.h>
#include<stdlib.h>
using namespace std ;

int main()
{

	cout<<"how many numbers do you want to save?"<<endl;

	int number ;

	cin>>number ;


	SafeArry a(number);

	for(int i = 0 ; i< 100 ; i++ ){
		srand(time(0));
		a.put(i,rand());
	}

	int m ;

	while(1){
		cout<<"which number do you want to know ?"<<endl;
		cin>>m;
		if(m==-1)break;
		cout<<a.get(m)<<endl;
	}
}


