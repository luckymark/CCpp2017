#include<stdio.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv)
{
	for(int x=100;x<1000;x++)
	{
		if(x==(x/100)*(x/100)*(x/100)+((x-x/100*100)/10)*((x-x/100*100)/10)*((x-x/100*100)/10)+(x-x/10*10)*(x-x/10*10)*(x-x/10*10))
		{
			printf("%d是水仙花数。\n",x);
		}
	}
	return 0;
}
