#include <stdio.h>  
//��һ����Ϊ��ʼ�����м����Ϊ�����������һ����ΪĿ����  
int i=1;//��¼����  
void move(int n,char from,char to) //�����Ϊn��������from�ƶ���to  
{printf("��%d��:��%d������%c---->%c\n",i++,n,from,to);  
}  
void hanoi(int n,char from,char denpend_on,char to) 
{  
    if (n==1)  
    move(1,from,to);//
    else  
    {  
      hanoi(n-1,from,to,denpend_on);
      move(n,from,to);                
      hanoi(n-1,denpend_on,from,to);
    }  
}  
void main()  
{  
     printf("���������ӵĸ���:\n");  
     int n;  
     scanf("%d",&n);  
     char x='A',y='B',z='C';  
     printf("�����ƶ��������:\n");  
     hanoi(n,x,y,z);  
}
