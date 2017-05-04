#include"Point.h"
#include"Circle.h"

int main(void)
{
	Point p(5, 3);
	Circle c(p, 6);
	p.Show();
	p.Move();
	p.Show();
	c.Show();
	c.Move();
	c.Show();
	system("pause");
	return 0;
 }