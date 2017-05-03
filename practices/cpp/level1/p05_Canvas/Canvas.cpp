# include<iostream>
using namespace std;
int Nc, Nr;

class Point {
private:
	int X, Y;
public:
	Point(int x = 0, int y = 0)
	{
		X = x;
		Y = y;
	}
	int GetX()
	{
		return X;
	}
	int GetY()
	{
		return Y;
	}
	void SetPoint(int x, int y)
	{
		X = x;
		Y = y;
	}
};

class Circle {
private:
	int R;
	Point Circl;
public:
	Circle(int r=0, Point circl = 0)
	{
		R = r;
		Circl = Circl;
	}
	void show()
	{
		cout << "The radius r = " << R << endl;
		cout << "The circlepoint is:" << "(" << Circl.GetX() << "," << Circl.GetY() << ")" << endl;
	}
	void SetCircle(int r, Point c)
	{
		R = r;
		Circl = c;
	}
};

class Rect {
private:
	Point Left;
	Point Right;
public:
	Rect(Point left=0, Point right= 0)
	{
		Left = left;
		Right = right;
	}
	void show()
	{
		cout << "The left point Left = " << "(" << Left.GetX() << "," << Left.GetY() << ")" << endl;
		cout << "The right point Right = " << "(" << Right.GetX() << "," << Right.GetY() << ")" << endl;
	}
	void SetRect(Point left, Point right)
	{
		Left = left;
		Right = right;
	}
};

class Canvas {
private:
		Circle *pc = new Circle[Nc];
		Rect *pr = new Rect[Nr];
		int iC;
		int iR;
public:
	void addCir(Circle c)
	{
		pc[iC] =  c;
		iC++;
	}
	void addRec(Rect r)
	{
		pr[iR] = r;
		iR++;
	}
	void showall()
	{
		cout << "The circles you have saved are below:" << endl;
		for (int i = 0; i < iC; i++) {
			pc[i].show();
		}
		cout<< "The rectangles you have saved are below:" << endl;
		for (int i = 0; i < iR; i++) {
			pr[i].show();
		}
	}
};

int main()
{
	cout << "How many circles do you want to save?" << endl;
	cin >> Nc;
	cout << "How many rectangles do you want to save?" << endl;
	cin >> Nr;
	Point P1;
	Point P2;
	Circle C;
	Rect R;
	Canvas Ca;
	int r = 0, xc = 0, yc = 0;
	for (int i = 0; i < Nc; i++) {
		cout << "Please input the " << i + 1 << "th circle:" << endl;
		cout << "r = ";
		cin >> r;
		cout  << "Please input its circlepoint :" << endl;
		cout << "x = ";
		cin >> xc;
		cout << "y = ";
		cin >> yc;
		
		P1.SetPoint(xc, yc);
		C.SetCircle(r, P1);
		Ca.addCir(C);
	}
	int leftx = 0, lefty = 0;
	int rightx = 0, righty = 0;
	for (int i = 0; i < Nr; i++) {
		cout << "Please input the " << i + 1 << "th rectangle:" << endl;
		cout << "The left lower point :" << endl;
		cout << "x = ";
		cin >> leftx;
		cout << "y = ";
		cin >> lefty;
		cout << "The left lower point :" << endl;
		cout << "x = ";
		cin >> rightx;
		cout<< "y = ";
		cin >> righty;
		
		P1.SetPoint(leftx, lefty);
		P2.SetPoint(rightx, righty);
		R.SetRect(P1, P2);
		Ca.addRec(R);
	}
	cout << endl;
	Ca.showall();
	system("pause");
	return 0;
}

