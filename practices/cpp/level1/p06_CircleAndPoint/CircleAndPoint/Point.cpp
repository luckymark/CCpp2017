#include "Point.h"

Point::Point(){
    x=0;
    y=0;
}

Point::Point(double x_input,double y_input){
    x=x_input;
    y=y_input;
}

double  Point::getx(){
    return x;
}

double  Point::gety(){
    return y;
}

void Point::change(double x_input,double y_input){
    x=x_input;
    y=y_input;
}
