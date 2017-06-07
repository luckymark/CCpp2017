#include <iostream>
#include "Cell.h"
#include "Circuit.h"
using namespace std;



int main()
{
	Circuit circuit;
	Fan f1,f2;
	Bulb b1,b2;
	circuit.addCell(&f1);
	circuit.addCell(&b2);
	circuit.on();
	circuit.off();
	return 0;
}
