#include<iostream>
using namespace std;

class point {
private:
	int x, y;		//点横坐标x，纵坐标y
public:
	point(int xx = 0, int yy = 0)
	{
		x = xx, y = yy;
	}
	void move();
	void show();
}Point;
void point::move()
{
	int move_x, move_y;
	cout << "请输入即将移动横坐标的大小：" << endl;
	cin >> move_x;
	cout << "请输入即将移动的纵坐标的大小" << endl;
	cin >> move_y;
	x += move_x, y += move_y;
}
void point::show()
{
	cout <<"点坐标"<< "(" << x << "," << y << ")" << endl;		//移动后点坐标
}

class circle :public point
{
private:
	int radii;		//圆的直径
public:
	circle(int R, int x, int y) :point(x, y)
	{
		radii = R;
	}
	void show_cir()
	{
		show();
		cout << "the radii of tthe circle is " << radii << endl;
	}
};

void main()
{
	circle Circle(1,0,0);
	Circle.show_cir();
	Circle.move();
	Circle.show_cir();
}
