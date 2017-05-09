#ifndef POINT_H
#define POINT_H
class Point{
	private:
		double x,y;
	public:
		Point();
		Point(double _x,double _y);
		double gitX();
		double gitY();
		void changeXY(double _x,double _y);
		void show();
};
#endif

