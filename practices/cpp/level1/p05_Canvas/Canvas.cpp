#include "Canvas.h"

void Canvas::creat_circle(Point x, double r){
	p[++cnt] = new Circle(x,r);
}

void Canvas::creat_rect(Point a, Point b){
	p[++cnt] = new Rect(a,b);
}

void Canvas::creat_tri(Point a, Point b, Point c){
	p[++cnt] = new Tri(a,b,c);
}

void Canvas::move(int whe, Point del){
	p[whe] -> move(del);
}

void Canvas::show(){
	for(int i = 1; i <= cnt; i++){
		p[i] -> show();
	}
}

void Canvas::show(int whe){
	p[whe] -> show();
}

Canvas::~Canvas(){
	for(int i = 1; i <= cnt; i++){
		delete p[i];
	}
}
