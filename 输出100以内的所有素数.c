
#include <stdio.h>
#include <stdlib.h> 
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
        
        int i,m;
        for(i=2;i<=100;i++)
        {
        m=mx(i);
        if(m!=-1)
        printf("%d\t",i);
        }
      
	system("pause");
	return 0;
}
