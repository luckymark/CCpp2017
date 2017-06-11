#include <cstdio>
#include "Circle.h"

    Circle::Circle(){
        circle_point=Point();
        r=0;
    }
    Circle::Circle(double x_input,double y_input,double r_input){
        circle_point=Point(x_input,y_input);
        r=r_input;
    }
    Circle::Circle(Point Point_input,double r_input){
        circle_point=Point_input;
        r=r_input;
    }
    void Circle::move(double aim_x,double aim_y){
        circle_point.change(aim_x,aim_y);
    }
    void Circle::extend(double aim_r){
        r=aim_r;
    }
    void Circle::show(){
        printf("point at (%.3lf,%.3lf) and round is %.3lf\n",circle_point.getx(),circle_point.gety(),r);
    }
