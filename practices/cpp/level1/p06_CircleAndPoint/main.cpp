/*
todolist
1.����Բ��
2.����Բ�İ뾶
3.�ƶ�Բ��
4.�ı�Բ�İ뾶
5.��ʾԲ
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