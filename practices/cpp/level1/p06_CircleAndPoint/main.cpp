/*
todolist
1.定义圆心
2.定义圆的半径
3.移动圆心
4.改变圆的半径
5.显示圆
*/
#include "Point.h"
#include "Circle.h"
#include <iostream>
using namespace std;
int main(int argc,char **argv) {
	Point p(0, 0);
	Circle c1(p, 5);
	c1.showCircle();
	c1.move(-10, 20);
	c1.showCircle();
	c1.resize(300);
	c1.showCircle();
	return 0;
}