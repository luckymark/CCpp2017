/*
 * main.cpp

 *
 *  Created on: 2017年3月31日
 *      Author: mark
 */
#include<iostream>
#include<string.h>
#include"Subject.h"
#include"class.h"
using namespace std;


int main()
{
		SUBJECT AI ;

	while(1){
		cout<<"add-1,delete-2,putscore-3,show-4,quit-5"<<endl;

		int flag = 0 ;

		int Switch ;
		cin >> Switch ;

		switch ( Switch ){
		case 1 :
			{
				Student student ;
				string name ;
				cin>>name ;
				student.Setname(name);
				AI.ADD_STUDENT(student);
			}
			break;
		case 2:
				cout<<"NUMBER"<<endl;
				int number ;
				cin>>number;
				number = AI.DELETE_STUDENT(number);
				if(number == 1 )cout<<"NO student in the system!"<<endl;
			break;
		case 3:
			{
				while(1){
				string name ;
				cout<<"NAME"<<endl;
				cin>>name ;
				cout<<"SCORE"<<endl;
				float score ;
				cin>>score;

				int i =AI.putsource(name,score);
				if( i == 1 )cout<<"can't find the student!"<<endl;
				cout<<"Do you want to still? y/n"<<endl;
				char c ;
				cin>>c;
				if(c=='n')break;
				}
			}
			break;
		case 4:
			{
				int j = AI.show();
				if( j == 1 )cout<<"no student!"<<endl;
			}
				break ;
		case 5:
			flag = 1 ;
			break ;
		}
		if( flag == 1 )break ;
	}

	cout<<"Thanks for using !"<<endl;

}
