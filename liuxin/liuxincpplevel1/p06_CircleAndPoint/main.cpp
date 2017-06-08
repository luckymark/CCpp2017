#include <iostream>
#include "Point.h"
#include "Circle.h"
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	while (1) {
		double x,y,r;
		cin>>x>>y>>r;
		Point A(x,y);
		Circle Q(A,r),P(x,y,r);
		Q.show();
		cin>>x>>y;
		Q.move(x,y);
		Q.show();
		cin>>x>>y;
		P.move(x,y);
		P.show();
	}
	return 0;
}
