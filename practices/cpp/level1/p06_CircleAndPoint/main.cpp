#include<iostream>
#include "Point.h"
#include "Circle.h"
using namespace std;
int main(){
	Point p(3,4);
	Circle circle1(p,5);
	
	cout<<circle1<<endl;
	circle1.move(3,4);//Ô²ÐÄÒÆ¶¯ £¨3£¬4£©
	cout<<circle1<<endl;
	circle1.change(3);//°ë¾¶+3 
	cout<<circle1<<endl;
	circle1.change(-7);//°ë¾¶-7 
	cout<<circle1<<endl;
	circle1=circle1+p;//Ô²ÐÄÒÆ¶¯ p 
	cout<<circle1<<endl;
	
	return 0;
}
