#include<stdio.h>
#define rate 1/6.0+1/12.0+1/7.0

void Diophantus(void);

int main(void)
{
	Diophantus();
	system("pause");
	
	return 0;
} 
void Diophantus(void)
{
	int age_father=6;
	
	while(age_father<=200)
	{
		if(age_father==(int)age_father*(rate+0.5)+9)
		{
			printf("%d\n",age_father-4);
		}
		age_father+=2;
	}
	
}
