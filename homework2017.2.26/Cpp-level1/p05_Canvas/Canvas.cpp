#include <cstdio>
#include "Canvas.h"
#include "Circle.h"
#include "Triangle.h"
#include "Rectangle.h"
Canvas::Canvas(){
	length=800;
	width=600;
	number=1000;
	for (int i=0;i<number;i++){
		shape[i]=NULL;
	}
}

void Canvas::draw(){
	for (int i=0;i<number;i++){
		if (shape[i]!=NULL){
			shape[i]->draw();
		}
	}
}

void Canvas::addCircle(int x,int y,int r){
	for (int i=0;i<number;i++){
		if (shape[i]==NULL){
			shape[i]=new Circle(x,y,r);	
		}
	}
}

void Canvas::delCircle(int x,int y,int r){
	for (int i=0;i<number;i++){
		Circle *tmp=(Circle*)shape[i];
		if (tmp->x==x&&tmp->y==y&&tmp->r==r){
			delete tmp;
			shape[i]=NULL;
			return;
		}
	}
	printf("找不到该图形\n");
	return;
}

void Canvas::addRectangle(int x,int y,int _length,int _width){
	for (int i=0;i<number;i++){
		if (shape[i]==NULL){
			shape[i]=new Rectangle(x,y,_length,_width);	
		}
	}
}

void Canvas::delRectangle(int x,int y,int _length,int _width){
	for (int i=0;i<number;i++){
		Rectangle *tmp=(Rectangle*)shape[i];
		if (tmp->x==x&&tmp->y==y&&tmp->length==_length&&tmp->width==_width){
			delete tmp;
			shape[i]=NULL;
			return;
		}
	}
	printf("找不到该图形\n");
	return;
}

void Canvas::addTriangle(int x1,int y1,int x2,int y2,int x3,int y3){
	for (int i=0;i<number;i++){
		if (shape[i]==NULL){
			shape[i]=new Triangle(x1,x2,x3,y1,y2,y3);	
		}
	}
}

void Canvas::delTriangle(int x1,int y1,int x2,int y2,int x3,int y3){
	for (int i=0;i<number;i++){
		Triangle *tmp=(Triangle*)shape[i];
		if (tmp->x1==x1&&tmp->x2==x2&&tmp->x3==x3&&tmp->y1==y1&&tmp->y2==y2&&tmp->y3==y3){
			delete tmp;
			shape[i]=NULL;
			return;
		}
	}
	printf("找不到该图形\n");
	return;
}
