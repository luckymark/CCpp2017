/* code:	Narcissus
 * author:	Kyrios0
 * date: 	2017.02.26
 * state: 	finished
 * version: 1.0.0
 */ 

#include "stdafx.h"
#include<stdio.h>
#include<windows.h>
#include<math.h>

int main(int argc, char** argv)
{
	system("chcp 437");
	system("cls");
	int hun, ten, one, sum = 100;//hun = 100
	puts("The following is the number of narcissus in 1000");

	while (sum < 1000)
	{
		one = sum % 10;
		ten = sum / 10 % 10;
		hun = sum / 100;

		if ((int)(pow(double(one), 3.0) + pow(double(ten), 3.0) + pow(double(hun), 3.0)) == sum)
		{
			printf("%d\n", sum);
		}

		sum++;
	}

	system("pause");
	return 0;
}