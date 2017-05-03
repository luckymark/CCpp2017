#ifndef POINT_H
#define POINT_H


class Point
{
    public:
        Point();
        virtual ~Point();
        void SetX(int x);
        int GetX();
        void SetY(int y);
        int GetY();

    private:
        int x,y;
};

#endif // POINT_H
