#include<stdio.h>
#include<string.h>
main(){
	char password[1000];
	
	scanf("%s",password);
	for(int i=0;i<strlen(password);i++){
	  password[i]+=5;
	}
	printf("%s\n",password);

	for(int i=0;i<strlen(password);i++){
		password[i]-=5;
	}
	printf("%s\n",password);
}
