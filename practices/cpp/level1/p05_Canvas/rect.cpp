#include<iostream>
#include "rect.h"

using namespace std;

rect::rect(double w, double x, double y, double z)
{
    p = point(w , x);
    length = y;
    width = z;
}

double rect::get_length()
{
    return length;
}

double rect::get_width()
{
    return width;
}

void rect::draw()
{
    cout<<"The top left corner point is ";
    p.display();
    cout<<"The length of the rect is "<<get_length();
    cout<<", and the width of rect is "<<get_width()<<endl; 
}
