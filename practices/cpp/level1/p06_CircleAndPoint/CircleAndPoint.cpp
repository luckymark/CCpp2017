#include "CircleAndPoint.h"

void Circle::move()
{
	cout << "请输入您想将其移动到什么位置：(x,y)" << endl;
	int x = 0;
	int y = 0;
	cin >> x;
	cin >> y;
	point.x = x;
	point.y = y;
}

void Circle::show()
{
	cout << "当前位置为（" << point.x << "," << point.y << "）" << endl;
}
