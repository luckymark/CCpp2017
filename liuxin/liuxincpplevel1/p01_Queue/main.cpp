#include <cstdio>
#include <iostream>
using namespace std;
#include "Queue.h"
#define FOR(i,a,b) for (int i=a;i<=b;++i)
#define ROF(i,b,a) for (int i=b;i>=a;--i)

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	Queue S;
	int n,m,x;
	while(1){
		S.clear();
		cout<<S.IsEmpty()<<endl;
		cin>>n;
		FOR(i,1,n) {
			cin>>x;
			if (!S.IsFull()) S.append(x);
		}
		cout<<S.IsEmpty()<<endl;
		cin>>m;
		FOR(i,1,m) {
			if (S.IsEmpty()) break;
			cout<<S.front()<<endl;
			S.pop();
		}
		cout<<S.IsEmpty()<<endl;
	}
	return 0;
}

/*
*/
