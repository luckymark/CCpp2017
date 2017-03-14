#include<stdio.h>
#include<string.h>

void decrypt();
void encrypt();
char word[1000];
char word1[1000];
int len;
int main()
{
	int choice;
	printf("decrypt :0 encrypt :1\n");
	scanf("%d",&choice);
	if(choice==0){
		decrypt();
	}else{
		encrypt();
	}
	return 0;
}
void decrypt()
{

	scanf("%s",word);
	len=strlen(word);
	for(int i=0;i<len;i++){
		word1[i]=word[i]+1;
	}
	printf("%s",word1);
}
void encrypt(){
	scanf("%s",word1);	
	len=strlen(word1);
	for(int i=0;i<len;i++){
		word[i]=word1[i]-1;
	}
	printf("%s",word);
}
