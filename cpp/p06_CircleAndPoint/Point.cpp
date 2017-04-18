#include"point.h"

void Point::MovePoint(int x, int y)
{
	this->x = x;
	this->y = y;
}

void Circle::move(int x, int y)
{
	this->pt.MovePoint(x, y);
}

void Circle::ChangeR(int r)
{
	this->r = r;
}

/*void Circle::show()
{
	int x = pt->x;
	int y = pt->y;

	for (int i = x - r; i < x + r; i++)
	{
		for (int j = y - r; j < y + y; j++)
		{
			if ()
			{
				cout << "*";
			}
		}
	}
}
*/