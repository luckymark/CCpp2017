#include <cstdio>
#include <iostream>
using namespace std;
#include "Stack.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int i,j,k,n;
	cin>>n;
	Stack S(n);
	cin>>n;
	for (i=1;i<=n;++i) {
		cin>>k;
		if (!S.IsFull()) S.push(k);
	}
	cout<<"IsFull:"<<S.IsFull()<<endl;
	cout<<"IsEmpty:"<<S.IsEmpty()<<endl;
	while (!S.IsEmpty()) {
		cout<<S.top()<<endl;
		S.pop();
	}
	return 0;
}

