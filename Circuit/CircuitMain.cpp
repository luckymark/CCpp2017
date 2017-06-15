#include <cstdio>
#include "Bulb.h"
#include "Fan.h"
#include "Circuit.h"
using namespace std;

int main(){
	Circuit circuit(100);
	Bulb bulb;
	Fan fan;
	
	circuit.insert(&bulb);
	circuit.insert(&fan);
	circuit.test();
}
