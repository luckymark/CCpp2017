#include<iostream>
#include<string>
#include<conio.h>
#include"Score.h"
using namespace std;
int main(){
	const string s1="c",s2="c++",s3="java";
	Score ccpp[3]={Score(s1),Score(s2),Score(s3),};
	char ch;
	
	do{
		system("cls");
		cout<<"What do you want to do?\n";
		cout<<"Watch the list(1.c 2.c++ 3.java)\n";
		cout<<"Add students(4.c 5.c++ 6.java)\n";
		cout<<"Delete students(7.c 8.c++ 9.java)\n";
		cout<<"Write the score(c.c p.c++ j.java)\n";
		cout<<"Quit(0)\n";
		ch=getch();
		switch(ch){
			case '1':
				ccpp[0].disp();
				system("pause");
				break; 
			case '2':
				ccpp[1].disp();
				system("pause");
				break; 
			case '3':
				ccpp[2].disp();
				system("pause");
				break; 
			case '4':
				ccpp[0].add();
				break;
			case '5':
				ccpp[1].add();
				break;
			case '6':
				ccpp[2].add();
				break;
			case '7':
				ccpp[0].del();
				break;
			case '8':
				ccpp[1].del();
				break;
			case '9':
				ccpp[2].del();
				break;
			case 'c':
				ccpp[0].write();
				break;
			case 'p':
				ccpp[1].write();
				break;
			case 'j':
				ccpp[2].write();
				break;
			case '0':
				return 0;
			default:
				;
		}
		 
	}while(1);
	
	return 0;
}
