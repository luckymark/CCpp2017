#include<stdio.h>
#include<stdbool.h>
#include<time.h>
bool check(int n, int array[]);
int main(void)
{
	double op, ed;
	op = clock();
	int array[10000];
	array[0] = 2;
	array[1] = 0;
	int num = 1;
	for (int i = 3; i <= 1000; ++i)
		if (check(i, array))
		{
			array[num] = i;
			++num;
			array[num] = 0;
		}
	for (int a = 4; a <= 1000; a += 2)
		for (int d = 0; array[d] != 0&&array[d]<=a/2+1; ++d)
		{
			for (int e = 0; array[e] != 0; ++e)
			{
				if (array[e] == a - array[d])
					printf("%d=%d+%d\n", a, array[d], array[e]);
			}
		}
	ed = clock();
	printf("%f", (ed - op) / 1000);
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