#include<stdio.h>
#include<stdlib.h>

int main()
{
	int L = 5;
	int i;
	char k, ch;
	char* p = (char*)malloc(sizeof(char) * L);
	int count = 0;
	printf("请选择您是想加密还是解密:a、加密     b、解密\n");
	k = getch();
	if (k == 'a') {
		printf("请输入您想加密的字符串: ");
		do
		{
			ch = getchar();
			count++;
			if (count >= L) {
				p = (char*)realloc(p, sizeof(char*) * (++L));
			}
			p[count - 1] = (char)((int)ch + 4);
		} while (ch != '\n');
		printf("您一共输入%d个字符\n加密后的密文为：", count - 1);
		for (i = 0;i < count;i++) {
			printf("%c", p[i]);
		}
		free(p);
	}


	else if (k == 'b') {
		printf("请输入您想解密的字符串: ");
		do
		{
			ch = getchar();
			count++;
			if (count >= L) {
				p = (char*)realloc(p, sizeof(char*) * (++L));
			}
			p[count - 1] = (char)((int)ch - 4);
		} while (ch != '\n');
		printf("您一共输入%d个字符\n解密后的密文为：", count - 1);
		for (i = 0;i < count;i++) {
			printf("%c", p[i]);
		}
		free(p);
	}
	else {
		printf("您输入的信息有误.");
		return 0;
	}
}

