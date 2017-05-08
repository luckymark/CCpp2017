#ifndef SHAPE_H
#define SHAPE_H


class Shape
{
    public:
        Shape();
        virtual ~Shape();
        Shape(int x,int y);
        virtual void draw() = 0;


    protected:
        int x,y;

    private:
};

#endif // SHAPE_H
