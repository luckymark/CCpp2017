#include<stdio.h>
#include<stdlib.h>

int main()
{
	const int lenth=80;
	int len_now=0,goBack=0,step;
	while (1)
	{
		system("cls");
		for (step=1;step<len_now;step++)
			printf(" ");
		printf("R");
		if (goBack) len_now--;
		else len_now++;
		if (len_now==lenth)	goBack=1;
		else if (len_now==0)	goBack=0;
		sleep(50);
	}
	return 0;
}
