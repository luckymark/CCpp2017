#include <iostream>
#include "Point.h"
#include "Circle.h"
using namespace std;
int main(){
		Circle my_c(0,0,1);
		my_c.show();
		my_c.move(Point(1,2));
		my_c.show();
		return 0;

}
