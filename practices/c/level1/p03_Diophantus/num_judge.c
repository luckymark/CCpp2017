#include<stdio.h>

int main(void)
{
	int i;
	for(i=10;i<=120;i++){
		
		if( i%6 == 0 && i%12 == 0 && i%7 == 0){
			
			printf("%d",i);
		
		}
	
	}
	
}
