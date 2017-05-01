#include<iostream>

using namespace std;

class point
{
    public:
        point(double a = 0, double b = 0): x(a), y(b){}
        double getx();
        double gety();
        double display();
        double setcenter(double a, double b);
    private:
        double x;
        double y;
};

double point::getx()
{
    return x;
}

double point::gety()
{
    return y;
}

double point::display()
{
    cout<<"("<<x<<", "<<y<<")"<<endl;
}

double point::setcenter( double a, double b)
{
    x = a;
    y = b;
}

class circle: public point
{
    public:
        circle(point p = point(), double radius = 0.0): p(p), radius(radius){}
        circle(double x, double y, double z);
        double get_radius();
        void draw();
        int move(double x, double y);
        int resize(double a);
    private:
        double radius;
        point p;
};

circle::circle(double x, double y, double z)
{
    p = point(x, y);
    radius = z;
}

double circle::get_radius()
{
    return radius;
}

void circle::draw()
{
    cout<<"the center of circle is: ";
    p.display();
    cout<<"the radius of circle is: "<<get_radius()<<endl;
}

int circle::move(double a, double b)
{
    p = point(a, b);
}

int circle::resize(double a)
{
    radius = a;
}

int main(void)
{
    circle c1(10, 20, 100);
    c1.draw();
    cout<<"Change the circle center."<<endl;
    c1.move(-10, 20);
    c1.draw();
    cout<<"Change the circle redius."<<endl;
    c1.resize(300);
    c1.draw();
}
