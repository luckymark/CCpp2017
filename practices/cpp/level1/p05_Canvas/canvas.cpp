#include"canvas.h"
point::point(int x, int y)
{
	this->x = x;
	this->y = y;
}
void point::move(int offx, int offy)
{
	x += offx;
	y += offy;
}

Circle::Circle(int r, int x, int y) :point(x, y) { radius = r; }


Rect::Rect(int l, int h, int x, int y) :point(x, y)
{
	length = l;
	height = h;
}

void Canvas::newCircle(int r, int x, int y , string name)
{
	circlelist.insert(pair<string, Circle>(name, Circle(r, x, y)));
	circle_count++;
}
void Canvas::newRect(int l, int h, int x , int y , string name)
{
	rectlist.insert(pair<string, Rect>(name, Rect(l, h, x, y)));
	rect_count++;
}

Canvas::Canvas()
{
	circlelist.clear();
	rect_count = 0;
	circle_count = 0;
	rectlist.clear();
}

void Circle::show()
{
	printf("Center: (%2d,%2d) Radius: %d \n", x, y, radius);
}

void Rect::show()
{
	printf("Center: (%2d,%2d) height: %d length: %d \n", x, y, height, length);
}
void Canvas::move(string s1, int offx, int offy)
{
	map<string, Circle>::iterator it;
	it = circlelist.find(s1);
	if (it == circlelist.end()) {
		map<string, Rect>::iterator it2;
		it2 = rectlist.find(s1);
		if (it2 == rectlist.end()) {
			printf("There is no shape named %s.\n",s1);
		}
		else it2->second.move(offx, offy);
	}
	else it->second.move(offx, offy);
}

void Canvas::show()
{
	for (map<string, Circle>::iterator it=circlelist.begin(); it != circlelist.end(); it++) {
		cout << "Cricel name:  " << it->first;
		it->second.show();
	}
	for (map<string, Rect>::iterator it=rectlist.begin(); it != rectlist.end(); it++) {
		cout << "Rect   name:  " << it->first;
		it->second.show();
	}
	printf("\n\n");
}