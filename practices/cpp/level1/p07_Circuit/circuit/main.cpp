#include <iostream>
#include "Circuit.h"
using namespace std;
int main()
{
    Circuit my_circuit;
    Fan my_fan;
    Lamp my_lamp;

    my_circuit.add(&my_fan);
    my_circuit.state();

    my_circuit.add(&my_lamp);
    my_circuit.state();

    my_circuit.power_on();
    my_circuit.state();

    my_fan.turn_on();
    my_circuit.state();

    my_lamp.turn_on();
    my_circuit.state();

    my_circuit.power_off();
    my_circuit.state();

    return 0;
}
