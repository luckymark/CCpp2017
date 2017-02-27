#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
int main(){
	printf("2 3 ");
	double start, finish;
	start = clock();
	for (int j = 2; j <= 1000; j++)
	for (int i = 2; i <= sqrt(j); i++)
	{

		if (j%i == 0)
		{
			break;
		}
		if (i == (int)sqrt(j))
		{
			printf("%d ",j);
		}
	}
	finish = clock();
	printf(" %f seconds\n", (finish - start) / CLOCKS_PER_SEC);
	system("pause");
	return 0;
}
