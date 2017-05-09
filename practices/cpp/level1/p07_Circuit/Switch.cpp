#include "Circuit.h"

void Switch::show(){
	cout << "The Switch " << name << " is " << (state == 1 ? "On" : "Off") << endl;
}

int Switch::is_switch(){
	return 1;
}
