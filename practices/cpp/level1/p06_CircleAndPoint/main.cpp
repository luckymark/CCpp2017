#include <iostream>
#include "Circle.h"
#include "Point.h"

using namespace std;

int main(void) {
	Circle circle;
	Point point;
	point.SetX(1);
	point.SetY(1);
	circle.SetCenter(point);
	circle.SetR(1);
	circle.Show();
	cout<<"\n";

	circle.Move(2,2);
	cout<<"�ƶ�Բ�ĺ�"<<endl;
	circle.Show();
	cout<<"\n";

	circle.ChangeSize(2);
	cout<<"�ı�뾶��"<<endl;
	circle.Show();
	cout<<"\n";

	return 0;
}
