#include<iostream>
#include"circle.h"

void draw(Circle);

using namespace  std ;
int main()
{
    Circle A(10,10,3);

    draw(A);

    A.move(-10,10);

    draw(A);

}

void draw(Circle B)
{
    cout<<"x="<<B.getx()<<endl;
    cout<<"y="<<B.gety()<<endl;
    cout<<"R="<<B.getr()<<endl;
}
