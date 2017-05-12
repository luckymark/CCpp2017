#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
bool check(int n);
int main(void)
{
	int num;
	printf("please input a number : ");
	scanf_s("%d", &num);
	getchar();
	while (num <= 1)
	{
		printf("error, please input a number is above 1 :");
		scanf_s("%d", &num);
		getchar();
	}
	if (check(num))
	{
		printf("\n%d is a prime", num);
	}
	else{
		printf("\n%d is not a prime", num);
	}
	getchar();
	return 0;
}

bool check(int n)
{
	for (int i = 2; i < n; ++i)
	{
		if (!(n%i))
		{
			return false;
		}
	}
	return true;
}
