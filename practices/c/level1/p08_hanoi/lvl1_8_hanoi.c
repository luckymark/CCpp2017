/* code:	Hanoi
 * author:	Kyrios0
 * date: 	2016.10 (Maybe this time)
 * state: 	finished
 * version: 1.0.0
 */
 
#include<stdio.h> 
#include<stdlib.h>
#include<windows.h>

void hanoi(int n, char a, char b, char c)
{
	if(n > 0)
	{
		hanoi(n - 1, a, c, b);
		printf("From %c to %c \n", a, c);//it's too slow...With fprintf to replace printf will be a lot faster
		hanoi(n - 1, b, a, c);
	}
}

int main(int argc, char** argv)
{
	int n; char a = 'A', b = 'B', c = 'C';
	
	puts("input the number of discs");
	scanf("%d", &n);
	
	hanoi(n, a, b, c);
	
	system("pause");
	return 0; 
}

