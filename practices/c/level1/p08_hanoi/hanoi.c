#include<stdio.h>

void Hanoi(int n,char a,char b,char c,unsigned long int * i);

int main(void)
{
	char aP='A',bP='B',cP='C';
	unsigned long int sum=0;
	int num;
	
	printf("Please enter the number of tower:\n");
	scanf("%d",&num);
	if(num<=0)
	{
		printf("error\n");
		system("pause");
		
		return 0;
	}
	Hanoi(num,aP,bP,cP,&sum);
	printf("The sum is %u\n",sum);
	
	return 0;
}
void Hanoi(int n,char a,char b,char c,unsigned long int * i)
{
	if(n==1)
	{
		printf("%c to %c\n",a,c);
		*i=*i+1;
		return;
	}
	else 
	{
		Hanoi(n-1,a,c,b,i);
		Hanoi(1,a,b,c,i);
		Hanoi(n-1,b,a,c,i);
	}

}
