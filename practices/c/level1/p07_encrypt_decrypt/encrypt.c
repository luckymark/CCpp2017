#include <stdio.h>
#include <stdlib.h>
int main() {
	char *str = NULL;
	int size = 100;
	int i = 0;
	str = (char*)malloc(sizeof(char) * size);
	if (str == NULL)
		return -1;
	while (1)
	{
		scanf("%c", str + i);
		if (*(str + i) == '\n')
			break;
		i++;
		if (i == size)
		{
			size <<= 1;
			str = (char*)realloc(str, size);
			if (str == NULL)
				return -1;
		}
	}

	int len = i;
	int a[4] = {3, 1, 2, 4};
	for (i = 0; i < len / 2; i++)
	{
		char tmp = *(str + i);
		*(str + i) = *(str + len - i - 1);
		*(str + len - i - 1) = tmp;
	}
	for (i = 0; i < len; i++)
	{
		*(str + i) -= a[i % 4];
	}
	for (i = 0; i < len; i++)
	{
		printf("%c", *(str + i));
	}
	if (str)
	{
		free(str);
	}
	return 0;
}
