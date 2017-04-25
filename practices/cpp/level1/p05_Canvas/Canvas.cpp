#include "Canvas.h"
#include<iostream>

Canvas::Canvas(){
	i=0;
}
void Canvas::add(Shape & item){
	if(i<10){
		data[i]=&item;
		i++;
	}
	else{
		std::cout<<"Error,this Canvas is full!\n";
	}
}
void Canvas::show(){
	for(int j=0;j<i;j++){
		data[j]->show();
	}
}
