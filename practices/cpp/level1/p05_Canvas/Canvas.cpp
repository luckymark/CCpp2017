#include "Canvas.h"

void Canvas::draw(Graphics *element)
{
	container.push_back(element);
}

void Canvas::output()
{
	for(vector<Graphics*>::iterator it = container.begin();it != container.end(); it++)
	{
		(*it)->showParams();
	}
}
