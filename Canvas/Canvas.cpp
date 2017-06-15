#include "Canvas.h"

Canvas::Canvas(int capability){
	this->capability=capability;
	End=0;
	if(capability){
		shapes=new Shape*[capability];
	}
}

Canvas::~Canvas(){
	if(capability){
		delete []shapes;
	}
}

void Canvas::insert(Shape* shape,int tag){
	shapes[End]=shape;
}

void Canvas::draw(){
	for(int i=0;i<End;++i){
		shapes[i]->draw();
	}
}
