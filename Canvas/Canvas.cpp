#include "Canvas.h"

Canvas::Canvas(int capability){
	this->capability=capability;
	End=0;
	if(capability){
		shapes=new Shape*[capability];
		tag=new int[capability];
	}
}

Canvas::~Canvas(){
	if(capability){
		delete []shapes;
		delete []tag;
	}
}

void Canvas::insert(Shape* shape,int tag){
	shapes[End]=shape;
	this->tag[End++]=tag;
}

void Canvas::draw(){
	for(int i=0;i<End;++i){
		if(tag[i]==0){
			((Point*)shapes[i])->draw();
		}
		else if(tag[i]==1){
			((Circle*)shapes[i])->draw();
		}
		else{
			((Rect*)shapes[i])->draw();
		}
	}
}
