#ifndef SHAPE_H_
#define SHAPE_H_

using namespace std;

class shape
{
    public:
        shape(double a = 0, double b = 0): x(a), y(b){}
        ~shape(){}
        virtual void draw() = 0;
    private:
        double x, y;
};

#endif
