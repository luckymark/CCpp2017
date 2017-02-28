#include<stdio.h>
main()
{ 	
	int a;
	scanf("%d",&a);
	if(a==1){
		printf("非素数");}
	for(int i=2;i<=a-1;i++){
		if(a%i==0){
			printf("非素数");
			break;}
		else
			printf("素数"); 	
	}
}
