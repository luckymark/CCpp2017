
class Point
{
	private:
		double x;
		double y; 
		
	public:
		Point(){};
		Point(double nx, double ny);
		void move(double nx, double ny);
		void reset(double nx, double ny);	
			
};

class Circle
{
	private:
		Point center;
		double radius;
	public:
		Circle(double r, double x, double y);
		Circle(double r, Point &p);
		void move(double cx, double cy);
		void moveTo(double nx, double ny);
};
