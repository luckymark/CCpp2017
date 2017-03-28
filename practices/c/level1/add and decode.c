#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) 
{
	
	printf("add:1£¬decode:2£º");
	int choose;
	scanf("%d",&choose);
	if(choose==1)
	{
		char add[30],*a;
	    a=add;
	    printf("add£º");
	    scanf("%s",add);
	    while(*a!='\0')
	    {
		    *a=*a+'B'-'m';
		    a++;
	    }
	printf("%s",add);
	}
	
	else if(choose==2)
	{
		char decode[30],*b;
	    b=decode;
	    printf("decode£º");
	    scanf("%s",decode);
	    while(*b!='\0')
	    {
		    *b=*b+'m'-'B';
		    b++;
	    }
	printf("%s",decode);
	}
	
	else
	{
		printf("error");
	}
	return 0;
}
