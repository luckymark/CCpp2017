#include<iostream>
#include "Point.h"
#include "Circle.h"
using namespace std;
int main(){
	Point p(3,4);
	Circle circle1(p,5);
	
	cout<<circle1<<endl;
	circle1.move(3,4);//Բ���ƶ� ��3��4��
	cout<<circle1<<endl;
	circle1.change(3);//�뾶+3 
	cout<<circle1<<endl;
	circle1.change(-7);//�뾶-7 
	cout<<circle1<<endl;
	circle1=circle1+p;//Բ���ƶ� p 
	cout<<circle1<<endl;
	
	return 0;
}
