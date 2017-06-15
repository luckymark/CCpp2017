#include<stdio.h>
#include<string.h>
#define MAXN 100010
#define KEY 71

char s[MAXN];

void Encrypt(char* S);
void Decrypt(char* S);

int main(){
	gets(s);
	Encrypt(s);
	puts(s);
	Decrypt(s);
	puts(s);
	return 0;
}

void Encrypt(char* S){
	int len=strlen(S);
	for(int i=0;i<len;++i){
		S[i]-=32;
		S[i]=(S[i]+KEY%95)%95+32;
	}
}

void Decrypt(char* S){
	int len=strlen(S);
	for(int i=0;i<len;++i){
		S[i]-=32;
		S[i]=(S[i]%95-KEY%95+95)%95+32;
	}
}
