#include "Canvas.h"


Canvas::Canvas(int can){
	this->Can=can;
	Last=1;
	if(Can>0){
		shapes=new Shape*[Can];
	}
}

Canvas::~Canvas(){}

void Canvas::add(Shape* shape,int tag){
	shapes[Last]=shape;
	Last++;
}

void Canvas::draw(){
	for(int i=1;i<Last;++i){
		shapes[i]->draw();
	}
}
