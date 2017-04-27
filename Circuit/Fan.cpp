#include "Fan.h"

Fan::Fan(){
	on=rotating=0;
}

void Fan::TurnOn(){
	on=1;
	rotating=1;//You can add more operations of a fan.
}

void Fan::TurnOff(){
	on=0;
	rotating=0;
}
