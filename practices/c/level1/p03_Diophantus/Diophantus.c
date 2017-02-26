#include <stdio.h>

#define MAX_AGE 130

int main(void)
{
	int age;
	
	for (int i = 1; i <= MAX_AGE; i++){
		if ((i / 6) + (i / 12) + (i / 7) + 5 + (i / 2) + 4 == i
			&& i % 6 == 0 && i % 12 == 0 && i % 7 == 0 && i % 2 == 0){
			age = i;
			break;
		}
	}
	printf("%d\n", age - 4);
	
	return 0;	
}
