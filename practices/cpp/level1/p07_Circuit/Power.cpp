#include "Circuit.h"

int Power::is_power(){
	return 1;
}

void Power::show(){
	cout << "The Power " << name << " is " << (state == 1 ? "On" : "Off") << endl;
}

