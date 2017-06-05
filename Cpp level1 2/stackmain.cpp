// stack.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "stack.h"
#include <iostream>
#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;




int main()
{
	int number;
	int flag = 0;
	std::cout << "input the size of the stack" <<std::endl;
	scanf("%d", &number);
	Stack<int>stack(number);
	printf("make a choice 'a number'(push a number) or 'b'(pop)\n");
	while (1)
	{
		if (flag == 0)
		{
			stack.show();
			printf("\n");
		}
		flag = 0;
		
		char ch = getchar();
		switch (ch)
		{
		case 'a':
			stack.push();
			break;
		case 'b':
			stack.pop();
			break;
		default:
			{
			flag = 1;
			break;
			}
		}
	}
   
}


