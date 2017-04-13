# include<stdio.h>
# include<stdlib.h>

struct LinkNode {
	int data;
	struct LinkNode *pNext;
};
typedef struct LinkNode node;

node*init(node*phead)
{
	phead = NULL;
}

node*addback(node*phead, int newdata)
{
	node*pnew = (node*)malloc(sizeof(node));
	pnew->data = newdata;
	pnew->pNext = NULL;
	if (phead == NULL) {
		phead = pnew;
	}
	else {
		node*ptemp = phead;
		
		while (ptemp->pNext != NULL)
		{
			ptemp = ptemp->pNext;
		}
		ptemp->pNext = pnew;
	}
	return phead;
}

void showall(node *phead)
{
	if (phead == NULL) {
		return;
	}
	else {
		printf("%d\t%p\t%p\n", phead->data, phead, phead->pNext);
		showall(phead->pNext);
	}
}

node* revit(node*phead)
{
	if (phead == NULL || phead->pNext == NULL) {
		return;
	}
	else {
		node*pre = NULL;
		node*pcur = NULL;
		node*pnext = NULL;

		pre = phead;		//pre指向第1个节点
		pcur = phead->pNext;		//pcur指向第二个节点
		while (pcur!=NULL)
		{
			pnext = pcur->pNext;		//备份下一个节点
			pcur->pNext = pre;			//反转

										//前进
			pre = pcur;
			pcur = pnext;
			//pnext = pnext->pNext;			在前面已经提到
		}
		phead->pNext = NULL;
		phead = pre;
	}
	return phead;
}
int finddata(node*phead, int finddata)
{
	int findnum=0;
	node*ptemp = phead;
	while (ptemp != NULL)
	{
		findnum++;
		if (ptemp->data == finddata) {
			return findnum;
		}
		ptemp = ptemp->pNext;
		
	}
	return -1;
}

int findsecdata(node*phead, int finddata)
{
	int findnum = 0;
	int cnt = 0;
	node*ptemp = phead;
	while (ptemp != NULL)
	{
		findnum++;
		if (ptemp->data == finddata) {
			cnt++;
			if(cnt==2){ 
				return findnum;
			}
			ptemp = ptemp->pNext;
			continue;		
		}
		ptemp = ptemp->pNext;
		
	}
	return -1;
}

int main()
{
	int number = 0;
	printf("input the number of the data\n");
	scanf("%d", &number);
	node*phead=NULL;
	init(phead);

	int newdata = 0;
	for (int i = 0; i < number; i++) {
		printf("please input the %dth number:", i);
		scanf("%d", &newdata);
		phead = addback(phead, newdata);
	}

	showall(phead);

	phead = revit(phead);
	printf("反转之后输出：\n");

	showall(phead);
	printf("\nplease input the data that you want to found:");
	int findnum = 0;
	scanf("%d", &findnum);
	
	printf("\n第一个数据所在的节点是：%d\n", finddata(phead, findnum));
	
	printf("\n第二个数据所在的节点是：%d\n", findsecdata(phead, findnum));
	system("pause");
	return 0;
}
