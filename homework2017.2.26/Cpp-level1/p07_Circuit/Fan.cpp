#include <cstdio>
#include "Fan.h"

Fan::Fan(char _identification[]){
	isOn=0;
	strcpy(identification,_identification);
}

void Fan::show(){
	printf("·çÉÈ£¬%s",identification);
	if (isOn){
		printf("	¿ª\n");
	}
	else printf("	¹Ø\n");
}
