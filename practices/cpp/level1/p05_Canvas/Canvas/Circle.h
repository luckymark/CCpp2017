#ifndef CIRCLE_H
#define CIRCLE_H

class Circle :public Shape
{
	public:
		void add();
		virtual void show();
	protected:
		int x,y,r;
};

#endif
