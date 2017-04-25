#include "Point.h"
#include "Circle.h"
#include "Rect.h"

class Canvas{
	private:
		Shape** shapes;
		int* tag;
		int capability,End;
	public:
		Canvas(int capability);
		void insert(Shape* shape,int tag);
		void draw();
};
