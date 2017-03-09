#include <stdio.h>
#include <math.h>

#define MAX_NUM 999

int main(void)
{
	int unit, decade, hundred;
	
	for (int i = 100; i < MAX_NUM; i++){
		hundred = i / 100;
		decade = i / 10 % 10;
		unit = (i % 100 % 10);
		if (pow(hundred, 3) + pow(decade, 3) + pow(unit, 3) == i){
			printf("%d ", i);
		}
	}
	
	return 0;
}
