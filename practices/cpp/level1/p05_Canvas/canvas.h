#include <vector>
using namespace std;

class Point;
class Circle;
class Rectan;
class Canvas;

class Point
{
private:
	double x;
	double y;

public:
	Point() {};
	Point(double nx, double ny);
	friend Canvas;
};

class Circle
{
private:
	Point center;
	double radius;
public:
	Circle() {};
	Circle(double r, double x, double y);
	Circle(double r, Point &p);
	friend Canvas;
};

class Rectan
{
private:
	Point center;
	double len;
	double hei;
	double theta;
public:
	Rectan() {};
	Rectan(double l, double h, double x, double y, double the);
	Rectan(double l, double h, Point &p, double the = 0);
	friend Canvas;
};

class Canvas
{
private:
	vector<Circle> circles;
	vector<Rectan> rectans;
public:
	Canvas() {};
	void paint();
	void add();
	void del();
};