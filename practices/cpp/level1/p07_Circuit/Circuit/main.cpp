#include <iostream>
#include "Device.h"
#include "Lamp.h"
#include "Fan.h"
#include "Circuit.h"

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	Circuit circuit;
	Fan fan;
	Lamp lamp;
	Device device;
	
	circuit.add(&fan);
	circuit.add(&lamp);
	circuit.on();
	circuit.off();
	return 0;
}
