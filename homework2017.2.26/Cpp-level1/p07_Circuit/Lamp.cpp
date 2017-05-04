#include <cstdio>
#include "Lamp.h"

Lamp::Lamp(char _identification[]){
	isOn=0;
	strcpy(identification,_identification);
}

void Lamp::show(){
	printf("µÆÅÝ£¬%s",identification);
	if (isOn){
		printf("	¿ª\n");
	}
	else printf("	¹Ø\n");
}
