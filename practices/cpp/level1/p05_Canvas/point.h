#ifndef POINT_H_
#define POINT_H_

using namespace std;

class point
{
    public:
        point(double a = 0, double b = 0): x(a), y(b){}
        void display();
    private:
        double x, y;
};

#endif
