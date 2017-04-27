#include <cstdio>
#include "Circuit.h"

Circuit::Circuit(int capability){
	this->capability=capability;
	End=0;
	if(capability){
		switches=new Switch*[capability];
	}
}

Circuit::~Circuit(){
	if(capability){
		delete[] switches;
	}
}

void Circuit::insert(Switch* sw){
	switches[End++]=sw;
}

void Circuit::test(){
	for(int i=0;i<End;++i){
		switches[i]->TurnOn();
		printf(switches[i]->is_on() ? "ON " : "OFF ");
		switches[i]->TurnOff();
		puts(switches[i]->is_on() ? "ON" : "OFF");
	}
}
