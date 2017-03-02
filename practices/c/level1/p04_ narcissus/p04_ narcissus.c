#include <stdio.h>
int main(void)
{
	int a,b,c;
	int num;
	
	for(a=1;a<=9;a++){
		for(b=0;b<=9;b++){
				for(c=0;c<=9;c++){
					num=a*100+b*10+c;
					if(num==(a*a*a+b*b*b+c*c*c)){
						printf("%d\n",num);
					}
				}
			}
	}
	return 0;
}
