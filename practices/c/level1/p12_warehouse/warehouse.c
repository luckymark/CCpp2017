
#include <stdio.h> 
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <malloc.h> 
/*
ʵ�����µĲ˵���������ѡ��˵����ܣ���
	1 ��ʾ����б�
	2 ���
	3 ����
    4 �˳�����
ʵ�ֲ˵���Ӧ���ܣ����¼������ͺš���������Ϣ����
��������ʱ���ļ��ж�ȡ��ǰ������ݣ��˳�ʱ���������ݣ�*/



typedef struct tempname//�ṹ part���� 
{
	int num;
	char* str;
	struct tempname *next;
}part;



void creatlb(part** nd)//��ʼ������ͷ 
{
	*nd = NULL;
}

void disp(part** head)
{
	part* cp = *head;
	while (cp != NULL)
	{
		printf("����Ϊ%s��", cp->str);
		printf("�����Ϊ%d\n", cp->num);
		cp = cp->next;
	}
	_getch();
}

int findname(part** head, char* zfc)
{
	part* xp = *head;
	int i = 1;
	int k = 0;
	while (xp != NULL)
	{
		if (strcmp((xp->str),zfc)==0)//ֻҪ����ͬ���ֵķ��ظ�����������λ�ã����򷵻�-1
		{
			return i;
		}
		xp = xp->next;
		i++;
	}
	return 0;
}


void weicha(part** head, part* new_part, int value, char* str)//β��,��һ���µĲ�������
{
	part* cp = *head;//����ָ��
	new_part->num = value;
	new_part->str = str;
	if (*head == NULL)//���Ϊ�� 
	{
		*head = new_part;//��ͷָ��ָ��new part����
		new_part->next = NULL;//��newpart��Ϊ�󲿷� 
	}
	else
	{
		while (cp->next != NULL)
		{
			cp = cp->next;
		}
		cp->next = new_part;
		new_part->next = NULL;
	}
}

int main(void)
{

	part* head;
	creatlb(&head);
	
	


//����Ϊ��ȡ�ļ�


	FILE *fp = fopen("userinfo.txt", "r");
	if (fp == NULL)
	{
		printf("can not open or create file!");
		system("pause");
		return 0;
	}
	else
	{
		while(!feof(fp))
		{
			char* sp=(char*)malloc(20*sizeof(char));
			int x;
			if(fscanf(fp,"%s %d ",sp,&x)==2)
			{
				part* new_part = (part*)malloc(sizeof(part));
				weicha(&head, new_part, x, sp);//��store��ȡ��ֵ���������
			}
			
		}
	}
	fclose(fp);






//����Ϊ��ʼ����
	while (1) 
	{

		system("cls");

		HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_RED);
		printf("\n\n\n\n\n\n\n\n\n\t                         A simple warehouse\n");//hello
		SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN);
		printf("\n\t                      Please choose an option!\n");
		SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY |FOREGROUND_RED | FOREGROUND_BLUE);
		printf("\n\t                       1:Show inventory list\n");
		printf("\t                              2:import\n");
		printf("\t                              3:export");
		printf("\t                           4:save and exit");
		SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY |FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);




//����Ϊ�û�����


	
		char cos = _getch();
		int slsl;
		if (cos == '1')//��ʾ����б�
		{
			system("cls");
			disp(&head);

		}
		else if (cos == '2')//���
		{
			char* ap=(char*)malloc(60*sizeof(char));
			system("cls");
			printf("������Ҫ�����Ʒ������:");
			scanf("%s", ap);
			printf("������Ҫ�����Ʒ������:");
			scanf("%d", &slsl);
			if (findname(&head, ap) != 0)//����������Ʒ����
			{

				_getch();
				part* cp = head;
				for(int i=1;i<findname(&head, ap);i++)
				{
					cp = cp->next;
				}
				cp->num = cp->num+slsl;
			}
			else
			{
				part* new_part = (part*)malloc(sizeof(part));
				weicha(&head, new_part, slsl, ap);
			}
			printf("��Ʒ����⣡");
			_getch();



		}
		else if (cos == '3')//����
		{
			char* ap=(char*)malloc(20*sizeof(char));
			system("cls");
			printf("������Ҫ������Ʒ������:");
			scanf("%s", ap);
			
			if (findname(&head, ap) != 0)//����������Ʒ����
			{
				printf("\n������Ҫ������Ʒ������:");
				scanf("%d", &slsl);
				part* cp = head;
				for (int i = 1; i<findname(&head, ap); i++)
				{
					cp = cp->next;
				}
				if (cp->num >= slsl)
				{
					cp->num = cp->num - slsl;
					printf("��Ʒ����ɹ���");
					_getch();
				}
				else
				{
					printf("��Ʒ�������㣡Ŀǰ����ֻ��%d����Ʒ��", cp->num);
					_getch();
				}
			}
			else
			{
				printf("��Ʒ�����ڣ�");
				_getch();
			}


		}
		else if (cos == '4')//�˳�����
		{
			
			
			FILE *op = fopen("userinfo.txt", "w");
			if (op == NULL)
			{
				printf("�˴����洢ʧ�ܣ�");
				system("pause");
				return 0;
			}
			else
			{
				int y;
				part* cp = head;
				while (cp != NULL)
				{
					char* wp=(char*)malloc(20*sizeof(char));
					y=cp->num;
					wp=cp->str;
					fprintf(fp,"%s %d ",wp,y);
					{
						cp = cp->next;
					}
				}
			}
			fclose(fp);
			
			
			return 0;
			
			
		}
	}
	return 0;
	}
	






