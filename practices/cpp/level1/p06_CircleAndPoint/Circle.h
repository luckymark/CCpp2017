#ifndef CIRCLE_H
#define CIRCLE_H
#include "Point.h"


class Circle
{
    public:
        Circle();
        virtual ~Circle();
        void SetCenter(Point O);
        void Show();
        void ChangeSize(int r);
        void SetR(int r);
        int GetR();
        Point GetCenter();
        void Move(int x,int y);

    private:
        int r;
        Point center;
};

#endif // CIRCLE_H
