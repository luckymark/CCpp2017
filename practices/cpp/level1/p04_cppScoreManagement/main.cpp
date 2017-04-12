/*
 * main.cpp
 *
 *  Created on: 2017年3月31日
 *      Author: mark
 */
#include<iostream>
#include<string.h>
#include"class.h"
using namespace std;


int main()
{
		SUBJECT AI ;

	while(1){
		cout<<"add-1,delete-2,putsorce-3,show-4,quit-5"<<endl;

		int flag = 0 ;

		int Switch ;
		cin >> Switch ;

		switch ( Switch ){
		case 1 :
			AI.ADD_STUDENT();
			break;
		case 2:
			AI.DELETE_STUDENT();
			break;
		case 3:
			AI.putsource();
			break;
		case 4:
			AI.show();
			break ;
		case 5:
			flag = 1 ;
			break ;
		}
		if( flag == 1 )break ;
	}

	cout<<"Thanks for using !"<<endl;

}
