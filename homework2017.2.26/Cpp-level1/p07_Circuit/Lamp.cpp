#include <cstdio>
#include "Lamp.h"

Lamp::Lamp(char _identification[]){
	isOn=0;
	strcpy(identification,_identification);
}

void Lamp::show(){
	printf("���ݣ�%s",identification);
	if (isOn){
		printf("	��\n");
	}
	else printf("	��\n");
}
