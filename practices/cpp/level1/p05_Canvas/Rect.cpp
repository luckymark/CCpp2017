#include "Canvas.h"

void Rect::show(){
	cout << "This is a Rect." << endl;
	cout << "U_L: " << u_l.x << " " << u_l.y << endl;
	cout << "D_R: " << d_r.x << " " << d_r.y << endl;
}

void Rect::move(Point x){
	u_l = u_l + x;
	d_r = d_r + x;
}

double Rect::area(){
	return (d_r.x - u_l.x) * (d_r.y - u_l.y);
}
