#include <stdio.h>
#include <math.h>
#include <time.h>

int main()
{
	int i,j; 
	long begin,end;
	
	begin = time(NULL);
	printf("\nThe primes are:\n%-7d",2);
	for (i=3; i<1000; i=i+2){
		for (j=3; j<=(int)sqrt(i); j=j+2)
			if (i%j == 0) break;
		if (j > (int)sqrt(i) )  printf("%-7d",i);
	}
	end = time(NULL);
	printf("\nThe begin time is: %d.",begin);
	printf("\nThe end time is: %d.",end);
	printf("\nThe total time is: %lf seconds.",(end-begin)/1000000.0);
	return 0;
}
