#include "Canvas.h"

void Tri::show(){
	cout << "This is a Tri." << endl;
	for(int i = 0; i < 3; i++){
		cout << "Point " << i << " is: " << p[i].x << " " << p[i].y << endl;
	}
}

void Tri::move(Point x){
	for(int  i = 0; i < 3; i++)
		p[i] = p[i] + x;
}

double Tri::area(){
	return abs((p[2]-p[0]).det(p[1]-p[0]))/2;
}
