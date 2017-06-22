#include<bits/stdc++.h>
using namespace std;
#ifndef CANVAS_H_
#define CANVAS_H_

class point {
protected:
	int x, y;
public:
	point(int x = 0, int y = 0);
	void move(int x, int y);
	~point(){}
};
class Circle:public point {
private:
	int radius;
public:
	Circle(int r, int x = 0, int y = 0);
	~Circle(){}
	void show();
};

class Rect :public point {
private:
	int height;
	int	length;
public:
	Rect(int l,int h, int x = 0, int y = 0);
	void show();
	~Rect(){}
};

class Canvas {
private:
	map<string, Rect>rectlist;
	map<string, Circle>circlelist;
	int circle_count;
	int rect_count;
public:
	void newCircle(int r, int x = 0, int y = 0, string name = "undefined");
	void newRect(int l, int h, int x = 0, int y = 0, string name = "undefined");
	Canvas();
	~Canvas(){}
	void move(string s1,int offx,int offy);
	void show();
};

#endif // !CANVAS_H_
