#include<stdio.h>;

void main()
{
	int  t = 1, m, n;
	int num[101] = { 0 };
	int prime[26];

	for (int a = 2;a <= 10;a++) {
		if (num[a] == 0) {
			for (int b = 2 * a;b <= 100;b += a)
				num[b] = 1;
		}
	}

	for (int a = 2;a <= 100;a++) {
		if (num[a] == 0) {
			prime[t] = a;
			t += 1;
		}
	}

	for (m = 1;m <= 50;m++) {
		n = 2 * m;        //n��ʾ100���ڵ�ż����
		for (int p = 1;p <= 26;p++) {
			for (int d = 1;d <= p;d++) {
				if (n == prime[p] + prime[d])
					printf("%2d=%2d+%2d\t", n, prime[p], prime[d]);
			}
		}
	}
	printf("\n\n");

	if (m = 50) {
		printf("��ˣ���100���ڸ�°ͺղ�����ȷ��");
	}
	else {
		printf("��ˣ���100���ڸ�°ͺղ��벻��ȷ��");
	}
}