#include<stdio.h>
int main(void) 
{
	for (int i=1;i<100;i++){
		if (i%3==0){ 
		   if(i%5!=0){ 
		     printf("%5d",i);
		    }
		} 
	}
}
