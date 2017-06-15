#include "Circle.h"
using namespace std;

int main(){
	int x,y,r;
	scanf("%d%d%d",&x,&y,&r);//读入圆心(x,y),半径r
	Circle circle(Point(x,y),r);
	circle.print();
	
	int delta_x,delta_y;//读入圆心移动的向量(delta_x,delta_y)
	scanf("%d%d",&delta_x,&delta_y);
	circle.move(delta_x,delta_y);
	circle.print();
	return 0;
}
