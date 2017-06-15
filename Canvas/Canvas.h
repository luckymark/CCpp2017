#include "Shape.h"

class Canvas{
	private:
		Shape** shapes;
		int capability,End;
	public:
		Canvas(int capability);
		~Canvas();
		void insert(Shape* shape,int tag);
		void draw();
};
