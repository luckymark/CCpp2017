#include <stdio.h>  
//第一个塔为初始塔，中间的塔为借用塔，最后一个塔为目标塔  
int i=1;//记录步数  
void move(int n,char from,char to) //将编号为n的盘子由from移动到to  
{printf("第%d步:将%d号盘子%c---->%c\n",i++,n,from,to);  
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
     printf("请输入盘子的个数:\n");  
     int n;  
     scanf("%d",&n);  
     char x='A',y='B',z='C';  
     printf("盘子移动情况如下:\n");  
     hanoi(n,x,y,z);  
}
