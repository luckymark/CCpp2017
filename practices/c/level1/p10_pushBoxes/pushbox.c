 #include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>
int migong[10][10]={ 1 };//ֵ��ʼ��

int shuaxin(int bushu)//�Թ��γɺ��� 
{
	printf("\n\n\n\n\t\t         ������������������������\n");
	for (int i = 0; i < 10; i++)
	{
			
			printf("\t\t         ");
			printf("��");
		for (int j = 0; j < 10; j++)
		{
			if (migong[i][j] == 1)//�˴���switch�������ѧBUG 
			{
				printf("��");//wall
			}
			else if(migong[i][j]==0)//ֻ��ʹ��if else�ṹ 
			{
				printf("  ");//air
			}
			else if(migong[i][j]==2)
			{ 
				printf("��");//I
			}
			else if(migong[i][j]==3)
			{
				printf("��");//box
			}
			else if(migong[i][j]==4)
			{
				printf("? ");//aim
			}
			else 
			{
				system("cls");
				printf("txt�ļ����ݳ����쳣��");//wrong
				return 1;	
			}
			
		}
		printf("��");
		printf("\n");
	}
	printf("\t\t         ������������������������");//���޸�
	printf("\n\t\t                Ŀǰ������%d",bushu);
	printf("\n\t\t               ���¿�ʼ�밴R��");
	return 0;
}


