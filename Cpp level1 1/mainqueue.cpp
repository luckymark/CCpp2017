// Queue.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "queue.h"
#include "iostream"
#include "stdio.h"
#define _CRT_SECURE_NO_WARNINGS
using namespace std;




int main()
{
	int number;
	int flag = 0;
	std::cout << "input the size of the queue" <<std::endl;
	scanf("%d", &number);
	Queue<int>queue(number);
	printf("make a choice 'a number'(append a number) or 'b'(pop)\n");
	while (1)
	{
		if (flag == 0)
		{
			queue.show();
			printf("\n");
		}
		flag = 0;
		
		char ch = getchar();
		switch (ch)
		{
		case 'a':
			queue.append();
			break;
		case 'b':
			queue.pop();
			break;
		default:
			{
			flag = 1;
			break;
			}
		}
	}
   
}


