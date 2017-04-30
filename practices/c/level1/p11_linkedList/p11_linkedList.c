#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define LEN 10
typedef struct Node{
	int value;
	struct Node * next;
}Node;
void opposite(Node **head,Node * first, Node * second, Node * third);
void FullList(Node * head);
int searchkey(Node **head,int key);
void research(Node * head, int key,int id);
int main(void)
{
	Node * current;
	Node * prev;
	Node * head = NULL;
	srand((unsigned)time(NULL));
	Node * first, *second, *third;
	int size;

	for (int i = 0; i < LEN; i++) {		//创建长度为LEN的链表
		if (head == NULL) {				//创建头节点
			head = (Node *)malloc(sizeof(Node));    //分配内存空间
			prev = head;     
		}
		else {
			current = (Node *)malloc(sizeof(Node));	//分配一个Node类型内存空间
			prev->next = current;
			current->next = NULL;
			prev = current;
		}
	}


	FullList(head);    //用1-20的随机数填满链表

	current = head; //输出正序链表
	for (int i = 0; i < LEN; i++) {
		printf("%d  ", current->value);
		current = current->next;
	}
	printf("\n");


	opposite(&head, head, head, head);  //将列表所有节点反序
	current = head;
	for (int i = 0; i < LEN; i++) {
		printf("%d  ", current->value);
		current = current->next;
	}
	printf("\n");

	size=searchkey(&head, 5);   //在链表中查找值为5的结点,如果找到则返回该节点的序号，否则输出－1；
	
	research(head, 5, size);    //再次查找
}
void opposite(Node ** head,Node * first,Node * second,Node * third) //在该链表中查找第一个值为5的节点，
{
	if (first == *head) {
		second = first->next;
		third = second->next;
		first->next = NULL;
		second->next = first;
		first = third->next;
		opposite(head, second, third, first);
	}
	else if (third == NULL) {
		second->next = first;
		*head = second;
		return ;
	}
	else {
		second->next = first;
		first = third->next;
		opposite(head, second, third, first);
	}
}

void FullList(Node * head)
{
	Node * current = head;
	while (current != NULL) {
		current->value = rand() % 20 + 1;     //生成1-20的随机数
		current = current->next;
	}
}

int searchkey(Node **head, int key)
{
	Node * current = *head;
	int flag = 0;
	for (int i = 0; current != NULL;++i) {
		if (current->value == key) {
			printf("%d\n", i + 1);
			*head = current->next;
			return i + 1;
		}
		else {
			current = current->next;
		}
	}
		printf("-1\n");
		return 0;
}
void research(Node * head, int key, int id)
{	
	Node * current = head;
	for (int i = 0; current != NULL; ++i) {
		if (current->value == key) {
			printf("%d\n", i + 1 + id);
			return;
		}
		else {
			current = current->next;
		}
	}
	printf("-1\n");
}