#include <iostream>
#include "Circuit.h"
#include "Device.h"
#include "Fan.h"
#include "Lamp.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	Circuit circuit;
	circuit.add((Device*)(new Fan("big")));
	circuit.add((Device*)(new Lamp("small")));
	circuit.showAll();
	circuit.turnOn(1);
	circuit.showOn();
	circuit.turnOnAll();
	circuit.showOn();
	circuit.turnOff(1);
	circuit.turnOffAll();
	circuit.showOn();
	return 0;
}
