# include<iostream>
using namespace std;

class Point {
private:
	int x,y;
public:
	Point(int sx=0, int sy=0)
	{
		x = sx;
		y = sy;
	}
	int GetX()
	{
		return x;
	}
	int GetY()
	{
		return y;
	}
	void SetPoint(int setx,int sety)
	{
		x = setx;
		y = sety;
	}
};

class Circle {
private:
	Point now;

	int R;
public:
	Circle(int r , Point nw) {
		R = r;
		now = nw;
	}
	void show()
	{
		cout << "x = " << now.GetX() << "\t" << "y = " << now.GetY() << endl;
		cout << "R = " << R << endl;
	}
	Circle move(int movex,int movey)
	{
		int NextX, NextY;
		NextX = now.GetX() + movex;
		NextY = now.GetY() + movey;
		Point temp;
		temp.SetPoint(NextX, NextY);
		Circle Temp(R, temp);
		return Temp;
	}
	
};
int main()
{
	Point P1(3, 5);
	Point P2(0, 0);
	Circle C1(3, P1);
	C1.show();
	Circle C2 = C1.move(1, 2);
	cout << "after " << 1 << " move :" << endl;
	C2.show();
	for (int i = 0; i < 9; i++) {
		 C2 = C2.move(1, 2);
		 cout << "after " << i + 2 << " move :" << endl;
		C2.show();
	}
	
	system("pause");
	return 0;
}
