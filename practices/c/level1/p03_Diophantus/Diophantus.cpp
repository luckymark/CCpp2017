#include <iostream>
#include<stdio.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) 
{

	for(int i=0;i<200;i++)							//¶ª·¬Í¼ÄêÁä
	{
		for(int j=0;j<i;j++)						//¶ª·¬Í¼¶ù×ÓÄêÁä
		{
		if(i==(1.0/6.0*i+1.0/12.0*i+1.0/7.0*i+5+j+4)&&j==(i/2))
		{
				printf("¶ª·¬Í¼µÄÄêÁäÊÇ£º%d\n",i);
		}
		}
	}
	return 0;
}
