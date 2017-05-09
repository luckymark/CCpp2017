#include <iostream>
#include "Point.h"
#include "Circle.h"


/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	Circle circle=Circle(2.3,1.9,5.8);
	circle.show();
	circle.changeXYR(circle.gitX(),4.9,circle.gitR()+9.3);
	circle.show();
	circle.move(-3.5,4.6);
	circle.show();
	circle.extend(16);
	circle.show();
	return 0;
}

