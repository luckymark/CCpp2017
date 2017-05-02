#ifndef CL_RECT_H
#define CL_RECT_H

using namespace std;
class rect: public shape
{
    private:
        point p1,p2,p3,p4;
    public:
        rect(int ax,int ay,int bx,int by,int cx,int cy,int dx,int dy)
        {
            p1.set(ax,ay);
            p2.set(bx,by);
            p3.set(cx,cy);
            p4.set(dx,dy);
        }
        rect(point p01,point p02,point p03,point p04)
        {
            p1=p01;
            p2=p02;
            p3=p03;
            p4=p04;
        }
        void move(int dx,int dy)
        {
            p1.move(dx,dy);
            p2.move(dx,dy);
            p3.move(dx,dy);
            p4.move(dx,dy);

        }
        void show()
        {
            cout<<"rectangle  ";
            p1.show();
            p2.show();
            p3.show();
            p4.show();
            cout<<endl;
        }
};


#endif //CL_RECT_H
