#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 10

void init();
void pushList();
void popList();
void displayList();
void quiteProgram();

struct node {
	char name[N];
	int num;
	struct node *next;
}*pHead;

char name[N];
int num;
int n = 0;

int main() {
	init();
	while (1) {
		printf("\n选择所需功能:\n");
		printf(" 1:显示存货列表\n 2:入库\n 3:出库\n 0:退出程序\n");
		int k;
		scanf("%d",&k);
		if (k == 0) {
			quiteProgram();
			break;
		}
		if (k == 1) {
			displayList();
			continue;
		}
		if (k == 2) {
			printf("输入入库货物名:\n");
			scanf("%s",name);
			printf("输入入库货物数量:\n");
			scanf("%d",&num);
			pushList();
			continue;
		}
		if (k == 3) {
			printf("输入出库货物名:\n");
			scanf("%s",name);
			printf("输入出库货物数量:\n");
			scanf("%d",&num);
			popList();
			continue;
		}
	}

	return 0;
}
			
void init() {
	pHead = (struct node *)malloc(sizeof(struct node));
	pHead -> next = NULL;
	FILE *file;
	file = fopen("warehouseDate","r");
	int n;
	if (fscanf(file,"%d",&n) != EOF) {
		for (int i = 0; i < n; i++) {
			fscanf(file,"%s",name);
			fscanf(file,"%d",&num);
			pushList();
		}
		fclose(file);
	}
}

void pushList() {
	int find = 0;
	struct node *p;
	p = pHead -> next;
	while (p != NULL) {
		if (strcmp(p -> name,name) == 0) {
			find = 1;
			p -> num += num;
			break;
		}
		p = p -> next;
	}
	if (!find) {
		struct node *q;
		q = (struct node *)malloc(sizeof(struct node));
		strcpy(q -> name,name);
		q -> num = num;
		q -> next = pHead -> next;
		pHead -> next = q;
		n ++;
	}
}

void popList() {
	int find = 0;
	int enough = 0;
	struct node *p, *pPre;
	p = pHead -> next;
	pPre = pHead;
	while (p != NULL) {
		if (strcmp(p -> name,name) == 0) {
			find = 1;
			if (p -> num < num) {
				break;
			}
			p -> num -= num;
			if (p -> num == 0) {
				enough = 2;
			}
			if (p -> num > 0) {
				enough = 1;
			}
			break;
		}
		pPre = p;
		p = p -> next;
	}
	if (!find) {
		printf("未找到名为%s的货物\n",name);
		return;
	}
	if (enough == 0) {
		printf("货物数量不足，取出失败\n");
		return;
	}
	if (enough == 2) {
		pPre -> next = p -> next;
		free(p);
		n --;
	}
}

void displayList() {
	struct node *p;
	p = pHead -> next;
	if (p == NULL) {
		printf("当前库存为空\n");
		return;
	}
	while (p != NULL) {
		printf("名称:%s 数量:%d\n",p -> name, p -> num);
		p = p -> next;
	}
}

void quiteProgram() {
	FILE *file;
	file = fopen("warehouseDate","w");
	fprintf(file,"%d\n",n);
	struct node *p, *q;
	p = pHead -> next;
	q = pHead;
	free(q);
	while (p != NULL) {
		fprintf(file,"%s\n",p -> name);
		fprintf(file,"%d\n",p -> num);
		q = p;
		p = p -> next;
		free(q);
	}
}

