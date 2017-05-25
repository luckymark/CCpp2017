#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<windows.h>

void gotoxy(int x, int y);
void read();
void boundry();
void show();
void remote();
void over();
void add();

struct slist{
	char name[20];
    int value;
	struct slist*next;
};
struct slist*head = NULL,*tail=NULL;
struct slist*prev = NULL, *cur=NULL;
FILE *fp;


int main()
{
	char k;
	read();
	while (1) {
		boundry();
		k = getchar();
		switch (k) {
			case '2': {
				show();
				break;
			}
			case '3': {
				add();
				break;
			}
			case '4': {
				remote();
				break;
			}
			case '5': {
				over();
				goto end;
			}
		}
	}
	end:return 0;
}

void boundry()
{
	system("cls");
	gotoxy(20, 8);
	printf("按数字键选择菜单功能");
	gotoxy(20, 10);
	printf("2.显示存货列表");
	gotoxy(20, 12);
	printf("3.入库");
	gotoxy(20, 14);
	printf("4.出库");
	gotoxy(20, 16);
	printf("5.退出程序");
	gotoxy(20, 18);
}
void gotoxy(int x, int y)//指定显示位置
{
	COORD c;
	c.X = x;
	c.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

void read() {
	FILE *fp = NULL;
	fp = fopen("warehouse.txt", "rb");
	if (fp == NULL) {
		printf("can't  open the file.\n");
		exit(1);
	}
	rewind(fp);
	fseek(fp, 0L, SEEK_END);
	if (ftell(fp) == 0)
	{
		return;
	}
	else{
		fseek(fp, 0, SEEK_SET); 
		cur = (struct slist*)malloc(sizeof(struct slist));
		head = cur;
		cur->next = NULL;
		do{
			fscanf(fp, "%s%d ", cur->name, &cur->value);
			prev = cur;
			cur = (struct slist*)malloc(sizeof(struct slist));
			prev->next = cur;
		} while (!feof(fp));
		free(cur);
		prev->next = NULL;
	}
	fclose(fp);
}

void show()
{
	system("cls");
	if (head == NULL) {
		printf("There's no products.\n");
	}
	else {
		cur = head;
		while (cur != NULL) {
			printf("%20s%20d", cur->name, cur->value);
			printf("\n");
			cur = cur->next;
		}
	}
	printf("Press any key to return.\n\n");
	system("pause");
}

void add()
{
	long int i;
	char a[10];
	char *find=NULL;
	system("cls");
	printf("Please input the product's name:");
	scanf("%s", &a);
	printf("Please input the number that you want to add:");
	scanf("%d", &i);
	if (head != NULL) {
		cur = head;
		while (cur != NULL) {
			if (find = strstr(cur->name, a)) {
				cur->value = cur->value + i;
				goto next;
			}
			else {
				cur = cur->next;
			}
		}
	}
	if(find == NULL){
		cur = (struct slist*)malloc(sizeof(struct slist));
		if (head == NULL) {
			head = cur;
		}
		else {
			prev->next = cur;
		}
		strcpy(cur->name,a);
		cur->value = i;
	}
	next:;
	printf("If you want to input another product,please input 1 ,otherwise,any key to return:");
	getchar();
	if (getchar() == '1') {
		prev = cur;
		prev->next = NULL;
		add();
	}
	else {
		prev = cur;
		prev->next = NULL;
	}
}

void remote()
{
	system("cls");
	char D[20];
	char *find = NULL;
	int k = 0;
	printf("Please input the product that you want remote. ");
	scanf("%s", &D);
	cur = head;
	while (cur != NULL) {
		if (find=strstr(cur->name,D)) {
			printf("The number of the %s is %d\n", cur->name, cur->value);
			break;
		}
		else {
			cur = cur->next;
		}
	}
	if (find) {
		printf("Please input the number that you want remote ( don't be more than %d):", cur->value);
		scanf("%d", &k);
		if (k < cur->value) {
			cur->value -= k;
		}
		else {
			prev->next = cur->next;
			free(cur);
		}
	}
	else {
		printf("There is no datas of what you want remote.\n");
	}
	printf("Finished!");
	system("pause");
}

void over()
{
	FILE *fp = NULL;
	fp = fopen("warehouse.txt", "w");
	if (fp == NULL) {
		printf("can't  open the file.\n");
		exit(1);
	}
	rewind(fp);
	cur = head;
	while (cur != NULL) {
		fprintf(fp, "%s %d ", cur->name, cur->value);
		prev = cur;
		cur = prev->next;
		free(prev);
	}
	fclose(fp);
}