#include <stdio.h>
#include <stdlib.h> 
#include <string.h>

struct Product
{
	char type[20];
	int quantity;
};
struct Product product[30];
int count=0;

void menu();
void show();
void add();
void remove_();
int exit_();

int main()
{
	for(int i=0;i<30;i++)
	{
		product[i].quantity=0;
	}
	freopen("product.txt","r",stdin);
	for(int i=0;i<30;i++)
	{
	    scanf("%s %d",product[i].type,&product[i].quantity);
		if(product[i].quantity!=0)
		{
			count++;
		}
	}
	freopen("con","r",stdin);
	menu();
	return 0;
}

void menu()
{
	int choice;
	printf("1:显示库存\n2:入库\n3:出库\n4:退出程序\n");
	printf("input your choice:");
	scanf("%d",&choice);
	printf("\n");
	switch (choice)
	{
		case 1:show();
		menu();
		break;
		case 2:add();
		menu();
		break;
		case 3:remove_();
		menu();
		break;
		case 4:exit_();
		break;
	}
}
void show()
{
	if(count==0) 
	{
	    printf("the warehouse is empty!");
    }
	for(int i=0;i<30;i++)
	{
		if(product[i].quantity!=0) 
		{
			printf("%s %d\n",product[i].type,product[i].quantity);
		}
	}
}
void add()
{
	int n=1;
	while(n!=0)
	{
		printf("please input type：\n");
		scanf("%s",product[count].type);
		printf("please input quantity：\n");
		scanf("%d",&product[count].quantity);
		count++;
		printf("1：继续 0：停止\n");
		scanf("%d",&n);
	}
}
void remove_()
{
	char type0[20];
	printf("input the type :");
	scanf("%s",type0);
	printf("\n");
	for(int i=0;i<30;i++)
	{
		if(strcmp(type0,product[i].type)==0)
		{
			for(int j=0;j<20;j++)
			{
				product[i].type[j]=0;
			}
			product[i].quantity=0;
			printf("%s ",type0);
			printf("delete succeed!\n");
			goto end;
		}
	}
	printf("no type is ");
	printf("%s\n",type0);
	end:;
}
int exit_()
{
	freopen("warehouse.txt","w",stdout);
	show();
	return 0;
}
