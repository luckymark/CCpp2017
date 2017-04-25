#include<iostream>
#include "Canvas.h"
#include "Shape.h"
int main(){
	Canvas can1;
	Circle c1(3,4,5),c2(1,0,1);
	Rect r1(1,2,4,3);
	
	can1.add(c1);
	can1.add(c2);
	can1.add(r1);
	can1.show();
	
	return 0;
}
