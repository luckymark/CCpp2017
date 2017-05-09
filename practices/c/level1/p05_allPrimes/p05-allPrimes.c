#include <stdio.h>
#include <time.h>
int main(void)
{
	int num=1000;
	int i,j,div;
	int x,y;
	
	x=clock();
	for(i=2;i<=num;i++)
	{
		for(div=2,j=1;(div*div)<i;div++)
		{
			if(i%div==0)
				break;
		}
		if((div*div)>i)
			printf("%5d",i);
	}
	y=clock();
	printf("总的计算时间为：%d",y-x);
	
	return 0;
 } 
