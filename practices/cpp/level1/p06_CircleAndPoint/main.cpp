#include <cstdio>
#include "main.h"
using namespace std;

int main()
{
    Circle circle;
    Point p;
    scanf("%lf%lf%lf", &circle.centre_point.x, &circle.centre_point.y, &circle.radius);
    printf("%lf %lf %lf\n", circle.centre_point.x, circle.centre_point.y, circle.radius);
    scanf("%lf%lf", &p.x, &p.y);
    circle.move(p);
    printf("%lf %lf %lf\n", circle.centre_point.x, circle.centre_point.y, circle.radius);
    Point p1(p);
    printf("%lf %lf", p1.x, p1.y);
    return 0;
}

Point::Point(const double &x, const double &y)
{
    this->x = x;
    this->y = y;
}

void Circle::move(const Point &p)
{
    this->centre_point = p;
}