/*Caesar cipher*/

#include <stdio.h>
#include <stdlib.h>

#define SHIFT_NUM 8

typedef struct list{
	struct list *next;
	char data;
}node;

node *encrypt(void);
void decrypt(node *);
void disp_psw(node *); //Using for checking

int main(void)
{
	node *psw;
	
	printf("Enter your password(any length): ");
	psw = encrypt();
	printf("Encrypt: ");
	disp_psw(psw);
	decrypt(psw);
	printf("Discrypt: ");
	disp_psw(psw);
	
	return 0;
}

node *encrypt(void)
{
	char ch;
	node *first, *sq, *p;
	
	p = NULL;
	for (;;){
		first = p;
		p = (node *)malloc(sizeof(node));
		p->next = NULL;
		ch = getchar();
		p->data = ch + SHIFT_NUM;
		if (first == NULL){
			first = p;
			sq = first;
		}
		else
			first->next = p;
		if (ch == '\n')
			return sq;
	}
}

void decrypt(node *psw)
{
	while (psw->next != NULL){
		psw->data -= SHIFT_NUM;
		psw = psw->next;
	}
}

void disp_psw(node *psw)
{
	while (psw->next != NULL){
		putchar(psw->data);
		psw = psw->next;
	}
	printf("\n");
}
