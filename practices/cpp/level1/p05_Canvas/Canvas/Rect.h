#ifndef RECT_H
#define RECT_H

class Rect :public Shape 
{
	public:
		void add();
		virtual void show();
	protected:
		int a,b,c,d;
};

#endif
