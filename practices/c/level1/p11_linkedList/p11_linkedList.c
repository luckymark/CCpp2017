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

	for (int i = 0; i < LEN; i++) {		//��������ΪLEN������
		if (head == NULL) {				//����ͷ�ڵ�
			head = (Node *)malloc(sizeof(Node));    //�����ڴ�ռ�
			prev = head;     
		}
		else {
			current = (Node *)malloc(sizeof(Node));	//����һ��Node�����ڴ�ռ�
			prev->next = current;
			current->next = NULL;
			prev = current;
		}
	}


	FullList(head);    //��1-20���������������

	current = head; //�����������
	for (int i = 0; i < LEN; i++) {
		printf("%d  ", current->value);
		current = current->next;
	}
	printf("\n");


	opposite(&head, head, head, head);  //���б����нڵ㷴��
	current = head;
	for (int i = 0; i < LEN; i++) {
		printf("%d  ", current->value);
		current = current->next;
	}
	printf("\n");

	size=searchkey(&head, 5);   //�������в���ֵΪ5�Ľ��,����ҵ��򷵻ظýڵ����ţ����������1��
	
	research(head, 5, size);    //�ٴβ���
}
void opposite(Node ** head,Node * first,Node * second,Node * third) //�ڸ������в��ҵ�һ��ֵΪ5�Ľڵ㣬
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
		current->value = rand() % 20 + 1;     //����1-20�������
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