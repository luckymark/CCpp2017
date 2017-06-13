#include <iostream>
#include "Circuit.h"
#include "Fan.h"
#include "Lamp.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	Circuit circuit;
	Fan fan;
	Lamp lamp;
	circuit.add(&fan);
	circuit.add(&lamp);
	circuit.on();
	circuit.off();
	return 0;
}
