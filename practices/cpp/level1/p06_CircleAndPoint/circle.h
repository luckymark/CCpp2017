#include"point.h"
class Circle
{
    private:
        Point A;
        float R;
    public:
       Circle(int x,int y , int r):R(r){
            A.setx(x) ;
            A.sety(y) ;    
       }
        
        
        void move(int x , int y){
            A.setx(A.getx()+x);
            A.sety(A.gety()+y);
        }

        int getx(){
            return A.getx();
        }

        int gety(){
            return A.gety();
        }

        float getr(){
            return R ;
        }

        void set(int a , int b , float r){
            A.setx(a) ;
            A.sety(b) ;
            R = r ;
        }

};
