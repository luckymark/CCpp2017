#ifndef SHAPE_H
#define SHAPE_H

class Shape
{
	public:
		Shape(int a=0,int b=0);
		virtual void show();
	protected:
		int x,y;
};
class Circle:public Shape
{
		int r;
	public:
		Circle(int a,int b,int c);
		virtual void show(); 
};
class Rect:public Shape
{
		int x_length,y_length;
	public:
		Rect(int a,int b,int c,int d);
		virtual void show(); 
};

#endif
