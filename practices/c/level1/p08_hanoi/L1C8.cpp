# include <stdio.h>

void hannuota(int n, char A, char B, char C)
{
	if (1 == n)
	{
		printf("将%d从%c->%c\n", n, A, C);
	}
	else
	{
		hannuota(n-1, A, C, B);
		printf("将%d从%c->%c\n", n, A, C);
		hannuota(n-1, B, A, C);

	}
}

int main(void)
{
	char ch1 = 'A';
	char ch2 = 'B';
	char ch3 = 'C';
	int n;
	printf("请输入盘子数目：");
	scanf("%d", &n);
	hannuota(n, 'A', 'B', 'C');
	return 0;
}
