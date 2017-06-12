#include <iostream>
#include "Point.h"
#include "Circle.h"

using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	Point p1(10,20);
	Circle c1(100);
	p1.draw();
	c1.draw();
	
	int x1,y1;
	cin>>x1>>y1;
	p1.move(x1,y1);
	p1.draw();
	c1.draw();
	
	int r1;
	cin>>r1;
	c1.resize(r1);
	p1.draw();
	c1.draw();
	return 0;
}
