#include <iostream>
#include "Canvas.h"
#include "Rect.h"
#include "Circle.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	Canvas c1;
//	Circle b1
	Circle* b1 = new Circle(3, 2, 10);
//	Rect r1(3, 2, 10, 20);  
	Rect* r1 = new Rect(3, 2, 10, 20);
	c1.add(b1);
	c1.add(r1); 
	c1.draw(); 
	return 0;
}
