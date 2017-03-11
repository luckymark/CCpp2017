#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#define MAX 5
typedef struct Good {
	char size[101] = "";
	int num = 0;	
}good;
int mark_del(int*book);
void printf_goodlist(int *ptr,good* temp_good);
void del_goodlist(int *ptr, good* temp_good);
void add_goodlist(int *ptr, good* temp_good);
int main()
{
	int index = 0;
	good temp_good[MAX];
	int *ptr = &index;
	
	printf_goodlist(ptr, temp_good);

	printf("input 1,2 or 3\n");
	printf("1:printf goodlist\n");
	printf("2:add goods size and number into the warehouse\n");
	printf("3:delete from the warehouse\n");
	printf("q to quit\n");

	while (1)
	{
		printf("go ahead!\n");
		char ch = getchar();
		system("cls");
		switch (ch)
		{
		case '1':
		{
			printf("printf goodlist\n");
			printf_goodlist(ptr, temp_good);
			getchar();
			break;
		}
		case '2':
		{

			printf("add goods size and number into the warehouse\n");
			printf("click enter(once)+ctrl+z + enter(twice) to finish \n");
			add_goodlist(ptr, temp_good);
			break;
		}
		case'3':
		{
			printf("delete from the warehouse\n");
			printf("input the index of goods you want to delete add ctrl+z(before enter) at last");
			del_goodlist(ptr, temp_good);
			break;
		}
		case 'q': exit(0);
		default: {
			printf("you should input 1,2 or 3\n");
		}

		}
	}
	system("pause");
	return 0;
}

void printf_goodlist(int *ptr, good* temp_good)
{
	*ptr = 0;
	FILE *rgood = fopen("E:\\good.dat", "r+b");
	if (!rgood)
	{
		printf("can't open the file");
		exit(1);
	}

	char c;
	fseek(rgood, 0, SEEK_SET);
	while (!feof(rgood)) {
		if ((c = fgetc(rgood)) == EOF)
		{
			break;
		}
		fread(temp_good, sizeof(good), 1, rgood);
		(*ptr)++;
	}
	fseek(rgood, 0, SEEK_SET);
	fread(temp_good, sizeof(good), *ptr, rgood);
	int temp_index = *ptr;
	fclose(rgood);
	for (int i = 0; i < *ptr; i++)
	{
		printf("%s %d\n", temp_good[i].size, temp_good[i].num);
	}
}

int mark_del(int*book)
{
	int j,sum = 0;
	fflush(stdin);
	while (scanf("%d", &j) == 1)
	{	
		book[j] = 1;
		sum++;
	}
	return sum;
}



void del_goodlist(int *ptr, good* temp_good)
{
	int book[MAX] = { 0 };
	int total = (*ptr) - mark_del(book);
	good change_good[MAX];
	for (int i = 0, j = 0; i < total; )
	{
		if (book[j] == 0)
		{
			change_good[i++] = temp_good[j++];
		}
		else
		{
			j++;
		}
	}
	FILE *rwgood = fopen("E:\\good.dat", "w+b");
	if (!rwgood)
	{
		printf("can't open the file");
		exit(1);
	}
	fseek(rwgood, 0, SEEK_SET);
	fwrite(change_good, sizeof(good), total, rwgood);
	fclose(rwgood);
	getchar();
}

void add_goodlist(int *ptr, good* temp_good)
{
	FILE *wgood = fopen("E:\\good.dat", "w+b");
	if (!wgood)
	{
		printf("can't open the file");
		exit(1);
	}
	while (*ptr < MAX && 2 == scanf("%s %d", &temp_good[*ptr].size, &temp_good[*ptr].num) )
	{
		(*ptr)++;
	}
	if (*ptr == MAX )
	{
		printf("the warehouse is full\n");
	}
	fseek(wgood, 0, SEEK_SET);
	fwrite(temp_good, sizeof(good), *ptr, wgood);
	fclose(wgood);
	getchar();
}
