#include <cstdio>
#include "Fan.h"

Fan::Fan(char _identification[]){
	isOn=0;
	strcpy(identification,_identification);
}

void Fan::show(){
	printf("���ȣ�%s",identification);
	if (isOn){
		printf("	��\n");
	}
	else printf("	��\n");
}
