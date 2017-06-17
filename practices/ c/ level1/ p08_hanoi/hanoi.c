#include<stdio.h>
void move(int a, char from, char to);
int i = 1;
void hanoi(int x, char from, char by, char to);
#include<stdlib.h>
void main()
{
	int n;
	char a = 'A', b = 'B', c = 'C';
	printf("请输入圆盘个数");
	scanf_s("%d", &n);
	printf("圆盘移动情况如下：");
	hanoi(n,a,b,c);
	system("pause");
}

void move(int a, char from, char to)
{
	printf("第%d步:第%d个盘从%c->%c\n",i,a, from, to);
	i++;
}

void hanoi(int x, char from, char by, char to)
{
	if (x == 1) {
		move(x, from, to);
	}
	if (x > 1) {
		hanoi(x - 1, from, to, by);
			move(x, from, to);
		hanoi(x - 1, by, from,to);
	}
}
