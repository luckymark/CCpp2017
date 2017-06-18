#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
	int n;
	scanf("%d",&n);
	char** result = ((char**)calloc((int)pow(2, n),sizeof(char*)));
	for (int i = 0; i <(int)pow(2,n); i++)
	{
		result[i] = (char*)calloc(2, sizeof(char));
	}
	result[1][0] = 'a';
	result[1][1] = 'c';
	for (int i = 2; i <= n ; i++)
	{
		int x = (int)pow(2, i - 1) ;
		result[x][0] = 'a';
		result[x][1] = 'c';
		for (int j = 1; j < x; j++)  //a b c  ->a c b
		{
			if (result[j][0] == 'c')
			{
				result[j][0] = 'b';
			}
			else if (result[j][0] == 'b')
			{
				result[j][0] = 'c';	
			}
			if (result[j][1] == 'b')
			{
				result[j][1] = 'c';				
			}
			else if (result[j][1] == 'c')
			{
				result[j][1] = ' b';
			}
		}
		for (int j = x + 1; j <= 2 * x-1; j++)//a c b ->b a c
		{
			if (result[j - x][0] == 'a')
			{
				result[j][0] = 'b';
			}
			else if (result[j - x][0] == 'b')
			{
				result[j][0] = 'c';
			}
			else
			{
				result[j][0] = ' a';
			}
			if (result[j - x][1] == 'a')
			{
				result[j][1] = ' b';
			}
			else if (result[j - x][1] == 'b')
			{
				result[j][1] = ' c';
			}
			else
			{
				result[j][1] = ' a';
			}
		}
	}
	for (int i = 1; i < (int)pow(2, n); i++)
	{
		printf("%c->%c\n", result[i][0], result[i][1]);
		free(result[i]);
	}
	free(result);
		system("pause");
	return 0;
}
