/*
 * Author:	Kyrios0
 * Date:	2016.04
 * To-Do List:
 *			Circle 
 	*			Point 
 * State:	Processing
 */
#include <iostream>
#include "circle.h"
using namespace std;


int main(int argc, char** argv) {
	Point p1(2.0, 2.0);
	Circle ra(5.0, p1);
	ra.move(1.0, 2.0);
	ra.moveTo(3.0, 3.0);
	return 0;
}
