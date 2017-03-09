#include <stdio.h>
#include <stdlib.h>

#define LENGTH 5

typedef int ElemType; 
typedef struct node{
	ElemType data;
	struct node *next;
} list;
list *stack[LENGTH];

void traversal(list *, int * );
int find(int );

int main(void)
{
	list *first, *sq, *new_node;
	int top = -1, value[LENGTH] = {5, 5, 5, 5, 1};
	
	sq = NULL;
	for (int i = 0; i < LENGTH; i++){
		new_node = (list *)malloc(sizeof(list));
		new_node->next = NULL;
		if (sq == NULL){
			sq = new_node;
			sq->next = new_node;
			first = sq;
		}
		else{
			sq = sq->next;
			sq->next = new_node;
		}
		top++;
		stack[top] = new_node;
	}
	traversal(first, value);
	for (; top; top--)
		stack[top]->next = stack[top - 1];
	stack[top]->next = NULL;
	for (int i = LENGTH - 1; i >= 0; i--){
		int val = find(i);
		printf("%d\n", LENGTH - val);
		if (val != -1)
			i = val;
		else if (val == -1)
			return 0;
	}
}

void traversal(list *p, int value[LENGTH])
{
	int i;
	
	for (i = 0; i < LENGTH - 1; i++){
		p->data = value[i];
		p = p->next;
	}
	p->data = value[i];
}

int find(int i)
{
	for (; i >= 0; i--){
		if (stack[i]->data == 5){
			return i;
		}
	}
	return -1;
}
