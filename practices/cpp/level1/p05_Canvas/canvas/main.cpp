#include<iostream>
#include"point.h"
#include"circle.h"
#include"rect.h"
#include"shape.h"
#include"canvas.h"
using namespace std;
int main()
{
    circle c1(1,0,1);
    c1.show();

    c1.move(1,-1);
    c1.show();

    c1.resize(2);
    c1.show();

    point p1(1,0);
    circle c2(p1,1);
    c2.show();

    rect r1(0,0,0,1,2,1,2,0);
    r1.show();

    r1.move(-2,-1);
    r1.show();

    cout<<endl<<endl;



    canvas mc;
    mc.add(c1);
    mc.add(r1);
    mc.show();

    return 0;
}
