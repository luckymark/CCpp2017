#include <stdio.h>
#include <time.h>

#define MAX_NUM 1000


int main(void)
{
	int a[MAX_NUM - 1];
	clock_t start, finish; //typedef long clock_t;
	double caculate_time;
	
	for (int k = 2; k < MAX_NUM; k++){
		a[k] = 1;
	}
		
	start = clock();  //start timing
	for (int i = 2; i < MAX_NUM; i++){
		if (a[i] == 0)
			continue;
		else
			printf("%d\t", i);
		for (int j = 2; i * j < MAX_NUM; j++){
			a[i * j] = 0;
		}
	}
	finish = clock(); //finish timing
	caculate_time = (double)(finish - start) / CLOCKS_PER_SEC;
	printf("\n\nUsing %f secends\n", caculate_time);
	
	return 0;
}
