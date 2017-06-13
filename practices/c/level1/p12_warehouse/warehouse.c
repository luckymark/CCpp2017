#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct Item
{
	int num, sum;
};
struct Node
{
	struct Item item;
	struct Node *next;
} * head, *last, *node;
void AddToLinkedList(struct Item item);
struct Item FindList(int x);
void Pre();
void ShowList();
void Add();
void Remove();
void ShowMenu();
int main()
{
	Pre();
	while (1)
	{
		ShowMenu();
		int n;
		scanf("%d", &n);
		switch (n)
		{
		case 1:
			ShowList();
			break;
		case 2:
		{
			printf("enter the number and quantity:\n");
			int n, s;
			scanf("%d%d", &n, &s);
			Add(n, s);
			break;
		}

		case 3:
		{
			printf("enter the number you want to remove:\n");
			int n;
			scanf("%d", &n);
			Remove(n);
			break;
		}
		case 4:
			return 0;
			break;
		}
		printf("please enter any key to continue\n");
		while (!kbhit())
			;
		system("cls");
	}

	return 0;
}
void AddToLinkedList(struct Item item)
{
	node = (struct Node *)malloc(sizeof(struct Node));
	node->item = item;
	node->next = NULL;
	if (last == NULL)
	{
		head = last = node;
	}
	else
	{
		last->next = node;
		last = node;
	}
}
void Pre()
{
	head = last = node = NULL;
	FILE *f = fopen("ware.txt", "r");
	int num, sum;
	while (fscanf(f, "%d%d", &num, &sum) > 0)
	{
		struct Item item;
		item.num = num;
		item.sum = sum;
		AddToLinkedList(item);
	}
}
void ShowList()
{
	struct Node *pos = head;
	for (; pos != NULL; pos = pos->next)
	{
		printf("sequence number is:%d item and quntitiy is:%d\n", pos->item.num, pos->item.sum);
	}
}
void Add(int a, int b)
{
	struct Item item;
	item.num = a;
	item.sum = b;
	AddToLinkedList(item);
}
void Remove(int x)
{
	struct Node *t1 = head, *t2 = NULL, *pos;
	int flag = 0;
	for (pos = head; pos != NULL; pos = pos->next)
		if (pos->item.num == x)
			flag = 1;
	if (flag == 0)
	{
		printf("not founded\n");
		return;
	}
	while (t1 != NULL)
	{
		t2 = t1;
		t2 = t1->next;
		if (t2->item.num == x)
		{
			t1->next = t2->next;
			free(t2);
			break;
		}
		t1 = t1->next;
	}
}
void ShowMenu()
{
	printf("\n\n\nMENU:\n\t1.Show List\n\t2.Put into warehouse\n\t3.Get item from warehouse\n\t4.exit program\n\n\n");
	printf("please enter a number to confirm your operation:");
}
struct Item FindList(int x)
{
	struct Node *pos;
	struct Item t;
	for (pos = head; pos != NULL; pos = pos->next)
	{
		if (x == pos->item.num)
		{
			t.num = x;
			t.sum = pos->item.sum;
			return t;
		}
	}
	t.num = -1;
	t.sum = -1;
	return t;
}
