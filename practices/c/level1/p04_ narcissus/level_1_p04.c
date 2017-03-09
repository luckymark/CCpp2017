#include<stdio.h>

main()
{
	for(int a=1;a<=9;a++)
		for(int b=0;b<=9;b++)
			for(int c=0;c<=9;c++){
					if(100*a+10*b+c==a*a*a+b*b*b+c*c*c){
						printf("%d\n",100*a+10*b+c);
					}
			}
}
