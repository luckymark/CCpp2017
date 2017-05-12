#include<iostream>
#include"CirCuit.h"
#include"Fan.h"
#include"Lamp.h"

int main(void)
{
	Circuit C;
	Fan f;
	Lamp l;
	C.add(f);
	C.add(l);
	C.on();
	C.off();
	system("pause");
	return 0;
}