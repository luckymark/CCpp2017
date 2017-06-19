#include "Canvas.h"
#include <iostream>
using namespace std;

void Canvas::add(Shape* shape){
	canvas.push_back(shape);
}

void Canvas::draw(){
	for(i=canvas.begin();i!=canvas.end();++i){
		(*i)->show();
}
