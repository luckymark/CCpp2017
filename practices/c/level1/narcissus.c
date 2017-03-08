#include<stdio.h>
int main()
{
	for(int number=100;number<=999;number++){
		int a=number%10;
		int b=(number/10)%10;
		int c=number/100;
		if(a*a*a+b*b*b+c*c*c==100*c+10*b+a){
			printf("%d\n",100*c+10*b+a);
		}
	}
	return 0;
}
