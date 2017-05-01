#ifndef  POINT_H
#define POINT_H
#include <iostream>
using namespace std;
class Point {
private:
	int X,Y;
public:
	Point(int X=0, int Y=0);
	void move(int OffX,int OffY);
	void show(void);
protected:
};
#endif 