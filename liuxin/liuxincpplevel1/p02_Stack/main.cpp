#include <cstdio>
#include <iostream>
#include "Stack.h"
inline int read(){
	int x=0,f=1; char ch=getchar();
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	while (ch>='0'&&ch<='9') { x=x*10+ch-'0'; ch=getchar(); }
	return x*f;
}

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	Stack S;
	int i,j,k,n=read();
	for (i=1;i<=n;++i) {
		k=read();
		if (!S.IsFull()) S.push(k);
	}
	while (!S.IsEmpty()) {
		std::cout<<S.top()<<std::endl;
		S.pop();
	}
	return 0;
}

