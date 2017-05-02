#ifndef CANVAS_H
#define CANVAS_H


class Canvas
{
	public:
		Canvas();
		void add(Shape* shape_0);
		void showall();
	protected:
		Shape* data[20];
		int num;
};

#endif
