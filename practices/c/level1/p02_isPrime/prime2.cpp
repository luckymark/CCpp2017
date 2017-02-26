#include <stdio.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

	int main(int argc, char** argv)
	{
		int x=0;
		printf("请输入一个正整数：\n");
		scanf("%d",&x);
		
		for(int i=2; i<x; i++)
		{
			if(x%i==0)
			{
				printf("这个数不是素数。\n");
				return 0;
			}
		}
		
		printf("这个数是素数。\n");
		return 0;	
	}
