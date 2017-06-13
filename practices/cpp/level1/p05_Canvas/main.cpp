#include <iostream>
#include "Canvas.h"
#include "Circle.h"
#include "Rect.h"
using namespace std;

Canvas* Canvas::instance = NULL;

int main(int *argv,char **argc)
{
	Canvas *canvas = Canvas::getInstance();
	Circle circle1;
	circle1.setR(2);
	Point p = Point(1,1);
	circle1.setPoint(p);
	Rect rect1;
	Point p2 = Point(2,2);
	rect1.setPoint(p2);
	rect1.setWidth(3);
	rect1.setHeight(3);
	canvas->draw(&rect1);
	canvas->draw(&circle1);
	canvas->output(); 
	return 0;
}
