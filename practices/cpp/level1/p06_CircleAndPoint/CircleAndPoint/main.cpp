#include<cstdio>
#include "Circle.h"
#include "point.h"
using namespace std;
int main(){
    Circle A=Circle(0,0,1);
    A.show();
    A.move(1,1);
    A.show();
    A.extend(2);
    A.show();
    return 0;
}
