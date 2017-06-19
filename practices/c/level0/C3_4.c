#include <stdio.h>  

int judgetri(int a,int b,int c)  
    {
    	if ((a*a+b*b== c*c) || (a*a+c*c == b*b) || (b*b+c*c == a*a))
    	{
    		printf("该三角形为直角三角形");
		}
		else
		{
			printf("该三角形非直角三角形");
		} 
    }  
    
    int main()  
    {
    	judgetri(3,4,5);
    	
    	return 0;
    }  
