#include <stdio.h>
#include <stdlib.h>

void initList();
void pushList(int x);
void findList(int x);
void inputValue();
void reverseList();
void displayList();

struct node {
	int value;
	struct node *next;
}*pHead,*pNow;

int main() {
	initList();
	inputValue();
	
	while (1) {
		printf("请输入需要进行的操作编号: \n");
		printf(" 1:遍历该链表\n 2:将链表节点反序\n 3:查找链表元素\n 0:退出\n");
		int k;
		scanf("%d",&k);
		if (k == 0) break;
		if (k == 1) {
			displayList();
			continue;
		}
		if (k == 2) {
			reverseList();
			continue;
		}
		if (k == 3) {
			printf("输入要查找的元素:");
			int x;
			scanf("%d",&x);
			findList(x);
			continue;
		}
	}
	return 0;
}

void initList() {
	pHead = (struct node *)malloc(sizeof(struct node));
	pHead -> next = NULL;
	pNow = (struct node *)malloc(sizeof(struct node));
	pNow -> next = NULL;
}

void pushList(int x) {
	struct node *p;
	p = (struct node *)malloc(sizeof(struct node));
	p -> value = x;
	p -> next = NULL;
	if (pHead -> next == NULL) {
		pHead -> next = p;
		pNow = p;
		return;
	}
	pNow -> next = p;
	pNow = p;
}

void findList(int x) {
	int k = 1;
	int find = 0;
	struct node *p;
	p = pHead -> next;
	while (p != NULL) {
		if (p -> value == x) {
			find = 1;
			printf("%d ",k);
		}
		p = p -> next;
		k++;
	}
	if (!find) {
		printf("-1");
	}
	printf("\n");
}

void displayList() {
	struct node *p;
	p = pHead -> next;
	while (p != NULL) {
		printf("%d ",p -> value);
		p = p -> next;
	}
	printf("\n");
}

void inputValue() {
	printf("输入链表元素个数:\n");
	int n;
	scanf("%d",&n);
	printf("请输入元素:\n");
	int x;
	for (int i = 0; i < n; i++) {
		scanf("%d",&x);
		pushList(x);
	}
}

void reverseList() {
	struct node *pPrev, *pNext, *p;
	p = pHead -> next;
	pNow = p;
	pPrev = NULL;
	while (p != NULL) {
		pNext = p -> next;
		p -> next = pPrev;
		pPrev = p;
		p = pNext;
	}
	pHead -> next = pPrev;
}
