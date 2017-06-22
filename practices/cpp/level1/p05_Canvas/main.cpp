#include"canvas.h"
int main()
{
	Canvas can;
	can.newCircle(10, 10, 30, "s1");
	can.newCircle(5, 5, 50, "c2");
	can.newRect(30, 10, 10, 5, "R1");
	can.newRect(10, 30, 50, 50, "R2");
	can.show();
	can.move("R2", 5, 3);
	can.show();
}