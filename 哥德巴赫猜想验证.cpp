#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */


#include <stdio.h>
#include <stdlib.h> 
#include <windows.h>
int mx(int c)
	{
     int i,m,t;
       t=0;  
    for(i=2;i<=c/2;i++)
    {
         
    	m=c%i;
    	if(m==0)
    	{
    	return -1;
		}
	}
		
		
			return c;
		
	}

int main()
{
	int i,j,m,a,b,c,k,s=0;
	for(i=4;i<=100;i+=2)
	{
    k=0;
	for(j=2;j<=i/2;j++)
	{
	a=mx(j);
    if(a!=j)
    { 
     continue;
     } 
    else
    {
	b=i-a; 
	c=mx(b);
    }
	if(c==b)
    {
    k=1;
	printf("%d =%d + %d\t",i,a,b);
     }
    }
    s=s+k;
    }
    if(s==(100-4)/2+1)
    {
    	printf("\n\n");
    printf("哥德巴赫猜想正确");
    Sleep(2000);
    }
    system("pause");
return 0;
}
