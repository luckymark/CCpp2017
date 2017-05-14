#include<iostream>
#include "canvas.h"
#include "circle.h"
#include "rect.h"

using namespace std;

void canvas::add_circle(double x, double y, double z)
{
    s[num++] = new circle(x, y ,z);
}

void canvas::add_rect(double w, double x, double y, double z)
{
    s[num++] = new rect(w , x, y, z);
}

void canvas::draw()
{
    for(int i = 0; i < num; i++)
    {
        s[i] -> draw();
    }
}

canvas::~canvas()
{
    if(num)
    {
        delete []s;
    }
}
