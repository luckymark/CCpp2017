#include<stdio.h>//?ÓÐÎÊÌâ 

void decrypt(); 
void encrypt();

int main()
{
	int choice;
	printf("Would you want to decrypt(1) or encrypt(2)?");
	scanf("%d",&choice);
	if(choice==1){
		decrypt();
	}else{
		encrypt();
	}
	return 0;
}


void encrypt()
{
	int n,j=0;
	char ch[80],tran[80];
	printf("input cipher code:");
	gets(ch);
	printf("\ncopher code :%s",ch);
	for(j;ch[j]!='\0'; j++){
		if((ch[j]>='A')&&(ch[j]<='Z')){
			tran[j]=155-ch[j]; 
		}else if((ch[j]>='a')&&(ch[j]<='z')){
			tran[j]=219-ch[j];	
		}else {
			tran[j]=ch[j];		
		}
		n=j;
		printf("\noriginal text:");
		for(j=0;j<n;j++){
			putchar(tran[j]);
		}
	}
}

void decrypt()
{
	int n,j=0;
	char ch[80],tran[80];
	printf("input original code:");
	gets(ch);
	printf("\noriginal code :%s",ch);
	for(j;ch[j]!='\0'; j++){
		if((ch[j]>='A')&&(ch[j]<='Z')){
			tran[j]=155-ch[j]; 
		}else if((ch[j]>='a')&&(ch[j]<='z')){
			tran[j]=219-ch[j];	
		}else {
			tran[n]=ch[j];		
		}
		n=j;
		printf("\ncipher text:");
		for(j=0;j<n;j++){
			putchar(tran[j]);
		}
	}
	
}
 
