#include <iostream>
#include "Point.h"
#include "Circle.h"
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	Point p1(3, 2);
	Circle c1(p1, 50); 
	c1.move(-1, 1);
	c1.show();
	return 0;
} 
