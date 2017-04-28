#include "Circuit.h"

void Light::show(){
	cout << "The Light " << name << " is " << (state == 1 ? "On" : "Off") << endl;
}

