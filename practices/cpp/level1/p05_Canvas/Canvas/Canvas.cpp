#include <iostream>
using namespace std;
#include "Shape.h"
#include "Canvas.h"


Canvas::Canvas()
{
	Shape* data[20]={0};
	num=0;
}
void Canvas::add(Shape* shape_0)
{
	data[num]=shape_0;
	num++;
}
void Canvas::showall()
{
	for(int i=1;i<=num;i++)
	{
		data[i]->show();
	}
}
