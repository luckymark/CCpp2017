#include <iostream>
using namespace std;
#include "Shape.h"
#include "Circle.h"
#include "Rect.h"
#include "Canvas.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	Canvas canvas;
	Shape shape;
	Circle circle;
	Rect rect;
	canvas.showall();
	rect.add();
	circle.add();
	
	return 0;
}
