#include "Shape.h"
#include<iostream>
using std::cout;
using std::endl;
Shape::Shape(int a,int b){
	x=a;
	y=b;
}
void Shape::show(){
	;
}
Circle::Circle(int a,int b,int c):Shape(a,b){
	r=c;
}
Rect::Rect(int a,int b,int c,int d):Shape(a,b){
	x_length=c;
	y_length=d;
}
void Circle::show(){
	cout<<"Circle: Center: X = "<<x<<" Y = "<<y<<" Parameter: R = "<<r<<endl;
}
void Rect::show(){
	cout<<"Rectangle: Center: X = "<<x<<" Y = "<<y<<"\n\t  Parameter: length of X = "
	<<x_length<<" length of Y = "<<y_length<<endl;
}
