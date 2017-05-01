#include<stdio.h>
#include<stdlib.h>
#define LEN sizeof(Node)
struct list {
	int data;
	struct list *next;
};
typedef struct list Node;
int main()
{
	int n=0;
	Node *head, *p, *p_new;
	head =
		p_new = (Node*)malloc(LEN);
	scanf_s("%d", &p_new->data);
	while (p_new->data != 0) {
		p = p_new;
		p_new = (Node*)malloc(LEN);
		scanf_s("%d", &p_new->data);
		p->next =
			p_new;
	}
	p_new->next =
		NULL;
	printf("存储的数据为：\n");
	p = head;
	while (p != NULL) {
		printf("%d\t", p->data);
		p =
			p->next;
	}
	printf("\n反序结果如下：\n");
	Node *pre, *cur, *next;
	cur =
		head;
	pre = NULL;
	while (cur!= NULL) {
		next =
			cur->next;
		cur->next =
			pre;
		pre = cur;
		cur = next;
	}
	head =
		pre;
	p = head;
	while (p->next!= NULL) {
		printf("%d\t", p->data);
		p =
			p->next;
	}
	printf("%d\n", p->data);
	Node*pp = head;
	while (pp != NULL) {
		if (pp->data == 5) {
			n++;
			printf("值为5的节点序号为%d\n", n);
		}
		pp =
			pp->next;
	}
	if (n == 0) {
		return -1;
	}
	system("pause");
}
