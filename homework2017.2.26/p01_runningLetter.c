#include<stdio.h>
#include<stdlib.h>

int main()
{
	const int LENGTH=80;
	int lenNow=0,goBack=0,step;
	while (1)
	{
		system("cls");
		for (step=1;step<lenNow;step++){			
			printf(" ");
		}		
		printf("R");
		if (goBack){
			lenNow--;
		}		
		else{
			lenNow++;
		}		
		if (lenNow==LENGTH){
			goBack=1;
		}		
		else if (lenNow==0){
			goBack=0;
		}		
		sleep(50);
	}
	return 0;
}
