#include<iostream>
#include "Circuit.h"
#include "Device.h"
int main(){
	Circuit circuit1;
	Fan fan1;
	Light light1;
	circuit1.add(&fan1);
	circuit1.add(&light1);
	circuit1.on();
	circuit1.disp();
	circuit1.off();
	circuit1.disp();
	
	return 0;
}
