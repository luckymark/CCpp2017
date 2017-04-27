#include "Switch.h"

Switch::Switch(){
	on=0;
}

void Switch::TurnOn(){
	on=1;
}

void Switch::TurnOff(){
	on=0;
}

bool Switch::is_on(){
	return on;
}
