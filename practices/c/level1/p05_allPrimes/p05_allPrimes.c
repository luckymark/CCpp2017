#include <stdio.h>
#include <time.h>
#include <math.h>
#define RAN 1000
int main(void)
{
	clock_t t1,t2;
	
	t1=clock();
		
	int num,temp;
	int i;
	
	for (num=2;num<RAN+1;num++){
		temp=sqrt(num);
		for (i=2;i<temp+1;i++)
		{
			if (num%i==0)break;
		}
		if (i==temp+1){
		    printf("%5d",num);
		} 
	}
	t2=clock();
	printf("����ʱ��һ������%d����",t2-t1);
	
 } 
