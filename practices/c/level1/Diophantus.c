#include<stdio.h>
int main()
{
	
	for(int age=28;age<100;age+=28)
	{
		if(age/4+age/7+age/2+5+4==age)
		{
			printf("儿子死时丢番图%d岁",age-4);
		}
	}
	
	return 0;
}
