#include<stdio.h>

int main(){
 	int age=1;
 	while (age++){
 		if (age%6==0&&age%12==0&&age%7==0&&(age/2-age/6-age/12-age/7)==9)	{
			break;
		}	
	}
	printf("%d\n",age-4);
	return 0;
}
