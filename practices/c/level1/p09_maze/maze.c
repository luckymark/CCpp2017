#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<math.h>
char migong[10][10] = { 0 };//�Թ�ֵ��ʼ��

int shuaxin(void)
{
	printf("\t��������������\n");
	for (int i = 0; i < 10; i++)
	{
		if(i!=0)
		{
			printf("\t");
			printf("��");
		}
		else printf("START��   ");
		for (int j = 0; j < 10; j++)
		{
			if (migong[i][j] == 1)
			{
				printf("|");
			}
			else if(migong[i][j]==0)
			{
				printf(" ");
			}
			else printf("I");
		}
		if(i!=9)printf("��");
		else printf("    ��END");
		printf("\n");
	}
	printf("\t��������������");//���޸� 
	return 0;
}


int main()
{

	for (int k = 0; k < 10; k++)//kΪ��
	{
		if (k % 2 == 0)
		{
			if (k % 4 == 0)
			{
				for (int i = 1; i < 10; i++)
				{
				    migong[i][k] = 1;
				}
			}
			else
			{
				for (int i = 0; i < 9; i++)
				{
					migong[i][k] = 1;
				}
			}
		}
	}

 
	//����Ϊ�Թ���״���죬���������㷨���棬�߽���shuaxin�����Զ����� 


		migong[0][1]=2;
		shuaxin();//�Թ���ʼ�����
		int m=0;
		int n=1;
		char judge; 
		while(judge=getch())
		{
		
			if(judge=='w')
			{
				if(m!=0)
				{
					if(migong[(m-1)][n]==0)
					{	
						migong[(m-1)][n]=2;
						migong[m][n]=0;
						m--;
					}
				}	
			}
			
			else if(judge=='a')
			{
				if(n!=0)
				{
					if(migong[(m)][n-1]==0)
					{	
						migong[m][(n-1)]=2;
						migong[m][n]=0;
						n--;
					}
				}
			}
		
			else if(judge=='d')
			{
				if(n!=9)
				{
					if(migong[(m)][n+1]==0)
					{	
						migong[m][(n+1)]=2;
						migong[m][n]=0;
						n++;
					}
				}
			}
		
			else if(judge=='s')
			{
				if(m!=9)
				{
					if(migong[(m+1)][n]==0)
					{	
						migong[(m+1)][n]=2;
						migong[m][n]=0;
						m++;
					}
				}	
			}
			
			system("cls");
			shuaxin();
			
			if(m==9&&n==9)
			{
				if(getch()=='d')
				{
					system("cls");
					printf("\n\n\n\n\n\n\n\n\n\n\n\t        Congratulations��You have finished my zhazha game!");
				}
			}
			
		}


    return 0;
}

