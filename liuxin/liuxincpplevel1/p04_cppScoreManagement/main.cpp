#include <cstdio>
#include <iostream>
#include "Student.h"
#include "Class.h"
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int n,m;
char s[1000],t[1000];
int main(int argc, char** argv) {
	Class math("math","teacher:gaozhongxi");
	cin>>n;
	for (int i=1;i<=n;++i) {
		scanf("%s%s",s+1,t+1);
		Student a(s,t);
		math.Add(a);
	}
	math.ShowList();
	cin>>m;
	for (int i=1;i<=m;++i) {
		scanf("%s%s",s+1,t+1);
		Student b(s,t);
		if (math.Delete(b)) cout<<"OK\n";
		else cout<<"Bad\n";
	}
	math.ShowList();
	math.InputScore();
	math.ShowList();
	return 0;
}
