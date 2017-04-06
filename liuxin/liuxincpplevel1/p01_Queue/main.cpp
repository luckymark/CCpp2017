#include <cstdio>
#include <iostream>
using namespace std;
#include "Queue.h"
#define FOR(i,a,b) for (int i=a;i<=b;++i)
#define ROF(i,b,a) for (int i=b;i>=a;--i)
inline int read(){
	int x=0,f=1; char ch=getchar();
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	while (ch>='0'&&ch<='9') { x=x*10+ch-'0'; ch=getchar(); }
	return x*f;
}

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	Queue S;
	int n,m,x;
	while(1){
		S.clear();
		cout<<S.isempty()<<endl;
		n=read();
		FOR(i,1,n) {
			x=read();
			if (!S.isfull()) S.append(x);
		}
		cout<<S.isempty()<<endl;
		m=read();
		FOR(i,1,m) {
			if (S.isempty()) break;
			cout<<S.front()<<endl;
			S.pop();
		}
		cout<<S.isempty()<<endl;
	}
	return 0;
}

/*
*/
