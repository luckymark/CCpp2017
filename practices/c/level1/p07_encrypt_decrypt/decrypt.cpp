#include <cstdio>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;
int main(){
	char *s=NULL;
	int size=100;
	int i=0;
	s = (char*)malloc(sizeof(char) * size);
	if(s == NULL) return -1;
	while (1)
		{
			scanf("%c",s+i);
			if (*(s+i)=='\n')
				break;
			i++;
			if (i==size)
				{
					size<<=1;
					s=(char*)realloc(s,size);
					if(s==NULL)
						return -1;
				}
		}
	int len=i;
	int a[4]={3,1,2,4};
	for (int i=0;i<len;i++)
		*(s+i)+=a[i%4];
	for (int i=0;i<len/2;i++)
		swap(*(s+i),*(s+len-i-1));
	for (int i=0;i<len;i++)
		printf("%c",*(s+i));
	if(s) free(s);
	return 0;
}