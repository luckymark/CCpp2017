#ifndef POINT_H
#define POINT_H
struct Point{
private:
    double x,y;
public:
    Point(double x_input,double y_input);
    Point();
    double getx();
    double gety();
    void change(double x_input,double y_input);
};
#endif // POINT_H
