#include<stdio.h>
int main()
{
	int life,tn,qn,ds,son;
	printf("age may be£º");
    for(life=1;life++;life<=100)
    {
    	tn=life/6;
    	qn=life/12;
    	ds=life/7;
    	son=life/2;
    	
		if(life==tn+qn+ds+5+son+4&&life%84==0)
    	{
    		printf("%d",life);
		}
	}
}
