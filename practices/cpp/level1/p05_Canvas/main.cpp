#include "Circle.h"
#include "Rect.h"
#include "Canvas.h"
#include <cstdio>

using namespace std;

int main(){
	int x,y,r,x1,y2;
	Canvas canvas(1000);

	Circle circle(1,1,1);
	canvas.add(&circle,1);

	Rect rect(1,1,4,4);
	canvas.add(&rect,2);

	canvas.draw();

	return 0;
}
