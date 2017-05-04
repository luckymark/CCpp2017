#pragma once
#ifndef Canvas_H_
#define Canvas_H_
#include"Shape.h"
#include"Circle.h"
#include"Point.h"
#include"Rect.h"
#include<array>

	class Canvas
	{
	private:
		int length;
		int wide;
		Shape* arr[10];
	public:
		Canvas(void);
		int relen(void) { return length; };
		int rewid(void) { return wide; };
		friend std::istream& operator>>(std::istream &is, Canvas &a);
		friend std::ostream& operator<<(std::ostream &os, Canvas &a);
		void setShape(int i);
		void show(void);
	};

	
#endif // !Canvas_H_