#include "Circuit.h"
#include <iostream>
using namespace std;
int main(){
	Circuit cir;
	cir.insert_power(1,2,"power_1");
	cir.insert_light(2,3,"light_1");
	cir.insert_light(3,4,"light_2");
	cir.insert_fan(2,5,"fan_1");
	cir.insert_fan(4,5,"fan_2");
	cir.insert_fan(5,6,"fan_3");
	cir.insert_switch(6,7,"s_1");
	cir.insert_switch(7,8,"s_2");
	cir.insert_switch(7,8,"s_3");
	cir.insert_switch(8,1,"s_4");

	cir.show();
	cout << endl;
	cir.change_switch(7);
	cir.show();
	cout << endl;
	cir.change_switch(7);
	cir.change_switch(8);
	cir.show();
	cout << endl;
	cir.change_switch(9);
	cir.show();
	cout << endl;
	
	return 0;
}
