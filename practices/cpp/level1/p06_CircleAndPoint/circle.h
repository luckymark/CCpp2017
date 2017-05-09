class Point
{
    public:
        double x,y;
        Point(){}
        Point(const double &x, const double &y);
};

class Circle
{
    public:
        Point centre_point;
        double radius;
        void move(const Point &p);
};