int main()
{
	
	back:;
		printf("\n\n\n\n\n\n\n\n\n\t             HELLO! HERE IS A SIMPLE BOX-PUSHING GAME~\n");//hello
		printf("\n\t                      PLEASE CHOOSE MODE!\n");
		printf("\n\t                           E:EASY\n");
		printf("\t                           N:NORMAL\n");
		printf("\t                           H:HARD");
		char ch=getch();
		fflush(stdin);
		system("cls");
		int dif;
		
	
		FILE*fp;//���ļ��ж�ȡ���� 
		int i,j;
		if(ch=='E'||ch=='e')
		{
			fp=fopen("EASY.txt","r");
			dif=0;//�����ж����ĸ��ļ���д�� 
		}
		else if(ch=='N'||ch=='n')
		{
			fp=fopen("NORMAL.txt","r");
			dif=1;
		}
		else if(ch=='H'||ch=='h')
		{
			fp=fopen("HARD.txt","r");
			dif=2;
		}
		else
		{
			printf("\n\n\n\n\n\n\n\n\n\n\n\t                   Please choose correct mode��");
			getch();
			fflush(stdin);
			system("cls");
			goto back;
			
		}
		if(fp==NULL) //���ļ�����
		{
			printf("\n\n\n\n\n\n\n\n\n\n\n\t                   Can not find this file!"); 
			getch();
			fflush(stdin);
			system("cls");
			goto back; 
		}
		else 
		{
			for(i=0;i<10;i++)
			{
				for(j=0;j<10;j++)
				{		
					fscanf(fp, "%d", &migong[i][j]); //��ȡ���ݵ����飬ֱ���ļ���β(����EOF)
				}
			}
		}
		
		fclose(fp);
		
		
		 
		int a=0;//������¼���������ı���
		int b=0;//������¼Ŀ�������ı���
		int m=0;//��¼ ��������
		int n=0; 
		int c[100];
		int d[100];//������¼Ŀ���λ�� ����͵һ������д��̬������ 
		for(i=0;i<10;i++)
		{
			for(j=0;j<10;j++)
			{	if(migong[i][j]==2)
				{
					m=i;
					n=j;
				}
		   		if(migong[i][j]==3)
				{
					a++;
				}
		   		if(migong[i][j]==4)
				{
					c[b]=i;
					d[b]=j;
					b++;
				}
			}
		}
		if(a!=b)
		{
			printf("\n\n\n\n\n\n\n\n\n\n\n\t               �ļ���������������Ŀ��λ��������ͬ��");
			system("cls"); 
		}
	

 		int bushu=0;
	

		if(shuaxin(bushu)==1)return 0;//�Թ���ʼ�����
		fflush(stdin);
		char move;
		while(move=getch())//����ѭ������ 
		{

			if(move=='w')
			{
				if(m!=0)
				{
					if(migong[(m-1)][n]==0||migong[(m-1)][n]==4)//�˿����������Ŀ��λ���� 
					{	
						migong[(m-1)][n]=2;
						migong[m][n]=0;
						m--;
						bushu++;
					}
					else if(m!=1&&migong[(m-1)][n]==3&&(migong[(m-2)][n]==0||migong[(m-2)][n]==4))//�˿��Խ��������������Ŀ��λ��
					{
						migong[(m-1)][n]=2;
						migong[(m-2)][n]=3;
						migong[m][n]=0;
						m--;
						bushu++;
					}
				}	
			}
			
			else if(move=='a')
			{
				if(n!=0)
				{
					if(migong[(m)][n-1]==0||migong[(m)][n-1]==4)
					{	
						migong[m][(n-1)]=2;
						migong[m][n]=0;
						n--;
						bushu++;
					}
					else if(n!=1&&migong[m][(n-1)]==3&&(migong[(m)][(n-2)]==0||migong[(m)][(n-2)]==4))
					{
						migong[m][(n-1)]=2;
						migong[m][(n-2)]=3;
						migong[m][n]=0;
						n--;
						bushu++;
					}
				}
			}
		
			else if(move=='d')
			{
				if(n!=9)
				{
					if(migong[(m)][n+1]==0||migong[(m)][n+1]==4)
					{	
						migong[m][(n+1)]=2;
						migong[m][n]=0;
						n++;
						bushu++;
					}
					else if(n!=8&&migong[m][(n+1)]==3&&(migong[(m)][(n+2)]==0||migong[(m)][(n+2)]==4))
					{
						migong[m][(n+1)]=2;
						migong[m][(n+2)]=3;
						migong[m][n]=0;
						n++;
						bushu++;
					}
				}
			}  
		
			else if(move=='s')
			{
				if(m!=9)
				{
					if(migong[(m+1)][n]==0||migong[(m+1)][n]==4)
					{	
						migong[(m+1)][n]=2;
						migong[m][n]=0;
						m++;
						bushu++;
					}
					else if(m!=8&&migong[(m+1)][n]==3&&(migong[(m+2)][n]==0||migong[(m+2)][n]==4))
					{
						migong[(m+1)][n]=2;
						migong[(m+2)][n]=3;
						migong[m][n]=0;
						m++;
						bushu++;
					}
				}	
			}
			else if(move=='r'||move=='R')
			{
				system("cls");
				goto back;
			}
			else if(move=='l')
			{
				if(getch()=='i')
				{
					if(getch()=='u')
					{
						if(getch()=='x')
						{
							if(getch()=='i')
							{
								if(getch()=='y')
								{
									if(getch()=='u')
									{
										if(getch()=='z')
										{
											if(getch()=='h')
											{
												if(getch()=='e')
												{
													if(getch()=='n')
													{
														if(getch()=='s')
														{
															if(getch()=='h')
															{
																if(getch()=='u')
																{
																	if(getch()=='a')
																	{
																		if(getch()=='i')
																		{
																			if(dif==0)
																			{
																				fp=fopen("EASYSAVE.TXT","a+");
																				fprintf(fp,"\n�˴����ò���Ϊ1��");
																				fclose(fp);
																						
																			}
																			else if(dif==1)
																			{
																				fp=fopen("NORMALSAVE.TXT","a+");
																				fprintf(fp,"\n�˴����ò���Ϊ1��");
																				fclose(fp);
						
																			}
																			else if(dif==2)
																			{
																				fp=fopen("HARDSAVE.TXT","a+");
																				fprintf(fp,"\n�˴����ò���Ϊ1��");	
																				fclose(fp);
									
																			}
																			system("cls");
																			printf("\n\n\n\n\n\n\n\n\n\n\t              You are clever~~~thank you!!");
																			getch();
																			return 0;
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
			
			while(1)//
			{
			
				for(int k=0;k<b;k++)
				{
					if(migong[(c[k])][(d[k])]!=3)//������δ��ɵĵ������ 
					{
					goto cot;
					}
				}
				while(1)
				{
					
					if(dif==0)
					{
						fp=fopen("EASYSAVE.TXT","a+");
						fprintf(fp,"\n�˴����ò���Ϊ%d��",bushu);
						fclose(fp);
						
					}
					else if(dif==1)
					{
						fp=fopen("NORMALSAVE.TXT","a+");
						fprintf(fp,"\n�˴����ò���Ϊ%d��",bushu);
						fclose(fp);
						
					}
					else if(dif==2)
					{
						fp=fopen("HARDSAVE.TXT","a+");
						fprintf(fp,"\n�˴����ò���Ϊ%d��",bushu);	
						fclose(fp);
						
					}
					system("cls");
					if(dif==0||dif==1)
					{
						printf("\n\n\n\n\n\n\n\n\n\n\t        Congratulations!You have finished my zhazha game!");
					}
					
					else if(dif==2)
					{
						printf("\n\n\n\n\n\n\n\n\n\n\t             Wow!You have fuck my game off!66666~");
					}
					
					printf("\n\n\n\t                      Try other modes? Y/N\n");
					
					
					char ck=getch();
					if(ck=='Y'||ck=='y')
					{
						system("cls");
						goto back;
					}
					else if(ck=='N'||ck=='n')
					{
					return 0;
					}
					else;
					
				}
			}
			
			
		cot:for(int k=0;k<b;k++)//�����ӻ��˲���Ŀ��λ��������Ŀ��λ��
			{
				if((migong[(c[k])][(d[k])]!=2)&&(migong[(c[k])][(d[k])]!=3))
				migong[(c[k])][(d[k])]=4;
			}
			

			
			
			
			system("cls");
			shuaxin(bushu);
		
	
			
		}
		
		
	return 0;
}

