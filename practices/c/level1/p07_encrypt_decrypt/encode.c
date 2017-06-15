#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct ch
{
	char st;
	int r;
	struct ch* link;
};
void encode(struct ch* p,int number,int s);
void decode(struct ch* p,int number,int s);
int main()
{
	int number,s,k;
	struct ch* str;
	struct ch* strlink;
	str=(struct ch*)malloc(sizeof(struct ch));
	puts("encode or decode?");
	puts("1.encode");
	puts("2.decode");
	scanf("%d",&k);
	printf("numberkey:");
	scanf("%d",&number);
	printf("stringkey");
	scanf("%d",&s);
	while(k!=1&&k!=2)
	{
		puts("Please enter right number to chose mode");
		scanf("%d",&k);
	}
	getchar();
	strlink=str;
	while(str->st=getchar()) 
	{
		if(str->st=='\n'||str->st=='\0')
		{
			free(str);
			str=strlink;
			break;
		} 
		str->link=(struct ch*)malloc(sizeof(struct ch));
		if(k==1)encode(str,number,s);
		else decode(str,number,s);
		str=str->link; 
	}
	return 0; 
}
void encode(struct ch* p,int number,int s)
{

	if(p->st>=48&&p->st<=57)
	{
		p->r=1; 
		number=number%10;
		int b=(p->st)-number-'0';
		if(b>=0&&b<=9)putchar(b+'0');
		else if(b<0)putchar(abs(b)+'0');
		else if(b>10)putchar(b%10+'0');
	}
	else if((p->st)>=32)
	{
		p->r=2;
		int f=(p->st)-s;
		if(f<32)putchar(126-(32-f));
		else if(f>=32&&f<=126)putchar(f);
		else if(f>126)putchar(32+(f-126));
	}
	
}
void decode(struct ch*p,int number,int s)
{
	if(p->r==1)
	{
		number=number%10;
		int c=(p->st)-'0'+number;
		if(c>9)putchar((c-9)+'0');
		else if(c<0)putchar(abs(c)+'0');
		else putchar(c+'0');
	}
	else if(p->r==2)
	{
		int d=(p->st)+s;
		if(s>126)putchar((s-126)+32);
		else if(s<32)putchar(126-(32-s));
		else putchar(s); 
	}
}
