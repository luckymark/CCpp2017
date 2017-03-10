#include<stdio.h>
int main()
{
	int i,j;
	char ch[80],tran[80];
	printf("input cipher code:");
	gets(ch);
	printf("\ncopher code :%s",ch);
	j=0;
	if(ch[j];ch[j]!='\0'; j++){
		if((ch[j]>='A')&&(ch[j]<='Z')){
			tran[j]=155-ch[j]; 
		}else if((ch[j]>='a')&&(ch[j]<='z')){
			tran[j]=219-ch[j];	
		}else {
			tran[i]=ch[j];		
		}
	}
	n=j;
	printf("\noriginal text:");
	for(j=0;j<n;j++){
		putchar(tran[j])
	}
	return 0;
}
