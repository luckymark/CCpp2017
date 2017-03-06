#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <conio.h>
typedef struct Node{
	int data;
	struct Node *pNext;
}NODE, *PNODE;

PNODE creat_list(void);
void traverse_list(PNODE);
PNODE inverse_list(PNODE);
void reserch_list(PNODE);

int main(){
	int val = 0;
	PNODE pHead = NULL;
	pHead = creat_list();
	pHead = inverse_list(pHead);
	traverse_list(pHead);
	reserch_list(pHead);
	return 0;
}

PNODE creat_list(void){
	PNODE pHead = (PNODE)malloc(sizeof(NODE));
	if(pHead == NULL){
		printf("初始化失败!\n");
		exit(-1); 
	}
	pHead->data = 0;
	pHead->pNext = NULL;
	PNODE pTail = pHead;
	int val;
	int n;
	printf("请输入要创建的链表的节点数:");
	scanf("%d", &n);
	
	for(int i=0; i<n; i++){
		PNODE pNew = (PNODE) malloc (sizeof(NODE));
		if(pNew == NULL){
			printf("初始化失败!\n");
			exit(-1); 
		}
		printf("请输入第%d个节点的数值:", i+1);
		scanf("%d", &val);
		pNew->data = val;
		pTail->pNext = pNew;
		pNew->pNext=NULL;
		pTail = pNew;
	}
	return pHead;
}

void traverse_list(PNODE pHead){
	PNODE p = pHead->pNext;
	while(p != NULL){
		printf("%d ", p->data);
		p = p->pNext;
	}
	printf("\n");
}

PNODE inverse_list(PNODE pHead){
	int num = 0;
	PNODE pHead_new = (PNODE)malloc(sizeof(NODE));
	PNODE pTail = pHead->pNext;
	while(pTail->pNext != NULL){
		pTail = pTail->pNext;
		num++;
	}
	pHead_new->pNext = pTail;
	PNODE p = pHead->pNext;
	for(int i=0; i<num; i++){
		while(p->pNext!=pTail){
			p = p->pNext;
		}
		pTail->pNext = p;
		pTail = p;
		p = pHead->pNext;
	}
	pTail->pNext = NULL;
	free(pHead);
	pHead = NULL;
	return pHead_new;
}

void reserch_list(PNODE pHead){
	printf("PLease input the num you want to research:\n");
	int val;
	scanf("%d", &val);
	char ch;
	int num = 1;
	PNODE p = pHead->pNext;
	while(p != NULL){
		if(p->data == val){
			printf("%d\n", num);
			printf("If you want to find the next?\nY OR N\n");
			switch(ch = getch()){
				case 'y':
				case 'Y':
					break;
				case 'N':
				case 'n':
					return;
				default :
					printf("INPUT ERROR!!\n");//
					break;
			}		
		}
		p = p->pNext;
		num++;
	}
	printf("-1");
	return;
}
