void main()
{
	int  t = 1,m,n;
	int c[101] = { 0 };
	int prime[26];

	for (int a = 2;a <= 10;a++) {
		if (c[a] == 0) {
			for (int b = 2 * a;b <= 100;b += a)
				c[b] = 1;
		}
	}

	for (int a = 2;a <= 100;a++) {
		if (c[a] == 0) {
			prime[t] = a;
			t += 1;
		}
	}

	for (m = 1;m <= 50;m++) {
		n = 2 * m;
		for (int p = 1;p <= 26;p++) {
			for (int d = 1;d <= p;d++) {
				if (n == prime[p] + prime[d])
					printf("%2d=%2d+%2d\t", n, prime[p], prime[d]);
			}
		}
	}
	printf("\n\n");

	if (m = 50) {
		printf("因此，在100以内哥德巴赫猜想正确。");
	}
	else {
		printf("因此，在100以内哥德巴赫猜想不正确。");
	}
}

