#include<stdio.h>
#include<stdlib.h>

int main()
{
    int x=0,block=1;
	  while(1)
	  {
	      system("cls");
	  	  for(int i=1;i<=x;++i) 
		    {
		        putchar(' ');
	      }
	  	  putchar('R');
	  	  x+=block;
	  	  if(x==0 || x==79) block=-block;
	  }
	  
	  return 0;
}
