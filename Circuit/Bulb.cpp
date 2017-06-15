#include "Bulb.h"

Bulb::Bulb(){
	on=lighting=0;
}

void Bulb::TurnOn(){
	on=1;
	lighting=1;//You can add more operations of a bulb.
}

void Bulb::TurnOff(){
	on=0;
	lighting=0;
}
