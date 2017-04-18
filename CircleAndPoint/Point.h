#include <cstdio>

class Point{
	private:
		int x,y;
	public:
		Point(int x,int y);
		Point(){};
		void move(int delta_x,int delta_y);
		void print();
};
