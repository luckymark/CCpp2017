#include<stdio.h>
int main()
{
	int sum;
	for(int number=1;number<=100;number++)
	{
		if(number%7==0||(number-7)%10==0)
		{
			printf("%d\n",number);
			sum+=number;
		}
	}
	printf("他们的和是%d",sum);
	return 0;
}
