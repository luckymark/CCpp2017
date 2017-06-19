#ifndef CL_POINT_H
#define CL_POINT_H

using namespace std;
class point
{
    private:
        int x; int y;
    public:
        point(int x0=0,int y0=0)
        {
            x=x0;
            y=y0;
        }
        void set(int x1,int y1)
        {
            x=x1;
            y=y1;
        }
        void move(int dx,int dy)
        {
            x+=dx;
            y+=dy;
        }
        void show()
        {
            cout<<"("<<x<<","<<y<<")";
        }
};


#endif //CL_POINT_H
