#include <iostream>
#include "Canvas.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	Canvas canvas;
	canvas.addTriangle(1,1,3,5,2,6);
	canvas.addCircle(2,3,4);
	canvas.addRectangle(7,7,2,5);
	canvas.delCircle(2,3,4);
	canvas.draw();
	return 0;
}
