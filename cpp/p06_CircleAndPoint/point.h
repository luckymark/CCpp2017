#ifndef POINT_H_
#define POINT_H_

class Point
{
public:
	void MovePoint(int x, int y);
	Point(int x=0,int y=0) { this->x = 0; this->y = 0; }

	friend class Circle;
private:
	int x;
	int y;

};

class Circle
{
public:
//	void show();
	void move(int x, int y);
	void ChangeR(int r);
	Circle(int x=0, int y=0, int r=0) { pt.x = x; pt.y = y; this->r = r; }

private:
	int r;
	Point pt;
};

#endif
