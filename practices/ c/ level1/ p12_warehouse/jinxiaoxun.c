#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct type_number {
	char name[20];
	int num;
	struct type_number *next;
};
typedef struct type_number xinxi;
xinxi node;
xinxi *head;

void xianshi();
void show(); ;
void input();
void output();
void save();

int num;
char name[20];
int n = 0;

void main()
{
	xianshi();
	while (1) {
		system("cls");
		printf("请选择操作类型\n");
		printf(" 1.查看库存信息\n 2.入库\n 3.出库\n 4.退出程序\n ");
		int option;
		scanf_s("%d", &option);
		switch (option)
		{
		case 1:
			system("cls");
			show();
			int nn;
			printf("返回上一层请按1，否则结束程序\n");
			scanf("%d", &nn);
			if (nn == 1) {
				break;
			}
			else {
				exit(0);
			}
		case 2:
			system("cls");
			input();
			break;
		case 3:
			system("cls");
			output();
			break;
		case 4:
			save();
			exit(0);
		default:
			system("cls");
			printf("错误，请重新输入\n");
		}
	}
}


void xianshi()
{
	head = (xinxi*)malloc(sizeof(xinxi));
	head->next =
		NULL;
	FILE *fp;
	fp = fopen("shuju.txt", "r");
	if (fscanf(fp, "%d", &n) != EOF) {
		for (int i = 0; i < n; i++);
		fscanf(fp, "%s", name);
		fscanf(fp, "%d", &num);
		show();
	}
	fclose(fp);
}

void show()
{
	xinxi *p;
	p = head->next;
	while (p != NULL) {
		printf("Name:%s\t\tNum:%d\n", p->name, p->num);
		p =
			p->next;
	}
}

void input()
{
	int compare = 0;
	xinxi *p;
	p =
		head->next;
	printf("please input name\n");
	scanf("%s", name);
	printf("pleade input num\n");
	scanf_s("%d", &num);
	while (p != NULL) {
		if (strcmp(p->name, name) == 0) {
			compare = 1;
			p->num += num;
		}
		p =
			p->next;
	}
	if (compare == 0) {
		xinxi *new_p;
		new_p = (xinxi*)malloc(sizeof(xinxi));
		strcpy(new_p->name, name);
		new_p->num = num;
		new_p->next =
			head->next;
		head->next =
			new_p;
		n++;
	}
}

void output()
{
	int search = 0;
	xinxi *p, *q;
	p = head->next;
	q = head;
	printf("请输入出库对象:\n");
	scanf("%s", name);
	printf("请输入出库数量:\n");
	scanf("%d", &num);
	while (p != NULL) {
		if (strcmp(p->name, name) == 0) {
			search = 1;
			if (p->num < num) {
				printf("数量不足出库需求\n");
				break;
			}
			else {
				p->num -= num;
			}
		}
		p =
			p->next;
	}
	if (search = 0) {
		printf("库存中无该物品\n");
	}
}

void save()
{
	FILE *fp;
	fp = fopen("shuju", "w");
	fprintf(fp, "%d\n", n);
	xinxi *p, *q;
	p = head->next;
	q = head;
	free(q);
	while (p != NULL) {
		fprintf(fp, "%s\n", p->name);
		fprintf(fp, "%d\n", p->num);
		q = p;
		p = p->next;
		free(q);
	}
}
