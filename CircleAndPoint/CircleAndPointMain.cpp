#include "Circle.h"
using namespace std;

int main(){
	int x,y,r;
	scanf("%d%d%d",&x,&y,&r);//����Բ��(x,y),�뾶r
	Circle circle(Point(x,y),r);
	circle.print();
	
	int delta_x,delta_y;//����Բ���ƶ�������(delta_x,delta_y)
	scanf("%d%d",&delta_x,&delta_y);
	circle.move(delta_x,delta_y);
	circle.print();
	return 0;
}
