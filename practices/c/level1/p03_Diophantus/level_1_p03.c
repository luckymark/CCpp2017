#include<stdio.h>
main()
{
	int ageDio;int ageSon;
	int i,j;
	for(i=1;i<=100;i++)
	  for(j=1;j<=100;j++){
		   ageDio=12*i*7*j;
		   ageSon=ageDio/2;
		    if(ageSon==((ageDio-4)-(ageDio*11/28+5))){
		 printf("%d",ageDio);
		}
	}
}
