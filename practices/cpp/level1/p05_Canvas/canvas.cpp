/*
题目：Canvas（画布程序）

功能要求：

可以在Canvas上添加任意数量的Circle（圆）、Rect（矩形）等图形元素
可画出画布上的所有图形（可用在console上输出图形元素的名称、属性参数，来代替在真实的图形界面的绘制操作）
*/
#include<iostream>
#include<vector>
using namespace std;

class Shape{
	public:
		virtual void show()=0;
};

class Circle:public Shape{
	public:
		Circle(int,int,int);
		void show();
	private:
		double x;
		double y;
		double r;
};

class Rect:public Shape{
	public:
		Rect(int,int,int,int);
		void show();
	private:
		double left;
		double top;
		double right;
		double bottom;
};

class Canvas{
	private:
		vector<Shape*> shapevector;
	public:
		void print();
		void add(Shape*);
};
Circle::Circle(int a,int b,int c){
	x=a;
	y=b;
	r=c;
}

void Circle::show(){
	cout<<"Circle:centre("<<this->x<<","<<this->y<<"),radius:"<<this->r<<endl;
}

Rect::Rect(int a,int b,int c,int d){
	left=a;
	top=b;
	right=c;
	bottom=d;
}

void Rect::show(){
	cout<<"Rect:("<<this->left<<","<<this->top<<"),("<<this->right<<","<<this->bottom<<")"<<endl;
}

void Canvas::print(){
	for(auto it=this->shapevector.begin();it!=this->shapevector.end();it++){
		(*it)->show();
	}
}

void Canvas::add(Shape* s){
	shapevector.push_back(s);
}

int main(){
    Circle c(5,5,2);
    Rect r(1,4,4,1);
    Canvas canvas;
    canvas.add(&c);
    canvas.add(&r);

    canvas.print();
	return 0;
}
