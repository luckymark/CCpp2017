#include<stdio.h>
#include<string.h>
int fan();
void input();
void show();
void divided5();


static int i = 1,a;
int *K;
struct slist {
	long int value;
	int number;
	struct slist*next;
};
struct slist*head = NULL;
struct slist*prev = NULL, *cur;


int main(void)
{
	int  k;

	printf("if you want to input data, please input any key,otherwise 2��");
	while (getchar() != '2'){
		printf("data:");
		input();
	}

	if (head == NULL) {
		printf("No datas were inputd\n");
	}
	else {
		printf("Here are the datas you've inputted:\n");
	}

	cur = head;
	show();

	if (i > 2) {
		fan();
		printf("Here are the datas �������:\n");
		show();
	}
	else if(i==2){
		printf("Here are the datas �������:\n");
		printf("��1һ������Ϊ%d\n", prev->value);
	}

	divided5();
	free(cur);
}


int fan()
{
	struct slist*next = NULL;
	if (NULL != head->next) {
		prev = head;
		cur = prev->next;
		next = cur->next;
	}
	else if(NULL == head->next) {
		prev = head;
		cur = prev->next;
	}
	
	i = i - 1;
	prev->next = NULL;
	prev->number = i;

	while (1) {
		i--;
		cur->number = i;
		cur->next = prev;

		if (next) {
			prev = cur;
			cur = next;
			next = next->next;
		}
		else {
			return K=cur;
		}
	}
}


void input()
{
	cur = (struct slist*)malloc(sizeof(struct slist));
	if ((struct slist*)malloc(sizeof(struct slist)) == NULL)
		return -1;
	if (head == NULL) {
		head = cur;
	}
	else {
		prev->next = cur;
	}
	cur->next = NULL;
	scanf_s("%d", &a);
	cur->value = a;
	cur->number = i;
	printf("if you want to input another data, please input any key,otherwise 2��");
	getchar();
	prev = cur;
	++i;
}


void show()
{
	while (cur != NULL) {
		printf("��%d������Ϊ%d\n", cur->number, cur->value);
		cur = cur->next;
	}
}

void divided5()
{
	if (i == 2) {
		if (prev->value % 5 == 0) {
			printf("�ܱ������������ݵ�λ��Ϊ��  1\n");
		}
		else {
			printf("û�����ݿ��Ա�5����");
		}
	}
	else {
		printf("�ܱ�5������λ��Ϊ��\n");
		cur = K;
		while (cur != NULL) {
			if (cur->value % 5 == 0) {
				printf("%5d", cur->number);
			}
			cur = cur->next;
		}

	}
}
