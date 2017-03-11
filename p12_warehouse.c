#include<stdio.h>
#include<stdlib.h>


char menu(void);
void AddItem();
void show_list();
void DeItem();
void save();
void load();
void Add(int type, int num);

typedef struct item
{
	int type;
	int num;
}Item;

typedef struct node
{
	Item item;
	struct node * next;
} Node;

typedef struct queue
{
	struct node* front;
	struct node* rear;

}Queue;

Item temp;
Queue queue;

void main()
{
	char input;
	queue.front = queue.rear = NULL;

	load();

	input = 0;
	while (input != '4')
	{
		input = menu();
		switch (input)
		{
		case'1':
			show_list();
			break;
		case'2':
			AddItem();
			break;
		case'3':
			DeItem();
			break;
		case'4':
			save();
			break;
		}


		

	}

	system("pause");

}




void AddItem()
{

	puts("enter type of item:");
	scanf_s("%d", &(temp.type));
	puts("enter number of item:");
	scanf_s("%d", &(temp.num));
	while (getchar() != '\n')
		continue;
	Add(temp.type,temp.num);


}
char menu(void)
{
	char ch;
	puts("enter the following letter to operate:");
	puts("1. show list");
	puts("2. add item");
	puts("3. delete item");
	puts("4. save and quit");

	ch = getchar();

	while (getchar() != '\n')
			continue;
	return ch;

}
void show_list()
{
	for (Node* pt = queue.front; pt != NULL; pt = pt->next)
	{
		printf("type:%d   number:%d\n", pt->item.type, pt->item.num);
	
	}

}
void DeItem()
{
	int type;
	Node* pr = NULL;
	Node* pt = queue.front;
	puts("enter the type to be deleted:");
	scanf_s("%d", &type);
	
	while (getchar() != '\n')
		continue;
	for (Node* pt = queue.front; pt != NULL; pr=pt,pt = pt->next)
	{

		

		if (pt->item.type == type)
		{
			if (pr == NULL)
			{
				queue.front = pt->next;
				break;
			}
			else
			{
				pr->next = pt->next;
				free(pt);
				break;
			}
		}

	}
}

void save()
{
	FILE* pf;
	fopen_s(&pf, "file.txt", "w+");

	for (Node*pt = queue.front; pt != NULL; pt = pt->next)
	{
		fprintf(pf, "%d %d ", pt->item.type, pt->item.num);
		
	}
	fclose(pf);
}
void load()
{
	FILE * pf;
	if (fopen_s(&pf, "file.txt", "r") != 0)
		puts("cannot open file");
	;
	while (fscanf_s(pf, "%d", &(temp.type)) == 1)
	{
		while (fscanf_s(pf, "%d", &(temp.num)) == 1) 
		{
			Add(temp.type, temp.num);
			break;
		}
	}
	fclose(pf);
}
void Add(int type,int num)
{
	Node * pnew = (Node*)malloc(sizeof(Node));
	pnew->item = temp;
	pnew->next = NULL;

	if (queue.front == NULL)
		queue.front = pnew;
	else
		queue.rear->next = pnew;
	queue.rear = pnew;
}