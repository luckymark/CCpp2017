#include<stdio.h>
#include<time.h>
#include<stdbool.h>
bool check(int n, int array[]);
int main(void) 
{
	double op = clock();
	int array[10000];
	array[0] = 2;
	array[1] = 0;
	int num = 1;
	for(int i=3;i<=10000;++i)
		if (check(i, array))
		{
			array[num] = i;
			++num;
			array[num] = 0;
		}
	for (int a = 0; a < num; ++a)
		printf("%d\n", array[a]);
	double ed = clock();
	printf("%lf",(ed - op)/1000);
	getchar();
	return 0;
}

bool check(int n, int array[])
{
	
	for (int i = 0; array[i] != 0; ++i)
		if (!(n%array[i]))
			return false;
	return true;
}