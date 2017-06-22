#include"Circle.h"
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

Circle::Circle(int r, int x, int y) :pt(x, y) { radius = r; }

pair<int, int> point::getPos() { return make_pair(x, y); }

void Circle::move(int x, int y) { pt.move(x, y); }

void Circle::show()
{
	cout << "Center: (" << pt.getPos().first << "," << pt.getPos().second << ")" << "  Radius: " << radius << endl;
}