# include<stdio.h>

void encrypt(char st[100]){
	int i = 0;
	while(st[i]!='\0'){
		st[i] += 10;
		i++;
	}
	return;
}

void decode(char st[100]){
	int i = 0;
	while(st[i]!='\0'){
		st[i] -= 10;
		i++;
	}
}

int main()
{
	char st[100] = {'\0'};
	gets(st);
	printf("%s\n", st);
	encrypt(st);
	printf("%s\n", st);
	decode(st);
	printf("%s\n", st);
	return 0;
}
