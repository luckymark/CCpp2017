#include "Circuit.h"

void Fan::show(){
	cout << "The Fan " << name << " is " << (state == 1 ? "On" : "Off") << endl;
}
