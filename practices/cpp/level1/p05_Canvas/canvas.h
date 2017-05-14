#ifndef CANVAS_H_
#define CANVAS_H_
#include<cstring>
#include "shape.h"
#include "point.h"

using namespace std;

class canvas: public shape
{
    public:
        canvas(){
            memset(s, 0 , sizeof(s));
            num = 0; 
        }
        ~canvas();
        void add_circle(double x, double y, double z);
        void add_rect(double w, double x, double y, double z);
        void draw();
    private:
        shape *s[10];
        int num;
};

#endif
