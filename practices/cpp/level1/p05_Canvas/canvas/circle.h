#ifndef CL_CIRCLE_H
#define CL_CIRCLE_H

#include"point.h"
#include"shape.h"

using namespace std;
class circle: public shape
{
    private:
        int r;
        point o;
    public:
        circle(int x0=0,int y0=0,int r0=0)
        {
            o.set(x0,y0);
            if(r0<0) return;
            r=r0;
        }
        circle(point p0,int r0)
        {
            o=p0;
            r=r0;
        }
        void show()
        {
            if(r<0)
            {
                cout<<"illegal circle"<<endl;
                return;
            }
            cout<<"circle  center:";
            o.show();
            cout<<" radius:"<<r<<endl;
        }
        void move(int dx,int dy)
        {
            o.move(dx,dy);
        }
        void resize(int r1)
        {
            r=r1;
        }
};


#endif //CL_CIRCLE_H
