#include "Canvas.h"
int main(){
	Canvas can;
	can.creat_circle(Point(1,2),3);
	can.creat_circle(Point(3,3),10);
	can.creat_rect(Point(1,2),Point(2,3));
	can.creat_rect(Point(1,2),Point(3,3));
	can.creat_tri(Point(1,2),Point(3,4),Point(5,6));

	can.show();
	can.move(4,Point(2,3));
	can.show(4);
	return 0;
}
